

#include <iostream>
#include <vector>


class MyLinkedList {
  public:
    struct LinkedNode {
      int val;
      LinkedNode* next;
      LinkedNode(int val):val(val), next(nullptr){}
    };
    LinkedNode* head;
    int size;
    MyLinkedList() {
      head = nullptr;
      size = 0;
    }
    int get(int index) {
      LinkedNode* point = head;
      if (index > (size - 1) || index < 0) {
        return -1;
      }
      while (index--) {
        point = point->next;
      }
      return point->val;
    }

    void addAtHead(int val) {
      LinkedNode* new_val = new LinkedNode(val);
      new_val->next = head;
      head = new_val;
      size++;
    }

    void addAtTail(int val) {
      LinkedNode* new_val = new LinkedNode(val);
      LinkedNode** point = &head;
      while (*point != nullptr) {
        point = &(*point)->next;
      }
      *point = new_val;
      size++;
    }

    void addAtIndex(int index, int val) {
      LinkedNode* new_val = new LinkedNode(val);
      if (index > size) {
        return;
      }
      if(index < 0){
        addAtHead(val);
        return;
      }
      LinkedNode** point = &head;
      while (index--) {
        point = &(*point)->next;
      }
      new_val->next = *point;
      *point = new_val;
      size++;
    }

    void deleteAtIndex(int index) {
      LinkedNode** point = &head;
      if (index > size-1) {
        return;
      }
      while (index--) {
        point = &(*point)->next;
      }
      *point = (*point)->next;
      size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
