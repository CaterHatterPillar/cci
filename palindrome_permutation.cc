#include "test.h"

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

bool is_palindrome_permutation(string s) {
  unordered_map<char, int> occurrences;
  for (string::const_iterator c = s.begin(); c != s.end(); ++c) {
    occurrences[*c] += 1;
  }

  bool found_odd = false;
  for (unordered_map<char, int>::const_iterator occur = occurrences.begin();
       occur != occurrences.end(); ++occur) {
    if (occur->second % 2 != 0) {
      if (found_odd) {
        return false;
      } else {
        found_odd = true;
      }
    }
  }

  return true;
}

int main() {
  // actual palindromes
  EXPECT_TRUE(is_palindrome_permutation(string("")));
  EXPECT_TRUE(is_palindrome_permutation(string("a")));
  EXPECT_TRUE(is_palindrome_permutation(string("aa")));
  EXPECT_TRUE(is_palindrome_permutation(string("abcba")));

  // permutations
  EXPECT_TRUE(is_palindrome_permutation(string("abcabc")));
  EXPECT_TRUE(is_palindrome_permutation(string("ababc")));

  EXPECT_FALSE(is_palindrome_permutation(string("ab")));
  EXPECT_FALSE(is_palindrome_permutation(string("abcabcab")));

  return 0;
}
