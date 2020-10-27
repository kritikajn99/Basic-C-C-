#include<iostream.h>
#include<conio.h>
#include<process.h>
struct node
{
	int roll;
	node*next;
};
node*nptr;
node*TOP;
node*rear;

void insert()

      {
	nptr=new node;
	     cout<<"ENTER ROLL NUMBER " ;
	     cin>>nptr->roll;
	     nptr->next= NULL;

	if(TOP==NULL)
		TOP=rear=nptr;
	  else
	  {
		rear->next=nptr;
		rear=nptr;
	  }


	}
void del()
{
	if(TOP==NULL)
	cout<<"underflow";
	else
	{
		nptr=TOP;
		TOP=TOP->next;
		cout<<"ROLL NUMBER"<<nptr->roll<<"\t";
		delete nptr;
	}

}
void display(node*np)
{
	while(np!=NULL)
	{
		cout<<np->roll<<"\t";
		np=np->next;
	}

}
void main()
{
	clrscr();
	int ch;


	cout<<endl<<"    MENU    ";
	cout<<endl<<"1.INSERT";
	cout<<endl<<"2.DELETE";
	cout<<endl<<"3.DISPLAY";
	cout<<endl<<"4.EXIT";

	do
	{
		cout<<endl<<"ENTER YOUR CHOICE "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:insert();
				break;
			case 2:del();
				break;
			case 3:display(TOP);
				break;
			case 4:exit(ch);
				break;
		}
	}  while(ch!=4);


	getch();


}