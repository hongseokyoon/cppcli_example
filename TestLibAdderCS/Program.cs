using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TestLibAdderCS
{
    class Program
    {
        static void MyCallback()
        {
            Console.WriteLine("This is user defined callback function.");
        }
        
        static void Main(string[] args)
        {
            LibAdderCS.AdderCS adder = new LibAdderCS.AdderCS(MyCallback);

            Console.WriteLine("(1)");
            adder.Do(1, 2, "Hongseok's message");

            int[] v = new int[5] { 1, 2, 3, 4, 5 };
            Console.WriteLine("\n(2)");
            adder.Do(v, "Hongseok's message");
        }
    }
}
