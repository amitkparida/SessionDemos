//Stack Overruns

// Note:
// In case of stack buffer overrun, the hackers can take control over the Return Address (by placing the address of their malicious function in place of the Return Address in stack)

// In order to prevent stack buffer overrun, VC++ compiler uses /GS(Guard Stack) switch by default. 
// Properties->C/C++->Code Generation->Security Check->Enable Security Check(/GS)
// /GS is on by default.If you expect your application to have no security exposure, use /GS-.
// The /GS compiler option does not protect against all buffer overrun security attacks. For example, if you have a buffer and a vtable in an object, a buffer overrun could corrupt the vtable.
// Even if you use / GS, always try to write secure code that has no buffer overruns.



#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

#include <windows.h>
#include <stdio.h>
#define MAX_CONN_LEN 5

void HelperFunction(char* pszConnectionString){
	char szCopy[MAX_CONN_LEN];
	strcpy(szCopy, pszConnectionString);
 
 	// use a secure CRT function to help prevent buffer overruns
	// truncate string to fit into destination buffer
	// strncpy_s(szCopy, _countof(szCopy), pszConnectionString, _TRUNCATE);

	//
	// ...
	// Establish connection
	// ...
	//
}

int main(){
	char szStr[MAX_CONN_LEN];
	
	printf("Please specify connection string on the command line:\n");
	scanf("%[^\n]", szStr);
	HelperFunction(szStr);
	//printf("Connection to %s established\n", szStr);

	return 0;
}




// https://www.youtube.com/watch?v=gqixbRLRJf0
// Below program will crash with stack corruption error by default as /GS is enabled.
// 
// If you disable /GS (and build it in Release preferably), then below program will get into infinite loop. When x becomes 100 in the loop, crashArray[100] buffer overflows. 
// In stack, int x memory is allicated next to the buffer. So, int x memory will be overwritten (as 'a' or 97) when crashArray buffer overflows.
// This will cause infinite loop.


//#include <iostream>
//
//void func()
//{
//	std::cout << "going to loop forever" << std::endl;
//
//	char crashArray[100];
//	for (int x = 0; x <= 100; ++x) {
//		*(crashArray + x) = 'a';
//	}
//
//	std::cout << "should not reach here" << std::endl;
//}
//
//int main()
//{
//	func();
//}
