#include <iostream>

using namespace std;

 // Definition for singly-linked list.
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
        ListNode* ans = new ListNode();
        ListNode* new_head = nullptr;
        while (head != NULL) {
            ListNode* curr = new ListNode(head->val, head->next);
            curr->next = new_head;
            new_head = curr;
            head = head->next;
        }
        return new_head;
    }
};