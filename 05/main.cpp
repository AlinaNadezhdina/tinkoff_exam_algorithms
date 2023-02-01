#include <iostream>
#include <vector>
#include <stdio.h>


void fillVector(int n, std::vector<int> &nums)
{
	for (int i = 1; i <= n; i++)
		nums.push_back(i);
}

int sumVector(std::vector<int> &nums)
{
	int sum = 0;
	for (size_t i = 0; i < nums.size(); i++)
		sum += nums[i];
	return (sum);
}

int checkNumSum(int sum)
{
	if (sum % 3 == 0)
		return 0;
	return -1;
}

void	fillResultVector(std::vector<int> &nums, std::vector<int> &result, int sum)
{
	int tail = 0;
	while (1)
	{
		if ((sumVector(result) + tail) == sum)
		{
			if (tail != 0)
				result.push_back(tail);
			std::vector<int>::iterator it = nums.begin();
			for (; it < nums.end(); it++)
			{
				if (*it == tail)
				{
					nums.erase(it);
					break;
				}
			}
			break;
		}
		tail = (sum - sumVector(result)) % nums.back();
		result.push_back(nums.back());
	 	nums.pop_back();
	}
}

void	printVector(std::vector<int> result)
{
	std::vector<int>::iterator it;
	std::cout << result.size() << std::endl;
	for (it = result.begin(); it != result.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

int main()
{
	int n;
	std::string	line;
	std::cin >> n;
	int sum = 0;
	std::vector<int> result1;
	std::vector<int> result2;
	std::vector<int> nums;
	getline(std::cin, line);


	fillVector(n, nums);
	sum = sumVector(nums);
	if (checkNumSum(sum) == 0)
	{
		fillResultVector(nums, result1, sum / 3);
		fillResultVector(nums, result2, sum / 3);

		printVector(result1);
		printVector(result2);
		printVector(nums);

	}
	else
		std::cout << -1 <<std::endl;
}