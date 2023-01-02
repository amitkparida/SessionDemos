//Stack Overruns

#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

#include <windows.h>
#include <stdio.h>
#define MAX_CONN_LEN 5

void HelperFunction(char* pszConnectionString){
	char szCopy[MAX_CONN_LEN];
	strcpy(szCopy, pszConnectionString);

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


