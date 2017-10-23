#include "test.h"

#include <string>

using std::string;

bool is_one_away_replace(string l, string r) {
  size_t num_replace = 0;

  string::const_iterator lit;
  string::const_iterator rit;
  for (lit = l.begin(), rit = r.begin(); lit != l.end(); ++lit, ++rit) {
    if (*lit != *rit) {
      ++num_replace;
    }
  }

  return num_replace <= 1 ? true : false;
}

size_t insertions_needed(string l, string r) {
  string *small = l.size() < r.size() ? &l : &r;
  string *large = l.size() < r.size() ? &r : &l;

  string::const_iterator it_small = small->begin();
  string::const_iterator it_large = large->begin();

  size_t insertions = 0;
  for (; it_small != small->end(); ++it_small, ++it_large) {
    if (*it_small != *it_large) {
      ++insertions;
      ++it_large;
    }
  }

  return insertions;
}

bool is_one_away(string l, string r) {  // or zero...
  if (l.size() == r.size()) {
    return is_one_away_replace(l, r);
  }
  return insertions_needed(l, r) <= 1 ? true : false;
}

int main() {
  EXPECT_TRUE(is_one_away(string("pale"), string("pale")));

  EXPECT_TRUE(is_one_away(string("pale"), string("ple")));
  EXPECT_TRUE(is_one_away(string("pales"), string("pale")));

  EXPECT_TRUE(is_one_away(string("pale"), string("bale")));

  EXPECT_FALSE(is_one_away(string("pale"), string("bake")));

  return 0;
}
