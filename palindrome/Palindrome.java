/** Contains a given String a palindrome ? */
class Palindrome {

  /* returns true if candidate is palindrome, otherwise false */
  private boolean isPalindrome(String candidate) {
    if (candidate.length() < 1) { return false; }
    for (int left=0, right=candidate.length()-1; left < right; right--, left++) {
      if (candidate.charAt(left) != candidate.charAt(right)) {
        return false;
      }
    }
    return true;
  }

  /* writes to console if candidate is palindrome or not */
  void testForPalindrome(String candidate) {
    if (isPalindrome(candidate)) System.out.println(candidate + " is palindrome");
    else System.out.println(candidate + " is NOT palindrome");
  }

  /* entry */
  public static void main(String[] args) {
    Palindrome checker = new Palindrome();
    checker.testForPalindrome("");
    checker.testForPalindrome("abc");
    checker.testForPalindrome("a");
    checker.testForPalindrome("aba");
    checker.testForPalindrome("abba");
  }
}