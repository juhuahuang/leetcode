/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp{
    bool operator()(const ListNode*a,const ListNode*b)const{
        return a->val>b->val;
    }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode*h=new ListNode(0);
        ListNode *p=h;
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        for(int i=0;i<lists.size();i++)
            if(lists[i]!=NULL)
                pq.push(lists[i]);
        while(!pq.empty()){
            p->next = pq.top();
            p=p->next;
            ListNode*q = p->next;
            pq.pop();
            if(q!=NULL) pq.push(q);
        }
        p=h->next;
        delete(h);
        return p;
    }
};