
// https://amitkparida.medium.com/structured-exception-handling-in-visual-c-618b9e792faa

// Exceptions like Access Violation, Divide by Zero are hardware exceptions.With / EHsc(default) or /EHs compiler options, 
// C++ does not handle these hardware exceptions using standard C++ Exception Handling(try and catch block).
// So the below program would crash due to unhandled hardware exception, if / EHsc(default) or /EHs compiler option is used.

// There is a very easy way to catch both standard C++ exceptions (software exceptions) and hardware exceptions 
// using C++ Exception handling tryand catch block.Just enable / EHa compiler option in the project settings in 
// Visual Studio (Project Properties -> C/C++ -> Code Generation -> Modify the Enable C++ Exceptions to “Yes With SEH Exceptions”).
// So the below program would not crash if / EHa compiler option is used, as the exception will be caught.

#include <iostream>
using namespace std;

void TestMethod()
{
    int i = 0, j = 1;
    j = j / i;   // This will throw a Structured Exception (divide by zero).
}

int main()
{
    try
    {
        TestMethod();
    }

    // catch block will not be executed for /EHsc or /EHs. catch block will be executed for /EHa
    catch (...)
    {
        cout << "An exception was caught." << endl;
    }
}




// Alternatively, both Cand C++ programs can use the Structured Exception Handling (SEH) mechanism in the Windows OS 
// for handling both hardwareand software exceptions identically. The concepts in SEH resemble the ones in C++ Exception Handling, 
// except that SEH uses the __try, __except, and __finally constructs instead of tryand catch.

//// compile with: /EHsc, /EHs, or /EHa
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//void TestMethod()
//{
//    int i = 0, j = 1;
//    j = j / i;   // This will throw a Structured Exception (divide by zero).
//}
//
//int main()
//{
//    __try
//    {
//        TestMethod();
//    }
//
//    // __except will catch the exception here. (You can also use only __except(EXCEPTION_EXECUTE_HANDLER) below)
//    __except (GetExceptionCode() == EXCEPTION_INT_DIVIDE_BY_ZERO ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH)
//    {
//        cout << "Divide by zero exception was caught in __except." << endl;
//    }
//}

// Output:
// Divide by zero exception was caught in __except.