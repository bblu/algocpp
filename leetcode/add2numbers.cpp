/*
2. Add Two Numbers  
Total Accepted: 178916 Total Submissions: 718942 Difficulty: Medium
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain 
a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x=0, y=0, carry=0, sum=0;
        ListNode *head=NULL, **cur=&head;
        while(l1 || l2){
            x = getValAndNext(l1);
            y = getValAndNext(l2);
            sum = carry + x + y;
            
            ListNode *node = new ListNode(sum%10);
            *cur = node;
            cur = &node->next;
            carry = sum/10;
        }
        if(carry>0){
            ListNode *node = new ListNode(carry%10);
            *cur = node;
        }
        return head;
    }
    int getValAndNext(ListNode* &l){
        int x = 0;
        if(l){
            x = l->val;
            l = l->next;
        }
        return x;
    }
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        int i1=0,i2=0;
        while(l1){
            i1 = i1*10 + l1->val;
            l1 = l1->next;
        }
        while(l2){
            i2 = i2*10 + l2->val;
            l2 = l2->next;
        }
        i1+=i2;
        if(i1==0) return new ListNode(0);
        ListNode*  result = NULL;
        ListNode** cur = &result;
        while(i1>0){
            int digit = i1%10;
            i1/=10;
            cout << digit << "|" << i1 << endl;
            ListNode *node = new ListNode(digit);
            *cur = node;
            cur = (&node->next);
        }
        return result;
    }
};
