#include <iostream>

using namespace std;

void Hanoi(char origin, char terminus, char mid, int n);

int main(int argc, char **argv)
{
	cout << "Hanoi Tower" << endl;
	cout << "Input number of disks: ";
	int n;
	cin >> n;
	Hanoi('A', 'B', 'C', n);
	return 0;
}

void Hanoi(char origin, char terminus, char mid, int n)
{
	if (n > 1)
	{
		Hanoi(origin, mid, terminus, n - 1);
		cout << origin << " -> " << terminus << endl;
		Hanoi(mid, terminus, origin, n - 1);
	}

	cout << origin << " -> " << terminus << endl;

	return;
}
