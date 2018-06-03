{
    "targets": [{
        "target_name":
        "yoga-binding",
        "sources": [
            "src/Binding.cc",
            "src/Node.cpp",
            "src/Node.h",
            "src/NanChecker.h",
            "src/NanChecker.cpp",
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
        'cflags_cc!': [ '-fno-exceptions', '-w' ],
    }]
}