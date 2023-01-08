// Exceptions

// https://stackoverflow.com/questions/11938979/what-exception-classes-are-in-the-standard-c-library

#include <windows.h>
#include <iostream>
using namespace std;

int devide(int i, int j) {
	// Throw C++ Software Exception if j == 0. 
	// If you don't check and throw here, you will get DevideByZero Hardware Exception when i/j is computed by CPU.
	if (j == 0) {
		throw std::invalid_argument("2nd argument can't be 0 as we can't devide by 0");
	}

	return i / j;
}

void devide_nested() {
	try {
		for (int i = 100; i > 0; i--) {
			devide(i, i / 10);
		}
	}
	catch (std::invalid_argument& e) {
		throw e; //you can rethrow the same exception 
		//throw std::runtime_error(e.what()); //you can rethrow different expetion with same message
		//throw std::exception("Some error occurred"); //you rethrow different expetion with different message 
	}
}


int main()
{
	//try {
	//	//Below errors are derived from std::exception calss
	// 
	//	throw std::invalid_argument("Invalid Argument");
	//	//throw std::runtime_error("Runtime error occured");
	//	//throw std::logic_error("Logic error occured");
	//	//throw std::overflow_error("Overflow error occured");
	//	//throw std::underflow_error("Underflow error occured");
	//	//throw std::range_error("Range error occured");
	//	//throw std::length_error("Length error occured");
	//}
	//catch(std::exception& e){
	//	cout << "Message: " << e.what() << endl;
	//	cout << "Type: " << typeid(e).name() << endl;
	//}
	//cout << endl;


	//You can also throw your own errors (int, char, string etc)
	try {
		throw 10;
		//throw std::string("My Exception");
	}
	catch (int& i) {
		cout << i << endl;
	}
	catch (std::string& str) {
		cout << str << endl;
	}
	cout << endl;


	try {
		devide(10, 0);
	}
	catch (std::exception& e) {
		cout << "Message: " << e.what() << endl;
		cout << "Type: " << typeid(e).name() << endl;
	}
	cout << endl;


	try {
		devide_nested();
	}
	catch (std::exception& e) {
		cout << "Message: " << e.what() << endl;
		cout << "Type: " << typeid(e).name() << endl;
	}
	cout << endl;

	return 0;
}