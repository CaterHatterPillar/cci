#include "test.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

string compress(string s) {
  vector<char> chars;
  vector<size_t> freqs;

  string::const_iterator it = s.begin();
  while (it != s.end()) {
    chars.push_back(*it);
    freqs.push_back(0);
    do {
      ++it;
      freqs.back() = freqs.back() + 1;
    } while (it != s.end() && *it == chars.back());
  }

  string c;

  vector<char>::const_iterator sym = chars.begin();
  vector<size_t>::const_iterator freq = freqs.begin();
  for (; sym != chars.end(); ++sym, ++freq) {
    c.push_back(*sym);
    c.append(std::to_string(*freq));
  }

  return c.size() < s.size() ? c : s;
}

int main() {
  EXPECT_EQUAL(compress(string("aabcccccaaa")), string("a2b1c5a3"));
  EXPECT_EQUAL(compress(string("aab")), string("aab"));

  return 0;
}
