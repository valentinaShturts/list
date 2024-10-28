#include <iostream>
using namespace std;


struct Element
{
	// ������
	char data;
	// ����� ���������� �������� ������
	Element* Next;
};

// ����������� ������
class List
{
	// ����� ��������� �������� ������
	Element* Head;
	// ����� ��������� �������� ������
	Element* Tail;
	// ���������� ��������� ������
	int Count;

public:
	// �����������
	List();
	// ����������
	~List();

	// ���������� �������� � ������
	// (����� ������� ���������� ���������)
	void Add(char data);

	// �������� �������� ������
	// (��������� �������� �������)
	void Del();
	// �������� ����� ������
	void DelAll();

	// ���������� ����������� ������
	// (���������� ���������� � ��������� ��������)
	void Print();

	// ��������� ���������� ���������, ����������� � ������
	int GetCount();

	// �������� �������� � ������������ �������
	void DelPos(int i)
	{
		if (i == 1)
		{
			Del();
			return;
		}
		Element* temp = Head;
		while (i > 2)
		{
			temp = temp->Next;
			i--;
		}
		//cout << temp->data << endl;
		Element* del = temp->Next;
		temp->Next = del->Next;
		delete del;
		Count--;
	}
	// ���������� �������� � ������������ ������� //��������
	void AddPos(int i, char e)
	{
		Element* temp = Head;
		while (i > 2)
		{
			temp = temp->Next;
			i--;
		}

		Element* add = new Element;
		add->data = e;
		Element* el = temp->Next;
		temp->Next = add;
		add->Next = el;
		Count++;
	}
	// ����� ��������� ��������  //��������
	bool SearchElement(char a)
	{
		Element* temp = Head;
		while (temp != 0)
		{
			if (temp->data == a) return true;
			else { temp = temp->Next; }
		}
		return 0;
	}
};

List::List()
{
	// ���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// ����� ������� ��������
	DelAll();
}

int List::GetCount()
{
	// ���������� ���������� ���������
	return Count;
}

void List::Add(char data)
{
	// �������� ������ ��������
	Element* temp = new Element;

	// ���������� �������
	temp->data = data;
	// ��������� ������� �����������
	temp->Next = NULL;
	// ����� ������� ���������� ��������� ��������� ������
	// ���� �� �� ������ �����������
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// ����� ������� ���������� ������������
	// ���� �� ������ �����������
	else {
		Head = Tail = temp;
	}
}

void List::Del()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ������������� ������ �� ��������� �������
	Head = Head->Next;
	// ������� ������ �������� �������
	delete temp;
}

void List::DelAll()
{
	// ���� ��� ���� ��������
	while (Head != 0)
		// ������� �������� �� ������
		Del();
}

void List::Print()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ���� ��� ���� ��������
	while (temp != 0)
	{
		// ������� ������
		cout << temp->data << " ";
		// ��������� �� ��������� �������
		temp = temp->Next;
	}

	cout << "\n\n";
}


// �������� ������
void main()
{
	// ������� ������ ������ List
	List lst;

	// �������� ������
	char s[] = "Hello, World !!!\n";
	// ������� ������
	cout << s << "\n\n";
	// ���������� ����� ������
	int len = strlen(s);
	// �������� ������ � ������
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	// ������������� ���������� ������
	lst.Print();
	lst.DelPos(3);
	lst.Print();
	// ������� ��� �������� ������
	/*lst.Del();
	lst.Del();
	lst.Del();*/
	//������������� ���������� ������
	//lst.Print();
	cout << "Is 'l' here? " << lst.SearchElement('l') << endl;
	lst.AddPos(3, '+');
	lst.Print();
}

