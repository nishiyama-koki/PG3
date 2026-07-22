#define NOMINMAX
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   
#include <functional>
#include <limits> 
#include <list> 


using namespace std;

void PrintStationList(const list<const char*>& stationList, int year)
{
	printf("===== %d =====\n", year);
	for (const char* station : stationList)
	{
		printf("%s\n", station);
	}
	printf("\n");
}

int main()
{
	SetConsoleOutputCP(65001);

	list<const char*> yamanote = {
		"Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno", "Uguisudani",
		"Nippori", "Tabata", "Komagome", "Sugamo", "Otsuka", "Ikebukuro",
		"Mejiro", "Takadanobaba", "Shin-Okubo", "Shinjuku", "Yoyogi", "Harajuku",
		"Shibuya", "Ebisu", "Meguro", "Gotanda", "Osaki", "Shinagawa",
		"Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho"
	};

	PrintStationList(yamanote, 1970);

	for (auto it = yamanote.begin(); it != yamanote.end(); ++it)
	{

		if (*it == "Tabata")
		{
			yamanote.insert(it, "Nishi-Nippori");
			break;
		}
	}

	PrintStationList(yamanote, 2019);

	for (auto it = yamanote.begin(); it != yamanote.end(); ++it)
	{
		if (strcmp(*it, "Tamachi") == 0)
		{
			yamanote.insert(it, "Takanawa Gateway");
			break;
		}
	}

	// 2022年時点のリストを表示
	PrintStationList(yamanote, 2022);

	return 0;
}