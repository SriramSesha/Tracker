#include<iostream>
#include<cstdarg>
#include<process.h>
#include<cstring>
#include<string>
#include<typeinfo>
#include <time.h>
using namespace std;
template<class T>
class node
{
	public:
	T data;
	node<T> *same;
	node<T> *next;
};
template<class T>
class array
{
	int dim;
	node<T> *start;
	public:
		array(int n)
		{
			dim=n;
			start=NULL;
		}
	    void convertor(T& t,string s)
		{
			char a;
		   	a=s[0];
		   	t=a;
		}
		T &operator ()(...)
		{
			va_list vlist;
			int l=0;
			int p[dim];
			node<T> *newnode;
			va_start(vlist,dim);
			for(int i=0;i<dim;i++)
			{
				p[i]=va_arg(vlist,int);
			}
			int i=0;
			if(start==NULL)
			{
				newnode=new node<T>;
				if(typeid(T)==typeid(string))
				convertor(newnode->data,"0");
				else
				newnode->data=(T)0;
				newnode->same=newnode->next=NULL;
				start=newnode;
			}
			node<T> *temp=start;
			while(i<dim)
			{
				int j=0;
				while(j<p[i])
				{
					if(temp->same==NULL)
					{
						newnode=new node<T>;
						if(!newnode)
						{
							cout<<"memory full";l=1;break;
						}
						if(typeid(T)==typeid(string))
			        	convertor(newnode->data,"0");
			        	else
						newnode->data=(T)0;						
						temp->same=newnode;newnode->same=newnode->next=NULL;
					}
					temp=temp->same;
					j++;
				}
				if(l==1)
				{
					break;
				}
				i++;
				if(i<dim)
				{
					if(temp->next==NULL)
					{
						newnode=new node<T>;
						if(!newnode)
						{
							cout<<"memory full";break;
						}
						if(typeid(T)==typeid(string))
				        convertor(newnode->data,"0");
				        else
						newnode->data=(T)0;
						temp->next=newnode;newnode->same=newnode->next=NULL;
					}
				temp=temp->next;
				}
			}
			return (temp->data);
		}
};
template<class T>
istream& operator >>(istream& s,array<T>& a)
{
	if(sizeof(a(0))!=sizeof(char))
	{
		cout<<"\nInvalid inputting style";
		return s;
	}
	a(0)=getchar();
	int i=0;
	while(a(i)!='$')
	{
		i++;
		a(i)=getchar();
	}
	return s;
	//a(i)=0;
}
template<class T>
ostream& operator <<(ostream& s,array<T>& a)
{
	if(sizeof(a(0))!=sizeof(char))
	{
		cout<<"\nInvalid outputting style";
		return s;
	}
	int i=0;
	while(a(i)!='$')
	{
		//s<<a(i)<<" ";
		putchar(a(i));
		i++;
	}
	return s;
}
int main()
{
	clock_t tStart1 = clock();
	int a1[20][20][20][20];int k2=1;
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
	    {
		     for(int k=0;k<20;k++)
		     {
		     	for(int l=0;l<20;l++)
		     		a1[i][j][k][l]=2;
			 }
		}
	}
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
	    {
		     for(int k=0;k<20;k++)
		     {
		     	for(int l=0;l<20;l++)
		        	printf("%d",a1[i][j][k][l]);
			 }
		}
	}
	printf("Time taken: %.2fs\n", (double)(clock() - tStart1)/CLOCKS_PER_SEC);
	clock_t tStart = clock();
	array<int> a(4);int k1=1;
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
	    {
		     for(int k=0;k<20;k++)
		     {
		     	for(int l=0;l<20;l++)
		     		a(i,j,k,l)=1;
			 }
		}
	}
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
	    {
		     for(int k=0;k<20;k++)
		     {
		     	for(int l=0;l<20;l++)
		        printf("%d",a(i,j,k,l));
			 }
		}
	}
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);	
    return 0;
}
