#include <iterator>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &outstream, const std::vector<T> &v) {
  for (auto x : v) {
    outstream << x << " ";
  }
  return outstream;
}

std::vector<std::string> split(const std::string &s, const char delim = ' ') {
  std::vector<std::string> tokens;
  std::string tok;
  std::stringstream ss(s);
  while (getline(ss, tok, delim)) {
    // if the token has something othern than the delimiter then add it
    if (tok.find_first_not_of(delim) != std::string::npos) {
      tokens.push_back(tok);
    }
  }
  return tokens;
}

void ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
          }));
}

void rtrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(),
                       [](unsigned char ch) { return !std::isspace(ch); })
              .base(),
          s.end());
}

void trim(std::string &s) {
  rtrim(s);
  ltrim(s);
}

std::string implode(const std::vector<std::string> &v, char delim = ' ') {
  std::ostringstream oss;
  auto begin = std::begin(v);
  auto end = std::end(v);
  if (begin != end) {
    std::copy(begin, std::prev(end),
              std::ostream_iterator<std::string>(oss, " "));
    begin = std::prev(end);
  }
  if (begin != end) {
    oss << *begin;
  }
  return oss.str();
}

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

TEST_CASE("P002: remove elements") {
  {
    std::vector<int> nums{3, 2, 2, 3};
    const int ret = P002_remove_element(nums, 3);
    std::vector<int> test1{2, 2};
    CHECK(2 == ret);
    CHECK(nums == test1);
  }
}

std::string P003_longestCommonPrefix(std::vector<std::string> &strs) {
  if (strs.size() == 0) {
    return "";
  }
  if (strs.size() == 1) {
    return strs[0];
  }
  std::string pre = strs[0];
  for (int i = 1; i < strs.size(); i++) {
    while (strs[i].find(pre) != 0) {
      // keep selecting 1 character less from the prefix when its not found
      pre = pre.substr(0, pre.length() - 1);
      if (pre == "") {
        return "";
      }
    }
  }
  return pre;
}

TEST_CASE("P003: longest common prefix") {
  {
    std::vector<std::string> strs{"flower", "flow", "flight"};
    CHECK("fl" == P003_longestCommonPrefix(strs));
  }
  {
    std::vector<std::string> strs{"ab", "a"};
    CHECK("a" == P003_longestCommonPrefix(strs));
  }
  {
    std::vector<std::string> strs{"a", "b"};
    CHECK("" == P003_longestCommonPrefix(strs));
  }
}

std::string P004_reverseWords(std::string s) {
  trim(s);
  std::vector<std::string> v = split(s);
  std::reverse(v.begin(), v.end());
  return implode(v);
}

TEST_CASE("P004: reverse words") {
  { CHECK("blue is sky the" == P004_reverseWords("the sky is blue")); }
  { CHECK("world hello" == P004_reverseWords("  hello world ")); }
  { CHECK("example good a" == P004_reverseWords("a good  example")); }
}
