#include "test.h"

#include <algorithm>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

unordered_map<char, int> occurrences(string s) {
  unordered_map<char, int> occur;
  for (string::const_iterator c = s.begin(); c != s.end(); ++c) {
    occur[*c] += 1;
  }
  return occur;
}

// O(n)
bool is_permutation(string l, string r) {
  unordered_map<char, int> occur_l = occurrences(l);
  unordered_map<char, int> occur_r = occurrences(r);
  return occurrences(l) == occurrences(r);
}

bool is_permutation_std(string l, string r) {
  return std::is_permutation(l.begin(), l.end(), r.begin(), r.end());
}

int main() {
  EXPECT_TRUE(is_permutation(string(""), string("")));
  EXPECT_TRUE(is_permutation(string("a"), string("a")));
  EXPECT_TRUE(is_permutation(string("abc"), string("cba")));

  EXPECT_FALSE(is_permutation(string("a"), string("")));
  EXPECT_FALSE(is_permutation(string("a"), string("b")));
  EXPECT_FALSE(is_permutation(string("a"), string("ab")));

  EXPECT_TRUE(is_permutation_std(string(""), string("")));
  EXPECT_TRUE(is_permutation_std(string("a"), string("a")));
  EXPECT_TRUE(is_permutation_std(string("abc"), string("cba")));

  EXPECT_FALSE(is_permutation_std(string("a"), string("")));
  EXPECT_FALSE(is_permutation_std(string("a"), string("b")));
  EXPECT_FALSE(is_permutation_std(string("a"), string("ab")));

  return 0;
}
