#define NOMINMAX
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   
#include <functional>
#include <limits> 

using namespace std;

template <typename Type1, typename Type2>
class ClassTemplate
{
public:

	Type1 num1;
	Type2 num2;

	ClassTemplate(Type1 n1, Type2 n2) : num1(n1), num2(n2) {}

	Type1 min() {
		if (num1 < num2) {
			return num1;
		}
		else {
			return num2;
		}
	}

};

int main()
{
	ClassTemplate<int, int> intInt(10, 20);
	ClassTemplate<int, float> intFloat(10, 5.5f);
	ClassTemplate<int, double> intDouble(10, 3.14);
	ClassTemplate<float, float> floatFloat(10.5f, 20.5f);
	ClassTemplate<float, double> floatDouble(10.5f, 4.25);
	ClassTemplate<double, double> doubleDouble(10.0, 20.5);
	
	cout << intInt.min() << endl;
	cout << intFloat.min() << endl;
	cout << intDouble.min() << endl;
	cout << floatFloat.min() << endl;
	cout << floatDouble.min() << endl;
	cout << doubleDouble.min() << endl;


	return 0;
}