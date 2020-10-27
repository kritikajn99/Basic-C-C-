#include<iostream.h>
#include<conio.h>
#include<process.h>
struct node
{
	int roll;
	node*next;
};
node*newptr;
node*TOP;
void push()
{
	newptr=new node;
	     cout<<" ENTER ROLL NUMBER " ;
	     cin>>newptr->roll;
	     newptr->next= NULL;

	if(TOP==NULL)
		TOP=newptr;
	  else
	  {
		newptr->next=TOP;
		TOP=newptr;
	  }

}
/*void insert_end()
{
	    newptr=new node;
	     cout<<" ENTER ROLL NUMBER " ;
	     cin>>newptr->roll;
	     newptr->next= NULL;

	     if (start==NULL)
	       start=rear=newptr;
	     else
	     {
		rear->next=newptr;
		rear=newptr;
	     }
} */
void pop()
{
	if(TOP==NULL)
		cout<<"UNDERFLOW";
	else
	{
		newptr=TOP;
		TOP=TOP->next;
		cout<<"ROLL NUMBER  "<<newptr->roll;
		delete newptr;
	}
}

void display(node*TOP)
{       while(TOP!=NULL)
	{
	cout<<TOP->roll<<"\t";
	TOP=TOP->next;
	}
}
void main()
{
	clrscr();
	int ch;


	cout<<endl<<"    MENU    ";
	cout<<endl<<"1.PUSH";
	cout<<endl<<"2.POP";
	cout<<endl<<"3.DISPLAY";
	cout<<endl<<"4.EXIT";

	do
	{
		cout<<endl<<"ENTER YOUR CHOICE "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:push();
				break;
			case 2:pop();
				break;
			case 3:display(TOP);
				break;
			case 4:exit(ch);
				break;
		}
	}  while(ch!=4);


	getch();
}