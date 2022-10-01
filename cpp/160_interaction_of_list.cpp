


#include <iostream>
#include <vector>



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode* point1 = headA;
      ListNode* point2 = headB;
      while (point1 != nullptr && point2 != nullptr) {
        point1 = point1->next;
        point2 = point2->next;
      }
      ListNode* start1 = headA;
      ListNode* start2 = headB;
      while(point1 != nullptr){
        start1 = start1->next;
        point1 = point1->next;
      }
      while(point2 != nullptr){
        start2 = start2->next;
        point2 = point2->next;
      }
      while (start1 != start2) {
        start1 = start1->next;
        start2 = start2->next;
      }
      return start1;
    }
};
