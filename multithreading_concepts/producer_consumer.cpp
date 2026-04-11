/**
 * Threads serving and eating soup
 */
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

class ServingLine {
    public:
        void serve_soup(int i) {
            unique_lock<mutex> ladle_lock(ladle);
            soup_queue.push(i);
            ladle_lock.unlock(); //also can work without unlock also as ladke lock is unique lock will be automatically unlocked when goes out of scope  but it is preferred to do before notify as it will save cpu cycles
            soup_served.notify_one(); //one is better than all because if we wake all thread then it may cpu cycles waking one will be better in this scenario
        }

        int take_soup() {
            unique_lock<mutex> ladle_lock(ladle);
            while (soup_queue.empty()) {
                soup_served.wait(ladle_lock);
            }
            int bowl = soup_queue.front();
            soup_queue.pop();
            return bowl;
        }
        
    private:
        queue<int> soup_queue;
        mutex ladle;
        condition_variable soup_served;
};

ServingLine serving_line = ServingLine();

void soup_producer() {
    for (int i=0; i<10000; i++) { // serve a 10,000 bowls of soup
        serving_line.serve_soup(1);
    }
    serving_line.serve_soup(-1); // indicate no more soup
    printf("Producer is done serving soup!\n");
}

void soup_consumer() {
    int soup_eaten = 0;
    while (true) {
        int bowl = serving_line.take_soup();
        if (bowl == -1) { // check for last bowl of soup
            printf("Consumer ate %d bowls of soup.\n", soup_eaten);
            serving_line.serve_soup(-1); // put back last bowl for other consumers to take
            return;
        } else {
            soup_eaten += bowl; // eat the soup
        }
    }
}

int main() {
    thread olivia(soup_producer);
    thread barron(soup_consumer);
    thread steve(soup_consumer);
    olivia.join();
    barron.join();
    steve.join();
}