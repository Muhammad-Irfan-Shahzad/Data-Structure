
#include <iostream>
#include<string>
#define MAX 20
using namespace std;
 string stack[20];
 int Top = -1;
void push(string v )
{
if(Top == MAX-1)
{
cout<<"Stack is empty \n";
}
else {
Top++;
stack[Top] = v;
}
}


string pop()
{

if(Top < 0)
{
cout<<"stack is empty\n";

}
else
{
	string ch;
ch = stack[Top];

Top--;
return ch;
}
}
string top()
{
	if(Top==-1)
	{
		cout<<"Stack is empty \n";
	}
	else
	{
		return stack[Top];
	}
}

bool isOperand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    else {
        return false;
    }
}
 
string PrefixToInfix(string prefix)
{
  
   
    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (isOperand(prefix[i])) {
           string op(1,prefix[i]);
            
            push(op);
        }
        else {
            string op1 = top();
            pop();
            string op2 = top();
            pop();
            push(op1 + prefix[i] + op2);
        }
    }
    return top();
}
 
int main()
{
    string infix, prefix;
    cout << "Enter the prefix expression :" << endl;
    cin >> prefix;
    cout << "Prefix Eexpression : " << prefix << endl;
    infix = PrefixToInfix(prefix);
    cout << "\n"<< "Infix Expression: " << infix;
 
    return 0;
}
