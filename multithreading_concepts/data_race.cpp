#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

unsigned int garlic_count = 0;

atomic<unsigned int> onion_count(0);

mutex pencil;

void shopper() {
    for (int i=0; i<10000000; i++) {
        pencil.lock(); //this will ensure th data is locked before increment ensuring atomicity
        garlic_count++;
        pencil.unlock();
        onion_count++; //this will ensure the value is incremented atomically hence correctness
    }
}

int main() {
    std::thread barron(shopper);
    std::thread olivia(shopper); //running this way will not make count to 20 million due to race 
    barron.join();
    olivia.join();
    printf("We should buy %u garlics.\n", garlic_count);
    printf("We should buy %u onions.\n", onion_count.load());

}