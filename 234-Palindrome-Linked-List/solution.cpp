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
    ListNode* reverse(ListNode* node){
        if( node == NULL) return node;
        ListNode* prev = node;
        ListNode* cur= prev->next;
        ListNode* nxt= cur;
        while( cur){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur= nxt;
        }
        node->next = NULL;
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if( head == NULL) return true;
        ListNode* slowNode = head;
        ListNode* fastNode = head;
        while( fastNode->next!=NULL && fastNode->next->next!=NULL){
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;
        }
        ListNode* secondHalf = slowNode->next;
        ListNode* reversedNode = reverse(secondHalf);
        while( reversedNode){
            if( reversedNode->val != head->val)  return false;
            reversedNode = reversedNode->next;
            head = head->next;
        }
        return true;
    }
    

};