#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

static struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode dummyhead;
    struct ListNode *iterate_pointer = &dummyhead;
 
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
           iterate_pointer->next = l1;
            l1 = l1->next;
        } else {
            iterate_pointer->next = l2;
            l2 = l2->next;
        }
        iterate_pointer = iterate_pointer->next;
    }

    if (l2 != NULL) {
        iterate_pointer->next = l2;
    }else{
       iterate_pointer->next = l1;
    }

    return dummyhead.next;
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
