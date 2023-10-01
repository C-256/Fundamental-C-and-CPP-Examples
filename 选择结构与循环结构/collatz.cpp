#include <iostream>

using namespace std;

int Collatz(int n);
void CollatzPath(int n);

int main(int argc, char **argv)
{
	int temp = 0, max = 0;

	for (int i = 1; i <= 100; i++)
	{
		int p;
		if ((p = Collatz(i)) > max)
		{
			temp = i;
			max = p;
		}
	}

	cout << "The number with the longest Collatz sequence is ";
	cout << temp << " with a length of " << max << "\n\n";
	cout << "The path is: \n";
	CollatzPath(temp);

	return 0;
}

int Collatz(int n)
{
	int result = 0;

	while (n != 1)
	{
		if (n % 2 == 0)
		{
			n /= 2;
		}
		else
		{
			n *= 3;
			n++;
		}
		result++;
	}

	cout << "Statement for "<< n << " is true." << endl;

	return result;
}

void CollatzPath(int n)
{
	while (n != 1)
	{
		cout << n;
		if (n % 2 == 0)
		{
			n /= 2;
			cout << " / 2 = " << n << "\n";
		}
		else
		{
			n *= 3;
			n++;
			cout << " * 3 + 1 = " << n << "\n";
		}
	}
}
