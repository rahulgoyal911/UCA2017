#include<iostream>
#include<string.h>
using namespace std;
struct Hash
{
	struct word *head;
	struct word *tail;
};
struct word
{
	char str[50];
	int count;
	struct word *next;
};
char * extract(char *s,int si,int ei)
{
	char *s1=new char[ei-si+1];
	int j=0;
	for(int i=si;i<=ei;i++)
	{
		s1[j]=s[i];
		j++;
	}
	s1[j]='\0';
	return s1;
}
void insert(struct Hash h[256],char *s,int si,int ei)
{
	char *s1=extract(s,si,ei);
	if(h[s1[0]].head==NULL)
	{
		struct word *a=new word();
		h[s1[0]].head=a;
		strcpy(a->str,s1);
		a->count=1;
		a->next=NULL;
		h[s1[0]].tail=a;
	}
	else
	{
		struct word *temp;
		int flag=0;
		for(temp=h[s1[0]].head;temp!=NULL;temp=temp->next)
		{
			if(strcmp(temp->str,s1)==0)
			{
				flag=1;
				temp->count++;
				break;
			}
		}
		if(flag==0)
		{
			struct word *b=new word();
			strcpy(b->str,s1);
			b->count=1;
			b->next=NULL;
			temp->next=b;
			h[s1[0]].tail=b;	
		}
	}
}
void print(struct Hash h[256])
{	
	for(int i=0;i<256;i++)
	{
		if(h[i].head!=NULL)
		{
			struct word *temp;
			for(temp=h[i].head;temp!=NULL;temp=temp->next)
			{
				cout<<temp->str<<":"<<temp->count<<endl;
			}
		}
	}
}

int main()
{
	struct Hash h[256];
	for(int i=0;i<=256;i++)
		h[i].head=NULL;
	char s[200];
	cin.getline(s,200);	
	bool inword=false;
	int si=-1,ei=-1,i=0;
	while(s[i]!='\0')
	{
		if(s[i]==' ')
		{
			if(inword==true)
			{
				ei=i-1;
				insert(h,s,si,ei);
			}
			inword=false;
		}
		else
		{
			if(inword==false)
				si=i;
			inword=true;
		}
		i++;
	}
	if(inword==true)
		insert(h,s,si,i-1);
	print(h);
}