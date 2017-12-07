CXXFLAGS:= \
  -Werror \
  -g

TESTS:=$(addprefix test_,$(basename $(wildcard *.cc)))

.PHONY: $(TESTS)
$(TESTS): test_% : %
	./$*

all: $(TESTS)
