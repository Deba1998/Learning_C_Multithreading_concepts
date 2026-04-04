#include<thread>
#include<chrono>
#include<unistd.h>
#include<iostream>


using namespace std;

void cpu_waster()
{
    cout<<"This thread id is " << this_thread::get_id()<<endl;
    cout<<"The process id is "<<getpid()<<endl;
    while (1)
    {
        continue;
    }
    
}

int main()
{
    cout<<"The main thread is "<<this_thread::get_id()<<endl;
    cout<<"The main process id is "<<getpid()<<endl;
    thread thread1(cpu_waster);
    thread thread2(cpu_waster);
    while(1){
        this_thread::sleep_for(chrono::seconds(1));
    }
}

