#include <iostream>
#include <thread>
#include <shared_mutex>

std::shared_mutex smtx;  //can lock the mutex multiple times using lock_shared() function and single time by using lock() can also using raii structures where lock will be destroyed automatically when goes out of scope
int data = 0;

void reader(int id) {
    smtx.lock_shared();
    printf("Reader %d sees %d.\n",id,data);
    smtx.unlock_shared();
}

void writer(int id) {
    smtx.lock();
    data++;
    smtx.unlock();
    printf("Write %d updated to %d.\n",id,data);
}

int main() {
    std::thread t1(reader, 1);
    std::thread t2(reader, 2);
    std::thread t3(writer, 1);

    t1.join();
    t2.join();
    t3.join();
}