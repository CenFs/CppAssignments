#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter, bool ignore_empty) {
  vector<string> internal;
  stringstream ss(str);
  string tok;

  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
  if (ignore_empty) {
      for (int i = 0; i < internal.size(); i++) {
          if (internal[i] == "") {
              // cout << i << endl;
              internal.erase(internal.begin()+i);
          }
      }
  }

  return internal;
}

int main(int argc, char **argv) {
  string myCSV = "one,two,,three,four";
  vector<string> sep = split(myCSV, ',', true);

  // If using C++11 (which I recommend)
  /* for(string t : sep)
   *  cout << t << endl;
   */

  for(int i = 0; i < sep.size(); ++i)
    cout << sep[i] << endl;
  return 0;
}
