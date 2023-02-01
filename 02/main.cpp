#include <iostream>
#include <vector>
#include <stdio.h>

int main()
{
	int n;
	std::string	line;
	int data;


	std::cin >> n;
	getline(std::cin, line);

	std::vector<int> speedVector;
	for (int i = 0; i < n; i++)
	{
		std::cin >> data;
		getline(std::cin, line);
		speedVector.push_back(data);
	}
	for (int i = 1; i < n; i++)
	{
		if (speedVector[i - 1] < speedVector[i])
			speedVector[i] = speedVector[i - 1];
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << speedVector[i] << " ";
	}
	std::cout << std::endl;
}