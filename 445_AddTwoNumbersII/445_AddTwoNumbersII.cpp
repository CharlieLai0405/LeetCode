#include <iostream>

using namespace std;


 // Definition for singly-linked list.
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

    ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* ptr = ans;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            ListNode* temp = new ListNode();
            if (l1 != NULL && l2 != NULL) {
                ans->val = l1->val + l2->val + carry;
                carry = ans->val / 10;
                cout << ans->val << " 22" << endl;
                cout << carry << " 23" << endl;
                if (ans->val >= 10) {
                    // cout << carry << endl;
                    ans->val = ans->val % 10;
                    cout << ans->val << " 27" << endl;
                    if (l1->next == NULL || l2->next == NULL) {
                        ListNode* Tptr;
                        if (l1->next == NULL && l2->next != NULL &&
                            l2->next->val + carry >= 10) {
                            Tptr = l2;
                            while (l2->next != NULL) {
                                l2->next->val += carry;
                                carry = l2->next->val / 10;
                                l2->next->val = l2->next->val % 10;
                                l2 = l2->next;
                            }
                            if (carry != 0) {
                                cout << carry << " 40" << endl;
                                ListNode* t = new ListNode(carry);
                                l2->next = t;
                            }
                            l2 = Tptr;
                        }
                        else if (l2->next == NULL && l1->next != NULL &&
                            l1->next->val + carry >= 10) {
                            Tptr = l1;
                            while (l1->next != NULL) {
                                l1->next->val += carry;
                                carry = l1->next->val / 10;
                                l1->next->val = l1->next->val % 10;
                                l1 = l1->next;
                            }
                            if (carry != 0) {
                                cout << carry << " 55" << endl;
                                ListNode* t = new ListNode(carry);
                                l1->next = t;
                            }
                            l1 = Tptr;
                        }
                        else if (l1->next == NULL && l2->next == NULL) { //  l1->next == NULL && l2->next == NULL
                            cout << carry << " 61" << endl;
                            ListNode* t = new ListNode(carry);
                            ans->next = t;
                            ans = ptr;
                            return ans;
                        }
                        else if (l1->next == NULL && l2->next != NULL &&
                            l2->next->val + carry < 10)
                        {
                            l2->next->val += carry;
                        }
                        else if (l1->next != NULL && l2->next == NULL &&
                            l1->next->val + carry < 10)
                        {
                            l1->next->val += carry;
                        }
                    }
                }
                if (l1->next != NULL && l2->next != NULL) {
                    ans->next = temp;
                    ans = ans->next;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1 == NULL) {
                ans->next = l2;
                break;
            }
            else if (l2 == NULL) {
                ans->next = l1;
                break;
            }
        }
        ans = ptr;
        return ans;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* l1_reverse;
        ListNode* l2_reverse;
        ListNode* ans;
        l1_reverse = reverseList(l1);
        l2_reverse = reverseList(l2);

        ans = AddTwoNumbers(l1_reverse, l2_reverse);

        ans = reverseList(ans);

        return ans;

    }
};

/*
ListNode* last_l1;
        ListNode* last_l2;
        ListNode* head_l1 = l1;
        ListNode* head_l2 = l2;
        int count_l1 = 0;
        int count_l2 = 0;

        for (; l1 != NULL; l1 = l1->next) {
            last_l1 = l1;
            cout << last_l1->val << endl;
            count_l1++;
        }
        l1 = head_l1;
        for (; l2 != NULL; l2 = l2->next) {
            last_l2 = l2;
            cout << last_l2->val << endl;
            count_l2++;
        }
        l2 = head_l2;

        int count = 0;
        int loop = 0;
        if (count_l1 >= count_l2) {
            while (count_l2 != 0) {
                last_l1->val = last_l1->val + last_l2->val + count;
                count = last_l1->val / 10;
                if (last_l1->val >= 10) {
                    last_l1->val = last_l1->val % 10;
                    loop++;

                    for (int i = 0; i < count_l1 - loop; i++) {
                        last_l1 = l1;
                        l1 = l1->next;
                    }
                    l1 = head_l1;
                    for (int i = 0; i < count_l2 - loop; i++) {
                        last_l2 = l2;
                        l2 = l2->next;
                    }
                    if (count_l2 == loop) {
                        last_l2 = l2;
                        l2 = l2->next;
                    }
                    l2 = head_l2;
                    count_l2--;
                }
                for (int i = 0; i < count_l1 - loop; i++) {
                    last_l1 = l1;
                    l1 = l1->next;
                }
                l1 = head_l1;
                while (count != 0 && count_l1 != loop) {
                    last_l1->val += count;
                    count = last_l1->val / 10;
                    if (last_l1->val >= 10)
                        last_l1->val = last_l1->val % 10;
                    for (int i = 0; i < count_l1 - loop; i++) {
                        last_l1 = l1;
                        l1 = l1->next;
                    }
                    l1 = head_l1;
                    loop++;
                }
                if (l1->val >= 10) {
                    ListNode* temp = new ListNode(l1->val / 10, l1);
                    l1->val %= 10;
                }
                return l1;
            }
        }
        else {      //   count_l1 < count_l2
            while (count_l1 != 0) {
                cout << "35_last_l1->val¡G " << last_l1->val << endl;
                cout << "36_last_l2->val¡G " << last_l2->val << endl;
                last_l2->val = last_l1->val + last_l2->val + count;
                cout << "37_last_l1->val¡G " << last_l2->val << endl;
                count = last_l2->val / 10;
                cout << "39_count¡G " << count << endl;
                if (last_l2->val >= 10) {
                    last_l2->val = last_l2->val % 10;
                    cout << "count¡G " << count << endl;
                    cout << "42_last_l1->val¡G " << last_l2->val << endl;
                }
                loop++;

                for (int i = 0; i < count_l1 - loop; i++) {
                    last_l1 = l1;
                    l1 = l1->next;
                }
                cout << "l1: " << last_l1->val << endl;
                l1 = head_l1;
                for (int i = 0; i < count_l2 - loop; i++) {
                    last_l2 = l2;
                    l2 = l2->next;
                }
                if (count_l1 == loop) {
                    last_l2 = l2;
                    l2 = l2->next;
                }
                cout << "l1: " << last_l1->val << endl;
                l2 = head_l2;
                count_l1--;
            }

            for (int i = 0; i < count_l2 - loop; i++) {
                last_l2 = l2;
                l2 = l2->next;
            }
            l2 = head_l2;

            while (count != 0 && count_l2 != loop) {
                last_l2->val += count;
                count = last_l2->val / 10;
                if (last_l2->val >= 10)
                    last_l2->val = last_l2->val % 10;
                for (int i = 0; i < count_l2 - loop; i++) {
                    last_l2 = l2;
                    l2 = l2->next;
                }
                l2 = head_l2;
                loop++;
            }

            if (l2->val >= 10 || count != 0) {
                ListNode* temp = new ListNode(count, l2);
                l2->val %= 10;
                return temp;
            }
            return l2;
*/
