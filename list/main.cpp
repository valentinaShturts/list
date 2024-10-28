#include <iostream>
using namespace std;


struct Element
{
	// Данные
	char data;
	// Адрес следующего элемента списка
	Element* Next;
};

// Односвязный список
class List
{
	// Адрес головного элемента списка
	Element* Head;
	// Адрес головного элемента списка
	Element* Tail;
	// Количество элементов списка
	int Count;

public:
	// Конструктор
	List();
	// Деструктор
	~List();

	// Добавление элемента в список
	// (Новый элемент становится последним)
	void Add(char data);

	// Удаление элемента списка
	// (Удаляется головной элемент)
	void Del();
	// Удаление всего списка
	void DelAll();

	// Распечатка содержимого списка
	// (Распечатка начинается с головного элемента)
	void Print();

	// Получение количества элементов, находящихся в списке
	int GetCount();

	// Удаление элемента в определенной позиции
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
	// Добавление элемента в определенную позицию //ПРАКТИКА
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
	// Поиск заданного элемента  //ПРАКТИКА
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
	// Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// Вызов функции удаления
	DelAll();
}

int List::GetCount()
{
	// Возвращаем количество элементов
	return Count;
}

void List::Add(char data)
{
	// создание нового элемента
	Element* temp = new Element;

	// заполнение данными
	temp->data = data;
	// следующий элемент отсутствует
	temp->Next = NULL;
	// новый элемент становится последним элементом списка
	// если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// новый элемент становится единственным
	// если он первый добавленный
	else {
		Head = Tail = temp;
	}
}

void List::Del()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// перебрасываем голову на следующий элемент
	Head = Head->Next;
	// удаляем бывший головной элемент
	delete temp;
}

void List::DelAll()
{
	// Пока еще есть элементы
	while (Head != 0)
		// Удаляем элементы по одному
		Del();
}

void List::Print()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// Пока еще есть элементы
	while (temp != 0)
	{
		// Выводим данные
		cout << temp->data << " ";
		// Переходим на следующий элемент
		temp = temp->Next;
	}

	cout << "\n\n";
}


// Тестовый пример
void main()
{
	// Создаем объект класса List
	List lst;

	// Тестовая строка
	char s[] = "Hello, World !!!\n";
	// Выводим строку
	cout << s << "\n\n";
	// Определяем длину строки
	int len = strlen(s);
	// Загоняем строку в список
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	// Распечатываем содержимое списка
	lst.Print();
	lst.DelPos(3);
	lst.Print();
	// Удаляем три элемента списка
	/*lst.Del();
	lst.Del();
	lst.Del();*/
	//Распечатываем содержимое списка
	//lst.Print();
	cout << "Is 'l' here? " << lst.SearchElement('l') << endl;
	lst.AddPos(3, '+');
	lst.Print();
}

