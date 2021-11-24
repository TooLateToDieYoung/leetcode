
typedef struct ListNode node_t;
node_t * mergeTwoLists(node_t * l1, node_t * l2){
    
    if(!l1) return l2;
    if(!l2) return l1;
    
    node_t list;
    node_t * curr = &list;

    do{
        curr->next = (l1->val < l2->val) ? l1 : l2;
        if(curr->next==l1) l1 = l1->next;
        else l2 = l2->next;
        curr = curr->next;
    }while(l1 && l2);
    
    if(l1) curr->next = l1;
    else curr->next = l2;
    
    return list.next;
}