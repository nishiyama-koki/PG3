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
#include <chrono>

using namespace std;
int main() {
    // 100万文字の 'a' で初期化
    std::string a(1000000, 'a');
    auto start_copy = std::chrono::high_resolution_clock::now();

    std::string copy_a = a; 

    auto end_copy = std::chrono::high_resolution_clock::now();
    auto duration_copy = std::chrono::duration_cast<std::chrono::microseconds>(end_copy - start_copy).count();

    // 2移動（ムーブ）にかかる時間の計測
    auto start_move = std::chrono::high_resolution_clock::now();

    std::string move_a = std::move(a); 

    auto end_move = std::chrono::high_resolution_clock::now();
    auto duration_move = std::chrono::duration_cast<std::chrono::microseconds>(end_move - start_move).count();
    // 結果表示
    std::cout << "Copy time: " << duration_copy << " us" << std::endl;
    std::cout << "Move time: " << duration_move << " us" << std::endl;

    return 0;
}