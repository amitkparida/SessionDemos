
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
	DWORD dwThread1ID;
	HANDLE hHandle;

	hHandle = CreateThread(NULL, 0, ThreadFunc, NULL, 0, &dwThread1ID);

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
		printf("\n Secondary thread prints %d", iCount);
		iCount += 1;
	}

	MessageBoxA(NULL, "ThreadFunc1 : Secondary Thread", "Caption", 0);

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


