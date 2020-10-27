#include<iostream.h>
#include<conio.h>

void fibosum (int n)
{
 int a,b,c,count;
 a=0,b=1;

 cout<<a<<" "<<b<<" ";
 for (count=3;count<=n;count++)
  {
   c=a+b;
   cout<<c<<" ";

   a=b;
   b=c;
  }
}
void main()
{
 clrscr();
 int n;
 cout<<"enter steps";
 cin>>n;
 fibosum(n);

 getch() ;
}