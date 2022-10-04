









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
    vector<double> averageOfLevels(TreeNode* root) {
      vector<double> res;
      double sum = 0;
      int size=0;
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
        sum += temp->val;
        size+=1;
        if(temp==end){
          res.push_back(sum/size);
          sum = 0;
          size = 0;
          end = end_temp;
        }
      }
      return res;
    }
};
