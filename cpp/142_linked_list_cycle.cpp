





#include <iostream>
#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
      ListNode* fast = head;
      ListNode* low = head;
      while (fast != NULL && fast->next != NULL) {
        low = low->next;
        fast = fast->next->next;
        if(fast == low){
          fast = head;
          while (fast != low){
            fast = fast->next;
            low = low->next;
          }
          return fast;
        }
      }
      return NULL;
    }
};
