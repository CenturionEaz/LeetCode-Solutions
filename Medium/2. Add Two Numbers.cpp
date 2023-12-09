/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum_val = carry;
            if (l1) {
                sum_val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum_val += l2->val;
                l2 = l2->next;
            }

            carry = sum_val / 10;
            current->next = new ListNode(sum_val % 10);
            current = current->next;
        }

        return dummy->next;
    }
};
