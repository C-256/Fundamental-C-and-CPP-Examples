#include <iostream>
#include <cstring>

using namespace std;

void Help();
void Print(int *arr, int len);
void Remove(int *arr, int &len, int item);
void RemoveDuplicates(int *arr, int &len);
void Reverse(int *arr, int len);
void RingShift(int *arr, int len, int steps, char direction);
int *Merge(int *arr1, int len1, int *arr2, int len2);

int main(int argc, char **argv)
{
	char t = 0;

	if (argc == 1)
	{
		Help();
		return 0;
	}

	else if (argc == 2)
	{
		t += (strcmp(argv[1], "-h") == 0) ? 1 : 0;
		t += (strcmp(argv[1], "-rm") == 0) ? 2 : 0;
		t += (strcmp(argv[1], "-rd") == 0) ? 3 : 0;
		t += (strcmp(argv[1], "-rv") == 0) ? 4 : 0;
		t += (strcmp(argv[1], "-rsl") == 0) ? 5 : 0;
		t += (strcmp(argv[1], "-rsr") == 0) ? 6 : 0;
		t += (strcmp(argv[1], "-m") == 0) ? 7 : 0;
	}

	else
	{
		cout << "Invalid command line arguments!" << endl;
		cout << "Use -h for help!" << endl;
		return -1;
	}

	if (t == 1)
	{
		Help();
		return 0;
	}

	// Array input

	int len, len2;
	int *arr = nullptr, *arr2 = nullptr;

	if (2 == t || 4 == t || 5 == t || 6 == t)
	{
		cout << "Enter array length: ";
		cin >> len;
		arr = new int[len];

		cout << "Enter array elements: ";

		for (int i = 0; i < len; i++)
		{
			cin >> arr[i];
		}
	}
	else if (3 == t)
	{
		cout << "Enter array length: ";
		cin >> len;
		arr = new int[len];

		cout << "Enter array elements in ascending order: ";

		for (int i = 0; i < len; i++)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < len - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				cout << "Array is not sorted!" << endl;
				return -1;
			}
		}
	}
	else if (7 == t)
	{
		cout << "Enter 2 array lengths: ";
		cin >> len >> len2;
		arr = new int[len];
		arr2 = new int[len2];

		cout << "Enter array1 elements: ";
		for (int i = 0; i < len; i++)
		{
			cin >> arr[i];
		}

		cout << "Enter array2 elements: ";
		for (int i = 0; i < len2; i++)
		{
			cin >> arr2[i];
		}

		for (int i = 0; i < len - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				cout << "Array is not sorted!" << endl;
				return -1;
			}
		}

		for (int i = 0; i < len2 - 1; i++)
		{
			if (arr2[i] > arr2[i + 1])
			{
				cout << "Array is not sorted!" << endl;
				return -1;
			}
		}
	}
	else
	{
		cout << "Invalid command line arguments!" << endl;
		cout << "Use -h for help!" << endl;
		return -1;
	}

	// Operations

	if (2 == t)
	{
		cout << "Enter item to remove: ";
		int i;
		cin >> i;
		int &l = len;
		Remove(arr, l, i);
		Print(arr, l);
	}
	else if (3 == t)
	{
		RemoveDuplicates(arr, len);
		Print(arr, len);
	}
	else if (4 == t)
	{
		Reverse(arr, len);
		Print(arr, len);
	}
	else if (5 == t)
	{
		int stepsl;
		cout << "Enter steps: ";
		cin >> stepsl;
		RingShift(arr, len, stepsl, 'l');
		Print(arr, len);
	}
	else if (6 == t)
	{
		int stepsr;
		cout << "Enter steps: ";
		cin >> stepsr;
		RingShift(arr, len, stepsr, 'r');
		Print(arr, len);
	}
	else if (7 == t)
	{
		int *newArr = Merge(arr, len, arr2, len2);
		Print(newArr, len + len2);
	}

	return 0;
}

void Help()
{
	cout << "Usage: ./SeqList [OPTIONS]" << endl;
	cout << "Options:" << endl;
	cout << "-h: help" << endl;
	cout << "-rm: remove item" << endl;
	cout << "-rd: remove duplicates" << endl;
	cout << "-rv: reverse" << endl;
	cout << "-rsl: ring shift left" << endl;
	cout << "-rsr: ring shift right" << endl;
	cout << "-m: merge" << endl;
}

void Print(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void Remove(int *arr, int &len, int item)
{
	int count = 0;

	for (int i = 0; i < len; i++)
	{
		if (arr[i] == item)
		{
			count++;
		}

		else
		{
			arr[i - count] = arr[i];
		}
	}

	len -= count;
	return;
}

void RemoveDuplicates(int *arr, int &len)
{
	int count = 0;
	for (int i = 1; i < len; i++)
	{
		if (arr[i] == arr[i - 1])
		{
			count++;
		}

		else
		{
			arr[i - count] = arr[i];
		}
	}

	for (int i = len - count; i < len; i++)
	{
		arr[i] = 0;
	}

	len -= count;
	return;
}

void Reverse(int *arr, int len)
{
	for (int a = 0, b = len - 1; a < b; a++, b--)
	{
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}

	return;
}

void RingShift(int *arr, int len, int steps, char direction)
{
	if (direction == 'l')
	{
		int *temp = new int[steps];
		for (int i = 0; i < steps; i++)
		{
			temp[i] = arr[i];
		}

		for (int i = steps; i < len; i++)
		{
			arr[i - steps] = arr[i];
		}

		for (int i = 0; i < steps; i++)
		{
			arr[i + len - steps] = temp[i];
		}

		delete[] temp;

		return;
	}

	else if (direction == 'r')
	{
		RingShift(arr, len, len - steps, 'l');
	}
}

int *Merge(int *arr1, int len1, int *arr2, int len2)
{
	int *result = new int[len1 + len2];
	int i = 0, j = 0, k = 0;
	while (i < len1 || j < len2)
	{
		if (arr1[i] < arr2[j])
		{
			result[k++] = arr1[i++];
		}

		else
		{
			result[k++] = arr2[j++];
		}
	}

	while (i < len1)
	{
		result[k++] = arr1[i++];
	}

	while (j < len2)
	{
		result[k++] = arr2[j++];
	}

	return result;
}
