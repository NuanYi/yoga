{
    "targets": [{
        "target_name":
        "yoga-binding",
        "sources": [
            "src/Binding.cc",
            "src/Node.cpp",
            "src/Node.h",
            "../yoga/Utils.cpp",
            "../yoga/YGConfig.cpp",
            "../yoga/YGEnums.cpp",
            "../yoga/YGFloatOptional.cpp",
            "../yoga/YGLayout.cpp",
            "../yoga/YGNode.cpp",
            "../yoga/YGNodePrint.cpp",
            "../yoga/YGStyle.cpp",
            "../yoga/Yoga.cpp"
        ],
        'include_dirs': [
            './../yoga',
            './../nan'
        ],
    }]
}