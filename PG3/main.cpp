#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(65001);

	char str[] = "こんにちは世界";

	printf("%s\n", str);

	return 0;

}