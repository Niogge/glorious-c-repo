using System;
using System.Runtime.InteropServices;

namespace CsharpWrapper
{
    class Program
    {
        [DllImport("mylib")]
        extern static void hello();
        [DllImport("mylib")]
        extern static void helloint(int val);

        static void hello(int val)
        {
            helloint(val);
        }

        static void Main(string[] args)
        {
            hello();
            hello(3);
            Console.ReadLine();
        }
    }
}
