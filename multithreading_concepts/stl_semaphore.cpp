#include <iostream>
#include <thread>
#include <vector>
#include <semaphore.h>
#include <unistd.h> // for sleep()

sem_t sem; // global semaphore

void worker(int id) {
    sem_wait(&sem); // acquire (P)

    std::cout << "Thread " << id << " entered critical section\n";
    sleep(1); // simulate work
    std::cout << "Thread " << id << " leaving\n";

    sem_post(&sem); // release (V)
}

int main() {
    sem_init(&sem, 0, 3); // allow max 3 threads

    std::vector<std::thread> threads;

    for (int i = 1; i <= 6; i++) {
        threads.emplace_back(worker, i);  //faster than threads.push_back(std::thread(worker, i));
    }

    for (auto &t : threads) {
        t.join();
    }

    sem_destroy(&sem); // cleanup
    return 0;
}