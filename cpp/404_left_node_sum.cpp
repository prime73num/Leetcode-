
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
    int sumOfLeftLeaves(TreeNode* root) {
      int sum = 0;
      queue<TreeNode*> q;

      q.push(root);

      while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if(temp != nullptr){
          TreeNode* left = temp->left;
          if(left != nullptr){
            if(left->left == nullptr && left->right == nullptr){
              sum += temp->left->val;
            }
          }
          q.push(temp->left);
          q.push(temp->right);
        }
      }
      return sum;
    }
};
