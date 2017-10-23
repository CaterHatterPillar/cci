#include "test.h"

int iter(int idx) {
  int l = 0;
  int r = 1;
  for (int i = 0; i < idx - 1; ++i) {
    int f = l + r;
    l = r;
    r = f;
  }

  return idx == 0 ? 0 : r;
}

int recu(int n) {
  if (n == 0) {
    return 0;
  }
  return n <= 2 ? 1 : recu(n - 1) + recu(n - 2);
}

void recu_tail(int idx, int& l, int& r) {
  if (idx) {
    int f = r + l;
    l = r;
    r = f;
    recu_tail(--idx, l, r);
  }
}

int tail(int idx) {
  int l = 0;
  int r = 1;
  recu_tail(idx, l, r);

  return l;
}

int main() {
  EXPECT_EQUAL(iter(0), 0);
  EXPECT_EQUAL(iter(1), 1);
  EXPECT_EQUAL(iter(2), 1);
  EXPECT_EQUAL(iter(3), 2);
  EXPECT_EQUAL(iter(4), 3);
  EXPECT_EQUAL(iter(5), 5);
  EXPECT_EQUAL(iter(6), 8);
  EXPECT_EQUAL(iter(7), 13);

  EXPECT_EQUAL(recu(0), 0);
  EXPECT_EQUAL(recu(1), 1);
  EXPECT_EQUAL(recu(2), 1);
  EXPECT_EQUAL(recu(3), 2);
  EXPECT_EQUAL(recu(4), 3);
  EXPECT_EQUAL(recu(5), 5);
  EXPECT_EQUAL(recu(6), 8);
  EXPECT_EQUAL(recu(7), 13);

  EXPECT_EQUAL(tail(0), 0);
  EXPECT_EQUAL(tail(1), 1);
  EXPECT_EQUAL(tail(2), 1);
  EXPECT_EQUAL(tail(3), 2);
  EXPECT_EQUAL(tail(4), 3);
  EXPECT_EQUAL(tail(5), 5);
  EXPECT_EQUAL(tail(6), 8);
  EXPECT_EQUAL(tail(7), 13);

  return 0;
}
