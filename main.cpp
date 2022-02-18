#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol2098;

/*
Input: arr[] ={4, 2, 6, 7, 8}, K = 3
Output: 18
*/
tuple<vector<int>, int, int> testFixture1()
{
  return make_tuple<vector<int>, int, int>(
      {4, 2, 6, 7, 8}, 3, 18);
}

/*
Input: arr[] = {5, 5, 1, 1, 3}, K = 3
Output: -1
*/
tuple<vector<int>, int, int> testFixture2()
{
  return make_tuple<vector<int>, int, int>(
      {5, 5, 1, 1, 3}, 3, -1);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<2>(f)) << endl;
  auto result = Solution::maxEvenSum(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << to_string(get<2>(f)) << endl;
  auto result = Solution::maxEvenSum(get<0>(f), get<1>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}