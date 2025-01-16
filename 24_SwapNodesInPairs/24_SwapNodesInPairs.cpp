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
    ListNode* swapPairs(ListNode* head) {
        ListNode* ptr = head;
        ListNode* node_ptr = head;
        ListNode* prev = new ListNode(0, head);
        if (node_ptr != nullptr && head->next != nullptr) 
            ptr = head->next;
            
        while (node_ptr != nullptr && node_ptr->next != nullptr) {
            ListNode* temp = node_ptr->next->next;
            node_ptr->next->next = node_ptr;
            prev->next = node_ptr->next;            
            node_ptr->next = temp;
            prev = node_ptr;
            node_ptr = temp;
        }
        head = ptr;
        return head;
    }
};

//cout << node_ptr->next->val << " " << endl;
//cout << prev->next->val << " " << endl;