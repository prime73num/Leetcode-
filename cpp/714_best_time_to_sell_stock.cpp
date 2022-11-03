









#include <iostream>
#include <vector>

using namespace std;






class Solution {
  public:
    int maxProfit(vector<int>& prices, int fee) {
      int sum = 0;
      int min = INT_MAX;
      int max = INT_MIN;
      for (int i = 0; i < prices.size(); i++) {
        int price = prices[i];
        if(price < min){
          min = price;
          max = price;
        }
        max = price > max ? price:max;
        if(max > min + fee && (i == prices.size()-1 || max >= fee + prices[i+1])){
          sum += max - min - fee;
          min = max;
        }
      }
      return sum;;
    }
};
