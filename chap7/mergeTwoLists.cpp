/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1 && !l2)
        return l1;
    if(!l1 && l2)
        return l2;
    if(l1 && !l2)
        return l1;
    ListNode *p = l1, *q = l2, *head, *cur;
    if((l1->val)<(l2->val)){
        head = p;
        cur = p;
        p = p->next;
    }else{
        head = q;
        cur = q;
        q = q->next;
    }
    while(p || q){
        if(p && q){
            if(p->val<q->val){
                cur ->next = p;
                cur = cur->next;
                p = p->next;
            }else{
                cur ->next = q;
                cur = cur->next;
                q = q->next;
            }
        }else if(p && !q){
            cur -> next = p;
            return head;
        }else if(!p && q){
            cur -> next = q;
            return head;
        }
    }
}