#include "list.h"
#include "test.h"

int main() {
  List<int> l;
  l.push_back(0);
  l.push_back(1);
  l.push_back(0);
  l.push_back(2);
  l.push_back(0);
  l.push_back(3);
  l.push_back(0);

  l.remove_dups(0);

  EXPECT_EQUAL(l[0], 0);
  EXPECT_EQUAL(l[1], 1);
  EXPECT_EQUAL(l[2], 2);
  EXPECT_EQUAL(l[3], 3);
  EXPECT_EQUAL(l.size(), 4);

  return 0;
}
