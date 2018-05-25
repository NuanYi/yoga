#pragma once

#include <nan.h>
#include <YGNode.h>
#include <Yoga.h>

namespace yoga {
    
    class Node: public Nan::ObjectWrap {
    public:
        static NAN_MODULE_INIT(Init);
        
        static NAN_METHOD(New);
        static NAN_METHOD(Create);
        static NAN_METHOD(setWidth);
        static NAN_METHOD(setHeight);
        
        static NAN_METHOD(setJustifyContent);
        
    private:
        YGNodeRef mNode;
        
        
        Node();
        virtual ~Node();
        
        static inline Nan::Persistent<v8::Function> & constructor() {
            static Nan::Persistent<v8::Function> my_constructor;
            return my_constructor;
        }
    };
    
}
