
//Take TTD trace of this program and run below commands to examine the raw memory of int arrays, strings, pointers etc.

/*
Commands to see raw memory:
---------------------------

dump ASCII:
-----------
da <address>
Prints the entire string if it's ASCII (char array)
Prints only 1st char if the string is Unicode (wchar_t array)

dump Unicode:
------------
du <address>
Prints the entire string if it's Unicode (wchar_t array)
Prints garbage Unicode string if the string ASCII (char array)

db (display byte)
dw (display word (2 byte))
dd (display dword (4 byte))
dq (display qword (8 byte))

dp (display pointer) - equivalent to dd in 32 bit dump, equivalent to dq in 64 bit dump
dc (display character) - equivalent to dd, but it shows characters as well

*/

#include <iostream>

int main()
{
	char chArr[18] = {0};
	strcpy_s(chArr, 18, "Amit Kumar Parida"); //Run command [ .formats 'Amit Kum' ] or [? 'Amit Kum' ] to find its hex equivalent value in memory. Then [ .formats ' Kum' ] and so on.

	char* str = new char[18];
	strcpy_s(str, 18, "Amit Kumar Parida");

	wchar_t* wstr = new wchar_t[18];
	wcscpy_s(wstr, 18, L"Amit Kumar Parida");

	int i = 47483612;
	unsigned int ui = 47483612;

	int iArr[10] = { 8443619, 2, 3, 4, 5, 474612, 7, 8, 9, 7483612 };

	int* ptr = new int[10] { 8443619, 2, 3, 4, 5, 474612, 7, 8, 9, 7483612 };

	int** ptrPtr = &ptr;

	long long ll = 8446744073709551;
	unsigned long long ull = 8446744073709551;

	return 0;
}



