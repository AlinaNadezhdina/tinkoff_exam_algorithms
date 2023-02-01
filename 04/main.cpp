#include <iostream>
#include <map>
#include <stdio.h>


void	findDivisor(int n, std::map<int, int> &myMap)
{
	int count = 0;
	for (int j = 1; j <= n; j++)
	{
		if (n % j == 0)
			count++;
	}
	myMap.insert(std::pair<int, int>(n, count));
}

int main()
{
	int n;
	std::string	line;
	std::cin >> n;
	getline(std::cin, line);

	std::map<int, int> myMap;
	for (int i = 1; i <= n; i++)
	{
		findDivisor(i, myMap);
	}

	std::pair<int, int> etalonMax;
	etalonMax.first = myMap.begin()->first;
	etalonMax.second = myMap.begin()->second;
	std::map<int, int>::iterator it = myMap.begin();
	for (;it != myMap.end(); it++)
	{
		if (it->second >= etalonMax.second)
		{
			etalonMax.first = it->first;
			etalonMax.second = it->second;
		}
	}
	std::cout << etalonMax.first<< std::endl;
	std::cout << etalonMax.second << std::endl;
}