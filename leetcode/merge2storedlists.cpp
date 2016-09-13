/*
21. Merge Two Sorted Lists 
Total Accepted: 153517 Total Submissions: 416610 Difficulty: Easy
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
            
        ListNode* result= NULL;
        ListNode* cur= NULL;
            
        while(l1 && l2){
            ListNode *n = NULL;
            if(l1->val < l2->val){
                n = l1;
                l1=l1->next;
            }else{
                n = l2;
                l2=l2->next;
            }
            if(result==NULL){
                result = cur = n;
            }else{
                cur->next = n;
                cur = cur->next;
            }
        }
        if(l1==NULL && l2==NULL){
            cur=NULL;
        }else{
            if(l1) cur->next = l1;
            if(l2) cur->next = l2;
        }
        return result;
    }
};
