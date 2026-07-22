#define NOMINMAX
#include <iostream>
//#include <windows.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   
#include <functional>
#include <limits> 


class IShape {
protected:
    double area; 

public:
    virtual ~IShape() {} 
    virtual void Size() = 0;
    virtual void Draw() = 0;
};

class Circle : public IShape {
private:
    double radius;

public:
    Circle(double r = 4.0) : radius(r) {}
    void Size() override {
        area = radius * radius * 3.14;
    }
    void Draw() override {
        printf("円の面積: %.2f\n", area);
    }
};

class Rectangle : public IShape {
private:
    double width;
    double height;

public:
    Rectangle(double w = 2.0, double h = 3.0) : width(w), height(h) {}
    void Size() override {
        area = width * height;
    }
    void Draw() override {
        printf("矩形の面積: %.2f\n", area);
    }
};


int main(void) {

    IShape* shape[2];

    shape[0] = new Circle();
    shape[1] = new Rectangle();

    printf("円の半径:4\n矩形の底辺:2\n矩形の高さ:3\n\n");
    for (int i = 0; i < 2; i++)
        shape[i]->Size();

    printf("\n");
    for (int i = 0; i < 2; i++)
        shape[i]->Draw();

    for (int i = 0; i < 2; i++)
        delete shape[i];

    return 0;
}