#include <iostream>

using namespace std;

  //Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* head_ptr = head;
        ListNode* prev = head;
        int last = 0;
        while (head != NULL)
        {
            if (last == head->val)   // delete node
            {
                prev->next = head->next;
            }
            else
            {
                last = head->val;
                prev = head;
            }
            head = head->next;
        }
        head = head_ptr;
        return head;
    }
};
