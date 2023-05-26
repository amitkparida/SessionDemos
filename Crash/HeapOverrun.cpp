//Heap Overruns and Underruns

// Heap Overruns can cause security issues.
// For example, you allocate a class object in heap. If you have a VPTR and a buffer in the object, 
// a buffer overrun could corrupt the VPTR. (VPTR is most typically located at very beginning of object). 
// Hacker can create his own VTABLE, and overwrite the VPTR to point to his VTABLE

#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

#include <windows.h>
#include <stdio.h>
#define SZ_MAX_LEN 10
WCHAR* pszCopy = NULL;

BOOL DupString(WCHAR* psz)
{
	BOOL bRet = FALSE;
	if (psz != NULL)
	{
		pszCopy = (WCHAR*)HeapAlloc(GetProcessHeap(), 0, SZ_MAX_LEN * sizeof(WCHAR));
		if (pszCopy)
		{
			wcscpy(pszCopy, psz);
			wprintf(L"Copy of string : %s", pszCopy);
			HeapFree(GetProcessHeap(), 0, pszCopy);
			bRet = TRUE;
		}
	}
	return bRet;
}

int  wmain(int argc, wchar_t* pArgs[])
{
	printf("Press any key to start\n");
	getchar();

	WCHAR szStr[SZ_MAX_LEN];
	wprintf(L"Please enter the string:\n");
	wscanf(L"%[^\n]", szStr);
	DupString(szStr);
}
