#include <conio.h>
#include <stdio.h>

void insertfront (void);
void insertloc (void);
void insertend (void);
void delfront (void);
void delend (void);
void delloc(void);
void printlist (void);


char data[10];
int link[10];
int start=-1, empty=0;

void main (void)
{
  int i,choice;
  clrscr();
  for (i=0;i<9;i++)
  link[i]=i+1;
  link[9]=-1;

  cout<<"\n1.\tINSERT ELEMENT AT FRONT\t";
  cout<<"\n2.\tINSERT ELEMENT AFTER GIVEN NODE\t";
  cout<<"\n3.\tINSERT ELEMENT AT END\t";
  cout<<"\n4.\tDELETE ELEMENT AT FRONT\t";
  cout<<"\n5.\tDELETE ELEMENT AT END\t";
  cout<<"\n6.\tDELETE GIVEN ELEMENT\t";
  cout<<"\n7.\tPRINT LIST\t";
  cout<<"\n8.\tEXIT\t";
  do
  {
  cout<<"\n\nENTER YOUR CHOICE\t";
  cin>>choice;
  switch(choice)
  {
   case 1:
    insertfront();
   break;
   case 2:
    insertloc();
   break;
   case 3:
    insertend();
   break;
   case 4:
    delfront();
    break;
   case 5:
    delend();
    break;
   case 6:
    delloc();
   break;
   case 7:
    printlist();
   break;
   case 8:
    cout<<"\n\nTHANK YOU";
   break;
   }

 }while(choice!=8);
}

void insertfront(void)
{
 char item,ch;
 int t;
 do
 {
 if (empty!=-1)
  {
    t=empty;
    empty=link[empty];
    cout<<"\n\nENTER CHARACTER";
    item=getche();
    data[t]=item;
    link[t]=start;
    start=t;
    cout<<"\n\n ADD ANOTHER";
    ch=getche();
  }

  else
  {
  cout<<"\n\nLINK OVERFLOW";
  break;
  }
}
while(ch=='y'||ch=='Y');

}


void insertloc(void)
{
  int t2,t,z;
  char item,ch,temp,item2;

cout<<"\n\nENTER CHARACTER, AFTER WHICH NEW CHARACTER TO BE INSERTED";
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

 cout<<"\n\n ENTER NEW CHARACTER";
 item2=getche();
 data[z]=item2;

 }
 else
 cout<<"\n\n CHARACTER NOT FOUND";

}
void insertend (void)
{
  int t2,t,z;
  char item,ch;
 do
 {

 if(empty!=-1)
 {

   cout<<"\n\n ENTER CHARACTER";
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
  cout<<"\n\nADD ANOTHER";
  ch=getche();
  }
  else
  {
  cout<<"\n\n LIST OVERFLOW";
  break;
  }

 }
 while(ch=='y'||ch=='Y');

}


 void printlist(void)
 {
 int t;
 if (start==-1)
 cout<<"\n\nLIST IS EMPTY";
 else
 {
  t=start;
  while(t!=-1)
  {
  cout<<"%c"<<data[t];
  t=link[t];
  }
 }
}


void delfront(void)
{
  char temp,ch;
  int t;

  do
  {
  if(start==-1)
   {
    cout<<"\n\n LIST IS EMPTY";
    break;
    }
  else
  {
  t=start;
  start=link[t];
  link[t]=empty;
  empty=t;
  temp=data[empty];
  cout<<"\n\n"<<temp<< "DELETED FROM LIST";
  }
  cout<<"\n\nDELETE ANOTHER FROM LIST";
  ch=getche();
  }
  while(ch=='y'||ch=='Y');
}

void delend (void)
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

  cout<<"\n"<<item<<"deleted from list";
  }
  cout<<"\nDELETE ANOTHER FROM LIST";
  ch=getche();
  }
  while(ch=='y'|| ch=='Y');
}

void delloc(void)
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
   cout<<"\n"<<item<<"DELETED FROM LIST";
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
