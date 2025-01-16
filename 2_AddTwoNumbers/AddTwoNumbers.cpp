#include <iostream>
//#include <string>
//#include <vector>
//
using namespace std;
//
//struct ListNode {
//    int val = 0;
//    ListNode* next;
//    ListNode(int x) :val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
///*void input(vector<int>* l) {
//    int temp = 0;
//    while (cin.get() != '\n') {
//        cin >> temp;
//        l->push_back(temp);
//    }
//};*/
//
//int main() {
//    //vector<int> l1;
//    //vector<int> l2;
//    ListNode* l1{};
//    ListNode* l2{};
//    ListNode* ptr{};
//    int temp = 0;
//    ptr = l1;
//    while (cin >> temp) {
//        //l1.push_back(temp);
//        ListNode* t{};
//        ptr-> val = temp;
//        ptr-> next = t;
//        ptr = ptr->next;
//        if (cin.peek() == '\n')
//            break;
//    }
//    cout << "l1 input" << endl;
//    
//    temp = 0;
//    ptr = l2;
//    while (cin >> temp) {
//        //l2.push_back(temp);
//        ListNode* t{};
//        t->val = temp;
//        ptr->next = t;
//        ptr = t;
//        if (cin.peek() == '\n')
//            break;
//    }
//    cout << "l2 input" << endl;
//
//
//
//    /*for (int i = 0; i <l1.size(); i++)
//        cout << l1[i] << " ";
//
//    cout << endl;
//
//    for (int i = 0; i < l2.size(); i++)
//        cout << l2[i] << " ";*/
//
//}






 //* Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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
};