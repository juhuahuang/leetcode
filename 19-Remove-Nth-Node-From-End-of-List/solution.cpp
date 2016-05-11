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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
       ListNode dummy(-1);
       dummy.next = head;
       ListNode *node1 = head;
       int i = 0;
       while(i<n ){
           node1= node1->next;
           i++;
       }
       ListNode *node2 = head;
       ListNode *pre = &dummy;
       while( node1!=NULL){
           node1 = node1->next;
           node2 = node2->next;
           pre = pre->next;
       }
       pre->next = node2->next;
       return dummy.next;
       
    }
};