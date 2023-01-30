#include <iostream>
#include <windows.h>
using namespace std;

#define MY_EXCEPTION_INVALID_PARAMETER 0x1000

int Divide(int i, int j)
{
    if (j == 0) {
        throw MY_EXCEPTION_INVALID_PARAMETER; // Throws C++ Exception (Software)
        //RaiseException(MY_EXCEPTION_INVALID_PARAMETER, 0, 0, NULL); //Structured Exception (Software). You must use /EHa
    }

    return i / j; // This will throw a Structured Exception (divide by zero - Hardware). You must use /EHa
}

int main()
{
    try {
        Divide(10, 0);
    }
    catch (...) {
        cout << "Exeption occurred" << endl;
    }

    cout << "Crash did not happen" << endl;

}