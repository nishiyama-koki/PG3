#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   

//01_03

typedef void (*PFunc)(int, int);

// コールバック関数
void JudgeResult(int dice, int userGuess) {
    // 出目が奇数(1)か偶数(2)かを判定
    int result = (dice % 2 != 0) ? 1 : 2;

    printf("\n出目: %d (%s)\n", dice, (result == 1) ? "半 / 奇数" : "丁 / 偶数");

    if (userGuess == result) {
        printf("正解\n");
    }
    else {
        printf("不正解\n");
    }
}

// タイムアウト処理
void SetTimeOut(PFunc p, int second, int dice, int userGuess) {
    printf("%d秒待機中...\n", second);
    fflush(stdout);
    Sleep(second * 1000);
    p(dice, userGuess);
}

int main() {
    srand((unsigned int)time(NULL));

    printf("丁半ゲーム！[1:半(奇数) / 2:丁(偶数)] 入力してください: ");

    int userGuess;
    scanf_s("%d", &userGuess);

    if (userGuess != 1 && userGuess != 2) {
        printf("1か2を入れてください。\n");
        return 1;
    }

    int dice = (rand() % 6) + 1;

    PFunc p = JudgeResult;
    SetTimeOut(p, 3, dice, userGuess);

    return 0;
}