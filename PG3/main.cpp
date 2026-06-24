#define NOMINMAX
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   
#include <functional>
#include <limits> // std::numeric_limits を使うために追加

using namespace std;

class Enemy {
public:
    void Update();

    void Attack();
    void Escape();
    void Approach();
    static void (Enemy::* table[])();
    int index = 0;
};

void Enemy::Attack() {
    printf("敵は攻撃してきた！\n");
}

void Enemy::Escape() {
    printf("敵は逃げ出した！\n");
}

void Enemy::Approach() {
    printf("敵は近づいてきた！\n");
}

void Enemy::Update() {
    // 関数テーブルから関数を実行
    (this->*table[index])();

    cout << ": ";
    int input;
    cin >> input;

    if (cin.fail()) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        input = -1; 
    }

    if (input == 0) {
        index = (index + 1) % 3;
    }
}

// メンバ関数ポインタテーブル
void (Enemy::* Enemy::table[])() = {
    &Enemy::Approach,
    &Enemy::Escape,
    &Enemy::Attack,
};

int main()
{

    Enemy enemy;

    while (1)
    {
        enemy.Update();
    }

    return 0;
}