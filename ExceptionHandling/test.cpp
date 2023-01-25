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
//}
//
//int main()
//{
//    try
//    {
//        TestMethod();
//
//    }
//    // catch block will not be executed for /EHsc or /EHs. catch block will be executed for /EHa
//    catch (...)
//    {
//        cout << "An exception was caught." << endl;
//    }
//}


// compile with: /EHsc, /EHs, or /EHa
#include <iostream>
#include <windows.h>
using namespace std;

void TestMethod()
{
        //int* ptr = NULL;
        //*ptr = 10; // CPU Generates EXCEPTION_ACCESS_VIOLATION, Hence Hardware Exception

        RaiseException(EXCEPTION_ACCESS_VIOLATION, 0, 0, NULL); //Programer generates EXCEPTION_ACCESS_VIOLATION, Hence Software Exception
}

int main()
{
    __try
    {
        TestMethod();
    }
    __except (GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH)
    {
        cout << "Access Violation was caught in __except." << endl;
    }
}
