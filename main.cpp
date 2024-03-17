#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include <algorithm>
#include <iostream>
#include <vector>

void P001_merge_sorted_array(std::vector<int> &nums1, int m,
                             std::vector<int> &nums2, int n) {
  nums1.resize(m + n);
  std::move(nums2.begin(), nums2.end(), nums1.begin() + m);
  std::sort(nums1.begin(), nums1.end(), std::less<int>());
}

TEST_CASE("P001: merge sorted array") {

  {
    std::vector<int> nums1{1, 2, 3, 0, 0, 0};
    std::vector<int> nums2{2, 5, 6};
    std::vector<int> test1{1, 2, 2, 3, 5, 6};
    P001_merge_sorted_array(nums1, 3, nums2, 3);
    CHECK(nums1 == test1);
  }
  {
    std::vector<int> nums1{1};
    std::vector<int> nums2{};
    std::vector<int> test1{1};
    P001_merge_sorted_array(nums1, 1, nums2, 0);
    CHECK(nums1 == test1);
  }
}

int P002_remove_element(std::vector<int> &nums, int val) {
  std::erase_if(nums, [val](const int &x) { return x == val; });
  return nums.size();
}

TEST_CASE("P001: merge sorted array") {
  {
    std::vector<int> nums{3, 2, 2, 3};
    const int ret = P002_remove_element(nums, 3);
    std::vector<int> test1{2, 2};
    CHECK(2 == ret);
    CHECK(nums == test1);
  }
}
