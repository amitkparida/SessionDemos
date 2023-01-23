//Usermode calls to ntdll APIs demo

#include <iostream>

int main()
{
    FILE* stream;
    errno_t err;

    // Open for read (will fail if file "test.txt" doesn't exist)
    err = fopen_s(&stream, "C:\\Users\\amparida\\Desktop\\GitHub\\SessionDemos\\x64\\Debug\\test.txt", "r");
    if (err == 0)
    {
        printf("The file 'test.txt' was opened\n");
    }
    else
    {
        printf("The file 'test.txt' was not opened\n");
    }

}

// Demo using WinDbg:
// 
// Launch the API_Calls_C++.exe in WinDbg and run below commands
// bp API_Calls_C++!main
// g
// F10, F11 to go inside fopen_s
// bp KERNELBASE!CreateFileW
// kp
// bp ntdll!ZwCreateFile
// kp
