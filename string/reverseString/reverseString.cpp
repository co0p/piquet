/* reverse string without api */

#include <string>
#include <iostream>

using namespace std;


string returnReverse(string& ostr) {
  string str = ostr;
  int j = 0;
  for (int i=ostr.length()-1; i>=0; i--) {
    str[j++] = ostr[i];
  }
  return str;
}


int main(int argc, char *argv[]) {

  string myString("abc de f");
  cout << "original : " << myString << endl;

  string reverseString = returnReverse(myString);

  cout << "reverse : " << reverseString << endl;
  return 0;
}