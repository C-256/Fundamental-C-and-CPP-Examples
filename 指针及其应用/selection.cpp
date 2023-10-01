#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void SelectionSort(int *arr, int n);

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		cout << "Please input the number of elements: ";
		int n;
		cin >> n;

		int *arr = new int[n];

		cout << "Please input the elements: ";

		for (int i = 0; i < n; i++)
		{
			cin >> *(arr + i);
		}

		SelectionSort(arr, n);

		cout << "Sorted array: ";

		for (int i = 0; i < n; i++)
		{
			cout << *(arr + i) << " ";
		}

		delete[] arr;

		return 0;
	}

	else if (argc == 2)
	{
		int i = 0;
		i += strcmp(argv[1], "--help") == 0 ? 1 : 0;
		i += strcmp(argv[1], "-r") == 0 ? 2 : 0;
		i += strcmp(argv[1], "-t") == 0 ? 4 : 0;

		if (i & 1)
		{
			cout << "Selection Sort" << endl;
			cout << "Usage: ./Selection [-r] [-t] [--help]";
			cout << endl;
			cout << "-r\tRandomizes the array" << endl;
			cout << "-t\tTest the time consumption" << endl;
			cout << "--help\tPrints this message" << endl;
		}

		else if (i & 2)
		{
			cout << "Please input the number of elements: ";
			int n;
			cin >> n;

			int *arr = new int[n];

			srand(time(NULL));
			for (int i = 0; i < n; i++)
			{
				*(arr + i) = rand();
			}

			cout << "Unsorted array: ";
			for (int i = 0; i < n; i++)
			{
				cout << *(arr + i) << " ";
			}

			SelectionSort(arr, n);

			cout << endl;
			cout << "Sorted array: ";

			for (int i = 0; i < n; i++)
			{
				cout << *(arr + i) << " ";
			}

			delete[] arr;
		}

		else if (i & 4)
		{
			cout << "Selection Sort" << endl;
			cout << "Size\t\tTime" << endl;
			for (int n = 1; n <= 20; n++)
			{
				int num = 5000 * n;

				int *arr = new int[num];

				srand(time(NULL));
				for (int i = 0; i < num; i++)
				{
					*(arr + i) = rand();
				}

				long long t0 = GetTickCount();

				SelectionSort(arr, num);

				long long t1 = GetTickCount();

				cout << num << "\t\t" << t1 - t0 << " ms" << endl;

				delete[] arr;
			}
		}

		else
		{
			cout << "Invalid option" << endl;
			return -1;
		}

		return 0;
	}

	else
	{
		cout << "Invalid option" << endl;
		return -1;
	}
}

void SelectionSort(int *arr, int n)
{
	int min;
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		min = *(arr + i);
		temp = i;

		for (int j = i + 1; j < n; j++)
		{
			if (*(arr + j) < min)
			{
				min = *(arr + j);
				temp = j;
			}
		}

		int t = *(arr + i);
		*(arr + i) = min;
		*(arr + temp) = t;
	}
}
