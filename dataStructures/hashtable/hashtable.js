/*
* run with nodejs hasshtable.js
*/

function HashTable(){
  this.items = [];
  this.generateHash = function(item) {
    return item.length;
  };
}

HashTable.prototype = {

  print: function() {
    for (var pos in this.items) {
      console.log(pos + ' -> "' + this.items[pos] + '"\n');
    }
  },

  // returns true for success, false if collision happend
  add: function (item) {
    var hashCode = this.generateHash(item);
    if (this.items[hashCode]) {
      return false;
    } else {
      this.items[hashCode] = item;
      return true;
    }
  },

  contains: function (key) {
    return !!this.items[this.generateHash(key)];
  }
};


var table1 = new HashTable();


console.log('adding "this is a test"');
table1.add('this is a test');
table1.print();

console.log('adding "this is a test"');
if (!table1.add('this is a test')) {
  console.log('collision');
}
table1.print();

console.log('adding "this is another test"');
table1.add('this is another test');
table1.print();

console.log('does it contain "this is another test" ?');
console.log(table1.contains('this is another test'));

console.log('does it contain "this is a test" ?');
console.log(table1.contains('this is a test'));

console.log('does it contain "this is not a test" ?');
console.log(table1.contains('this is not a test'));
