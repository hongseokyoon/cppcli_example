// LibAdderCS.h

#pragma once

#include <vector>
#include "../LibAdder/Adder.h"
using namespace System;
using namespace System::Runtime::InteropServices;

#pragma comment(lib, "../Debug/LibAdder.lib")

namespace LibAdderCS {
    
	public ref class AdderCS
	{
    public:
		delegate void Callback();

        AdderCS(Callback^ callback)            
            : _callback(nullptr)
        {
            _callback = callback;
            GCHandle callbackHandle = GCHandle::Alloc(_callback);
            IntPtr ptr = Marshal::GetFunctionPointerForDelegate(_callback);

           _adr = new Adder(static_cast<Adder::callback_t>(ptr.ToPointer()));
        }

        ~AdderCS()
        {
            delete _adr;
        }

        int Do(int a, int b, String^ msg)
        {
            char* native_msg = (char*)Marshal::StringToHGlobalAnsi(msg).ToPointer();
            int ret = _adr->Do(a, b, native_msg);
            Marshal::FreeHGlobal(IntPtr(native_msg));

            return ret;
        }

        int Do(array<int>^ v, String^ msg)
        {
            std::vector<int> _v;

            for (int i = 0; i < v->Length; ++i)
            {
                _v.push_back(v[i]);
            }

            char* native_msg = (char*)Marshal::StringToHGlobalAnsi(msg).ToPointer();
            int ret = _adr->Do(_v, native_msg);
            Marshal::FreeHGlobal(IntPtr(native_msg));

            return ret;
        }

    private:        
        Callback^ _callback;
        Adder* _adr;
	};
    
    void MyCallback()
    {
    }

    void MyCallback2(void* adr2)
    {
    }
}
