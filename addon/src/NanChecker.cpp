#include "NanChecker.h"


namespace yoga {
    
    bool ToMaybeNative(v8::Local<v8::Value> value, bool& outVal) {
        
        if (!value->IsBoolean()) {
            Nan::ThrowError("value should be a boolean!");
            return false;
        }
        
        auto maybe = Nan::To<bool>(value);
        outVal = maybe.FromJust();
        return true;
    }
    
    bool ToMaybeNative(v8::Local<v8::Value> value, int& outVal) {
        if (!value->IsInt32()) {
            Nan::ThrowError("value should be a float!");
            return false;
        }
        auto maybe = Nan::To<int>(value);
        outVal = maybe.FromJust();
        return true;
    }
    
    bool ToMaybeNative(v8::Local<v8::Value> value, float& outVal) {
        if (!value->IsNumber()) {
            Nan::ThrowError("value should be a float!");
            return false;
        }
        
        auto maybe = Nan::To<double>(value);
        outVal = static_cast<float>(maybe.FromJust());
        return true;
    }
    
    bool ToMaybeNative(v8::Local<v8::Value> value, double& outVal) {
        if (!value->IsNumber()) {
            Nan::ThrowError("value should be a float or double!");
            return false;
        }
        
        auto maybe = Nan::To<double>(value);
        outVal = maybe.FromJust();
        return true;
    }
    
    bool ToMaybeNative(v8::Local<v8::Value> value, std::string& outValue) {
        if (!value->IsString() && !value->IsStringObject()) {
            Nan::ThrowError("value check to String type failed!");
            return false;
        }
        auto maybe = Nan::To<v8::String>(value);
        
        v8::String::Utf8Value v(maybe.ToLocalChecked());
        outValue = std::string(*v);
        return true;
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
                return false;
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
                return false;
            }
            return true;
        });
        
        return *this;
    }
    
    NanMethodArgBinding& NanMethodArgBinding::isArray() {
        
        mParent.addAndClause([this](Nan::NAN_METHOD_ARGS_TYPE args) -> bool {
            bool isArray = args[mArgIndex]->IsArray();
            
            if (!isArray) {
                std::ostringstream stringStream;
                stringStream<<"Argument "<<mArgIndex<<" violates isArray check";
                std::string msg = stringStream.str();
                Nan::ThrowError(msg.c_str());
                return false;
            }
            
            return true;
        });
        
        return *this;
    }
    
    NanMethodArgBinding& NanMethodArgBinding::isString() {
        
        mParent.addAndClause([this](Nan::NAN_METHOD_ARGS_TYPE args) -> bool {
            bool isStr = args[mArgIndex]->IsString() || args[mArgIndex]->IsStringObject();
            
            if (!isStr) {
                std::ostringstream stringStream;
                stringStream<<"Argument "<<mArgIndex<<" violates isString check";
                std::string msg = stringStream.str();
                Nan::ThrowError(msg.c_str());
                return false;
            }
            return true;
        });
        
        return *this;
    }
    
    NanMethodArgBinding& NanMethodArgBinding::customCheck(std::function<bool(const v8::Local<v8::Value>&, std::string&)> callback) {
        
        mParent.addAndClause([this, callback](Nan::NAN_METHOD_ARGS_TYPE args) -> bool {
            std::string msg;
            bool checkresult = callback(args[mArgIndex], msg);
            if (!checkresult) {
                std::ostringstream stringStream;
                Nan::ThrowError(msg.c_str());
                return false;
            }
            return true;
        });
        
        return *this;
    }
    
    NanMethodArgBinding& NanMethodArgBinding::NotNull() {
        
        mParent.addAndClause([this](Nan::NAN_METHOD_ARGS_TYPE args) -> bool{
            if (args[mArgIndex]->IsNull()) {
                std::ostringstream stringStream;
                stringStream<<"Argument "<<mArgIndex<<" violates NotNull check";
                std::string msg = stringStream.str();
                Nan::ThrowError(msg.c_str());
                return false;
            }
            
            return true;
        });
        
        return *this;
    }
    
    NanCheckArguments::NanCheckArguments(Nan::NAN_METHOD_ARGS_TYPE args)
    : mArgs(args)
    , mInit([](Nan::NAN_METHOD_ARGS_TYPE) -> bool{ return true;})
    , mErrorCallback([](const std::string& msg) {})
    {
        
    }
    
    NanCheckArguments::NanCheckArguments(Nan::NAN_METHOD_ARGS_TYPE args, ErrorCallback onError)
    : mArgs(args)
    , mInit([](Nan::NAN_METHOD_ARGS_TYPE) -> bool{ return true;})
    , mErrorCallback(onError)
    {
    }
    
    NanCheckArguments& NanCheckArguments::argumentsCount(int count) {
        
        return addAndClause([count](Nan::NAN_METHOD_ARGS_TYPE args) -> bool {
            if (args.Length() != count) {
                std::ostringstream stringStream;
                stringStream<<"Invalid number of arguments passed to a function which expect "<<count<<" arguments"<<" but actual pass "<<args.Length();
                std::string msg = stringStream.str();
                Nan::ThrowError(msg.c_str());
                return false;
            }
            return true;
        });
    }
    
    NanMethodArgBinding NanCheckArguments::argument(int index) {
        return NanMethodArgBinding(index, *this);
    }
    
    NanCheckArguments::operator bool() const {
        return mInit(mArgs);
    }
    
    bool NanCheckArguments::check() {
        return mInit(mArgs);
    }
    
    NanCheckArguments& NanCheckArguments::addAndClause(InitFunction rightCondition) {
        InitFunction prevInit = mInit;
        InitFunction newInit = [prevInit, rightCondition](Nan::NAN_METHOD_ARGS_TYPE args) -> bool{
            return prevInit(args) && rightCondition(args);
        };
        mInit = newInit;
        
        return *this;
    }
    
    NanCheckArguments NanCheck(Nan::NAN_METHOD_ARGS_TYPE args) {
        
        return NanCheckArguments(args);
    }
}
