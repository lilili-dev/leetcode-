#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

static struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if(l1==NULL){
        return l2;
    }
    if(l2==NULL){
        return l1;
    }
   if(l1->val<=l2->val){
       l1->next = mergeTwoLists(l1->next, l2);
       return l1;
   }else{
       l2->next = mergeTwoLists(l1, l2->next);
       return l2;
   }
 
    
}

int main(int argc, char **argv)
{
    struct ListNode l1;
    l1.val = 2;
    l1.next = NULL;
    struct ListNode l2;
    l2.val = 1;
    l2.next = NULL;
    struct ListNode * list = mergeTwoLists(&l1, &l2);
    while (list != NULL) {
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n");
    return 0;
}
