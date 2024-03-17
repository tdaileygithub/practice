#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include <iostream>

TEST_CASE("one") {
  std::cout << "hello world" << std::endl;
  std::cout << "";
}
