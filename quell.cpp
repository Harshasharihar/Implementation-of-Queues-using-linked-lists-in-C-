#include<iostream>
using namespace std;
#define NUL 0

class Queu
{
	private : struct node
		{
			int data;
			struct node *next;
		}*start;
		
	public :
		Queu();
		void addtoQu(int num);
		int delQu();
		~Queu();
};

Queu::Queu()
{
	start  = NUL;
}

void Queu::addtoQu(int num)
{
	struct node *temp,*k;
	if(start == NUL)//new queue
	{
		temp = new struct node;
		if(temp == NUL)
		{
			cout<<"The Queue is full\n";
			exit(0);
		}
		temp ->data = num;
		temp->next = NUL;
		start = temp;
	}
	else//existing queue
	{
		temp = start;
		while(temp->next!=NUL)
		{
			temp = temp->next;
		}
		
		
		k = new struct node;
		if(k == NUL)
		{
			cout<<"The Queue is full\n";
			exit(0);
		}
		
		
		k->data = num;
		k->next = NUL;
		temp->next = k;
	}
}

int Queu::delQu()
{
	struct node *temp;
	temp = start;
	if(temp == NUL)
	{
		cout<<"The que is empty\n";
		exit(0);
	}
	int x = temp->data;
	start  = start->next;
	delete temp;
	return x;
}

Queu::~Queu()
{
	struct node *temp;
	temp = start;
	while(temp!=NUL)
	{
		start = start ->next;
		delete temp;
		temp = start;
		
	}
}

int main()
{	Queu q;
	int num = 0,choice = 0;
	while(1)
	{
		cout<<"Enter the choice\n";
		cout<<"1 for add element to the Queue\n";
		cout<<"2 to remove element from the Queue\n";
		cout<<"3 to exit..\n";
		cin>>choice;
		
		switch(choice)
		{
			case 1 :cout<<"Enter the num\n";
				cin>>num;
				q.addtoQu(num);
				break;
			case 2 :num = q.delQu();
				cout<<"The element came out of the queue is "<<num<<endl;
				break;
			case 3 :cout<<"Exiting...\n";
				exit(0);
			default:cout<<"Invalid input...Try Again...!!\n";
				break;
		}
	}
}
