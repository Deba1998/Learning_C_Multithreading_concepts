#include <thread>
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;


void chef_olivia() {
    printf("Olivia started & waiting for sausage to thaw...\n");
    this_thread::sleep_for(chrono::seconds(3));
    printf("Olivia is done cutting sausage.\n");
}

void kitchen_cleaner() {
    while (true) {
        printf("Debajyoti cleaned the kitchen.\n");
        this_thread::sleep_for(chrono::seconds(1));
    }
}

int main() {
    printf("Barron requests Olivia's help.\n");
    thread olivia(chef_olivia);
    printf("  Olivia is joinable? %s\n", olivia.joinable() ? "true" : "false"); //joinable return true if the thread active and not terminated
    printf("Barron need Debajyoti to clean the kitchen consistently\n");
    thread debajyoti(kitchen_cleaner);
    debajyoti.detach(); //will continue cleaning seperartely while the program is executed

    printf("Barron continues cooking soup.\n");
    this_thread::sleep_for(chrono::seconds(1));
    printf("  Olivia is joinable? %s\n", olivia.joinable() ? "true" : "false");

    printf("Barron patiently waits for Olivia to finish and join...\n");
    olivia.join();
    printf("  Olivia is joinable? %s\n", olivia.joinable() ? "true" : "false"); //now after join olivia thread terminated and hence return false
    printf("  Debajyoti is joinable? %s\n", debajyoti.joinable() ? "true" : "false"); //false becuase once a thread is detached it cannot be joined
    printf("Barron and Olivia are both done!\n");
}