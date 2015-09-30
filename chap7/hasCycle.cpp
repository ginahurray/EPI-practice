/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool hasCycle(ListNode *head) {
    ListNode *p = head, *q = head;
    if(!p)
        return false;
    while(p->next!=NULL && p->next->next!=NULL){
        p = p->next->next;
        q = q->next;
        if(p==q)
            return true;
    }
    return false;
}