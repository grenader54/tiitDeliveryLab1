
#include <iostream>
#include <Windows.h>
#include "Treap.h"

using namespace std;

bool wrongNumber(char a[], int argc, int c)
{
	if (c >= argc)
	{
		cout << "Wrong input\n";
		return true;
	}
	if (atoi(a) == 0 && (a[0] - 48) != 0)
	{
		cout << "Wrong input\n";
		return true;
	}
	return false;
}
int main(int argc, char *argv[])
{
	int *arr;
	int k = 1, i, n, x, y;
	Treap a, b;
	if (k < argc)
	{
		if (atoi(argv[k]) != 0 || ((argv[k][0] - 48) == 0 && atoi(argv[k]) == 0))
		{
			cout << "Wrong input\n";
			return 1;
		}
		if (strcmp(argv[k], "srand") == 0)
		{
			k++;
			if (wrongNumber(argv[k], argc, k))
				return 1;
			x = atoi(argv[k]);
			k++;
			a.randseed(x);
			b.randseed(x);
		}
	}

	while (1)
	{
		if (k < argc)
		{
			if (strcmp(argv[k], "insert") != 0)
				if (strcmp(argv[k], "find") != 0)
					if (strcmp(argv[k], "erase") != 0)
						if (strcmp(argv[k], "build") != 0)
							if (strcmp(argv[k], "merge") != 0)
								if (strcmp(argv[k], "interception") != 0)
									if (strcmp(argv[k], "view") != 0)
									{
										cout << "Wrong input\n";
										return 1;
									}
			if (strcmp(argv[k], "insert") == 0)
			{
				k++;
				if (wrongNumber(argv[k], argc, k))
					return 1;
				//a
				///////////////////////////////////////////////
				if (atoi(argv[k]) == 1)
				{

					k++;
					if (wrongNumber(argv[k], argc, k))
						return 1;
					switch (atoi(argv[k]))
					{
					case 1:
						k++;
						if (wrongNumber(argv[k], argc, k))
							return 1;
						a.insert(atoi(argv[k]));
						k++;
						break;
					case 2:
						k++;
						if (wrongNumber(argv[k], argc, k))
							return 1;
						x = atoi(argv[k++]);
						if (wrongNumber(argv[k], argc, k))
							return 1;
						y = atoi(argv[k++]);
						a.insert(x, y);
						break;
					}
				}
				//b
				//////////////////////////////////////////////////
				else if (atoi(argv[k]) == 2)
				{

					k++;
					if (wrongNumber(argv[k], argc, k))
						return 1;
					switch (atoi(argv[k]))
					{
					case 1:
						k++;
						if (wrongNumber(argv[k], argc, k))
							return 1;
						b.insert(atoi(argv[k]));
						k++;
						break;
					case 2:
						k++;
						if (wrongNumber(argv[k], argc, k))
							return 1;
						x = atoi(argv[k++]);
						if (wrongNumber(argv[k], argc, k))
							return 1;
						y = atoi(argv[k++]);
						b.insert(x, y);
						break;
					}
				}

			}
			else if (strcmp(argv[k], "find") == 0)
			{
				k++;
				if (wrongNumber(argv[k], argc, k))
					return 1;
				//a
				///////////////////////////////////////////////
				if (atoi(argv[k]) == 1)
				{
					k++;
					if (wrongNumber(argv[k], argc, k))
						return 1;
					if (a.findKey(atoi(argv[k])))
						cout << "Key exists\n";
					else
						cout << "Key not found\n";
					k++;
				}
				//b
				//////////////////////////////////////////////////
				else if (atoi(argv[k]) == 2)
				{

					k++;
					if (wrongNumber(argv[k], argc, k))
						return 1;
					if (b.findKey(atoi(argv[k])))
						cout << "Key exists\n";
					else
						cout << "Key not found\n";
					k++;
				}

			}
			else if (strcmp(argv[k], "erase") == 0)
			{
				k++;
				if (wrongNumber(argv[k], argc, k))
					return 1;
				//a
				///////////////////////////////////////////////
				if (atoi(argv[k]) == 1)
				{
					k++;
					if (wrongNumber(argv[k], argc, k))
						return 1;
					a.erase(atoi(argv[k]));
					k++;
				}
				//b
				//////////////////////////////////////////////////
				else if (atoi(argv[k]) == 2)
				{

					k++;
					if (wrongNumber(argv[k], argc, k))
						return 1;
					b.erase(atoi(argv[k]));
					k++;
				}

			}
			else if (strcmp(argv[k], "build") == 0)
			{
				k++;
				if (wrongNumber(argv[k], argc, k))
					return 1;
				x = atoi(argv[k]);
				k++;
				if (wrongNumber(argv[k], argc, k))
					return 1;
				n = atoi(argv[k]);
				k++;
				arr = new int[n];
				for (i = 0; i < n; i++)
				{
					if (wrongNumber(argv[k], argc, k))
						return 1;
					arr[i] = atoi(argv[k]);
					k++;
				}
				//a
				///////////////////////////////////////////////
				if (x == 1)
					a.build(a, arr, n);
				//b
				//////////////////////////////////////////////////
				else if (x == 2)
					b.build(b, arr, n);
				delete arr;
			}
			else if (strcmp(argv[k], "merge") == 0)
			{
				k++;
				if (wrongNumber(argv[k], argc, k))
					return 1;
				//a
				///////////////////////////////////////////////
				if (atoi(argv[k]) == 1)
				{
					a.merge(a, a, b);
					k++;
				}
				//b
				//////////////////////////////////////////////////
				else if (atoi(argv[k]) == 2)
				{
					b.merge(b, a, b);
					k++;
				}

			}
			else if (strcmp(argv[k], "interception") == 0)
			{
				k++;
				a.intersection(b);
			}
			else if (strcmp(argv[k], "view") == 0)
			{
				k++;
				if (wrongNumber(argv[k], argc, k))
					return 1;
				//a
				///////////////////////////////////////////////
				if (atoi(argv[k]) == 1)
				{
					k++;
					a.viewTree();
				}
				//b
				//////////////////////////////////////////////////
				else if (atoi(argv[k]) == 2)
				{
					k++;
					b.viewTree();
				}

			}
		}
		else
			break;
	}
	return 0;
}