/*
141. Linked List Cycle  QuestionEditorial Solution  My Submissions
Total Accepted: 130406 Total Submissions: 359349 Difficulty: Easy
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return false;
        ListNode *slow = head;
        ListNode *fast = head;
        do{
            slow = slow->next;
            fast = fast->next->next;
        }while(fast && fast->next && fast!=slow);
        
        return fast == slow; 
    }
};
