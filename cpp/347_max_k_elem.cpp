









#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
  public:
    class mycomparison {
      public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
          return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> map; // map<nums[i],对应出现的次数>
      for (int i = 0; i < nums.size(); i++) {
        map[nums[i]]++;
      }

      priority_queue<pair<int, int>, vector<pair<int, int> >, mycomparison> pri_que;

      for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
        pri_que.push(*it);
        if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
          pri_que.pop();
        }
      }

      vector<int> result(k);
      for (int i = k - 1; i >= 0; i--) {
        result[i] = pri_que.top().first;
        pri_que.pop();
      }
      return result;

    }
};
