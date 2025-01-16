#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
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

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp_head = nullptr;
        ListNode* temp_trail = nullptr;
        ListNode* ans_head = nullptr;

        while (head != NULL) {
            int counter = 0;
            int count = 0;
            ListNode* ans_temp = nullptr;

            while (head != NULL && count < k)
            {

                ListNode* curr = new ListNode(head->val, head->next);
                cout << "curr->val¡G " << curr->val << " count¡G " << count << endl;
                curr->next = ans_temp;
                ans_temp = curr;

                head = head->next;
                count++;
            }

            if (counter==0)
                ans_head = ans_temp;
            else 
            {
                temp_head = ans_head;
                while (ans_head != NULL)
                {
                    temp_trail = ans_head;
                    ans_head = ans_head->next;
                }
                ans_head = temp_head;
                temp_trail->next = ans_temp;
            }

            head = head->next;
            counter++;
        }
        return ans_head;
        
    }
};
