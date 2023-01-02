//Heap Overruns and Underruns

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
