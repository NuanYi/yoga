#include "Node.h"
#include "NanChecker.h"

namespace yoga {
    
    typedef v8::Local<v8::FunctionTemplate> FunctionTemplate;
    
    Node::Node(): mNode(nullptr) {
        mNode = YGNodeNew();
        
        YGNodeStyleSetWidthAuto(mNode);
        YGNodeStyleSetHeightAuto(mNode);
        YGNodeSetContext(mNode, reinterpret_cast<void*>(this));
    }
    
    Node::~Node() {
        YGNodeFree(mNode);
    }
    
    NAN_MODULE_INIT(Node::Init) {
        FunctionTemplate tpl = Nan::New<v8::FunctionTemplate>(New);
        tpl->SetClassName(Nan::New("Node").ToLocalChecked());
        tpl->InstanceTemplate()->SetInternalFieldCount(1);
        
        Nan::SetPrototypeMethod(tpl, "setPositionType", setPositionType);
        Nan::SetPrototypeMethod(tpl, "setPosition", setPosition);
        Nan::SetPrototypeMethod(tpl, "setPositionPercent", setPositionPercent);

        Nan::SetPrototypeMethod(tpl, "setAlignContent", setAlignContent);
        Nan::SetPrototypeMethod(tpl, "setAlignItems", setAlignItems);
        Nan::SetPrototypeMethod(tpl, "setAlignSelf", setAlignSelf);
        Nan::SetPrototypeMethod(tpl, "setFlexDirection", setFlexDirection);
        Nan::SetPrototypeMethod(tpl, "setFlexWrap", setFlexWrap);
        Nan::SetPrototypeMethod(tpl, "setJustifyContent", setJustifyContent);

        Nan::SetPrototypeMethod(tpl, "setMargin", setMargin);
        Nan::SetPrototypeMethod(tpl, "setMarginPercent", setMarginPercent);
        Nan::SetPrototypeMethod(tpl, "setMarginAuto", setMarginAuto);
        
        Nan::SetPrototypeMethod(tpl, "setOverflow", setOverflow);
        Nan::SetPrototypeMethod(tpl, "setDisplay", setDisplay);
        
        Nan::SetPrototypeMethod(tpl, "setFlex", setFlex);
        Nan::SetPrototypeMethod(tpl, "setFlexBasis", setFlexBasis);
        Nan::SetPrototypeMethod(tpl, "setFlexBasisPercent", setFlexBasisPercent);
        Nan::SetPrototypeMethod(tpl, "setFlexBasisAuto", setFlexBasisAuto);
        Nan::SetPrototypeMethod(tpl, "setFlexGrow", setFlexGrow);
        Nan::SetPrototypeMethod(tpl, "setFlexShrink", setFlexShrink);
        
        Nan::SetPrototypeMethod(tpl, "setWidth", setWidth);
        Nan::SetPrototypeMethod(tpl, "setWidthPercent", setWidthPercent);
        Nan::SetPrototypeMethod(tpl, "setWidthAuto", setWidthAuto);
        Nan::SetPrototypeMethod(tpl, "setHeight", setHeight);
        Nan::SetPrototypeMethod(tpl, "setHeightPercent", setHeightPercent);
        Nan::SetPrototypeMethod(tpl, "setHeightAuto", setHeightAuto);
        
        Nan::SetPrototypeMethod(tpl, "setMinWidth", setMinWidth);
        Nan::SetPrototypeMethod(tpl, "setMinWidthPercent", setMinWidthPercent);
        Nan::SetPrototypeMethod(tpl, "setMinHeight", setMinHeight);
        Nan::SetPrototypeMethod(tpl, "setMinHeightPercent", setMinHeightPercent);
        
        Nan::SetPrototypeMethod(tpl, "setMaxWidth", setMaxWidth);
        Nan::SetPrototypeMethod(tpl, "setMaxWidthPercent", setMinWidthPercent);
        Nan::SetPrototypeMethod(tpl, "setMaxHeight", setMaxHeight);
        Nan::SetPrototypeMethod(tpl, "setMaxHeightPercent", setMaxHeightPercent);
        
        Nan::SetPrototypeMethod(tpl, "setAspectRatio", setAspectRatio);
        
        Nan::SetPrototypeMethod(tpl, "setBorder", setBorder);
        Nan::SetPrototypeMethod(tpl, "setPadding", setPadding);
        Nan::SetPrototypeMethod(tpl, "setPaddingPercent", setPaddingPercent);
        
        Nan::SetPrototypeMethod(tpl, "getPositionType", getPositionType);
        Nan::SetPrototypeMethod(tpl, "getPosition", getPosition);
        
        Nan::SetPrototypeMethod(tpl, "getAlignContent", getAlignContent);
        Nan::SetPrototypeMethod(tpl, "getAlignItems", getAlignItems);
        Nan::SetPrototypeMethod(tpl, "getAlignSelf", getAlignSelf);
        Nan::SetPrototypeMethod(tpl, "getFlexDirection", getFlexDirection);
        Nan::SetPrototypeMethod(tpl, "getFlexWrap", getFlexWrap);
        Nan::SetPrototypeMethod(tpl, "getJustifyContent", getJustifyContent);
        Nan::SetPrototypeMethod(tpl, "getMargin", getMargin);
        Nan::SetPrototypeMethod(tpl, "getOverflow", getOverflow);
        Nan::SetPrototypeMethod(tpl, "getDisplay", getDisplay);
        Nan::SetPrototypeMethod(tpl, "getFlexBasis", getFlexBasis);
        Nan::SetPrototypeMethod(tpl, "getFlexGrow", getFlexGrow);
        Nan::SetPrototypeMethod(tpl, "getFlexShrink", getFlexShrink);
        
        Nan::SetPrototypeMethod(tpl, "getWidth", getWidth);
        Nan::SetPrototypeMethod(tpl, "getHeight", getHeight);
        
        Nan::SetPrototypeMethod(tpl, "getMinWidth", getMinWidth);
        Nan::SetPrototypeMethod(tpl, "getMinHeight", getMinHeight);
        
        Nan::SetPrototypeMethod(tpl, "getMaxHeight", getMaxHeight);
        Nan::SetPrototypeMethod(tpl, "getMaxWidth", getMaxWidth);
        Nan::SetPrototypeMethod(tpl, "getAspectRatio", getAspectRatio);
        Nan::SetPrototypeMethod(tpl, "getBorder", getBorder);
        Nan::SetPrototypeMethod(tpl, "getPadding", getPadding);
        
        Nan::SetPrototypeMethod(tpl, "insertChild", insertChild);
        Nan::SetPrototypeMethod(tpl, "removeChild", removeChild);
        Nan::SetPrototypeMethod(tpl, "getParent", getParent);
        Nan::SetPrototypeMethod(tpl, "getChild", getChild);
        
        Nan::SetPrototypeMethod(tpl, "markDirty", markDirty);
        Nan::SetPrototypeMethod(tpl, "isDirty", isDirty);
        Nan::SetPrototypeMethod(tpl, "calculateLayout", calculateLayout);
        
        Nan::SetPrototypeMethod(tpl, "getComputedLeft", getComputedLeft);
        Nan::SetPrototypeMethod(tpl, "getComputedRight", getComputedRight);
        Nan::SetPrototypeMethod(tpl, "getComputedTop", getComputedTop);
        Nan::SetPrototypeMethod(tpl, "getComputedBottom", getComputedBottom);
        
        Nan::SetPrototypeMethod(tpl, "getComputedWidth", getComputedLeft);
        Nan::SetPrototypeMethod(tpl, "getComputedHeight", getComputedHeight);
        
        Nan::SetPrototypeMethod(tpl, "getComputedLayout", getComputedLayout);
        
        Nan::SetPrototypeMethod(tpl, "getComputedMargin", getComputedMargin);
        Nan::SetPrototypeMethod(tpl, "getComputedBorder", getComputedBorder);
        Nan::SetPrototypeMethod(tpl, "getComputedPadding", getComputedPadding);
        
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
    
    NAN_METHOD(Node::setAlignItems) {
        Nan::HandleScope();
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        int alignItems;
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
        .bind(alignItems)
        .check();
        
        YGNodeStyleSetAlignItems(node->node(), static_cast<YGAlign>(alignItems));
    }
    
    NAN_METHOD(Node::setAlignSelf) {
        Nan::HandleScope();
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        int alignSelf;
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
        .bind(alignSelf)
        .check();
        
        YGNodeStyleSetAlignSelf(node->node(), static_cast<YGAlign>(alignSelf));
    }
    
    NAN_METHOD(Node::setFlexDirection) {
        Nan::HandleScope();
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        int flexDirection;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .stringEnum<int>({
            {"column", YGFlexDirectionColumn},
            {"column-reverse", YGFlexDirectionColumnReverse},
            {"row", YGFlexDirectionRow},
            {"row-reverse", YGFlexDirectionRowReverse}
        }).bind(flexDirection)
        .check();
        
        YGNodeStyleSetFlexDirection(node->node(), static_cast<YGFlexDirection>(flexDirection));
    }
    
    NAN_METHOD(Node::setFlexWrap) {
        Nan::HandleScope();
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        int wrap;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .stringEnum<int>({
            {"none", YGWrapNoWrap},
            {"wrap", YGWrapWrap},
            {"wrap-reverse", YGWrapWrapReverse}
        }).bind(wrap)
        .check();
        
        YGNodeStyleSetFlexWrap(node->node(), static_cast<YGWrap>(wrap));
    }
    
    NAN_METHOD(Node::setJustifyContent) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        int justfyContent;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0).stringEnum<int>({
            { "center", YGJustifyCenter },
            { "flex-start", YGJustifyFlexStart },
            { "flex-end", YGJustifyFlexEnd },
            { "space-between", YGJustifySpaceBetween },
            { "space-around", YGJustifySpaceAround }
        }).bind(justfyContent)
        .check();
        
