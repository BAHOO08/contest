#include <vector>
#include <span>

#include "gtest/gtest.h"

int getNextUnique(const std::vector<int>&nums, int index)
{
    int inp_value = nums[index];
    for(;index < nums.size() && nums[index] == inp_value; index++);
    return index;
}

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0;

    int index = 0;

    for(int r = 0; r < nums.size();)
    {
        int next_unique = getNextUnique(nums, r);
        nums[index++] = nums[r];
        r = next_unique;
    }

    return index;
}

TEST(removeDublicates, returnTest) 
{
    using std::vector;
    vector<int> expected;
    EXPECT_EQ(removeDuplicates(expected), 0);

    expected.push_back(1);
    EXPECT_EQ(removeDuplicates(expected), 1);
    
    expected = {1,1,2};
    EXPECT_EQ(removeDuplicates(expected), 2);
}

TEST(removeDublicates, arrDataTest) 
{
    using std::vector;
    vector<int> input_arr;
    int size = removeDuplicates(input_arr);
    vector<int> expected;
    EXPECT_EQ(input_arr, vector<int> {});

    input_arr.push_back(1);
    removeDuplicates(input_arr);
    EXPECT_EQ(input_arr, vector<int> {1});
    
    input_arr = {1,1,2};
    size = removeDuplicates(input_arr);
    vector<int> actual(input_arr.begin(), input_arr.begin() + size);
    expected = {1,2};
    EXPECT_EQ(actual, expected);


    input_arr = {1,1,2,2,2,3,3};
    size = removeDuplicates(input_arr);
    actual = vector<int> {input_arr.begin(), input_arr.begin() + size};
    expected = {1,2, 3};
    EXPECT_EQ(actual, expected);
}