/* is string palindrome - recursive style */

#include <stdio.h>
#include <string.h>

/* old c does not know boolean */
typedef enum { FALSE=0, TRUE=1 } BOOLEAN;

/* does the recursive work for palindrome checking */
BOOLEAN isPalindromeRecursive(int left, int right, const char* candidate) {
  if (candidate[left] == candidate[right]) {
    if (left == right || (left+1) == right) return TRUE;
    else return isPalindromeRecursive(++left, --right, candidate);
  } 
  return FALSE;
}

/* helper func for recursive palindrome checker */
BOOLEAN isPalindrome(const char* candidate) {
  int length = strlen(candidate);
  if (length < 1) return FALSE;
  return isPalindromeRecursive(0, length-1, candidate);
}


/* pretty printer for palindrome */
void testForPalindrome(const char* candidate) {
  if (isPalindrome(candidate)) {
    printf("'%s' is palindrome\n", candidate);
  } else {
    printf("'%s' is NOT palindrome\n", candidate);
  }
}

/* entry */
int main(int argc, char *argv[]) {
  
  testForPalindrome("");
  testForPalindrome("a");
  testForPalindrome("ab");
  testForPalindrome("aba");
  testForPalindrome("abba");
  testForPalindrome("abcba");

  return 0;
}