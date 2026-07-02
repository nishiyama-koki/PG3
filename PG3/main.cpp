#define NOMINMAX
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   
#include <functional>
#include <limits> 

using namespace std;

class Animal {
public:
	virtual void speak()=0;
protected:
	const char* name;
};

class Dog : public Animal {
public:
	void speak() override {
		printf("犬:わん\n");
	};
};

class Cat : public Animal {
public:
	void speak() override {
		printf("猫:にゃー\n");
	};
};

int main()
{
	Animal* animal1 = new Dog();
	Animal* animal2 = new Cat();

	animal1->speak();
	animal2->speak();

	delete animal1;
	delete animal2;

	return 0;
}