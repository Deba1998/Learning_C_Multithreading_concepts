/**
 * Connecting cell phones to a charger
 */

//difference between binary semaphore and mutex is that mutex can be unlocked by the same thread as the thread acquired  but in case of semaphore any thread can unlock it

#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

using namespace std;
//there is no semaphore before c++20
//custom semaphore implementation
class Semaphore {
public:
    Semaphore(unsigned long init_count) {
        count_ = init_count;
    }

    void acquire() { // decrement the internal counter
        std::unique_lock<std::mutex> lck(m_);
        while (!count_) {
            cv_.wait(lck);
        }
        count_--;
    }

    void release() { // increment the internal counter
        std::unique_lock<std::mutex> lck(m_);
        count_++;
        lck.unlock();
        cv_.notify_one();
    }

private:
    std::mutex m_;
    std::condition_variable cv_;
    unsigned long count_;
};

Semaphore charger(4); //acts as counting semaphore if value is more than one otherwise acts as binary semaphore

void cell_phone(int id) {
    charger.acquire();
    printf("Phone %d is charging...\n", id);
    srand(id); // charge for "random" amount between 1-3 seconds
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 2000 + 1000));
    printf("Phone %d is DONE charging!\n", id);
    charger.release();
}

int main() {
    thread phones[10];
    for (int i=0; i<10; i++) {
        phones[i] = thread(cell_phone, i);
    }
    for (auto& p : phones) {
        p.join();
    }
}