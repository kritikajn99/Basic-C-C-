#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main()
{ clrscr();
  char name[20],grade[20];
  int  roll[20],m1[20],m2[20],m3[20],n;
  int  i,large=-1,pos=-1,total[20],avg[20];

     cout<<"enter number of students  ";
     cin>>n;
  for(i=1;i<=n;i++)
  {
	cout<<"enter roll no.  ";
	cin>>roll[i];
	cout<<"name    ";
       //	gets(name[i]);
	cout<<"enter marks of three subjects  ";
	cin>>m1[i]>>m2[i]>>m3[i];
  }
  for(i=1;i<=n;i++)
  {
	cout<<"roll no. "<<roll[i];
	cout<<"name     "<<name[i];
	cout<<"marks    "<<m1[i]<<"   "<<m2[i]<<"  "<<m3[i]<<"\n";
  }
  for(i=1;i<=n;i++)

  {
	cout<<"total marks   "<<total[i];
	total[i]=m1[i]+m2[i]+m3[i];
	avg[i]=total[i]/3;
	cout<<"average marks  "<<avg[i];
	   if ( avg[i]> 90)
		grade[i]='A';

	   else if ((avg[i]>70)&&(avg[i]<=90))
		grade[i]='B';
	   else if ((avg[i]>50)&&(avg[i]<=70))
		grade[i]='C';
	   else
		grade[i]='F';
	cout<<" Grade is   "<<grade[i];

  }

  getch();
}