



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
    struct MyNode {
      bool expanded;
      TreeNode* node;
      MyNode(bool expanded, TreeNode* node)
        :expanded(expanded), node(node)
      {}
    };
  public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> res;
      stack<MyNode> s;
      if(root != nullptr){
        s.emplace(false, root);
      }
      while (!s.empty()) {
        MyNode temp = s.top();
        s.pop();
        if(temp.expanded){
          res.push_back(temp.node->val);
        } else {
          if(temp.node->right != nullptr){
            s.emplace(false, temp.node->right);
          }
          if(temp.node->left != nullptr){
            s.emplace(false, temp.node->left);
          }
          s.emplace(true, temp.node);
        }
      }
      return res;
    }
};

int main (int argc, char *argv[])
{
  Solution sol;
  return 0;
}
