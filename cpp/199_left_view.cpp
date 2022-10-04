








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
    vector<int> rightSideView(TreeNode* root) {
      vector<int> row;
      queue<TreeNode*> q;

      TreeNode* end = root;
      TreeNode* end_temp;
      if(root != nullptr){
        q.push(root);
      }

      while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if(temp->left != nullptr){
          q.push(temp->left);
          end_temp = temp->left;
        }
        if(temp->right != nullptr){
          q.push(temp->right);
          end_temp = temp->right;
        }
        if(temp==end){
          row.push_back(end->val);
          end = end_temp;
        }
      }
      return row;
    }
};
