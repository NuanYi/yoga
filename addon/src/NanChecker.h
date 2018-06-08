#pragma once

#include <nan.h>
#include <initializer_list>
#include <string>
#include <functional>
#include <map>
#include <vector>
#include <sstream>

namespace yoga {
    
    typedef std::function<bool(Nan::NAN_METHOD_ARGS_TYPE)> InitFunction;
    typedef std::function<void(const std::string& msg)> ErrorCallback;
    
    
    // util function
    bool ToMaybeNative(v8::Local<v8::Value> value, bool& outVal);
    bool ToMaybeNative(v8::Local<v8::Value> value, int& outVal);
    bool ToMaybeNative(v8::Local<v8::Value> value, float& outVal);
    bool ToMaybeNative(v8::Local<v8::Value> value, double& outVal);
    bool ToMaybeNative(v8::Local<v8::Value> value, std::string& outValue);
    
    
    class NanMethodArgBinding;
    class NanCheckArguments;
    
    template <typename EnumType>
    class NanArgStringEnum;
    
    
    
    class NanCheckArguments {
    public:
        NanCheckArguments(Nan::NAN_METHOD_ARGS_TYPE args);
        NanCheckArguments(Nan::NAN_METHOD_ARGS_TYPE args, ErrorCallback onError);
        
        NanCheckArguments& argumentsCount(int count);
        NanCheckArguments& argumentsCount(int argsCount1, int argsCount2);
        
        NanMethodArgBinding argument(int index);
     
        operator bool() const;
        
        bool check();
        
        NanCheckArguments& addAndClause(InitFunction rightCondition);
        
    protected:
        Nan::NAN_METHOD_ARGS_TYPE mArgs;
        InitFunction mInit;
        ErrorCallback mErrorCallback;
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
        
        NanCheckArguments& bind(std::function<void(EnumType value)> callback);
        
    protected:
        
        bool TryMatchStringEnum(const std::string& key, EnumType& outValue) const;
        
    protected:
        std::map<std::string, EnumType> mPossibleValues;
        NanMethodArgBinding& mOwner;
        int mArgIndex;
    };
    
    template <typename EnumType>
    class NanArgNumberEnum {
    public:
        explicit NanArgNumberEnum(std::initializer_list<EnumType> possibleValues, NanMethodArgBinding& owner, int argindex)
        : mPossibleValues(possibleValues.begin(), possibleValues.end())
        , mOwner(owner)
        , mArgIndex(argindex)
        {
            
        }
        NanCheckArguments& bind(EnumType& value);
        
    protected:
        bool TryMatchNumberEnum(const EnumType& value, EnumType& outValue) const;
        
    protected:
        std::vector<EnumType> mPossibleValues;
        NanMethodArgBinding& mOwner;
        int mArgIndex;
    };
    
    
    class NanMethodArgBinding {
    public:
        template<typename EnumType>
        friend class NanArgStringEnum;
        template<typename T>
        friend class NanArgNumberEnum;
        
        NanMethodArgBinding(int index, NanCheckArguments& parent);
        
        NanMethodArgBinding& isBuffer();
        NanMethodArgBinding& isFunction();
        NanMethodArgBinding& isString();
        NanMethodArgBinding& NotNull();
        NanMethodArgBinding& isArray();
        
        NanMethodArgBinding& customCheck(std::function<bool(const v8::Local<v8::Value>&, std::string& msg)> callback);
        
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
        
        template <typename T>
        NanCheckArguments& bind(std::function<void(T value)> callback) {
            return mParent.addAndClause([this, callback](Nan::NAN_METHOD_ARGS_TYPE args) -> bool{
                T temp;
                bool ret = ToMaybeNative(args[mArgIndex], temp);
                if (ret) {
                    callback(temp);
                }
                return ret;
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
            return ToMaybeNative(args[mArgIndex], key) && TryMatchStringEnum(key, value);
        });
    }
    
    template <typename T>
    NanCheckArguments& NanArgStringEnum<T>::bind(std::function<void(T value)> callback){
        return mOwner.mParent.addAndClause([this, callback](Nan::NAN_METHOD_ARGS_TYPE args) -> bool{
            std::string key;
            bool ret = ToMaybeNative(args[mArgIndex], key);
            if (ret) {
                T temp;
                ret = this->TryMatchStringEnum(key, temp);
                if (ret)
                    callback(temp);
            }
            return ret;
        });
    }
    
    template <typename T>
    bool NanArgStringEnum<T>::TryMatchStringEnum(const std::string &key, T &outValue) const {
        
        auto it = mPossibleValues.find(key.c_str());
        if (it != mPossibleValues.end()) {
            outValue = static_cast<T>(it->second);
            return true;
        }
        
        std::ostringstream stringStream;
        stringStream<<"param at "<<mArgIndex<<"shoud be a string enum which is a flex justfy content value";
        std::string msg = stringStream.str();
        Nan::ThrowError(msg.c_str());
        
        return false;
    }
    
    
    template <typename T>
    NanCheckArguments& NanArgNumberEnum<T>::bind(T &value) {
        
        return mOwner.mParent.addAndClause([this, &value](Nan::NAN_METHOD_ARGS_TYPE args) -> bool {
            
            return ToMaybeNative(args[mArgIndex], value);
        });
    }
    
    template <typename T>
    bool NanArgNumberEnum<T>::TryMatchNumberEnum(const T &value, T &outValue) const {
        for(T it : mPossibleValues) {
            if (it == value) {
                outValue = it;
                return true;
            }
        }
        return false;
    }
}
