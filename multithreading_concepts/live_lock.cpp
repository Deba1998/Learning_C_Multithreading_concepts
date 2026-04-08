/**
 * Exceptionally polite philosophers, thinking and eating sushi
 */
#include <thread>
#include <mutex>

int sushi_count = 5000;

void philosopher(std::mutex &first_chopstick, std::mutex &second_chopstick) {
    while (sushi_count > 0) {
        first_chopstick.lock();
        if (!second_chopstick.try_lock()) {     //here we are checking for the second lock is available or not if not available we are releasing the first lock also by this way we can avoid deadlock between two threads now if more than two threads is involved it will stuck in deadlock as one thread will put the release the lock and before acquiring the first lock it is taken by some other thread in this way it will waste cpu cycles and keep tryring and stuck in livelock
            first_chopstick.unlock();  
            std::this_thread::yield(); //this thread will introduce a delay between releasing and reacquiring the lock and thus help to rpevent deadlock for more threads
        } else {
            if (sushi_count) {
                sushi_count--;
            }
            second_chopstick.unlock();
            first_chopstick.unlock();
        }
    }
    printf("the thread id id %d \n.", std::this_thread::get_id());
    
}

int main() {
    std::mutex chopstick_a, chopstick_b;
    std::thread barron(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread olivia(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    std::thread steve(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread nikki(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    barron.join();
    olivia.join();
    steve.join();
    nikki.join();
    printf("The philosophers are done eating.\n");
}