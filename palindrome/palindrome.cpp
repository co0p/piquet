/** Contains a given String a palindrome ? */

#include <string>
#include <iostream>

using namespace std;

/* returns true if candidate is palindrome, otherwise false */
bool isPalindrome(string candidate) {
  if (candidate.length() < 1) return false;

  int left = 0;
  int right = candidate.length()-1;

  while (left <= right) {
    if (candidate[left] != candidate[right]) return false;
    left++;
    right--;
  }

  return true;
}

/* writes to stdout if candidate is palindrome or not */
void testForPalindrome(string candidate) {
  if (isPalindrome(candidate)) {
    cout << candidate << " is palindrome" << endl;
  } else {
    cout << candidate << " is NOT palindrome" << endl;
  }
}

/* entry */
int main() {
  testForPalindrome("");
  testForPalindrome("a");
  testForPalindrome("abc");
  testForPalindrome("aba");
  testForPalindrome("abba");
  return 0;
}