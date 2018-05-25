#pragma once

#include <nan.h>
#include <initializer_list>
#include <string>
#include <functional>
#include <map>

namespace yoga {
    
    typedef std::function<bool(Nan::NAN_METHOD_ARGS_TYPE)> InitFunction;
    
    
    // util function
    bool ToMaybeNative(v8::Local<v8::Value> value, bool& outVal);
    bool ToMaybeNative(v8::Local<v8::Value> value, int& outVal);
    bool ToMaybeNative(v8::Local<v8::Value> value, float& outVal);
    bool ToMaybeNative(v8::Local<v8::Value> value, std::string& outValue);
    
    
    class ArgumentMismatchException {
    public:
        ArgumentMismatchException(const std::string& msg);
        explicit ArgumentMismatchException(int actual, int expected);
        ArgumentMismatchException(int arctual, const std::initializer_list<int>& expected);
        virtual ~ArgumentMismatchException() {}
        
        virtual const char* what() const;
        
    protected:
        std::string mMessage;
    };
    
    class NanMethodArgBinding;
    class NanCheckArguments;
    
    template <typename EnumType>
    class NanArgStringEnum;
    
    
    
    class NanCheckArguments {
    public:
        NanCheckArguments(Nan::NAN_METHOD_ARGS_TYPE args);
        
        NanCheckArguments& argumentsCount(int count);
        NanCheckArguments& argumentsCount(int argsCount1, int argsCount2);
        
        NanMethodArgBinding argument(int index);
     
        operator bool() const;
        NanCheckArguments& addAndClause(InitFunction rightCondition);
        NanCheckArguments& error(std::string* error);
        
    protected:
        Nan::NAN_METHOD_ARGS_TYPE mArgs;
        InitFunction mInit;
        std::string* mError;
    };
    
    
    template<typename EnumType>
    class NanArgStringEnum {
    public:
        explicit NanArgStringEnum(std::initializer_list<std::pair<const char*, EnumType>> possibleValues, NanMethodArgBinding& owner, int argIndex)
        : mPossibleValues(possibleValues.begin(), possibleValues.end())
        , mOwner(owner)
        , mArgIndex(argIndex)
        {
            
        }
        
        NanCheckArguments& bind(EnumType& value);
    protected:
        
        bool TryMatchStringEnum(const std::string& key, EnumType& outValue) const;
        
    protected:
        std::map<std::string, EnumType> mPossibleValues;
        NanMethodArgBinding& mOwner;
        int mArgIndex;
    };
    
    
    class NanMethodArgBinding {
    public:
        template<typename EnumType>
        friend class NanArgStringEnum;
        
        NanMethodArgBinding(int index, NanCheckArguments& parent);
        
        NanMethodArgBinding& isBuffer();
        NanMethodArgBinding& isFunction();
        NanMethodArgBinding& isString();
        NanMethodArgBinding& NotNull();
        NanMethodArgBinding& isArray();
        
        template <typename T>
        NanArgStringEnum<T> stringEnum(std::initializer_list<std::pair<const char*, T>> possibleValues) {
            return std::move(NanArgStringEnum<T>(possibleValues, isString(), mArgIndex));
        }
        
        template <typename T>
        NanCheckArguments& bind(v8::Local<T>& value) {
            
            return mParent.addAndClause([this, &value](Nan::NAN_METHOD_ARGS_TYPE args) -> bool {
                value = args[mArgIndex].As<T>();
                return true;
            });
        }
        
        
        template <typename T>
        NanCheckArguments& bind(T& value) {
            return mParent.addAndClause([this, &value](Nan::NAN_METHOD_ARGS_TYPE args) -> bool {
                return ToMaybeNative(args[mArgIndex], value);
            });
        }
        
        template <typename T1, typename T2>
        NanCheckArguments& bind(T1& value1, T2& value2) {
            return mParent.addAndClause([this, &value1, &value2](Nan::NAN_METHOD_ARGS_TYPE args) -> bool{
                return ToMaybeNative(args[mArgIndex], value1) || ToMaybeNative(args[mArgIndex], value2);
            });
        }
        
    private:
        int mArgIndex;
        NanCheckArguments& mParent;
    };
    
    
    NanCheckArguments NanCheck(Nan::NAN_METHOD_ARGS_TYPE args);
    
    ///////////////////////////////////////////////////////////////////
    // Template functions implementation
    
    
    template <typename T>
    NanCheckArguments& NanArgStringEnum<T>::bind(T &value) {
        
        return mOwner.mParent.addAndClause([this, &value](Nan::NAN_METHOD_ARGS_TYPE args) -> bool {
            std::string key;
            return ToMaybeNative(args[mArgIndex], key) || TryMatchStringEnum(key, value);
        });
    }
    
    template <typename T>
    bool NanArgStringEnum<T>::TryMatchStringEnum(const std::string &key, T &outValue) const {
        
        auto it = mPossibleValues.find(key.c_str());
        if (it != mPossibleValues.end()) {
            outValue = static_cast<const char*>(it->second);
            return true;
        }
        
        return false;
    }
}
