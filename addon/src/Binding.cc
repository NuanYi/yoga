#include <nan.h>
#include "Node.h"

using v8::FunctionTemplate;

using namespace yoga;

NAN_MODULE_INIT(InitAll) {
    Node::Init(target);
}


NODE_MODULE(yoga, InitAll)
