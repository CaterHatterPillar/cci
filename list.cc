#include "list.h"
#include "test.h"

int main() {
  List<int> l;

  bool thrown = false;
  try {
    int i = l[0];
  } catch(std::out_of_range& e) {
    thrown = true;
  }
  EXPECT_TRUE(thrown);

  l.pop_front();
  l.pop_back();

  l.push_back(0);
  l.pop_front();

  l.push_back(0);
  l.pop_back();

  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  EXPECT_EQUAL(l[0], 1);
  EXPECT_EQUAL(l[1], 2);
  EXPECT_EQUAL(l[2], 3);

  l.push_front(0);
  l.push_front(-1);

  EXPECT_EQUAL(l[0], -1);
  EXPECT_EQUAL(l[1], 0);
  EXPECT_EQUAL(l[2], 1);
  EXPECT_EQUAL(l[3], 2);
  EXPECT_EQUAL(l[4], 3);

  EXPECT_EQUAL(l.size(), 5);

  l.pop_back();

  EXPECT_EQUAL(l[0], -1);
  EXPECT_EQUAL(l[1], 0);
  EXPECT_EQUAL(l[2], 1);
  EXPECT_EQUAL(l[3], 2);
  EXPECT_EQUAL(l.size(), 4);

  l.pop_front();

  EXPECT_EQUAL(l[0], 0);
  EXPECT_EQUAL(l[1], 1);
  EXPECT_EQUAL(l[2], 2);
  EXPECT_EQUAL(l.size(), 3);

  return 0;
}
