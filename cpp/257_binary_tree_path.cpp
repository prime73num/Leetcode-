
#include <iostream>
#include <vector>

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
    void count(TreeNode* root, string begin, vector<string>& res){
      if(root->left==nullptr && root->right==nullptr){
        res.push_back(begin + std::to_string(root->val));
      }
      begin += std::to_string(root->val) + "->";
      if(root->left != nullptr){
        count(root->left, begin, res);
      }
      if(root->right != nullptr){
        count(root->right, begin, res);
      }
    }
  public:
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<string> res;
      if(root != nullptr){
        count(root, "", res);
      }
      return res;
    }
};
