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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prevGroupEnd = dummy;
        ListNode* end = head;

           while (end) {
            // Check if there are at least k nodes to reverse
            for (int i = 1; i < k && end; ++i) {
                end = end->next;
            }
            if (!end) break;

            // Reverse k nodes
            ListNode* nextGroupStart = end->next;
            ListNode* prev = nextGroupStart;
            ListNode* curr = prevGroupEnd->next;

            while (curr != nextGroupStart) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Update pointers for the next group
            ListNode* temp = prevGroupEnd->next;
            prevGroupEnd->next = end;
            prevGroupEnd = temp;
            end = prevGroupEnd->next;
        }

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
