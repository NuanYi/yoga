#include "NanChecker.h"
#include <sstream>

namespace yoga {
    
    ArgumentMismatchException::ArgumentMismatchException(const std::string& msg)
    : mMessage(msg)
    {
        
    }
    
    
    ArgumentMismatchException::ArgumentMismatchException(int actual, int expected)
    : mMessage("Invalid number of arguments passed to a function")
    {
        
    }
    
    ArgumentMismatchException::ArgumentMismatchException(int arctual, const std::initializer_list<int>& expected)
    : mMessage("Invalid number of arguments passed to a function")
    {
        
    }
    
    NanMethodArgBinding::NanMethodArgBinding(int index, NanCheckArguments& parent)
    : mArgIndex(index)
    , mParent(parent)
    {
        
    }
    
    NanMethodArgBinding& NanMethodArgBinding::isBuffer() {
        auto bind = [this](Nan::NAN_METHOD_ARGS_TYPE args) -> bool{
            bool isBuf = node::Buffer::HasInstance(args[mArgIndex]);
            
            if (!isBuf) {
                std::ostringstream stringStream;
                stringStream<<"Argument "<<mArgIndex<<" violates isBuffer check";
                std::string msg = stringStream.str();
                Nan::ThrowError(msg.c_str());
            }
            return true;
        };
        
        mParent.addAndClause(bind);
        return *this;
    }
    
    NanMethodArgBinding& NanMethodArgBinding::isFunction() {
        
        mParent.addAndClause([this](Nan::NAN_METHOD_ARGS_TYPE args) -> bool{
            bool isFn = args[mArgIndex]->IsFunction();
            if (!isFn) {
                std::ostringstream stringStream;
                stringStream<<"Argument "<<mArgIndex<<" violates isFunction check";
                std::string msg = stringStream.str();
                Nan::ThrowError(msg.c_str());
            }
        });
        
        return *this;
    }
    
}
