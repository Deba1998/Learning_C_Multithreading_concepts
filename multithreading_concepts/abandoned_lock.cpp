/**
 * Two philosophers, thinking and eating sushi
 */
#include <thread>
#include <mutex>

int sushi_count = 5000;

void philosopher(std::mutex &chopsticks) {
    while (sushi_count > 0) {
        std::scoped_lock lock(chopsticks); //this helps to release the lock even when one is break as it goes out of scope and destroy
        //chopsticks.lock(); // this will cause deadlock if some thread is break before unlocking
        if (sushi_count) {
            sushi_count--;
        }
        if (sushi_count == 10) {
            printf("This philosopher has had enough!\n");
            break;
        }
        //chopsticks.unlock();
    }
}

int main() {
    std::mutex chopsticks;
    std::thread barron(philosopher, std::ref(chopsticks));
    std::thread olivia(philosopher, std::ref(chopsticks));
    barron.join();
    olivia.join();
    printf("The philosophers are done eating.\n");
}