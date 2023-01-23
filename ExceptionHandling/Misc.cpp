

// Important Notes:
//
// __except(EXCEPTION_EXECUTE_HANDLER) can catch exceptions raised by RaiseException API, e.g. RaiseException(EXCEPTION_CODE_1, 0, 2, NULL); 
// __except(EXCEPTION_EXECUTE_HANDLER) can also catch hardware exceptions. 
// __except(EXCEPTION_EXECUTE_HANDLER) cannot catch exceptions thrown by C++ throw.
// Hardware exptions are not thrown/raised by RaiseException or throw. They are directly raised by Processor.
// By default, C++ catch(...) can catch exceptions thrown by only C++ throw.
// By default, C++ catch(...) cannot catch Hardware Exceptions or any exception raised by RaiseException.
// If you enable /EHa, C++ catch(...) can catch hardware exceptions, as well as exceptions raised by RaiseException (and by C++ throw obviously)


//#include <iostream>
//#include <windows.h>
//using namespace std;

//void TestMethod()
//{
//    int i = 0, j = 1;
//    j = j / i;   // This will throw a Structured Exception (divide by zero).
//}
//
//int main()
//{
//    try
//    {
//        TestMethod();
//        //throw 1;
//        //RaiseException(1, 0, 2, NULL); // This is also caught by __except()
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
    int i = 0, j = 1;
    j = j / i;   // This will throw a Structured Exception (divide by zero).
}

int main()
{
    __try
    {
        throw EXCEPTION_INT_DIVIDE_BY_ZERO; // can't be caught by __except, hence crash 
        //RaiseException(EXCEPTION_INT_DIVIDE_BY_ZERO, 0, 2, NULL); // This is also caught by __except()
        //TestMethod();
    }
     //__except will catch the exception here. (You can also use only __except(EXCEPTION_EXECUTE_HANDLER) below)
    __except (GetExceptionCode() == EXCEPTION_INT_DIVIDE_BY_ZERO ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH)
    {
        cout << "Divide by zero exception was caught in __except." << endl;
    }
}

// Output:
// Divide by zero exception was caught in __except.