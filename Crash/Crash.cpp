#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

#include <iostream>
#include <windows.h>
using namespace std;


//demo program for heap corruption
//See vganga session 5 for heap corruption debugging video with !heap, !uiext.heap commands

#define SZ_MAX_LEN 5

void CorruptStack()
{
	char str1[5];
	strcpy(str1, "amitkumarparida"); // It will corrupt the pushed EBP and Return Address (EIP)
}

void fun1(char* pStr)
{
	char* str2 = new char[SZ_MAX_LEN];

	strcpy(str2, pStr); 
	cout << pStr << " " << str2;

	delete[] str2;
}
void CorruptHeap()
{
	char* str1 = new char[SZ_MAX_LEN];
	strcpy(str1, "amitkumar"); //Heap Buffer overrun and hence corruption

	fun1(str1);

	cout << str1 << endl;
	delete[] str1;
}

int main()
{
	CorruptHeap();
	//CorruptStack();
}



//demo program for stack corruption



//Note:
//In case of stack buffer overrun, the hackers can take control over the Return Address(by placing the address of their malicious function in place of the Return Address in stack)

//In case of heap buffer overrun, the hackers can take control over the Virtual Table of the dynamically created Class object. (by placing address of their malicious function in the virtual Table)
