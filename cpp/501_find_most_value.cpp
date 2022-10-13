







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
    int count;
    int most;
    vector<int> res;
    TreeNode* pre;
    void travel(TreeNode* root){
      if(root==nullptr)
        return;
      travel(root->left);

      if(pre != nullptr){
        if(root->val != pre->val){
          if(most < count){
            most = count;
            res.clear();
            res.push_back(pre->val);
          } else if(most == count){
            res.push_back(pre->val);
          }
          count = 0;
        }
      }
      count++;
      pre = root;
      travel(root->right);
    }
  public:
    vector<int> findMode(TreeNode* root) {
      pre = nullptr;
      count = 0;
      most = INT_MIN;
      res.clear();
      travel(root);
      if(most < count){
        most = count;
        res.clear();
        res.push_back(pre->val);
      } else if(most == count){
        res.push_back(pre->val);
      }
      return res;
    }
};
