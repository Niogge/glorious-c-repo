using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CsharpWrapper
{
    class AivVector<T> : IDisposable
    {
        IntPtr Handle;
        public bool IsEmpty { get { return AivVectorNative.IsEmpty(Handle); } }
        public AivVector()
        {
            Handle = AivVectorNative.Create();
        }

        ~AivVector()
        {
            Dispose();
        }
        public void Dispose()
        {
            if (Handle == IntPtr.Zero) return;

            for (uint i = 0; i < Count(); i++)
            {
                IntPtr valptr = AivVectorNative.At(Handle, i);
                GCHandle.FromIntPtr(valptr).Free();
            }
            AivVectorNative.Destroy(Handle);
            Handle = IntPtr.Zero;

            GC.SuppressFinalize(this);
        }
        public int Count()
        {
            return AivVectorNative.Count(Handle);
        }
        public void Add(T elem)
        {
            GCHandle itemH = GCHandle.Alloc(elem);
            IntPtr item = GCHandle.ToIntPtr(itemH);
            AivVectorNative.Add(Handle, item);

        }

        public T At(int index)
        {
            IntPtr valptr = AivVectorNative.At(Handle, (uint)index);
            GCHandle handle = GCHandle.FromIntPtr(valptr);
            return (T)handle.Target;
        }

        public void ForEach(Action<T> doAction)
        {
            AivVectorNative.AivAction actPtr = (ptr) =>
            {
                GCHandle gch = (GCHandle)ptr;

                doAction((T)gch.Target);
            };
            AivVectorNative.ForEach(Handle, actPtr);
        }
        public void BubbleSort()
        {
           
            
            AivVectorNative.AivComprator comp = (ptr1, ptr2)=>
            {
                GCHandle gch1 = (GCHandle)ptr1;
                GCHandle gch2 = (GCHandle)ptr2;

                int val1 = (int)gch1.Target;
                int val2 = (int)gch2.Target;
                if (val1 < val2) return -1;
                if (val2 < val1) return 1;
                return 0;
            };
            AivVectorNative.BubbleSort(Handle, comp);
        }
    }
}
