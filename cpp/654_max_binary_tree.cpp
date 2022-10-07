







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
  public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      vector<int> temp = nums;

      stack<int> s;
      stack<TreeNode**> s_node;
      TreeNode* res = nullptr;

      if(nums.size() != 0){
        s.push(0);
        s_node.push(&res);
      }

      while (!s.empty()) {
        TreeNode** node = s_node.top();
        int start = s.top();
        s.pop();
        s_node.pop();

        int root = start;
        int i = start;
        while (i != temp.size() && temp[i] != -1) {
          root = temp[i] > temp[root] ? i:root;
          i++;
        }
        *node = new TreeNode(temp[root]);
        temp[root] = -1;
        if(temp[start] != -1){
          s.push(start);
          s_node.push(&(*node)->left);
        }
        if(root+1 != temp.size() && temp[root+1] != -1){
          s.push(root+1);
          s_node.push(&(*node)->right);
        }
      }
      return res;
    }
};
