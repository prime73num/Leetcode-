


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode** point1 = &head;
      ListNode** point2 = &head;
      while (point2 != nullptr && n--) {
        point2 = &(*point2)->next;
      }
      while(*point2 != nullptr){
        point1 = &(*point1)->next;
        point2 = &(*point2)->next;
      }
      *point1 = (*point1)->next;
      return head;
    }
};
