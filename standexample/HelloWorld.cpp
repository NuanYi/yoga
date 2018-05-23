
#include <Yoga.h>
#include <YGNode.h>
#include <iostream>

int main(int argc, char const *argv[])
{
    auto root = YGNodeNew();

    auto child = YGNodeNew();
    auto child2 = YGNodeNew();

    YGNodeStyleSetWidth(child, 100.f);
    YGNodeStyleSetHeight(child, 100.f);

    YGNodeStyleSetHeight(child2, 100.f);
    YGNodeStyleSetWidth(child2, 100.f);

    YGNodeInsertChild(root, child, 0);
    YGNodeInsertChild(root, child2, 1);


    YGNodeStyleSetHeight(root, 500.f);
    YGNodeStyleSetWidthAuto(root);
    YGNodeStyleSetJustifyContent(root, YGJustifySpaceAround);
    YGNodeStyleSetFlexDirection(root, YGFlexDirectionRow);

    YGNodeCalculateLayout(root, 300.f, 500.f, YGDirectionLTR);


    std::cout<<"left : "<<YGNodeLayoutGetLeft(child)<< "|"
    << "right: "<<YGNodeLayoutGetRight(child)<<"|"
    << "top: "<<YGNodeLayoutGetTop(child)<<"|"
    << "bottom: "<<YGNodeLayoutGetBottom(child)<<std::endl;
    std::cout<<"layoutedWidth = "<<YGNodeLayoutGetWidth(root)<<std::endl;

    /* code */
    return 0;
}
