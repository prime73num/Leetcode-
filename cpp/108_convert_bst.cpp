





#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
  private:
    TreeNode* travel(vector<int>& nums, int begin, int end){
      if(begin == end) return nullptr;
      int mid = (begin+end)/2;
      TreeNode* res = new TreeNode(nums[mid]);
      res->left = travel(nums, begin, mid);
      res->right = travel(nums, mid+1, end);
      return res;
    }
  public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return travel(nums, 0, nums.size());
    }
};
