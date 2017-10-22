#include "test.h"

#include <algorithm>
#include <string>
#include <vector>

using std::string;
using std::vector;

string urlify(string s) {
  vector<size_t> occurrences;

  size_t pos = s.find(' ');
  while(pos != string::npos) {
    occurrences.push_back(pos);
    pos = s.find(' ', pos + 1);
  }

  for (int i = 0; i < occurrences.size(); ++i) {
    s.replace(occurrences[i] + i * 2, 1, "%20");
  }

  return s;
}

int main() {
  EXPECT_EQUAL(urlify(string("Mr John Smith")), string("Mr%20John%20Smith"));
  EXPECT_EQUAL(urlify(string("    ")), string("%20%20%20%20"));
  EXPECT_EQUAL(urlify(string("MrJohnSmith")), string("MrJohnSmith"));

  return 0;
}
