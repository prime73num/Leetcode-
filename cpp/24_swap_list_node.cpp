

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
    ListNode* swapPairs(ListNode* head) {
      ListNode** point = &head;
      while(*point != nullptr && (*point)->next != nullptr){
        ListNode* next = (*point)->next;
        (*point)->next = next->next;
        next->next = *point;
        *point = next;
        point = &next->next->next;
      }
      return head;
    }
};
