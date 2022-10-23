







#include <iostream>
#include <vector>

using namespace std;


class Solution {
  struct list
  {
    int value;
    list* next;
    list(int value){
      this->value = value;
      this->next = nullptr;
    }
  };
  private:
    void travel(vector<vector<int>>&res, list* nums){
      if(nums == nullptr){
        res.push_back(vector<int>());
        return;
      }
      for (list** it = &nums; *it != nullptr; it = &(*it)->next) {
        list* temp = (*it);
        *it = temp->next;
        int size = res.size();
        travel(res, nums);
        *it = temp;
        for (int i = size; i < res.size(); i++) {
          res[i].push_back(temp->value);
        }
      }
    }
  public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      list* head = nullptr;
      for (auto i: nums) {
        list* temp = new list(i);
        temp->next = head;
        head = temp;
      }
      travel(res, head);
      return res;
    }
};
