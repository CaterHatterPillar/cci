#include "test.h"

#include <map>
#include <stack>
#include <string>
#include <vector>

using std::map;
using std::pair;
using std::stack;
using std::string;
using std::vector;

// 0              16  19                37    44  48
// (defun cur-line () (+ (count-lines 1 (point)) 1))
//                  17   22                  43  47

vector<pair<size_t, size_t> > matching_parens(string s) {
  vector<pair<size_t, size_t> > parens;

  stack<size_t> starting;
  for (size_t idx = 0; idx < s.size(); ++idx) {
    if (s[idx] == '(') {
      starting.push(idx);
    } else if (s[idx] == ')') {
      parens.push_back(std::make_pair(starting.top(), idx));
      starting.pop();
    }
  }

  return parens;
}

size_t closing_paren(string s, size_t opening) {
  map<size_t, size_t> opening_to_closing;

  vector<pair<size_t, size_t> > matching = matching_parens(s);
  for (vector<pair<size_t, size_t> >::const_iterator match = matching.begin();
       match != matching.end(); ++match) {
    opening_to_closing[match->first] = match->second;
  }

  return opening_to_closing[opening];
}

int main () {
  string s = "(defun cur-line () (+ (count-lines 1 (point)) 1))";

  EXPECT_EQUAL(closing_paren(s, 0  ), 48);
  EXPECT_EQUAL(closing_paren(s, 16 ), 17);
  EXPECT_EQUAL(closing_paren(s, 22 ), 44);
  EXPECT_EQUAL(closing_paren(s, 37 ), 43);

  return 0;
}
