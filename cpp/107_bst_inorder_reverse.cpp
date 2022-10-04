







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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int> > res;
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
        row.push_back(temp->val);
        if(temp==end){
          res.push_back(row);
          row = vector<int>();
          end = end_temp;
        }
      }
      reverse(res.begin(), res.end());
      return res;
    }
};
