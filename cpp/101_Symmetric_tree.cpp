









#include <iostream>
#include <vector>
#include <queue>

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
    bool isSymmetric(TreeNode* root) {
      queue<TreeNode*> q_left;
      queue<TreeNode*> q_right;

      q_left.push(root);
      q_right.push(root);

      while (!q_left.empty()) {
        TreeNode* temp_left = q_left.front();
        TreeNode* temp_right = q_right.front();
        q_left.pop();
        q_right.pop();
        bool res = temp_left==temp_right;
        if(temp_right != nullptr){
          q_right.push(temp_right->right);
          q_right.push(temp_right->left);
          if(temp_left != nullptr){
            q_left.push(temp_left->left);
            q_left.push(temp_left->right);
            if(temp_left->val == temp_right->val){
              res = true;
            }
          }
        }
        if(!res){
          return false;
        }
      }
      return true;
    }
};
