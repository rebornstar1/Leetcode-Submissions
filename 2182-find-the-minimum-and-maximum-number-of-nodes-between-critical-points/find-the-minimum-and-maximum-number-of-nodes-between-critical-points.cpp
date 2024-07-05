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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == NULL) return {-1,-1};
        int ab = INT_MIN;
        int cd = INT_MAX;
        int cnt = 0;
        ListNode* prev = head;
        ListNode* curr = head->next;
        vector<int>check;
        while(curr->next != NULL)
        {
            if(prev->val > curr->val && curr->next->val > curr->val)
            {
                check.push_back(cnt);
            }
            if(prev->val < curr->val && curr->next->val < curr->val)
            {
                check.push_back(cnt);
            }
            curr = curr->next;
            prev = prev->next;
            cnt++;
        }

        if(check.size() == 1 || check.size() == 0) return {-1,-1};
        int ans = INT_MAX;
        for(int i = 1 ; i < check.size() ; i++ )
        {
           ans = min(ans,check[i]-check[i-1]);
        }
        return {ans,check[check.size()-1]-check[0]};
    }
};