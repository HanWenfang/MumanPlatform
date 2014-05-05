// g++ -W int_size.cpp -o test

#include <iostream>


using namespace std;

int main(int argc, char const *argv[])
{

	cout << sizeof(int) << endl;
	cout << sizeof(long int) << endl;
	cout << sizeof(double) << endl;
	double a = 8000000000;
	int b = a;

	cout << "a: " << a << endl;
	cout << "(long)a: " << (long)a << endl;
	cout << "(long long)a: " << (long long)a << endl;
	cout << "b: " << b << endl;
}

