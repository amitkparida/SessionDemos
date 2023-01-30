using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exception_DotNet
{
    internal class Program
    {
        static void Main(string[] args)
        {
            try
            {
                int output = Divide(5, 0);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                Console.WriteLine(ex.GetType());
                Console.WriteLine(ex.StackTrace);
            }

        }

        public static int Divide(int i, int j)
        {
            if (j == 0)
            {
                throw new ArgumentException("Invalid Argument"); //Throws CLR (Software) Exception
            }

            return i / j; // Throws Hardware Exception 
        }
    }
}


// Demo of Inner Exceptions

//namespace Exception_DotNet
//{
//    internal class Program
//    {
//        static void Main(string[] args)
//        {
//            try
//            {
//                int result = Fun1(10);
//                Console.WriteLine($"The value at the given position is {result}");
//            }
//            catch (Exception ex)
//            {
//                Console.WriteLine(ex.Message);
//                Console.WriteLine(ex.GetType());
//                Console.WriteLine(ex.StackTrace);

//                var inner = ex.InnerException;   
//                while (inner != null)
//                {
//                    Console.WriteLine(inner.GetType());
//                    Console.WriteLine(inner.StackTrace);
//                    inner = inner.InnerException;
//                }
//            }

//            Console.ReadLine();
//        }

//        public static int Fun1(int position)
//        {
//            int output = 0;

//            Console.WriteLine("Open Database Connection");

//            //try
//            //{
//            output = Fun2(position);
//            //}
//            //catch (Exception ex)
//            //{
//            //    throw new ArgumentException("You passed in bad data", ex);
//            //}
//            //finally
//            //{
//            //    Console.WriteLine("Close Database Connection");
//            //}

//            return output;
//        }

//        public static int Fun2(int position)
//        {
//            return Fun3(position);
//        }

//        public static int Fun3(int position)
//        {
//            int output = 0;

//            //try
//            //{
//            int[] numbers = new int[] { 1, 4, 7, 2 };
//            output = numbers[position];
//            //}
//            //catch (Exception ex)
//            //{
//            //    Console.WriteLine(ex.Message);
//            //    Console.WriteLine(ex.GetType());
//            //    Console.WriteLine(ex.StackTrace);
//            //}

//            return output;
//        }
//    }
//}









