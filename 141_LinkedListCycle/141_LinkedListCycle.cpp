#include <iostream>

using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* head_ptr = head;
        if (head == NULL)
            return false;

        if (head->next == NULL)
            return false;

        while (head != NULL) {
            if (head->val == -1000)
                return true;

            else
                head->val = -1000;
            head = head->next;
        }
        return false;
    }
};