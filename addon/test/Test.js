const yoga = require('../build/Release/yoga-binding');

const { Node } = yoga;

console.log('yoga = ', yoga);
console.log('Node = ', Node);

let root = Node.Create();
console.log('root = ', root);
let child = Node.Create();
child.setWidth(100);
child.setHeight(200);
child.setMargin('bottom',10);
let child2 = Node.Create();
// child2.setWidth(100);
// child2.setHeight(200);

root.insertChild(child, 0);
root.insertChild(child2,1);

root.setWidth(400);
root.setHeight(500);

root.setFlexDirection('row');
root.setJustifyContent('flex-start');

root.calculateLayout(400, 500, 'rtl');

console.log('child.computedLayout = ', child2.getComputedLayout());