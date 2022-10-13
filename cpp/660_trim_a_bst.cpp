



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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
      TreeNode** pos = &root;
      while ((*pos) != nullptr)
      {
        if((*pos)->val == low){
          break;
        }
        if( low > (*pos)->val ){
          *pos = (*pos)->right;
        } else {
          pos = &(*pos)->left;
        }
      }
      if((*pos) != nullptr){
        (*pos)->left = nullptr;
      }
      pos = &root;
      while ((*pos) != nullptr)
      {
        if((*pos)->val == high){
          break;
        }
        if( high < (*pos)->val ){
          *pos = (*pos)->left;
        } else {
          pos = &(*pos)->right;
        }
      }
      if((*pos) != nullptr){
        (*pos)->right = nullptr;
      }
      return root;
    }
};
