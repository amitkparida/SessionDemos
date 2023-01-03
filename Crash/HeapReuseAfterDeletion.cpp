// Heap Reuse After Deletion

//Double Free
#include <windows.h>
#include <stdio.h>
int wmain()
{
	printf("Press any key to start\n");
	getchar();

	BYTE* pByte = new BYTE(50);
	delete pByte;
	delete pByte;
	printf("Done...exiting application\n");

	//BYTE* pByte = (BYTE*)HeapAlloc(GetProcessHeap(), 0, 10);
	//(*pByte) = 50;
	//HeapFree(GetProcessHeap(), 0, pByte);
	//HeapFree(GetProcessHeap(), 0, pByte);
	//printf("Done...exiting application\n");
	return 0;
}