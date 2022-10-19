#include<iostream>
#include"MySharedPtr.h"

using namespace std;

class Foo
{
private:

	int m_number;

public:
	Foo(int number) : m_number(number)
	{
	}

	int GetNumber()
	{
		return m_number;
	}
};
int main()
{
	MySharedPtr<Foo> p1(new Foo(5));
	MySharedPtr<Foo> p2 = p1;
	cout << p1.get() << ' ' << p1.get()->GetNumber() << endl;
	cout << p2.get() << ' ' << p2.get()->GetNumber() << endl;
	cout << p2.getcount();
	
}