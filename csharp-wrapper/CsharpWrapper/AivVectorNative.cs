using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;


namespace CsharpWrapper
{
    internal static class AivVectorNative
    {

        private const string DLL_NAME = "aiv-collections";

        [DllImport(DLL_NAME, EntryPoint = "aiv_vector_new")]
        //aiv_vector* aiv_vector_new();
        internal static extern IntPtr Create();

        [DllImport(DLL_NAME, EntryPoint = "aiv_vector_destroy")]
        internal static extern void Destroy(IntPtr ptr);

        [DllImport(DLL_NAME, EntryPoint = "aiv_vector_size")]
        internal static extern int Count(IntPtr ptr);

        [DllImport(DLL_NAME, EntryPoint = "aiv_vector_add")]
        internal static extern void Add(IntPtr ptr, IntPtr item);

        [DllImport(DLL_NAME, EntryPoint = "aiv_vector_at")]
        internal static extern IntPtr At(IntPtr ptr, uint index);

        [DllImport(DLL_NAME, EntryPoint = "aiv_vector_is_empty")]
        [return: MarshalAs(UnmanagedType.I1)]
        internal static extern bool IsEmpty(IntPtr ptr);

        internal delegate void AivAction(IntPtr ptr);
        [DllImport(DLL_NAME, EntryPoint = "aiv_vector_foreach")]
        internal static extern void ForEach(IntPtr ptr, AivAction action);

        internal delegate int AivComprator(IntPtr ptr1, IntPtr ptr2);
        [DllImport(DLL_NAME, EntryPoint = "aiv_vector_bubble")]
        internal static extern void BubbleSort(IntPtr ptr, AivComprator comparator);




    }
}
