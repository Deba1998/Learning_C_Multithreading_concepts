/**
 * Recursively sum range of numbers
 */
//one thing keep in mind don't launch too many thread with std::async other system can get blocked with two many threads
//while performing divide and conquer don't parallize to much after a certain point the speed up becames constant even if you increase number of processors as per amdhal's law the speed is limited by the part program which is to be executed serially, for small range prefer serial execution as there is overhead for parallel executions and thread scheduling


#include <cstdio>
#include <future>

unsigned long long recursive_sum(unsigned int lo , unsigned int hi, unsigned int depth=0) {
    if (depth > 3) { // base case threshold
        unsigned long long sum = 0;
        for (auto i=lo; i<hi; i++) {
            sum += i;
        }
        return sum;
    } else {  // divide and conquer
        auto mid = (hi + lo) / 2; // middle index for splitting
        auto left = std::async(std::launch::async, recursive_sum, lo, mid, depth+1); //using auto will directly assign to appropriate term that is future<int/long>
        //std::async will launch another thread to continue with the execution
        auto right = recursive_sum(mid, hi, depth+1);
        return left.get() + right;
    }
}

int main() {
    unsigned long long total = recursive_sum(0, 1000000000);
    printf("Total: %lld\n", total);
}