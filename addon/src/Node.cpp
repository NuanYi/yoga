#include "Node.h"
#include "NanChecker.h"

namespace yoga {
    
    typedef v8::Local<v8::FunctionTemplate> FunctionTemplate;
    
    Node::Node(): mNode(nullptr) {
        mNode = YGNodeNew();
        YGNodeSetContext(mNode, reinterpret_cast<void*>(this));
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

    NAN_METHOD(Node::setPositionType) {
        Nan::HandleScope();
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());

        NanCheckArguments(info).argumentsCount(1)
        .argument(0).stringEnum<int>({
            {"abslout", YGPositionTypeAbsolute},
            {"relative", YGPositionTypeRelative}
        }).bind([node](int value) -> void {
            YGNodeStyleSetPositionType(node->node(), static_cast<YGPositionType>(value));
        })
        .check();
    }

    NAN_METHOD(Node::setPosition) {
        Nan::HandleScope();
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());

        int edge;
        double position;
        NanCheckArguments(info).argumentsCount(2)
        .argument(0)
        .stringEnum<int>({
            {"left", YGEdgeLeft},
            {"right", YGEdgeRight},
            {"top", YGEdgeTop},
            {"bottom", YGEdgeBottom},
            {"start", YGEdgeStart},
            {"end", YGEdgeEnd},
            {"horizontal", YGEdgeHorizontal},
            {"vertical", YGEdgeVertical},
            {"all", YGEdgeAll}
        })
        .bind(edge)
        .argument(1)
        .bind(position)
        .check();

        YGNodeStyleSetPosition(node->node(), static_cast<YGEdge>(edge), position);
    }

    NAN_METHOD(Node::setPositionPercent) {
        Nan::HandleScope();
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());

        int edge;
        double position;
        NanCheckArguments(info).argumentsCount(2)
        .argument(0)
        .stringEnum<int>({
            {"left", YGEdgeLeft},
            {"right", YGEdgeRight},
            {"top", YGEdgeTop},
            {"bottom", YGEdgeBottom},
            {"start", YGEdgeStart},
            {"end", YGEdgeEnd},
            {"horizontal", YGEdgeHorizontal},
            {"vertical", YGEdgeVertical},
            {"all", YGEdgeAll}
        })
        .bind(edge)
        .argument(1)
        .bind(position)
        .check();

        YGNodeStyleSetPositionPercent(node->node(), static_cast<YGEdge>(edge), position);
    }

    NAN_METHOD(Node::setAlignContent) {
        Nan::HandleScope();
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());

        int alignContent;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0).stringEnum<int>({
            {"auto", YGAlignAuto},
            {"flex-start", YGAlignFlexStart},
            {"center", YGAlignCenter},
            {"flex-end", YGAlignFlexEnd},
            {"stretch", YGAlignStretch},
            {"baseline", YGAlignBaseline},
            {"space-between", YGAlignSpaceBetween},
            {"space-around", YGAlignSpaceAround}
        })
        .bind(alignContent)
        .check();

        YGNodeStyleSetAlignContent(node->node(), static_cast<YGAlign>(alignContent));
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
        .argument(0).stringEnum<int>({
            { "center", YGJustifyCenter },
            { "flex-start", YGJustifyFlexStart },
            { "flex-end", YGJustifyFlexEnd },
            { "space-between", YGJustifySpaceBetween },
            { "space-around", YGJustifySpaceAround }
        })
        .bind([node](int value) -> void{
            YGNodeStyleSetJustifyContent(node->node(), static_cast<YGJustify>(value));
        })
        .check();
    }
}
