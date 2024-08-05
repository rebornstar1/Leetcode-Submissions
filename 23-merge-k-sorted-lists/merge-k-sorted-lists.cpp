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
    ListNode* mergeTwo(ListNode* one,ListNode* two)
    {
        if(one == NULL) return two;
        if(two == NULL) return one;

        if(one->val > two->val)
        {
           two->next = mergeTwo(one,two->next);
           return two;
        }
        else
        {
           one->next = mergeTwo(one->next,two);
           return one;
        }

        return NULL;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        
        ListNode* temp = lists[0];
        for(int i = 1 ; i < lists.size() ; i++ )
        {
            temp = mergeTwo(temp,lists[i]);
        }
        return temp;
    }
};

// This might not be the most optimal solution out there