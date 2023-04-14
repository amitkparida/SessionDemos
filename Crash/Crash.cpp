

// demo programs for stack and heap corruptions
// See vganga session 5 for heap corruption debugging video with !heap, !uiext.heap commands


// Note:
// In case of stack buffer overrun, the hackers can take control over the Return Address (by placing the address of their malicious function in place of the Return Address in stack)

// In case of heap buffer overrun, the hackers can take control over the Virtual Table of the dynamically created Class object if you have a buffer and a vtable in the object.
// (by placing address of their malicious function in the virtual Table in place of the virtual function addresses)


// In order to prevent stack buffer overrun, VC++ compiler uses /GS(Guard Stack) switch by default. 
// Properties->C/C++->Code Generation->Security Check->Enable Security Check(/GS)
// /GS is on by default.If you expect your application to have no security exposure, use /GS-.
// The /GS compiler option does not protect against all buffer overrun security attacks. For example, if you have a buffer and a vtable in an object, a buffer overrun could corrupt the vtable.
// Even if you use / GS, always try to write secure code that has no buffer overruns.


#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

#include <iostream>
#include <windows.h>
using namespace std;

#define SZ_MAX_LEN 5

void CorruptStack()
{
	char buffer[5];
	strcpy(buffer, "amitkumarparida"); // It will corrupt the pushed EBP and Return Address (EIP)

	// use a secure CRT function to help prevent buffer overruns
	// truncate string to fit into destination buffer
	// strncpy_s(buffer, _countof(buffer), "amitkumarparida", _TRUNCATE);
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
	char* buffer = new char[SZ_MAX_LEN];
	strcpy(buffer, "amitkumar"); //Heap Buffer overrun and hence corruption

	fun1(buffer);

	cout << buffer << endl;
	delete[] buffer;
}

int main()
{
	CorruptHeap();
	//CorruptStack();
}




