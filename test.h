#pragma once

#include <iostream>
#include <stdlib.h>

#define STR(l) #l
#define XSTR(l) STR(l)

#define LOCATION __FILE__ ":" XSTR(__LINE__) ": "  // Looks good in Emacs

#define FAIL_UNLESS(cond, msg)                          \
  do {                                                  \
    if (!cond) {                                        \
      std::cerr << LOCATION << msg << std::endl;        \
      exit(EXIT_FAILURE);                               \
    }                                                   \
  } while (0)

#define EXPECT_TRUE(cond) FAIL_UNLESS(cond, "expected true")
#define EXPECT_FALSE(cond) FAIL_UNLESS(!cond, "expected false")
#define EXPECT_EQUAL(l, r) FAIL_UNLESS(l == r, "expected " << l << " == " << r)
