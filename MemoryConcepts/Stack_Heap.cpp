#include<iostream>
using namespace std;

char* getStringFromStack() {
	char str[13] = "Stack String";
	return str;
}

char* getStringFromHeap() {
	char* str = new char[12] {"Heap String"};
	return str;
}

int main() {
	char* strStack = getStringFromStack();
	cout << "String from Stack = " << strStack << endl << endl;

	char* strHeap = getStringFromHeap();
	cout << "String from Heap = " << strHeap << endl;

	delete[] strHeap;
}









//int getIntByValue() {
//	int i = 30;
//	return i;
//}
//
//int* getIntFromStack() {
//	int i = 10;
//	int* ptr = &i;
//	return ptr;
//}
//
//int* getIntFromHeap() {
//	int* ptr = new int{ 20 };
//	return ptr;
//}
//
//int main() {
//	int intVal = getIntByValue();
//	cout << "Int by value = " << intVal << endl;
//
//	int* ptrStack = getIntFromStack();
//	cout << "Int from Stack = " << *ptrStack << endl;
//
//	int* ptrHeap = getIntFromHeap();
//	cout << "Int from Heap = " << *ptrHeap << endl;
//}