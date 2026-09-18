#include <iostream>
#include "head.h"
#include "mod_head.h"

int main()
{
	int a;
	double b;
	std::cout << "Выберите режим (n / m): ";
	char s;
	std::cin >> s;
	std::cout << "Введите два числа через пробел: ";
	std::cin >> a >> b;
	float res;
	if (s == 'n')
	{
		res = average<float>(a, b);
	}
	else if (s == 'm')
	{
		res = mod_average<float>(a, b);
	}
	else
	{
		std::cout << "Введён некорректный режим";
	}
	std::cout << res;
	return 0;
}