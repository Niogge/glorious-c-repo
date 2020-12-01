using System;
using System.Runtime.InteropServices;


namespace CsharpWrapper
{

    [StructLayout(LayoutKind.Sequential)]//cosi` abbiamo lo stesso layout di memoria del C
    public struct Pair
    {
        public int a;
        public int b;

    }
    static class LibWrapping
    {

        [DllImport("mylib")]
        public extern static void hello();
        [DllImport("mylib", EntryPoint = "helloint")]
        public extern static void hello(int val);

        [DllImport("mylib", EntryPoint = "hellostr")]
        public extern static void hello(string val);

        [DllImport("mylib")]
        private extern static int sum(int[] v, int size);
        public static int sum(int[] v)
        {
            return sum(v, v.Length);
        }

        [DllImport("mylib", EntryPoint = "sumPair")]
        public static extern int sum(Pair p);

        [DllImport("mylib", EntryPoint = "sumPairPtr")]
        public static extern int sum(ref Pair p);

        [DllImport("mylib", EntryPoint = "sum_out")]
        public static extern void sum(int a, int b, out int r );

        [DllImport("mylib")]
        private static extern IntPtr fixed_str();//public static extern string LibString();//col marshaling viene distrutta la stringa della memoria unmanaged, che quindi era la nostra stringa, rip
        public static string LibString()
        {
            IntPtr strPointer = fixed_str();
            string str = Marshal.PtrToStringAnsi(strPointer);
            return str;
        }
    }
    class Program
    {

        static void Main(string[] args)
        {
            //LibWrapping.hello();
            //LibWrapping.hello(3);
            //LibWrapping.hello("ciaocane");

            //int[] arr = { 1, 2, 3 };
            //Console.WriteLine(LibWrapping.sum(arr));

            //Pair p;
            //p.a = 3;
            //p.b = 5;

            //Console.WriteLine(LibWrapping.sum(p));

            //Console.WriteLine(LibWrapping.sum(ref p));

            //int r;
            //LibWrapping.sum(1, 2, out r);
            //Console.WriteLine(r);

            //string str = LibWrapping.LibString();
            //Console.Write(str);

            //Console.ReadLine();

            //IntPtr handle = AivVectorNative.Create();
            //Console.WriteLine(handle);

            //int elem = 10;
            //GCHandle itemH = GCHandle.Alloc(elem);
            //IntPtr item =GCHandle.ToIntPtr(itemH);
            //AivVectorNative.Add(handle, item);

            //int count = AivVectorNative.Count(handle);

            //Console.WriteLine(count);

            //itemH.Free();
            //AivVectorNative.Destroy(handle);
            //Console.WriteLine("END");

            
            AivVector<int> v = new AivVector<int>();
            Console.WriteLine(v.IsEmpty);
            v.Add(10);
            Console.WriteLine(v.IsEmpty);
            Console.WriteLine(v.Count());
            Console.ReadLine();
        }
    }
}
