#include <stdio.h>
#include <windows.h>

int main() {
	HANDLE hHeap;

	hHeap = HeapCreate(HEAP_NO_SERIALIZE, 4096 * 10, 4096 * 100);
	if (NULL == hHeap) {
		printf("HeapCreate failed\n");
		return 0;
	}

	//Allocate memory for 30 integers from the newly created heap
	int* pArr = (int*)HeapAlloc(hHeap, 0, sizeof(int) * 30);
	if (NULL == pArr) {
		printf("HeapAlloc failed\n");
		return 0;
	}

	//Intiallize first 10 integers
	for (int i = 0; i < 10; ++i)
	{
		pArr[i] = (i + 1) * 100;
	}

	//Print the entire array of 30 integers
	for (int i = 0; i < 30; ++i)
	{
		printf("%d ", pArr[i]);
	}

	HeapFree(hHeap, 0, pArr);
	HeapDestroy(hHeap);

	return 0;
}