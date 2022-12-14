



// Accepted


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
    int most;
    TreeNode* pre;
    void travel(TreeNode* root){
      if(root==nullptr)
        return;
      travel(root->left);
      if(pre != nullptr){
        int temp = root->val - pre->val;
        most = temp < most ? temp:most;
      }
      pre = root;
      travel(root->right);
    }
  public:
    int getMinimumDifference(TreeNode* root) {
      most = INT_MAX;
      pre = nullptr;
      travel(root);
      return most;
    }
};
