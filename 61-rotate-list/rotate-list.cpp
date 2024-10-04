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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL) return NULL;
        if(k == 0 || head->next  == NULL) return head;

        // Count the Total Number of Nodes
        int Num = 0;
        ListNode* temp = head,*tail = head;
        while(temp != NULL)
        {
            tail = temp;
            temp = temp->next;
            Num++;
        }

        k = (k%Num);
        if(k == 0) return head;

        ListNode *prev = head, *curr = head;
        int cnt = (Num-k-1);
        while(cnt--)
        {
            curr = curr->next;
        }
        prev = curr->next;
        curr->next = NULL;
        tail->next = head;
        return prev;
    }
};

// Rotate the Linked List by K places