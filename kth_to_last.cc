#include "list.h"
#include "test.h"

int main() {
  List<int> l;
  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.push_back(4);
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);
  l.push_back(8);

  EXPECT_EQUAL(l.kth_to_last(0), 8);
  EXPECT_EQUAL(l.kth_to_last(1), 7);
  EXPECT_EQUAL(l.kth_to_last(2), 6);
  EXPECT_EQUAL(l.kth_to_last(3), 5);

  return 0;
}
