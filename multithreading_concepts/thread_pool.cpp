/**
 * Chopping vegetables with a thread pool
 */
//thread pool initializes number of threads and complete the number of thread using that threads we have to just post the task in the below example task is done woth 4 threads

#include <boost/asio.hpp> //boost asio header

void vegetable_chopper(int vegetable_id) {
    printf("Thread %d chopped vegetable %d.\n", std::this_thread::get_id(), vegetable_id);
}

int main() {
    boost::asio::thread_pool pool(4); // thread pool containing 4 threads
    for (int i=0; i<100; i++) {
        boost::asio::post(pool, [i](){vegetable_chopper(i);}); //posting tasks to the pool using lambda not using creating individual threads
    }
    pool.join();
}