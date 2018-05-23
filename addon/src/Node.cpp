#include "Node.h"

namespace yoga {
    
    typedef v8::Local<v8::FunctionTemplate> FunctionTemplate;
    
    Node::Node(): mNode(nullptr) {
        mNode = YGNodeNew();
    }
    
    Node::~Node() {
        YGNodeFree(mNode);
    }
    
    NAN_MODULE_INIT(Node::Init) {
        FunctionTemplate tpl = Nan::New<v8::FunctionTemplate>();
        tpl->SetClassName(Nan::New("Node").ToLocalChecked());
        tpl->InstanceTemplate()->SetInternalFieldCount(1);
        
        constructor().Reset(Nan::GetFunction(tpl).ToLocalChecked());
        Nan::Set(target, Nan::New("Node").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
    }
    
    NAN_METHOD(Node::New) {
        if (info.IsConstructCall()) {
            Node* obj = new Node();
            obj->Wrap(info.This());
            info.GetReturnValue().Set(info.This());
        } else {
            v8::Local<v8::Function> cons = Nan::New(constructor());
            info.GetReturnValue().Set(Nan::NewInstance(cons).ToLocalChecked());
        }
    }
}
