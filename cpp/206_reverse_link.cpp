
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
      ListNode* before = nullptr;
      while(head != nullptr){
        ListNode* temp = head->next;
        head->next = before;
        before = head;
        head = temp;
      }
      return before;
    }
};

