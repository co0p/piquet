#!/usr/bin/nodejs

/**
* Returns 1 if given string has only unique characters, -1 otherwise
* 
* $ nodejs allUniqueChars.js <"STRING TO CHECK">
*/

function hasUniqueChars(str) {
	var charHash = {};

	for (var i = 0, length = str.length; i < length; i++) {
		var character = str[i];
		if (charHash[character]) {
			return false;
		} else {
			charHash[character] = true;
		}
	}

	return true;
}

function main(args) {
	if (!args[0]) {
		console.log('usage: ./allUniqueChars <"String to check">');
		return 0;
	} else {
		var unique = hasUniqueChars(args[0]);
		console.log('unique: ', unique);
		return unique;
	}
}

main(process.argv.slice(2));




