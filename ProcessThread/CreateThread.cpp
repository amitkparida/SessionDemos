
//CreateThread Demo

#include <windows.h>
#include <stdio.h>
#include<TCHAR.h>

DWORD WINAPI ThreadFunc(PVOID pvParam);
void fun1();
void fun2(int, int);
void fun3();
void fun4(int, int, int);

int main()
{
	DWORD dwThreadId;
	HANDLE hHandle;

	hHandle = CreateThread(
						NULL,				// default security attributes
						0,					// use default stack size 
						ThreadFunc,			// thread function
						NULL,				// argument to thread function
						0,					// use default creation flags
						&dwThreadId			// returns the thread identifier
						);
	if (hHandle == NULL)
	{
		printf("CreateThread() failed, error: %d.\n", GetLastError());

		return -1;
	}

	fun1();

	WaitForSingleObject(hHandle, INFINITE);
	CloseHandle(hHandle);

	return 0;
}

DWORD WINAPI ThreadFunc(PVOID pvParam)
{
	int iCount = 1;

	while (iCount < 20)
	{
		Sleep(100);
		printf("\n Secondary thread prints %d", iCount++);
	}

	MessageBoxA(NULL, "ThreadFunc : Secondary Thread", "Caption", 0);

	return 0;
}

void fun1() {
	fun2(2, 3);
}

void fun2(int x, int y) {
	fun3();
}

void fun3() {
	fun4(4, 5, 6);
}

void fun4(int x, int y, int z) {
	int a = 10;
	int b = 20;
	int c = 30;

	MessageBoxA(NULL, "fun4 : Primary Thread", "Caption", 0);
}


