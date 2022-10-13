







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
    TreeNode* deleteNode(TreeNode* root, int key) {
      TreeNode** pos = &root;
      while (*pos != nullptr)
      {
        TreeNode* temp = *pos;
        if(temp->val == key){
          break;
        }
        pos = temp->val > key ? &temp->left : &temp->right;
      }
      if(*pos == nullptr){
        return root;
      }
      TreeNode** target = nullptr;
      if((*pos)->left != nullptr){
        target = &(*pos)->left;
        while ((*target)->right != nullptr) {
          target = &(*target)->right;
        }
        TreeNode* temp = *target;
        *target = temp->left;
        temp->right = (*pos)->right;
        temp->left = (*pos)->left;
        delete *pos;
        (*pos) = temp;
        return root;
      }
      TreeNode* temp = *pos;
      *pos = temp->right;
      delete temp;
      return root;
    }
};
