#include <thread>
#include <mutex>

using namespace std;

unsigned int garlic_count = 0;
unsigned int potato_count = 0;
recursive_mutex pencil; // allows locking multiple times and have to unlocked same number of times as it is locked
//if we normal mutex instead of recursive mutex the program will halt and not proceeded further

void add_garlic() {
    pencil.lock();
    garlic_count++;
    pencil.unlock();
}

void add_potato() {
    pencil.lock();
    potato_count++;
    add_garlic();  //inside this function again the mutex is locked and hence have to use recursive mutex
    pencil.unlock();
}

void shopper() {
    for (int i=0; i<10000; i++) {
        // add_garlic();
        add_potato();  //inside this functione the mutex pencil is locked twice by the same thread hence have to use recursive mutex
    }
}

int main() {
    thread barron(shopper);
    barron.join();
    printf("We should buy %u garlic.\n", garlic_count);
    printf("We should buy %u potatoes.\n", potato_count);
}