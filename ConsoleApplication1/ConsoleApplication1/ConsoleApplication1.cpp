// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define collection cin.tie(NULL);ios_base::sync_with_stdio(false);
#include <iostream>
struct Queuedata
{
	int value=0;
	Queuedata* nextdata=NULL;
};
class Queue
{
public:
	Queue();
	~Queue();
	void Push(int value);
	int Pop();
	int Size();
	int IsEmpty();
	int Front();
	int Back();
private:
	Queuedata* head;
	Queuedata* tail;
	int size;
};

Queue::Queue()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

Queue::~Queue()
{
}
void Queue::Push(int value)
{
	if (head == NULL)
	{
		head = new Queuedata();
		head->value = value;
		tail = head;
	}
	else
	{
		Queuedata* tmp= new Queuedata();
		tmp->value = value;
		tail->nextdata = tmp;
		tail = tmp;
	}
	size++;
}
int Queue::Pop()
{
	int value = 0;
	if (head != NULL)
	{
		value = head->value;
		if (head->nextdata == NULL)
		{
			tail = NULL;
			head = NULL;
		}
		else
		{
			head = head->nextdata;
		}
		size--;
	}
	else
	{
		return -1;
	}
	return value;
}
int Queue::Size()
{
	return size;
}
int Queue::IsEmpty()
{
	if (size == 0)
	{
		return 1;
	}
	return 0;
}
int Queue::Front()
{
	if (head == NULL)
	{
		return -1;
	}
	return head->value;
}
int Queue::Back()
{
	if (tail == NULL)
	{
		return -1;
	}
	return tail->value;
}
using namespace std;
int main()
{
	collection;
	int count = 0;
	Queue myQueue;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		string command = "";
		cin >> command;
		if (command == "push")
		{
			int value;
			cin >> value;
			myQueue.Push(value);
		}
		else if (command == "pop")
		{
			cout << myQueue.Pop()<<'\n';
		}
		else if (command == "size")
		{
			cout << myQueue.Size() << '\n';
		}
		else if (command == "empty")
		{
			cout << myQueue.IsEmpty() << '\n';
		}
		else if (command == "front")
		{
			cout << myQueue.Front() << '\n';
		}
		else if (command == "back")
		{
			cout << myQueue.Back() << '\n';
		}
	}
}

