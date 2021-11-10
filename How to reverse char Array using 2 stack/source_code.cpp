//How to reverse char Array using 2 stack
#include <iostream>
using namespace std;

class stack{
	char *arr;
	int size;
	int top;
	public:
		stack(int s)
		{
			arr = new char[size];
			size=s;
			top=-1;
		
		}
	bool isempty()
	{
		if(top==-1)
		{
			return true;
		}
		else 
		{
			return false;
		}
	} 
	
	bool isfull()
	{
		if(top==size-1)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}
	
	
	
	
	
	
	void push(char  v)
	{
		if(isfull())
		{
			cout<<"stack is full "<<endl;
		}
		else
		{   top++;
			arr[top]=v;
			
		}
	}
	
	
	
	
		
	char pop1()
	{
		if(isempty())
		{
			cout<<"stack is empty"<<endl;
		}
		else
		{
			char var= arr[top];
			top--;
			return var;
		}
	}
	
	void display()
	{
		for(int i=0;i<=top;i++)
		{
			cout<<arr[i]<<" ";
		}
	}
	
	
};
class stack1{
	
	
	
	char *ar1;
	int size;
	int top;
	public:
		stack1(int s)
		{
			ar1 = new char[size];
			size=s;
			top=-1;
		
		}
	bool isempty()
	{
		if(top==-1)
		{
			return true;
		}
		else 
		{
			return false;
		}
	} 
	
	bool isfull()
	{
		if(top==size-1)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}
	
	
	
	void push1(char  v)
	{
		if(isfull())
		{
			cout<<"stack is full "<<endl;
		}
		else
		{   top++;
			ar1[top]=v;
			
		}
	}
	
	
	
		
	char pop1()
	{
		if(isempty())
		{
			cout<<"stack is empty"<<endl;
		}
		else
		{
			char var= ar1[top];
			top--;
			return var;
		}
	}
};



int main() {
	int s;
	
	cout<<"Enter the size of stack :";
	cin>>s;
	stack obj(s);
	cout<<"Enter the value of stack \n";
	for(int i=0;i<s;i++)
	{
		char a;
		cin>>a;
		obj.push(a);
	}
	
	cout<<"\n stack 1 output :";
	obj.display();
	
	stack obj1(s);
	for(int i=0;i<s;i++)
	{
		char temp= obj.pop1();
		obj1.push(temp);
	}
	cout<<"\n stack 2 output :";
	obj1.display();
	
	
	
	
   return 0;
}

