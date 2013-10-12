/* reverse string without api */

#include <string>
#include <iostream>

using namespace std;

string returnReverse(string& ostr) {
  string str = ostr;
  char tmp;
  int pos = str.length()-1;
  for (int i=0; i<str.length()/2; i++) {
    tmp = str.at(pos);
    str[i] = str[pos];
    str[pos] = tmp;
    pos--;
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