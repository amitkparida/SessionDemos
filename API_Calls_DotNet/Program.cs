using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace API_Calls_DotNet
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string text = System.IO.File.ReadAllText(@"C:\Users\amparida\Desktop\GitHub\SessionDemos\API_Calls_DotNet\bin\Debug\test.txt");
            System.Console.WriteLine("Contents of test.txt = {0}", text);
        }
    }
}

// Demo using WinDbg:
// 
// Launch the API_Calls_DotNet.exe in WinDbg and run below commands
// sxe ld clrjit
// g
// !Name2EE API_Calls_DotNet.exe!API_Calls_DotNet.Program.Main
// !bpmd -md <Address>
// bp kernelbase!ReadFile
// g
// kp
// bp ntdll!NtReadFile
// g
// kp