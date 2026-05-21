#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   
#include <functional>

using PFunc = std::function<void(int)>;

//01_04

void SetTimeOut(PFunc p, int second, int dice) {
    printf("%d秒待機中...\n", second);
    fflush(stdout);
    Sleep(second * 1000);
    p(dice);
}

int main() {
    srand((unsigned int)time(NULL));

    printf("丁半ゲーム[1:半(奇数) / 2:丁(偶数)] 入力してください: ");

    int userGuess;
    scanf_s("%d", &userGuess);

    if (userGuess != 1 && userGuess != 2) {
        printf("1か2を入れてください。\n");
        return 1;
    }

    int dice = (rand() % 6) + 1;

    PFunc p = [userGuess](int d) {
        int result = (d % 2 != 0) ? 1 : 2;

        printf("\n出目: %d (%s)\n", d, (result == 1) ? "半 / 奇数" : "丁 / 偶数");

        if (userGuess == result) {
            printf("正解\n");
        }
        else {
            printf("不正解\n");
        }
        };

    SetTimeOut(p, 3, dice);

    return 0;
}