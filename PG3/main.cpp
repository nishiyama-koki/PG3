#include <iostream>
#include <windows.h>

//01_02
int Recursive(int n) {
    //1時間目は100円
    if (n <= 1) {
        return 100;
    }
    // 再帰
    return Recursive(n - 1) * 2 - 50;
}

int main() {

    SetConsoleOutputCP(65001);

    int fixed_rate = 1072;     // 一般的な時給
    int recursive_total = 0; // 再帰の累積額
    int fixed_total = 0;     // 一般の累積額

    printf("時間 | 再帰時給 | 再帰累計 | 一般累計\n");
    printf("\n--------------------------------------\n");

    for (int h = 1; h <= 10; h++) {
        int hourly_wage = Recursive(h);
        recursive_total += hourly_wage;
        fixed_total += fixed_rate;

        printf("\n%2dh | %8d\ | %8lld\ | %8lld\ \n", h, hourly_wage, recursive_total, fixed_total);

        
    }

    return 0;
}