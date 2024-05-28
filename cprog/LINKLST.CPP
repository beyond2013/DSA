#include <iostream.h>
#include <conio.h>
#include <stdio.h>

class Linklist
{
private:
char data[10];
int link[10];
int start, empty;
public:
 Linklist()
 {
  init();
   start=-1;
  empty=0;
 }
 void init(void);
 void insertfront(void);
 void insertloc(void);
 void insertend(void);
 void printlist(void);
 void delfront(void);
 void delend(void);
 void delloc(void);
};
void Linklist:: init()
 {
 int i;
  for (i=0;i<9;i++)
  link[i]=i+1;
  link[9]=-1;
 }

void Linklist:: insertfront(void)
{
 char item,ch;
 int t;
 do
 {
 if (empty!=-1)
  {
    t=empty;
    empty=link[empty];
    cout<<"\nENTER CHARACTER\t";
    item=getche();
    data[t]=item;
    link[t]=start;
    start=t;
    cout<<"\n ADD ANOTHER\t";
    ch=getche();
  }

  else
  {
  cout<<"\nLINKLIST OVERFLOW";
  break;
  }
}
while(ch=='y'||ch=='Y');

}


void Linklist::insertloc(void)
{
  int t2,t,z;
  char item,ch,temp,item2;

cout<<"\nENTER CHARACTER, AFTER WHICH NEW CHARACTER TO BE INSERTED\t";
temp=getche();
t2=start;
while(link[t2]!=-1 && temp!=data[t2])
 t2=link[t2];

 if(data[t2]==temp)
 {
 z=empty;
 empty=link[empty];
 link[z]=link[t2];
 link[t2]=z;

 cout<<"\n ENTER NEW CHARACTER\t";
 item2=getche();
 data[z]=item2;

 }
 else
 cout<<"\n CHARACTER NOT FOUND";

}
void Linklist:: insertend (void)
{
  int t2,t,z;
  char item,ch;
 do
 {

 if(empty!=-1)
 {
   cout<<"\n ENTER CHARACTER\t";
   item=getche();
   t=empty;
   empty=link[empty];

   data[t]=item;
   if(start==-1)
   {
    link[t]=start;
    start=t;
   }
   else
   {
    t2=start;
    while(link[t2]!=-1)
    t2=link[t2];

    z=link[t2];
    link[t2]=t;
    link[t]=z;

    }
  cout<<"\nADD ANOTHER\t";
  ch=getche();
  }
  else
  {
  cout<<"\n LIST OVERFLOW";
  break;
  }

 }
 while(ch=='y'||ch=='Y');
}


void Linklist:: printlist(void)
 {
 int t;
 if (start==-1)
 cout<<"\nLIST IS EMPTY";
 else
 {
  t=start;
  while(t!=-1)
  {
  cout<<data[t]<<"\t";
  t=link[t];
  }
 }
}


void Linklist:: delfront(void)
{
  char temp,ch;
  int t;

  do
  {
  if(start==-1)
   {
    cout<<"\n LIST IS EMPTY";
    break;
    }
  else
  {
  t=start;
  start=link[t];
  link[t]=empty;
  empty=t;
  temp=data[empty];
  cout<<"\n\t"<<temp<< "DELETED FROM LIST";
  }
  cout<<"\nDELETE ANOTHER FROM LIST\t";
  ch=getche();
  }
  while(ch=='y'||ch=='Y');
}

void Linklist:: delend (void)
{
  int s,t;
  char ch;
  char item;

  do
  {

  if(start==-1)
  {
  cout<<"\n LIST IS EMPTY";
  break;
  }
  else
  {
  t=start;
  while(link[t]!=-1)
  {
   s=t;
   t=link[t];
  }

  link[s]=-1;
  link[t]=empty;
  empty=t;
  item=data[t];

  cout<<"\n\t"<<item<<"deleted from list";
  }
  cout<<"\nDELETE ANOTHER FROM LIST\t";
  ch=getche();
  }
  while(ch=='y'|| ch=='Y');
}

void Linklist:: delloc(void)
{
int t,s;
char item,ch;
do
{
t=start;
s=t;

if(start!=-1)
{
  cout<<"\nENTER ELEMENT TO DELETE\t";
  item=getche();
  while(t!=-1 && data[t]!=item)
  {
   s=t;
   t=link[t];
  }
  if(data[t]==item)
   {
   link[s]=link[t];
   link[t]=empty;
   empty=t;
   item=data[t];
   cout<<"\n\t"<<item<<"DELETED FROM LIST";
   }
   else
   cout<<"\nCHARACTER NOT FOUND";

cout<<"\nDELETE ANOTHER CHARACTER\t";
ch=getche();
}
else
cout<<"\nLIST IS EMPTY";
}
while(ch=='y'|| ch=='Y');
}

void main (void)
{
  int i,choice;
  clrscr();
  Linklist lnklst;
  cout<<"\n1.\tINSERT ELEMENT AT FRONT\t"<<endl;
  cout<<"\n2.\tINSERT ELEMENT AFTER GIVEN NODE\t"<<endl;
  cout<<"\n3.\tINSERT ELEMENT AT END\t"<<endl;
  cout<<"\n4.\tDELETE ELEMENT AT FRONT\t"<<endl;
  cout<<"\n5.\tDELETE ELEMENT AT END\t"<<endl;
  cout<<"\n6.\tDELETE GIVEN ELEMENT\t"<<endl;
  cout<<"\n7.\tPRINT LIST\t"<<endl;
  cout<<"\n8.\tEXIT\t"<<endl;
  do
  {
  cout<<"\n\nENTER YOUR CHOICE\t";
  cin>>choice;
  switch(choice)
  {
   case 1:
    lnklst.insertfront();
   break;
   case 2:
    lnklst.insertloc();
   break;
   case 3:
   lnklst.insertend();
   break;
   case 4:
    lnklst.delfront();
    break;
   case 5:
    lnklst.delend();
    break;
   case 6:
    lnklst.delloc();
   break;
   case 7:
    lnklst.printlist();
   break;
   case 8:
    cout<<"\n\nTHANK YOU";
   break;
   }

 }while(choice!=8);
}

