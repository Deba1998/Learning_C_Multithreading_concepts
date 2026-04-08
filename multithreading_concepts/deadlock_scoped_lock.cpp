//now this normal program will cause deadlock as olivia and barron try to accquire different locks so the way to remove is:-
// 1> lock ordering:- make both the thread to accquire same first lock then it will avoid deadlock
// 2> scoped_lock:- use the scoped lock while accquired this internally have deadlock avoidance mechanism and will complete successfully. Note:- no need to unlock it will automatically releases the lock once out of scope

#include <thread>
#include <mutex>

using namespace std;

int sushi_count = 5000;

void philosopher(mutex &first_chopstick, mutex &second_chopstick) {
    while (sushi_count > 0) {
       // first_chopstick.lock();  
       // second_chopstick.lock();
        scoped_lock(first_chopstick,second_chopstick);
        if (sushi_count) {
            sushi_count--;
        }
        //second_chopstick.unlock();
        //first_chopstick.unlock();
    }
}

int main() {
    mutex chopstick_a, chopstick_b;
    thread barron(philosopher,ref(chopstick_a), ref(chopstick_b));
    thread olivia(philosopher, ref(chopstick_b), ref(chopstick_a));// you have to use the wrapper ref(mutex_name) to pass the mutex as reference
    barron.join();
    olivia.join();
    printf("The philosophers are done eating.\n");
}