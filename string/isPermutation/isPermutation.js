#!/usr/bin/nodejs

/**
* returns true if one string is the permuation of the other
*
* it uses the fact that a permutation of a string means
* - same number of individual characters
*
* run with nodejs isPermutation string1 string2
*/

// returns a map of chars as key and char count as value
function generateCharCountMap(str) {
  var chars = {};
  var char = null;
  for (var i = 0, length = str.length; i < length; i++) {
    char = str[i];
    chars[char] = !!chars[char] ? (chars[char] + 1) : 1;
  }
  return chars;
}

// returns true if map1 equals map2
function compareMaps(map1, map2) {

  var mapsAreEqual = true;
  var keys1 = Object.keys(map1);
  var keys2 = Object.keys(map2);
  if (keys1.length !== keys2.length) {
    return false;
  }

  function equalValues(key) {
    if (map1[key] !== map2[key]) {
      mapsAreEqual = false;
    }
  }
  keys1.forEach(equalValues);

  return mapsAreEqual;
}


// returs true if string1 is a permutation of string2 and vice versa
function main(args) {
	if (!args[0] && !args[1]) {
		console.log('usage: ./isPermutation <string1> <string2>');
		return 0;
	} else {
    var map1 = generateCharCountMap(args[0]);
    var map2 = generateCharCountMap(args[1]);

		return compareMaps(map1, map2);
	}
}

// run it
console.log(main(process.argv.slice(2)));
