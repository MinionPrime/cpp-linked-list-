#include<iostream>      //header file
using namespace std;
class node 				//class definition
{
	public:
	int prn;
	string name;
	node *next;
};
class pinnacle		//class definition
{
	public:
	node *head,*tail;
	pinnacle()
	{
		head=NULL;
		tail=NULL;
	}
	node *create();
	void president();
	void member();
	void secretary();	
	void displaypr();
	void displaysec();
	void displayall();
	void search();
	void concate(pinnacle,pinnacle);
	void reverse(node *p);
};

//--------------------------------Function Definition----------------------------------------------

node *pinnacle::create()
{
	node *temp;
	temp=new node;
	int n;
	string name1;
	cout<<"\nEnter the PRN number : ";
	cin>>n;
	cout<<"\nEnter the name : ";
	cin>>name1;
	if(temp==NULL)	
	{
		cout<<"\nMemory not allocated.";
		return 0;
	}
	else 
	{
		temp->prn=n;
		temp->name=name1;
		temp->next=NULL;
		return temp;
	}
}
void pinnacle::president()
{
	node *temp,*temp1;
	temp=create();
	if(head==NULL)
	{
		head=temp;
		head->next=NULL;
	}
	else
	{
		temp1=head;
		head=temp;
		head->next=temp1;
	}
	cout<<"\nPresident's data has been entered.";
}
void pinnacle::secretary()
{
	node *temp,*temp1;
	temp=create();
	temp1=head;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp->next=NULL;
	temp1->next=temp;
	tail=temp;
	cout<<"\nSecretary's data has been entered.";
}
void pinnacle::displayall()
{
	cout<<"\nEntered data is follows (including president at first and secretary at last) : \n";
	node *temp,*temp1;
	temp=head;
	while(temp!=NULL)
	{
		cout<<"PRN : "<<temp->prn<<endl<<"NAME : "<<temp->name<<endl;
		temp=temp->next;
	}
}
void pinnacle::displaypr()
{
	cout<<"\nPresident's data : ";
	cout<<"\n"<<"PRN : "<<head->prn<<endl<<"NAME : "<<head->name<<endl;
}
void pinnacle::displaysec()
{
	cout<<"\nSecretary's data : ";
	cout<<"\n"<<"PRN : "<<tail->prn<<endl<<"NAME : "<<tail->name<<endl;
}
void pinnacle::search()								//searching for a node
{
	int key,no,ch1,pos,flag=0;
	string name2;
	cout<<"\nWhat do you want to find (PRN=1)/(NAME=2) : ";
	cin>>ch1; 
	if(ch1==1)
	{
		cout<<"\nEnter PRN : ";
		cin>>no;
	}
	else
	{
		cout<<"\nEnter Name : ";
		cin>>name2;
	}
	node *temp;
	temp=head;
	pos=1;
	while(temp!=NULL)
	{	
		if(temp->prn==no||temp->name==name2)
		{
			flag=1;
			break;
		}
		else
		{
			temp=temp->next;
		}pos++;
	}
	if(flag==1)
	cout<<"\nData is found at "<<pos<<" position.\n";
	else
	cout<<"\nData is not found.";
}

void pinnacle::member()
{
	node *temp,*temp1;
	temp=head;
	int mbr,c;
	cout<<"\nEnter the no of members : ";
	cin>>mbr;
	for(c=0;c<mbr;c++)
	{
		temp1=create();
		temp->next=temp1;
		temp=temp->next;
	}
	temp1->next=tail;
	cout<<"\n"<<mbr<<" Member's data has been entered.";
}
void pinnacle::concate(pinnacle p,pinnacle p1)  //Creating the objects of pinnacle as p and p1 respectively
{													//Concatenating
	node *temp,*temp1;
	temp1=p.head;
	temp=p.head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=p1.head;	
	while(temp1!=NULL)
	{
		cout<<"PRN : "<<temp1->prn<<endl<<"NAME : "<<temp1->name<<endl;
		temp1=temp1->next;
	}
}
void pinnacle::reverse(node *p)             //reversing
{
	if(p->next==NULL)
	{
		head=p;
		cout<<"PRN : "<<p->prn<<endl<<"NAME : "<<p->name<<endl;
		return;
	}
	//cout<<p->data<<"->";
	reverse(p->next);
	node *q=p->next;
	q->next=p;
	p->next=NULL;
	cout<<"PRN : "<<p->prn<<endl<<"NAME : "<<p->name<<endl;
}
	
//-------------------------------------Driver code-----------------------------------------

int main()
{
	int ch,ch1,ch2,ch3;
	pinnacle p,p1,p2;
	do
	{
		cout<<"\n-----ENTER 8 FOR EXIT (first list)-----\n1.President data\n2.Secretary data\n3.Display all\n4.Dispaly president\n5.Display secretary\n6.Member data\n7.Search\n8.Reverse list\n9.Exit\nEnter choice : ";
		cin>>ch;
		cout<<"\n--------------------------------------\n";	
		switch(ch)
		{
			case 1:	
			p.president();
			break;
			case 2:
			p.secretary();
			break;
			case 3:
			cout<<endl;
			p.displayall();
			break;
			case 4:
			p.displaypr();
			break;
			case 5:
			p.displaysec();
			break;
			case 6:
			p.member();
			break;
			case 7:
			p.search();
			break;
			case 8:
			p.reverse(p.head);
			break;
			default:
			break;
		}
	}while(ch!=9);
	cout<<"\nDo you want to add another list ? yes or no (1/0) : ";
	cin>>ch1;
	if(ch1==1)
	{
		do
		{
			cout<<"\n-----ENTER 8 FOR EXIT (second list)-----\n1.President data\n2.Secretary data\n3.Display all\n4.Dispaly president\n5.Display secretary\n6.Member data\n7.Search\n8.Reverse list\n9.Exit\nEnter choice : ";
			cin>>ch;
			cout<<"\n--------------------------------------\n";	
			switch(ch)
			{
				case 1:	
				p1.president();
				break;
				case 2:
				p1.secretary();
				break;
				case 3:
				cout<<endl;
				p1.displayall();
				break;
				case 4:
				p1.displaypr();
				break;
				case 5:
				p1.displaysec();
				break;
				case 6:
				p1.member();
				break;
				case 7:
				p1.search();
				break;
				case 8:
				p1.reverse(p1.head);
				break;
				default:
				break;
			}
		}while(ch!=9);
		cout<<"\nDo you want to concatinate both lists ? yes or no (1/0) : ";
		cin>>ch2;
	}
	if(ch2==1)
	{
		p2.concate(p,p1);
	}
	cout<<"\nDo you want to reverse list ? (1/0) : ";
	cin>>ch3;
	if(ch3==1)
	{
		p2.reverse(p.head);
	}	
	return 0;
}
