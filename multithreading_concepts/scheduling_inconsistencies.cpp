//here each time you execute you will get different count for olivia and barron due t scheduling incosistencies
#include <thread>
#include <chrono>
#include <iostream>


using namespace std;

bool chopping = true;

void vegetable_chopper(const char *name) {
    unsigned long vegetable_count = 0;
    while (chopping) {
        vegetable_count++;
    }
    //cout<< name << " chopped "<< vegetable_count << " vegetable" <<endl;
    printf("%s chopped %lu vegetables.\n", name, vegetable_count);
}

int main() {
    thread olivia(vegetable_chopper, "Olivia");
    thread barron(vegetable_chopper, "Barron");
    
	cout<<"Barron and Olivia are chopping vegetables..."<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    chopping = false;
    barron.join();
    olivia.join();
}