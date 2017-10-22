#include "test.h"

#include <string>

using std::string;

bool is_palindrome(string s) {
  string::const_iterator l = s.begin();
  string::const_iterator r = s.end() - 1;
  for (int i = 0; i < s.size() / 2; ++i, ++l, --r) {
    if (*l != *r) {
      return false;
    }
  }

  return true;
}

int main() {
  EXPECT_TRUE(is_palindrome(string("")));
  EXPECT_TRUE(is_palindrome(string("a")));
  EXPECT_TRUE(is_palindrome(string("aa")));
  EXPECT_TRUE(is_palindrome(string("abcba")));

  EXPECT_FALSE(is_palindrome(string("ab")));
  EXPECT_FALSE(is_palindrome(string("abcabc")));

  return 0;
}
