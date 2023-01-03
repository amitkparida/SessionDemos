using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace stack_heap
{
    class Program
    {
        static string getString()
        {
            string str = "My String";
            return str;
        }

        static void Main(string[] args)
        {
            string mystr = getString();
            Console.WriteLine($"String = {mystr}");
        }
    }
}

