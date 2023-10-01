#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Node
{
public:
	int value;
	Node *next;
	static Node *Create(int value);
	static void Destroy(Node *header);
	static void NInsert(Node *header, int value);
	static void NInsert(Node *header, int n, int value);
	void Insert(int value);
	void Append(int value);
	const bool operator<(const Node &rv) const;
	static void Remove(Node *header, int value);
	static void RemoveDuplicates(Node *header);
	static Node *Reverse(Node *header);
	static Node *RingShift(Node *header, int n, char direction);
	static Node *Merge(Node *header1, Node *header2);
	static Node *Input();
	static bool IsSorted(Node *header);
	static void Print(Node *header);
};

void Help();

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

	else if (2 == t)
	{
		Node *header = Node::Input();
		cout << "Enter value to remove: ";
		int n;
		cin >> n;
		Node::Remove(header, n);
		Node::Print(header);
		Node::Destroy(header);
		return 0;
	}

	else if (3 == t)
	{
		Node *header = Node::Input();
		if (Node::IsSorted(header))
		{
			Node::RemoveDuplicates(header);
			Node::Print(header);
		}

		else
		{
			cout << "List is not sorted!" << endl;
			exit(0);
		}
		Node::Destroy(header);
	}

	else if (4 == t)
	{

		Node *header = Node::Input();
		header = Node::Reverse(header);
		Node::Print(header);
		Node::Destroy(header);
	}

	else if (5 == t)
	{
		Node *header = Node::Input();
		cout << "Enter shift amount: ";
		int n;
		cin >> n;
		header = Node::RingShift(header, n, 'l');
		Node::Print(header);
		Node::Destroy(header);
	}

	else if (6 == t)
	{
		Node *header = Node::Input();
		cout << "Enter shift amount: ";
		int n;
		cin >> n;
		header = Node::RingShift(header, n, 'r');
		Node::Print(header);
		Node::Destroy(header);
	}

	else if (7 == t)
	{
		cout << "Please enter 2 lists according to guidance" << endl;
		Node *h1 = Node::Input();
		Node *h2 = Node::Input();
		Node *header = nullptr;

		if (Node::IsSorted(h1) && Node::IsSorted(h2))
		{
			header = Node::Merge(h1, h2);
		}
		else
		{
			cout << "At least 1 list is not sorted" << endl;
		}
		header = Node::Merge(h1, h2);
		Node::Print(header);
		Node::Destroy(h1);
		Node::Destroy(h2);
	}

	return 0;
}

void Help()
{
	cout << "Usage: ./LinkList [OPTIONS]" << endl;
	cout << "Options:" << endl;
	cout << "-h: help" << endl;
	cout << "-rm: remove item" << endl;
	cout << "-rd: remove duplicates" << endl;
	cout << "-rv: reverse" << endl;
	cout << "-rsl: ring shift left" << endl;
	cout << "-rsr: ring shift right" << endl;
	cout << "-m: merge" << endl;
}

Node *Node::Create(int value)
{
	Node *result = new Node;
	result->value = value;
	result->next = nullptr;
	return result;
}

void Node::Destroy(Node *header)
{
	while (header->next != nullptr)
	{
		Node *temp = header->next;
		delete header;
		header = temp;
	}

	return;
}

void Node::NInsert(Node *header, int value)
{
	Node *temp = header;
	header = Create(value);
	header->next = temp;

	return;
}

void Node::NInsert(Node *header, int n, int value)
{
	for (int i = 0; i < n; i++)
	{
		if (header == nullptr)
		{
			cout << "Out of range" << endl;
			exit(0);
		}
		header = header->next;
	}

	Node::NInsert(header, value);

	return;
}

void Node::Insert(int value)
{
	Node *temp = next;
	next = Create(value);
	next->next = temp;

	return;
}

void Node::Append(int value)
{
	Node *temp = next;
	while (next != nullptr)
	{
		temp = next;
	}
	next = Create(value);

	return;
}

const bool Node::operator<(const Node &rv) const
{
	return value < rv.value;
}

