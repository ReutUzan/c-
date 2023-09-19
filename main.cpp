#include <iostream>
#include "pointers.h"
#include <memory>
#include <string>

using namespace std;

class Pos
{
public:
	int x;
};

int main()
{
	///*********UNIQUE POINTER*************/
	/*Unique Pointer operations - Move semantics*/
	std::unique_ptr<int> p1(new int(6));
	//std::unique_ptr<int> p2(p1); //Error - No copy constructor only Move constructor
	std::unique_ptr<int> p2(std::move(p1));
	std::unique_ptr<int> p3(std::move(p2));

	if (nullptr != p1)
		cout << "p1 = " << *p1 << endl;

	if (nullptr != p2)
		cout << "p2 = " << *p2 << endl;

	if (nullptr != p3)
		cout << "p3 = " << *p3 << endl;


	///*********SHARED POINTER*************/
	{
		std::shared_ptr<int> s1(new int(6));
		std::shared_ptr<int> s2(s1);
		std::shared_ptr<int> s3 = s2;

		if (nullptr != s1)
			cout << "s1 = " << *s1 << endl;

		if (nullptr != s2)
			cout << "s2 = " << *s2 << endl;

		if (nullptr != s3)
			cout << "s3 = " << *s3 << endl;

		{
			std::shared_ptr<int> s4 = s3;
		}
	}


	/*********WEAK POINTER********************/
	/*********OUR IMPLEMENTATION*************/
	{
		SharedPointer<int> sp(new int(1));
		WeakPointer<int> wp(sp);
		{
			SharedPointer<int> sp2(sp);
			WeakPointer<int> wp2(sp);
		}
		int num = 5;
	}

	{
		SharedPointer<int> sp(new int(1));
	}


	///*********WEAK & SHARED CPP STD*****************/

	std::shared_ptr<int> s1(new int(6));
	std::weak_ptr<int> wp2(s1);

	cout << "Use Count is: " << s1.use_count() << endl;

	std::shared_ptr<int> x(new int(10));
	std::cout << "Address is " << x.get() << std::endl;
	std::cout << "*x is " << *x << std::endl;
	{
		std::shared_ptr<int> y = x;
		std::cout << "Ref count is " << x.use_count() << std::endl;
	}

	std::cout << "Ref count is " << x.use_count() << std::endl;


	/*********UNIQUE POINTER*****************/
	/*********SHARED POINTER*****************/
	/*********WEAK POINTER*******************/
	/*********OUR IMPLEMENTATION*************/
	UniquePointer<int> up(new int(10));

	UniquePointer<int> up1(std::move(up));

	cout << "The Value of up is: " << *up << endl;
	cout << "The Value of up1 is: " << *up1 << endl;

	SharedPointer<Pos> sp(new Pos());
	WeakPointer<Pos> wp3(sp);
	{
		{
			SharedPointer<Pos> sp2(sp);
			WeakPointer<Pos> wp4(sp);
			cout << wp4->x << endl;
		}
	}

	{
		SharedPointer<int> sp3(new int(1));
	}

	std::cout << "The Value of wp is: " << (wp3)->x << std::endl;
}


