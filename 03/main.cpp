#include <iostream>
#include <vector>

typedef	struct s_res
{
	int i;
	int j;
}t_res;

void tryVertical(int mapArr[4][4], std::vector <t_res> &res)
{
	t_res	elem;
	for (int i = 0; i < 4 - 1; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (mapArr[i][j] == 0 && mapArr[i + 1][j] == 0)
			{
				mapArr[i][j] = 1;
				mapArr[i + 1][j] = 1;
				elem.i = i;
				elem.j = j;
				res.push_back(elem);
				return ;
			}
		}
	}
}

void tryHorisontal(int mapArr[4][4], std::vector <t_res> &res)
{
	t_res	elem;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - 1; j++)
		{
			if (mapArr[i][j] == 0 && mapArr[i][j + 1] == 0)
			{
				mapArr[i][j] = 1;
				mapArr[i][j + 1] = 1;
				elem.i = i;
				elem.j = j;
				res.push_back(elem);
				return ;
			}
		}
	}
}

void checkMap(int mapArr[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		if (mapArr[i][0] == 1 && mapArr[i][1] == 1 && mapArr[i][2] == 1 && mapArr[i][3] == 1)
		{
			mapArr[i][0] = 0;
			mapArr[i][1] = 0;
			mapArr[i][2] = 0;
			mapArr[i][3] = 0;
		}
	}
	for (int j = 0; j < 4; j++)
	{
		if (mapArr[0][j] == 1 && mapArr[1][j] == 1 && mapArr[2][j] == 1 && mapArr[3][j] == 1)
		{
			mapArr[0][j] = 0;
			mapArr[1][j] = 0;
			mapArr[2][j] = 0;
			mapArr[3][j] = 0;
		}
	}
}

void	insertBrick(int mapArr[4][4], char type, std::vector <t_res> &res)
{

	if (type == '0')
		tryVertical(mapArr, res);
	else
		tryHorisontal(mapArr, res);
	
	checkMap(mapArr);//проверить карту, есть ли в ней строки или толбцы полностью заполненные единицами
}

int main()
{
	int					mapArr[4][4] = {{0}};
	std::vector <t_res>	res;
	std::string			line;
	getline(std::cin, line);

	for (size_t i = 0; i < line.length(); i++)
	{
		insertBrick(mapArr, line[i], res);
	}
	for (size_t i = 0; i < res.size(); i++)
	{
		std::cout << res[i].i + 1 << " " << res[i].j + 1 <<std::endl;
	}
}