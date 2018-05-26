#include "Node.h"
#include "NanChecker.h"

namespace yoga {
    
    typedef v8::Local<v8::FunctionTemplate> FunctionTemplate;
    
    Node::Node(): mNode(nullptr) {
        mNode = YGNodeNew();
    }
    
    Node::~Node() {
        YGNodeFree(mNode);
    }
    
    NAN_MODULE_INIT(Node::Init) {
        FunctionTemplate tpl = Nan::New<v8::FunctionTemplate>(New);
        tpl->SetClassName(Nan::New("Node").ToLocalChecked());
        tpl->InstanceTemplate()->SetInternalFieldCount(1);
        
        Nan::SetPrototypeMethod(tpl, "setWidth", setWidth);
        Nan::SetPrototypeMethod(tpl, "setHeight", setHeight);
        Nan::SetPrototypeMethod(tpl, "setJustifyContent", setJustifyContent);
        
        Nan::SetPrototypeMethod(tpl, "getWidth", getWidth);
        
        Nan::SetMethod(tpl, "Create", Create);
        
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

    NAN_METHOD(Node::Create) {

        auto cons = Nan::New(constructor());
        info.GetReturnValue().Set(Nan::NewInstance(cons).ToLocalChecked());
    }

    NAN_METHOD(Node::setHeight) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        NanCheckArguments(info).argumentsCount(1)
        .argument(0).bind<int>([node](int value) -> void{
            YGNodeStyleSetHeight(node->node(), value);
        })
        .check();
    }
    
    NAN_METHOD(Node::setWidth) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        NanCheckArguments(info).argumentsCount(1)
        .argument(0).bind<int>([node](int value) -> void{
            YGNodeStyleSetWidth(node->node(), value);
        })
        .check();
    }
    
    NAN_METHOD(Node::getWidth) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        YGValue value = YGNodeStyleGetWidth(node->node());
        if (value.unit == YGUnitUndefined || value.unit == YGUnitAuto) {
            info.GetReturnValue().Set(Nan::Undefined());
        } else {
            info.GetReturnValue().Set(value.value);
        }
        
    }
    
    NAN_METHOD(Node::setJustifyContent) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        NanCheckArguments(info).argumentsCount(1)
        .argument(0).customCheck([](const v8::Local<v8::Value>& value, std::string& msg) -> bool{
            int temp;
            bool castRet = ToMaybeNative(value, temp);
            if (castRet) {
                if (temp >= YGJustifyFlexStart && temp <= YGJustifySpaceEvenly) {
                    return true;
                } else {
                    msg = "argument at 1 should be One of Node.Justfy value";
                    return false;
                }
            } else {
                msg = "argument at 1 should be One of Node.Justfy value";
                return false;
            }
        }).bind<int>([node](int value) -> void{
            YGNodeStyleSetJustifyContent(node->node(), static_cast<YGJustify>(value));
        })
        .check();
    }
}