        YGNodeStyleSetJustifyContent(node->node(), static_cast<YGJustify>(justfyContent));
    }
    
    NAN_METHOD(Node::setMargin) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        int edge;
        double margin;
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
        }).bind(edge)
        .argument(1)
        .bind(margin)
        .check();
        
        YGNodeStyleSetMargin(node->node(), static_cast<YGEdge>(edge), margin);
    }
    
    NAN_METHOD(Node::setMarginPercent) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        int edge;
        double margin;
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
        }).bind(edge)
        .argument(1)
        .bind(margin)
        .check();
        
        YGNodeStyleSetMarginPercent(node->node(), static_cast<YGEdge>(edge), static_cast<float>(margin));
    }
    
    NAN_METHOD(Node::setMarginAuto) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        int edge = 0;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0).stringEnum<int>({
            {"left", YGEdgeLeft},
            {"right", YGEdgeRight},
            {"top", YGEdgeTop},
            {"bottom", YGEdgeBottom},
            {"end", YGEdgeEnd},
            {"start", YGEdgeStart},
            {"horizontal", YGEdgeHorizontal},
            {"vertical", YGEdgeVertical},
            {"all", YGEdgeAll}
        })
        .bind(edge)
        .check();
        
        YGNodeStyleSetMarginAuto(node->node(), static_cast<YGEdge>(edge));
    }

    NAN_METHOD(Node::setOverflow) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        int overflow;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .stringEnum<int>({
            {"visible", YGOverflowVisible},
            {"hidden", YGOverflowHidden},
            {"scroll", YGOverflowScroll}
        }).bind(overflow)
        .check();
        
        YGNodeStyleSetOverflow(node->node(),  static_cast<YGOverflow>(overflow));
    }
    
    NAN_METHOD(Node::setDisplay) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        int display;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .stringEnum<int>({
            {"flex", YGDisplayFlex},
            {"none", YGDisplayNone}
        }).bind(display)
        .check();
        
        YGNodeStyleSetDisplay(node->node(), static_cast<YGDisplay>(display));
    }
    
    NAN_METHOD(Node::setFlex) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        // Todo: To add flex arguments
        float flex;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(flex)
        .check();
        YGNodeStyleSetFlex(node->node(), flex);
    }
    
    NAN_METHOD(Node::setFlexBasis) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float basis;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(basis)
        .check();
        
        // Todo:
        YGNodeStyleSetFlexBasis(node->node(), basis);
    }

    NAN_METHOD(Node::setFlexBasisPercent) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float basis;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(basis)
        .check();
        
        // Todo:
        YGNodeStyleSetFlexBasisPercent(node->node(), basis);
    }

    NAN_METHOD(Node::setFlexBasisAuto) {
        Nan::HandleScope();

        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());

        YGNodeStyleSetFlexBasisAuto(node->node());
    }

    NAN_METHOD(Node::setFlexGrow) {
        Nan::HandleScope();

        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        float grow;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(grow)
        .check();

        YGNodeStyleSetFlexGrow(node->node(), grow);
    }

    NAN_METHOD(Node::setFlexShrink) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        // Todo:
        float shrink;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(shrink)
        .check();
        
        YGNodeStyleSetFlexShrink(node->node(), shrink);
    }
    
    NAN_METHOD(Node::setWidth) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float width;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(width)
        .check();
        
        YGNodeStyleSetWidth(node->node(), width);
    }
    
    NAN_METHOD(Node::setWidthPercent) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float width;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(width)
        .check();
        
        YGNodeStyleSetWidthPercent(node->node(), width);
    }
    
    NAN_METHOD(Node::setWidthAuto) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        YGNodeStyleSetWidthAuto(node->node());
    }

    NAN_METHOD(Node::setHeight) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float height;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(height)
        .check();
        
        YGNodeStyleSetHeight(node->node(), height);
    }
    
    NAN_METHOD(Node::setHeightPercent) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float height;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(height)
        .check();
        
        YGNodeStyleSetHeightPercent(node->node(), height);
    }
    
    NAN_METHOD(Node::setHeightAuto) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        YGNodeStyleSetHeightAuto(node->node());
    }
    
    NAN_METHOD(Node::setMinWidth) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float minWidth;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(minWidth)
        .check();
        
        YGNodeStyleSetMinWidth(node->node(), minWidth);
    }
    
    NAN_METHOD(Node::setMinWidthPercent) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float minWidth;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(minWidth)
        .check();
        
        YGNodeStyleSetMinWidthPercent(node->node(), minWidth);
    }
    
    NAN_METHOD(Node::setMinHeight) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float minHeight;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(minHeight)
        .check();
        
        YGNodeStyleSetMinHeight(node->node(), minHeight);
    }
    
    NAN_METHOD(Node::setMinHeightPercent) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float minHeight;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(minHeight)
        .check();
        
        YGNodeStyleSetMinHeight(node->node(), minHeight);
    }
    
    NAN_METHOD(Node::setMaxWidth) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float maxWidth;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(maxWidth)
        .check();
        
        YGNodeStyleSetMaxWidth(node->node(), maxWidth);
    }
    
    NAN_METHOD(Node::setMaxWidthPercent) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float maxWidth;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(maxWidth)
        .check();
        
        YGNodeStyleSetMaxWidth(node->node(), maxWidth);
    }
    
    NAN_METHOD(Node::setMaxHeight) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float maxHeight;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(maxHeight)
        .check();
        
        YGNodeStyleSetMaxHeight(node->node(), maxHeight);
    }
    
    NAN_METHOD(Node::setMaxHeightPercent) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float maxHeight;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(maxHeight)
        .check();
        
        YGNodeStyleSetMaxHeight(node->node(), maxHeight);
    }
    
    NAN_METHOD(Node::setAspectRatio) {
        Nan::HandleScope();

        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float aspectRatio;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0)
        .bind(aspectRatio)
        .check();

        YGNodeStyleSetAspectRatio(node->node(), aspectRatio);
    }
    
    NAN_METHOD(Node::setBorder) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        int edge;
        float border;
        NanCheckArguments(info).argumentsCount(2)
        .argument(0).stringEnum<int>({
            {"left", YGEdgeLeft},
            {"right", YGEdgeRight},
            {"top", YGEdgeTop},
            {"bottom", YGEdgeBottom},
            {"start", YGEdgeStart},
            {"end", YGEdgeEnd},
            {"horizontal", YGEdgeHorizontal},
            {"vertical", YGEdgeVertical},
            {"all", YGEdgeAll}
        }).bind(edge)
        .argument(1)
        .bind(border)
        .check();
        
        YGNodeStyleSetBorder(node->node(), static_cast<YGEdge>(edge), border);
    }
    
    NAN_METHOD(Node::setPadding) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        int edge;
        float padding;
        NanCheckArguments(info).argumentsCount(2)
        .argument(0).stringEnum<int>({
            {"left", YGEdgeLeft},
            {"right", YGEdgeRight},
            {"top", YGEdgeTop},
            {"bottom", YGEdgeBottom},
            {"start", YGEdgeStart},
            {"end", YGEdgeEnd},
            {"horizontal", YGEdgeHorizontal},
            {"vertical", YGEdgeVertical},
            {"all", YGEdgeAll}
        }).bind(edge)
        .argument(1)
        .bind(padding)
        .check();
        
        YGNodeStyleSetPadding(node->node(), static_cast<YGEdge>(edge), padding);
    }
    
    NAN_METHOD(Node::setPaddingPercent) {
        Nan::HandleScope();
        
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        int edge;
        float padding;
        NanCheckArguments(info).argumentsCount(2)
        .argument(0).stringEnum<int>({
            {"left", YGEdgeLeft},
            {"right", YGEdgeRight},
            {"top", YGEdgeTop},
            {"bottom", YGEdgeBottom},
            {"start", YGEdgeStart},
            {"end", YGEdgeEnd},
            {"horizontal", YGEdgeHorizontal},
            {"vertical", YGEdgeVertical},
            {"all", YGEdgeAll}
        }).bind(edge)
        .argument(1)
        .bind(padding)
        .check();
        
        YGNodeStyleSetPaddingPercent(node->node(), static_cast<YGEdge>(edge), padding);
    }
    
    /************* style getters ***************/
    NAN_METHOD(Node::getPositionType) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        YGPositionType type = YGNodeStyleGetPositionType(node->node());
        
        switch (type) {
            case YGPositionTypeAbsolute:
                info.GetReturnValue().Set(Nan::New("absolute").ToLocalChecked());
                break;
            case YGPositionTypeRelative:
                info.GetReturnValue().Set(Nan::New("relative").ToLocalChecked());
                break;
            default:
                info.GetReturnValue().Set(Nan::Undefined());
                break;
        }
    }
    
    NAN_METHOD(Node::getPosition) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        int edge;
        
        NanCheckArguments(info).argumentsCount(1)
        .argument(0).stringEnum<int>({
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
        .check();
        
        YGValue value =  YGNodeStyleGetPosition(node->node(), static_cast<YGEdge>(edge));
        
        switch (value.unit) {
            case YGUnitAuto:
                info.GetReturnValue().Set(Nan::New("auto").ToLocalChecked());
                break;
            default:
                info.GetReturnValue().Set(value.value);
                break;
        }
    }
    
    NAN_METHOD(Node::getAlignContent) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        YGAlign align = YGNodeStyleGetAlignContent(node->node());
        
        switch (align) {
            case YGAlignCenter:
                info.GetReturnValue().Set(Nan::New("center").ToLocalChecked());
                break;
            case YGAlignAuto:
                info.GetReturnValue().Set(Nan::New("auto").ToLocalChecked());
                break;
            case YGAlignFlexEnd:
                info.GetReturnValue().Set(Nan::New("flex-end").ToLocalChecked());
                break;
            case YGAlignStretch:
                info.GetReturnValue().Set(Nan::New("stretch").ToLocalChecked());
                break;
            case YGAlignBaseline:
                info.GetReturnValue().Set(Nan::New("baseline").ToLocalChecked());
                break;
            case YGAlignFlexStart:
                info.GetReturnValue().Set(Nan::New("flex-start").ToLocalChecked());
                break;
            case YGAlignSpaceAround:
                info.GetReturnValue().Set(Nan::New("space-around").ToLocalChecked());
                break;
            case YGAlignSpaceBetween:
                info.GetReturnValue().Set(Nan::New("space-between").ToLocalChecked());
                break;
            default:
                info.GetReturnValue().Set(Nan::Undefined());
                break;
        }
    }
    
    NAN_METHOD(Node::getAlignItems) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        YGAlign align = YGNodeStyleGetAlignItems(node->node());
        
        switch (align) {
            case YGAlignCenter:
                info.GetReturnValue().Set(Nan::New("center").ToLocalChecked());
                break;
            case YGAlignAuto:
                info.GetReturnValue().Set(Nan::New("auto").ToLocalChecked());
                break;
            case YGAlignFlexEnd:
                info.GetReturnValue().Set(Nan::New("flex-end").ToLocalChecked());
                break;
            case YGAlignStretch:
                info.GetReturnValue().Set(Nan::New("stretch").ToLocalChecked());
                break;
            case YGAlignBaseline:
                info.GetReturnValue().Set(Nan::New("baseline").ToLocalChecked());
                break;
            case YGAlignFlexStart:
                info.GetReturnValue().Set(Nan::New("flex-start").ToLocalChecked());
                break;
            case YGAlignSpaceAround:
                info.GetReturnValue().Set(Nan::New("space-around").ToLocalChecked());
                break;
            case YGAlignSpaceBetween:
                info.GetReturnValue().Set(Nan::New("space-between").ToLocalChecked());
                break;
            default:
                info.GetReturnValue().Set(Nan::Undefined());
                break;
        }
    }
    
    NAN_METHOD(Node::getAlignSelf) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        YGAlign align = YGNodeStyleGetAlignSelf(node->node());
        
        switch (align) {
            case YGAlignCenter:
                info.GetReturnValue().Set(Nan::New("center").ToLocalChecked());
                break;
            case YGAlignAuto:
                info.GetReturnValue().Set(Nan::New("auto").ToLocalChecked());
                break;
            case YGAlignFlexEnd:
                info.GetReturnValue().Set(Nan::New("flex-end").ToLocalChecked());
                break;
            case YGAlignStretch:
                info.GetReturnValue().Set(Nan::New("stretch").ToLocalChecked());
                break;
            case YGAlignBaseline:
                info.GetReturnValue().Set(Nan::New("baseline").ToLocalChecked());
                break;
            case YGAlignFlexStart:
                info.GetReturnValue().Set(Nan::New("flex-start").ToLocalChecked());
                break;
            case YGAlignSpaceAround:
                info.GetReturnValue().Set(Nan::New("space-around").ToLocalChecked());
                break;
            case YGAlignSpaceBetween:
                info.GetReturnValue().Set(Nan::New("space-between").ToLocalChecked());
                break;
            default:
                info.GetReturnValue().Set(Nan::Undefined());
                break;
        }
    }
    
    NAN_METHOD(Node::getFlexDirection) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        YGFlexDirection direction = YGNodeStyleGetFlexDirection(node->node());
        
        switch (direction) {
            case YGFlexDirectionRow:
                info.GetReturnValue().Set(Nan::New("row").ToLocalChecked());
                break;
            case YGFlexDirectionColumn:
                info.GetReturnValue().Set(Nan::New("column").ToLocalChecked());
                break;
            case YGFlexDirectionRowReverse:
                info.GetReturnValue().Set(Nan::New("row-reverse").ToLocalChecked());
                break;
            case YGFlexDirectionColumnReverse:
                info.GetReturnValue().Set(Nan::New("column-reverse").ToLocalChecked());
                break;
            default:
                info.GetReturnValue().Set(Nan::Undefined());
                break;
        }
    }
    
    NAN_METHOD(Node::getFlexWrap) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        YGWrap wrap = YGNodeStyleGetFlexWrap(node->node());
        
        switch (wrap) {
            case YGWrapWrap:
                info.GetReturnValue().Set(Nan::New("wrap").ToLocalChecked());
                break;
            case YGWrapNoWrap:
                info.GetReturnValue().Set(Nan::New("none").ToLocalChecked());
                break;
            case YGWrapWrapReverse:
                info.GetReturnValue().Set(Nan::New("wrap-reverse").ToLocalChecked());
                break;
            default:
                info.GetReturnValue().Set(Nan::Undefined());
                break;
        }
    }
    
    NAN_METHOD(Node::getJustifyContent) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        YGJustify justify = YGNodeStyleGetJustifyContent(node->node());
        
        switch (justify) {
            case YGJustifyCenter:
                info.GetReturnValue().Set(Nan::New("center").ToLocalChecked());
                break;
            case YGJustifyFlexEnd:
                info.GetReturnValue().Set(Nan::New("flex-end").ToLocalChecked());
                break;
            case YGJustifyFlexStart:
                info.GetReturnValue().Set(Nan::New("flex-start").ToLocalChecked());
                break;
            case YGJustifySpaceAround:
                info.GetReturnValue().Set(Nan::New("space-around").ToLocalChecked());
                break;
            case YGJustifySpaceEvenly:
                info.GetReturnValue().Set(Nan::New("space-evenly").ToLocalChecked());
                break;
            case YGJustifySpaceBetween:
                info.GetReturnValue().Set(Nan::New("space-between").ToLocalChecked());
                break;
            default:
                info.GetReturnValue().Set(Nan::Undefined());
                break;
        }
    }
    
    NAN_METHOD(Node::getMargin) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        int edge;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0).stringEnum<int>({
            {"left", YGEdgeLeft},
            {"right", YGEdgeRight},
            {"top", YGEdgeTop},
            {"bottom", YGEdgeBottom},
            {"start", YGEdgeStart},
            {"end", YGEdgeEnd},
            {"horizontal", YGEdgeHorizontal},
            {"vertical", YGEdgeVertical},
            {"all", YGEdgeAll}
        }).bind(edge)
        .check();
        
        YGValue value = YGNodeStyleGetMargin(node->node(), static_cast<YGEdge>(edge));
        switch (value.unit) {
            case YGUnitAuto:
                info.GetReturnValue().Set(Nan::New("space-around").ToLocalChecked());
                break;
            case YGUnitUndefined:
                info.GetReturnValue().Set(Nan::Undefined());
                break;
            default:
                info.GetReturnValue().Set(value.value);
                break;
        }
    }
    
    NAN_METHOD(Node::getOverflow) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        YGOverflow overflow = YGNodeStyleGetOverflow(node->node());
        switch (overflow) {
            case YGOverflowHidden:
                info.GetReturnValue().Set(Nan::New("hidden").ToLocalChecked());
                break;
            case YGOverflowScroll:
                info.GetReturnValue().Set(Nan::New("scroll").ToLocalChecked());
                break;
            case YGOverflowVisible:
                info.GetReturnValue().Set(Nan::New("visible").ToLocalChecked());
                break;
            default:
                info.GetReturnValue().Set(Nan::Undefined());
                break;
        }
    }
    
    NAN_METHOD(Node::getDisplay) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        YGDisplay display = YGNodeStyleGetDisplay(node->node());
        switch (display) {
            case YGDisplayFlex:
                info.GetReturnValue().Set(Nan::New("flex").ToLocalChecked());
                break;
            default:
                info.GetReturnValue().Set(Nan::New("none").ToLocalChecked());
                break;
        }
    }
    
    NAN_METHOD(Node::getFlexBasis) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        YGValue value = YGNodeStyleGetFlexBasis(node->node());
        switch (value.unit) {
            case YGUnitAuto:
                info.GetReturnValue().Set(Nan::New("auto").ToLocalChecked());
                break;
            default:
                info.GetReturnValue().Set(value.value);
                break;
        }
    }
    
    NAN_METHOD(Node::getFlexGrow) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float ret = YGNodeStyleGetFlexGrow(node->node());
        info.GetReturnValue().Set(ret);
    }
    
    NAN_METHOD(Node::getFlexShrink) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float ret = YGNodeStyleGetFlexShrink(node->node());
        info.GetReturnValue().Set(ret);
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
    
    NAN_METHOD(Node::getHeight) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        YGValue value = YGNodeStyleGetHeight(node->node());
        if (value.unit == YGUnitUndefined) {
            info.GetReturnValue().Set(Nan::Undefined());
        } else if (value.unit == YGUnitAuto) {
            info.GetReturnValue().Set(Nan::New("auto").ToLocalChecked());
        } else {
            info.GetReturnValue().Set(value.value);
        }
    }
    
    NAN_METHOD(Node::getMinWidth) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        YGValue value = YGNodeStyleGetMinWidth(node->node());
        if (value.unit == YGUnitUndefined) {
            info.GetReturnValue().Set(Nan::Undefined());
        } else if (value.unit == YGUnitAuto) {
            info.GetReturnValue().Set(Nan::New("auto").ToLocalChecked());
        } else {
            info.GetReturnValue().Set(value.value);
        }
    }
    
    NAN_METHOD(Node::getMinHeight) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        YGValue value = YGNodeStyleGetMinHeight(node->node());
        if (value.unit == YGUnitUndefined) {
            info.GetReturnValue().Set(Nan::Undefined());
        } else if (value.unit == YGUnitAuto) {
            info.GetReturnValue().Set(Nan::New("auto").ToLocalChecked());
        } else {
            info.GetReturnValue().Set(value.value);
        }
    }
    
    NAN_METHOD(Node::getMaxWidth) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        YGValue value = YGNodeStyleGetMaxWidth(node->node());
        if (value.unit == YGUnitUndefined) {
            info.GetReturnValue().Set(Nan::Undefined());
        } else if (value.unit == YGUnitAuto) {
            info.GetReturnValue().Set(Nan::New("auto").ToLocalChecked());
        } else {
            info.GetReturnValue().Set(value.value);
        }
    }
    
    NAN_METHOD(Node::getMaxHeight) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        YGValue value = YGNodeStyleGetMaxHeight(node->node());
        if (value.unit == YGUnitUndefined) {
            info.GetReturnValue().Set(Nan::Undefined());
        } else if (value.unit == YGUnitAuto) {
            info.GetReturnValue().Set(Nan::New("auto").ToLocalChecked());
        } else {
            info.GetReturnValue().Set(value.value);
        }
    }
    
    NAN_METHOD(Node::getAspectRatio) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float ret = YGNodeStyleGetAspectRatio(node->node());
        info.GetReturnValue().Set(ret);
    }
    
    NAN_METHOD(Node::getBorder) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        int edge;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0).stringEnum<int>({
            {"left", YGEdgeLeft},
            {"right", YGEdgeRight},
            {"top", YGEdgeTop},
            {"bottom", YGEdgeBottom},
            {"start", YGEdgeStart},
            {"end", YGEdgeEnd},
            {"horizontal", YGEdgeHorizontal},
            {"vertical", YGEdgeVertical},
            {"all", YGEdgeAll}
        }).bind(edge)
        .check();
        
        float ret = YGNodeStyleGetBorder(node->node(), static_cast<YGEdge>(edge));
        info.GetReturnValue().Set(ret);
    }
    
    NAN_METHOD(Node::getPadding) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        int edge;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0).stringEnum<int>({
            {"left", YGEdgeLeft},
            {"right", YGEdgeRight},
            {"top", YGEdgeTop},
            {"bottom", YGEdgeBottom},
            {"start", YGEdgeStart},
            {"end", YGEdgeEnd},
            {"horizontal", YGEdgeHorizontal},
            {"vertical", YGEdgeVertical},
            {"all", YGEdgeAll}
        }).bind(edge)
        .check();
        
        YGValue value = YGNodeStyleGetPadding(node->node(), static_cast<YGEdge>(edge));
        if (value.unit == YGUnitUndefined) {
            info.GetReturnValue().Set(Nan::Undefined());
        } else if (value.unit == YGUnitAuto) {
            info.GetReturnValue().Set(Nan::New("auto").ToLocalChecked());
        } else {
            info.GetReturnValue().Set(value.value);
        }
    }
    
    NAN_METHOD(Node::insertChild) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        v8::Local<v8::Value> object1;
        int index;
        NanCheckArguments(info).argumentsCount(2)
        .argument(0).NotNull()
        .bind(object1)
        .argument(1).bind(index)
        .check();
        
        Nan::MaybeLocal<v8::Object> child = Nan::To<v8::Object>(object1);
        if (child.IsEmpty()) {
            Nan::ThrowError("Child is Null or Undefined");
        }
        Node* nchild = Nan::ObjectWrap::Unwrap<Node>(child.ToLocalChecked());
        YGNodeInsertChild(node->node(), nchild->node(), index);
        info.GetReturnValue().Set(Nan::Undefined());
    }
    
    NAN_METHOD(Node::removeChild) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        v8::Local<v8::Value> object1;
        NanCheckArguments(info).argumentsCount(1)
        .argument(0).NotNull()
        .bind(object1)
        .check();
        
        
        Nan::MaybeLocal<v8::Object> child = Nan::To<v8::Object>(object1);
        if (child.IsEmpty()) {
            Nan::ThrowError("Child is Null or Undefined");
        }
        Node* nchild = Nan::ObjectWrap::Unwrap<Node>(child.ToLocalChecked());
        
        YGNodeRemoveChild(node->node(), nchild->node());
    }
    
    NAN_METHOD(Node::getParent) {
        // Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        // TODO
        info.GetReturnValue().Set(Nan::Undefined());
    }
    
    NAN_METHOD(Node::getChild) {
        // TODO
        info.GetReturnValue().Set(Nan::Undefined());
    }
    
    
    NAN_METHOD(Node::markDirty) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        YGNodeMarkDirty(node->node());
    }
    
    NAN_METHOD(Node::isDirty) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        bool ret = YGNodeIsDirty(node->node());
        
        info.GetReturnValue().Set(ret);
    }
    
    NAN_METHOD(Node::calculateLayout) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float availableWidth, availableHeight;
        int ownerDirection;
        NanCheckArguments(info).argumentsCount(3)
        .argument(0).bind(availableWidth)
        .argument(1).bind(availableHeight)
        .argument(2).stringEnum<int>({
            {"inherit", YGDirectionInherit},
            {"ltr", YGDirectionLTR},
            {"rtl", YGDirectionRTL}
        }).bind(ownerDirection)
        .check();
        
        YGNodeCalculateLayout(node->node(), availableWidth, availableHeight, static_cast<YGDirection>(ownerDirection));
    }
    
    
    NAN_METHOD(Node::getComputedLeft) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float left = YGNodeLayoutGetLeft(node->node());
        info.GetReturnValue().Set(left);
    }
    
    NAN_METHOD(Node::getComputedRight) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        info.GetReturnValue().Set(YGNodeLayoutGetRight(node->node()));
    }
    
    NAN_METHOD(Node::getComputedTop) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        info.GetReturnValue().Set(YGNodeLayoutGetTop(node->node()));
    }
    
    NAN_METHOD(Node::getComputedBottom) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        info.GetReturnValue().Set(YGNodeLayoutGetBottom(node->node()));
    }
    
    NAN_METHOD(Node::getComputedWidth) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        info.GetReturnValue().Set(YGNodeLayoutGetWidth(node->node()));
    }
    
    NAN_METHOD(Node::getComputedHeight) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        info.GetReturnValue().Set(YGNodeLayoutGetHeight(node->node()));
    }
    
    NAN_METHOD(Node::getComputedLayout) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float left = YGNodeLayoutGetLeft(node->node());
        float top = YGNodeLayoutGetTop(node->node());
        float right = YGNodeLayoutGetRight(node->node());
        float bottom = YGNodeLayoutGetBottom(node->node());
        float width = YGNodeLayoutGetWidth(node->node());
        float height = YGNodeLayoutGetHeight(node->node());
        
        Nan::MaybeLocal<v8::Object> obj = Nan::New<v8::Object>();
        
        Nan::Set(obj.ToLocalChecked(), Nan::New("left").ToLocalChecked(), Nan::New(left));
        Nan::Set(obj.ToLocalChecked(), Nan::New("top").ToLocalChecked(), Nan::New(top));
        Nan::Set(obj.ToLocalChecked(), Nan::New("right").ToLocalChecked(), Nan::New(right));
        Nan::Set(obj.ToLocalChecked(), Nan::New("bottom").ToLocalChecked(), Nan::New(bottom));
        Nan::Set(obj.ToLocalChecked(), Nan::New("width").ToLocalChecked(), Nan::New(width));
        Nan::Set(obj.ToLocalChecked(), Nan::New("height").ToLocalChecked(), Nan::New(height));
        
        info.GetReturnValue().Set(obj.ToLocalChecked());
    }
    
    NAN_METHOD(Node::getComputedMargin) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
    
        float left = YGNodeLayoutGetMargin(node->node(), YGEdgeLeft);
        float top = YGNodeLayoutGetMargin(node->node(), YGEdgeTop);
        float right = YGNodeLayoutGetMargin(node->node(), YGEdgeRight);
        float bottom = YGNodeLayoutGetMargin(node->node(), YGEdgeBottom);
        
        Nan::MaybeLocal<v8::Object> obj = Nan::New<v8::Object>();
        
        Nan::Set(obj.ToLocalChecked(), Nan::New("left").ToLocalChecked(), Nan::New(left));
        Nan::Set(obj.ToLocalChecked(), Nan::New("top").ToLocalChecked(), Nan::New(top));
        Nan::Set(obj.ToLocalChecked(), Nan::New("right").ToLocalChecked(), Nan::New(right));
        Nan::Set(obj.ToLocalChecked(), Nan::New("bottom").ToLocalChecked(), Nan::New(bottom));
        info.GetReturnValue().Set(obj.ToLocalChecked());
    }
    
    NAN_METHOD(Node::getComputedBorder) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float left = YGNodeLayoutGetBorder(node->node(), YGEdgeLeft);
        float top = YGNodeLayoutGetBorder(node->node(), YGEdgeTop);
        float right = YGNodeLayoutGetBorder(node->node(), YGEdgeRight);
        float bottom = YGNodeLayoutGetBorder(node->node(), YGEdgeBottom);
        
        Nan::MaybeLocal<v8::Object> obj = Nan::New<v8::Object>();
        
        Nan::Set(obj.ToLocalChecked(), Nan::New("left").ToLocalChecked(), Nan::New(left));
        Nan::Set(obj.ToLocalChecked(), Nan::New("top").ToLocalChecked(), Nan::New(top));
        Nan::Set(obj.ToLocalChecked(), Nan::New("right").ToLocalChecked(), Nan::New(right));
        Nan::Set(obj.ToLocalChecked(), Nan::New("bottom").ToLocalChecked(), Nan::New(bottom));
        info.GetReturnValue().Set(obj.ToLocalChecked());
    }
    
    NAN_METHOD(Node::getComputedPadding) {
        Node* node = Nan::ObjectWrap::Unwrap<Node>(info.Holder());
        
        float left = YGNodeLayoutGetPadding(node->node(), YGEdgeLeft);
        float top = YGNodeLayoutGetPadding(node->node(), YGEdgeTop);
        float right = YGNodeLayoutGetPadding(node->node(), YGEdgeRight);
        float bottom = YGNodeLayoutGetPadding(node->node(), YGEdgeBottom);
        
        Nan::MaybeLocal<v8::Object> obj = Nan::New<v8::Object>();
        
        Nan::Set(obj.ToLocalChecked(), Nan::New("left").ToLocalChecked(), Nan::New(left));
        Nan::Set(obj.ToLocalChecked(), Nan::New("top").ToLocalChecked(), Nan::New(top));
        Nan::Set(obj.ToLocalChecked(), Nan::New("right").ToLocalChecked(), Nan::New(right));
        Nan::Set(obj.ToLocalChecked(), Nan::New("bottom").ToLocalChecked(), Nan::New(bottom));
        info.GetReturnValue().Set(obj.ToLocalChecked());
    }
    
}
