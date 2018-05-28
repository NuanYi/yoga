const yoga = require('../build/Release/yoga-binding');

const { Node } = yoga;

console.log('yoga = ', yoga);
console.log('Node = ', Node);

let root = new Node();
console.log('root = ', root);

root.setWidth(200);

console.log('width = ', root.getWidth());

root.setJustifyContent('space-between');