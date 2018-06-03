#pragma once

#include <nan.h>
#include <YGNode.h>
#include <Yoga.h>

namespace yoga {
    
    class Node: public Nan::ObjectWrap {
    public:
        /**
         * node addon method
         */
        static NAN_MODULE_INIT(Init);
        static NAN_METHOD(New);
        /*** Create method ***/
        static NAN_METHOD(Create);
        /******* Style setters **********/
        static NAN_METHOD(setPositionType);
        static NAN_METHOD(setPosition);
        static NAN_METHOD(setPositionPercent);

        static NAN_METHOD(setAlignContent);
        static NAN_METHOD(setAlignItems);
        static NAN_METHOD(setAlignSelf);
        static NAN_METHOD(setFlexDirection);
        static NAN_METHOD(setFlexWrap);
        static NAN_METHOD(setJustifyContent);

        static NAN_METHOD(setMargin);
        static NAN_METHOD(setMarginPercent);
        static NAN_METHOD(setMarginAuto);

        static NAN_METHOD(setOverflow);
        static NAN_METHOD(setDisplay);

        static NAN_METHOD(setFlex);
        static NAN_METHOD(setFlexBasis);
        static NAN_METHOD(setFlexBasisPercent);
        static NAN_METHOD(setFlexBasisAuto);
        static NAN_METHOD(setFlexGrow);
        static NAN_METHOD(setFlexShrink);

        static NAN_METHOD(setWidth);
        static NAN_METHOD(setWidthPercent);
        static NAN_METHOD(setWidthAuto);
        static NAN_METHOD(setHeight);
        static NAN_METHOD(setHeightPercent);
        static NAN_METHOD(setHeightAuto);

        static NAN_METHOD(setMinWidth);
        static NAN_METHOD(setMinWidthPercent);
        static NAN_METHOD(setMinHeight);
        static NAN_METHOD(setMinHeightPercent);

        static NAN_METHOD(setMaxWidth);
        static NAN_METHOD(setMaxWidthPercent);
        static NAN_METHOD(setMaxHeight);
        static NAN_METHOD(setMaxHeightPercent);

        static NAN_METHOD(setAspectRatio);

        static NAN_METHOD(setBorder);
        static NAN_METHOD(setPadding);
        static NAN_METHOD(setPaddingPercent);

        /************ style getters ***************/
        static NAN_METHOD(getPositionType);
        static NAN_METHOD(getPosition);

        static NAN_METHOD(getAlignContent);
        static NAN_METHOD(getAlignItems);
        static NAN_METHOD(getAlignSelf);
        static NAN_METHOD(getFlexDirection);
        static NAN_METHOD(getFlexWrap);
        static NAN_METHOD(getJustifyContent);

        static NAN_METHOD(getMargin);

        static NAN_METHOD(getOverflow);
        static NAN_METHOD(getDisplay);

        static NAN_METHOD(getFlexBasis);
        static NAN_METHOD(getFlexGrow);
        static NAN_METHOD(getFlexShrink);

        static NAN_METHOD(getWidth);
        static NAN_METHOD(getHeight);
        
        static NAN_METHOD(getMinWidth);
        static NAN_METHOD(getMinHeight);

        static NAN_METHOD(getMaxWidth);
        static NAN_METHOD(getMaxHeight);

        static NAN_METHOD(getAspectRatio);
        static NAN_METHOD(getBorder);
        static NAN_METHOD(getPadding);

        /********** tree hierarchy mutators **********/
        static NAN_METHOD(insertChild);
        static NAN_METHOD(removeChild);
        static NAN_METHOD(getParent);
        static NAN_METHOD(getChild);

// current not export function
#if 0
        static NAN_METHOD(setMeasureFunc);
        static NAN_METHOD(unsetMeasureFunc);
        static NAN_METHOD(callMeasureFunc);
#endif

        static NAN_METHOD(markDirty);
        static NAN_METHOD(isDirty);

        static NAN_METHOD(calculateLayout);

        static NAN_METHOD(getComputedLeft);
        static NAN_METHOD(getComputedRight);
        static NAN_METHOD(getComputedTop);
        static NAN_METHOD(getComputedBottom);

        static NAN_METHOD(getComputedwidth);
        static NAN_METHOD(getComputedHeight);

        static NAN_METHOD(getComputedLayout);

        static NAN_METHOD(getComputedMargin);
        static NAN_METHOD(getComputedBorder);
        static NAN_METHOD(getComputedPadding);

        inline YGNodeRef node() {
            return mNode;
        }
        
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
