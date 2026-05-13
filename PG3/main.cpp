#include<iostream>
#include<Windows.h>
#include<stdio.h>

//01_01

//関数テンプレート
template <typename Type>
Type Min(Type a, Type b) {
    return (a < b) ? a : b;
}

template <>
char Min<char>(char a, char b) {

    printf("数字以外代入できない\n");
    return '\0';
}

int main() {

    int i1 = 10;
    int i2 = 20;
    float f1 = 5.5f;
    float f2 = 2.2f;
    double d1 = 3.14;
    double d2 = 3.14159;
    char c1 = 'A';
    char c2 = 'B';

    SetConsoleOutputCP(65001);
    printf("%d\n", Min<int>(i1, i2));
    printf("%f\n", Min<float>(f1, f2));
    printf("%f\n", Min<double>(d1, d2));
    printf("%c\n", Min<char>(c1, c2));

    return 0;
}