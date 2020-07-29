#include <iostream>
#include <string>
using namespace std;
class STACK
{
private:
    string stack[100];
    int size;

public:
    STACK()
    {
        size = 0;
    }
    int isEmpty();
    string Top();
    int  push(string data);
    string pop();
    void show();
};
int STACK::isEmpty()
{
    if (size == 0)
        return 1; //stack đang rỗng
    else
        return 0;
}
string STACK::Top()
{
    int temp=size-1;
    return stack[temp];
}
int STACK::push(string data)
{
    if(size==100)
    {
        cout<<"stack full!\n";
        return 0;
    }
    stack[size++]=data;
    return 1;
} 
string STACK::pop()
{
    if(size == 0)
    {
        cout <<"Stack is empty\n";
    }
    else
    {
        return stack[--size];
    }
}
void STACK::show()
{
    for (int i = 0; i < size; i++)
    {
        cout << "s[" << i << "] = " << stack[i] <<"\n";
    }
}
int uutien(char a)
{
	if (a == '(' || a == ')')
		return 0;
	else if (a == '+' || a == '-')
		return 1;
	else if (a == '*' || a == '/')
		return 2;
	else
		return -1;
}
int uutien(string a)
{
	if (a == "(" || a == ")")
		return 0;
	else if (a == "+" || a == "-")
		return 1;
	else if (a == "*" || a == "/")
		return 2;
	else
		return -1;
}
/*int  main()
{
    STACK stack;
    stack.push("duong");
    stack.push("van");
    stack.push("dan");
   // stack.show();
    //stack.pop();
    stack.push("*");
   // stack.show();
   //cout<<"haudau\n";
   string s="*";
    if(uutien('*')<=uutien(s))
    {
        cout<<"dung\n";
    }
    return 0;
}
*/