#include "test.h"

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

// O(n)
bool is_unique(string s) {
  unordered_map<char, int> counts;
  for (string::const_iterator c = s.begin(); c != s.end(); ++c) {
    counts[*c] += 1;
  }

  for (unordered_map<char, int>::const_iterator it = counts.begin();
       it != counts.end(); ++it) {
    if (it->second > 1) {
      return false;
    }
  }

  return true;
}

// O(n^2)
bool is_unique_plain(string s) {
  if (s.size() <= 1) {
    return true;
  }

  for (string::const_iterator i = s.begin(); i != s.end(); ++i) {
    for (string::const_iterator j = i + 1; j != s.end(); ++j) {
      if (*i == *j) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  EXPECT_TRUE(is_unique(string("")));
  EXPECT_TRUE(is_unique(string("a")));
  EXPECT_TRUE(is_unique(string("abcde")));

  EXPECT_FALSE(is_unique(string("abcba")));
  EXPECT_FALSE(is_unique(string("aa")));

  EXPECT_TRUE(is_unique_plain(string("")));
  EXPECT_TRUE(is_unique_plain(string("a")));
  EXPECT_TRUE(is_unique_plain(string("abcde")));

  EXPECT_FALSE(is_unique_plain(string("abcba")));
  EXPECT_FALSE(is_unique_plain(string("aa")));

  return 0;
}
