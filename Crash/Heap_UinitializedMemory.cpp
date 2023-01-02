//Using Uninitialied State

#include <windows.h>
#include <iostream>
using namespace std;

void InitArray(int** ppIntArray)
{ 
	//for (int i = 0; i < 10; i++) {
	//	ppIntArray[i] = new int;
	//}

	return;
}

int main()
{
	cout << "Press any key to start...";
	getchar();

	int** ppIntArray = new int*[10];
	InitArray(ppIntArray);
	*(ppIntArray[0]) = 20;
	delete[] ppIntArray;
}

