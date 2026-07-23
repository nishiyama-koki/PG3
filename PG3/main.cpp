#define NOMINMAX
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   
#include <functional>
#include <limits> 
#include <list> 
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;
std::mutex mtx;
std::condition_variable cnd;
int turn = 1; 
int main() {

    auto printThread = [](int id) {
        
        std::unique_lock<std::mutex> lock(mtx);
        cnd.wait(lock, [id] { return turn == id; });
        printf("thread %d\n", id);
        turn++;
        cnd.notify_all();
        };

    std::thread th1(printThread, 1);
    std::thread th2(printThread, 2);
    std::thread th3(printThread, 3);

    th1.join();
    th2.join();
    th3.join();

    return 0;
}