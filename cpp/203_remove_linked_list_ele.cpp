

#include <iostream>
#include <vector>

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
  public:
    ListNode* removeElements(ListNode* head, int val) {
      ListNode** point = &head;
      while (*point != nullptr) {
        if((*point)->val == val){
          *point = (*point)->next;
        } else {
          point = &(*point)->next;
        }
      }
      return head;
    }
};
