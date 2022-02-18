#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <string>
#include <queue>
using namespace sol2098;
using namespace std;

/*takeaways
  - the key is to sort the input and sum up the top
    k numbers.
    - if the sum is an even number, we are done.
    - or we need to test two things:
      - if we can swap out the minimum even number
        in the top k with the max odd number in
        the top k-1 to produce an even number sum
      - if we can swap out the minimum odd number
        in the top k with the max even number in
        the top k-1 to produce an even number sum
      - pick whichever is bigger

*/

int Solution::maxEvenSum(vector<int> &nums, int k)
{
  const int n = nums.size();
  /* biggest number at the end */
  sort(begin(nums), end(nums));
  /*C++ notes
    - don't forget end() is one off the very
      last element
  */
  auto sum = accumulate(end(nums) - k, end(nums), 0);
  /*
     - the sum of the of the top K numbers is even;
       we are done here
  */
  if (sum % 2 == 0)
    return sum;

  /* sum is an odd number after this point */

  int minO = -1, minE = -1, maxO = -1, maxE = -1;

  /*
    - within the top K numbers, find the smallest
      even and odd numbers so we can swap one
      of them out, depending on what we can find
      within the top K-1 numbers, to get an even
      sum
    - you might be thinking why can't we scan
      from left to right as the numbers are
      sorted? You can but in the end the code
      will be more complicated as you need to
      when to stop scanning for even numbers
      and odd numbers separately
  */
  for (auto i = n - 1; i >= n - k; i--)
  {
    if (nums[i] % 2 == 0)
      minE = nums[i];
    else
      minO = nums[i];
  }
  /*
    - find the max even and odd numbers from the
      top k -1 numbers
  */
  for (auto i = 0; i < n - k; i++)
  {
    if (nums[i] % 2 == 0)
      maxE = nums[i];
    else
      maxO = nums[i];
  }

  auto result = -1;

  /*
    - you need to test both, swapping out even
      or odd number from the top K if you can
      as we don't know which one will result in
      a larger sum
  */
  if (maxE != -1 && minO != -1)
    /* swap out the minimum odd number */
    result = max(result, sum - minO + maxE);
  if (maxO != -1 && minE != -1)
    result = max(result, sum - minE + maxO);

  return result;
}