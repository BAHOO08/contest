#include <vector>
#include <utility>

#include "gtest/gtest.h"

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;

    int max_profit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        auto delta = prices[i] - prices[i - 1];
        max_profit = delta > 0 ? delta + max_profit : max_profit;
    }
    
    return max_profit;
}

TEST(Best_Time_to_Buy_and_Sell_Stock, returnTest) 
{
    vector<pair<vector<int>, int>> test_cases =
    {
        {{7,1,5,3,6,4}, 7},
        {{1,2,3,4,5}, 4},
        {{7,6,4,3,1}, 0}
    };

    for( auto & [inp_vect, expected] : test_cases)
    {
        auto actual = maxProfit(inp_vect);
        EXPECT_EQ(actual, expected);
    }
}