void Node::Remove(Node *header, int value)
{
	Node *temp = header;
	Node *r = nullptr;

	while (header->value == value)
	{
		r = header;
		header = header->next;
		delete r;
		r = nullptr;
	}

	while (temp->next != nullptr)
	{
		if (temp->next->value == value)
		{
			r = temp->next;
			temp->next = temp->next->next;
			delete r;
			r = nullptr;
		}

		else
		{
			temp = temp->next;
		}
	}

	return;
}

void Node::RemoveDuplicates(Node *header)
{
	Node *temp = header;
	Node *r = nullptr;

	while (temp->next != nullptr)
	{
		if (temp->value == temp->next->value)
		{
			r = temp->next;
			temp->next = temp->next->next;
			delete r;
			r = nullptr;
		}

		else
		{
			temp = temp->next;
		}
	}
}

Node *Node::Reverse(Node *header)
{
	Node *p1 = header;
	Node *p2 = nullptr;
	Node *p3 = nullptr;

	while (p1->next != nullptr)
	{
		header = header->next;
		p1->next = p2;
		p2 = p1;
		p1 = header;
	}

	p1->next = p2;

	return header;
}

Node *Node::RingShift(Node *header, int n, char direction)
{
	if (direction == 'l')
	{
		Node *temp = header;
		Node *tail = header;

		while (tail->next != nullptr)
		{
			tail = tail->next;
		}

		for (int i = 0; i < n - 1; i++)
		{
			if (temp->next != nullptr)
			{
				temp = temp->next;
			}

			else
			{
				temp = header;
			}
		}

		tail->next = header;
		header = temp->next;
		temp->next = nullptr;
	}

	else if (direction == 'r')
	{
		Node *navigator = header;
		Node *temp = header;
		Node *tail = header;

		while (tail->next != nullptr)
		{
			tail = tail->next;
		}

		for (int i = 0; i < n; i++)
		{
			if (navigator->next != nullptr)
			{
				navigator = navigator->next;
			}

			else
			{
				navigator = header;
			}
		}

		while (navigator->next != nullptr)
		{
			temp = temp->next;
			navigator = navigator->next;
		}

		tail->next = header;
		header = temp->next;
		temp->next = nullptr;
	}

	return header;
}

Node *Node::Merge(Node *header1, Node *header2)
{
	Node *p1 = header1;
	Node *p2 = header2;
	Node *header = nullptr, *temp = header;
	bool m = true;

	while (p1 != nullptr && p2 != nullptr)
	{
		if (m)
		{
			if (p1->value < p2->value)
			{
				header = Create(p1->value);
				p1 = p1->next;
			}

			else
			{
				header = Create(p2->value);
				p2 = p2->next;
			}

			temp = header;
			m = false;
		}

		if (p1->value < p2->value)
		{
			temp->next = Create(p1->value);
			temp = temp->next;
			p1 = p1->next;
		}

		else
		{
			temp->next = Create(p2->value);
			temp = temp->next;
			p2 = p2->next;
		}
	}

	while (p1 != nullptr)
	{
		temp->next = Create(p1->value);
		temp = temp->next;
		p1 = p1->next;
	}

	while (p2 != nullptr)
	{
		temp->next = Create(p2->value);
		temp = temp->next;
		p2 = p2->next;
	}

	return header;
}

Node *Node::Input()
{
	Node *rv;

	cout << "Enter the number of elements: ";
	int n;
	cin >> n;

	cout << "Enter the " << n << " elements: ";
	Node *p = nullptr;

	for (int i = 0, t; i < n; i++)
	{
		cin >> t;

		if (!i)
		{
			rv = Create(t);
			p = rv;
		}

		else
		{
			p->Insert(t);
			p = p->next;
		}
	}

	return rv;
}

bool Node::IsSorted(Node *header)
{
	while (header->next != nullptr)
	{
		if (header < header->next)
		{
			header = header->next;
		}

		else
		{
			return false;
		}
	}

	return true;
}

void Node::Print(Node *header)
{
	while (header != nullptr)
	{
		cout << header->value << " ";
		header = header->next;
	}

	return;
}
