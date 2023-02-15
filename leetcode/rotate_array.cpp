#include <vector>
#include <utility>

#include "gtest/gtest.h"

using namespace std;

void rotate(vector<int>& nums, int k) {
    vector<int> tmp;
    tmp.reserve(nums.size());
    k = nums.size() - k % nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        tmp.push_back(nums[(i + k) % nums.size()]);
    }

    nums = move(tmp);
}

TEST(rotate_array, test) 
{
    vector<tuple<vector<int>, int, vector<int>>> test_cases =
    {
        {{1,2,3,4,5,6,7}, 3, {5,6,7,1,2,3,4}},
      //  {{1,2,3,4,5}, 4},
        //{{7,6,4,3,1}, 0}
    };

    for( auto & [inp_vect, k, expected] : test_cases)
    {
        rotate(inp_vect, k);
        EXPECT_EQ(inp_vect, expected);
    }
}