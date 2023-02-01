#include <iostream>
#include <vector>
#include <stdio.h>
#include <cmath>

int main()
{
	int n;//длина доски с фигурками-уголками
	std::string	line;

	std::cin >> n;
	getline(std::cin, line);

	if (n % 3 == 0)
	{
		int pow2 = n / 3;
		std::cout << pow(2, pow2) << std::endl;
	}
	else
	{
		std::cout << 0 << std::endl;
	}
}