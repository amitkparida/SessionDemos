//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//void TestMethod()
//{
//    //int i = 0, j = 1;
//    //j = j / i;   // This will throw a Structured Exception (divide by zero).
//
//    int* ptr = NULL;
//    *ptr = 10; // Generates EXCEPTION_ACCESS_VIOLATION
//
//    //RaiseException(EXCEPTION_ACCESS_VIOLATION, 0, 0, NULL); //Programmer generates EXCEPTION_ACCESS_VIOLATION, Hence Software Exception
//    //throw EXCEPTION_ACCESS_VIOLATION;
//
//}
//
//int main()
//{
//    try
//    {
//        TestMethod();
//    }
//    // catch block will not be executed for /EHsc or /EHs. catch block will be executed for /EHa
//    catch (...) {
//        cout << "Exception was caught" << endl;
//    }
//}


// compile with: /EHsc, /EHs, or /EHa
#include <stdio.h>
#include <windows.h>
using namespace std;

#define MY_EXCEPTION_INVALID_PARAMETER 0x1000

int Divide(int i, int j)
{
    if (j == 0) {
        RaiseException(MY_EXCEPTION_INVALID_PARAMETER, 0, 0, NULL); //Programmer generates MY_EXCEPTION_INVALID_PARAMETER, Hence Software Exception
    }

    return i/j; // CPU Generates EXCEPTION_INT_DIVIDE_BY_ZERO, Hence Hardware Exception
}

void TestMethod(int* ptr)
{
    if (ptr == NULL) {
        //RaiseException(MY_EXCEPTION_INVALID_PARAMETER, 0, 0, NULL); //Programmer generates MY_EXCEPTION_INVALID_PARAMETER, Hence Software Exception
    }
     
    *ptr = 10; // CPU Generates EXCEPTION_ACCESS_VIOLATION, Hence Hardware Exception
}

int main()
{
    __try{
        Divide(5, 0);
        //TestMethod(NULL);
    }
    __except(EXCEPTION_EXECUTE_HANDLER){
        printf("Exception was caught: 0x%X", GetExceptionCode()); 
    }
}



// .dump /ma c:\pathToDump.dmp
