#include <stdio.h>
#include <windows.h>
using namespace std;

#define MY_EXCEPTION_INVALID_PARAMETER 0x1000

void TestMethod(int* ptr)
{
    if (ptr == NULL) {
        RaiseException(MY_EXCEPTION_INVALID_PARAMETER, 0, 0, NULL); //Programmer generates MY_EXCEPTION_INVALID_PARAMETER, Hence Software Exception
    }

    *ptr = 10; // CPU Generates EXCEPTION_ACCESS_VIOLATION (0xC0000005), Hence Hardware Exception
}

int main()
{
    __try {
        TestMethod(NULL);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        printf("Exception was caught: 0x%X", GetExceptionCode());
    }

    printf("Didn't crash");
    getchar();
}
