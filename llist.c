#include "llist.h"

extern LLIST* createLinkedListNode(void *p_new_data, _UNUSED_ unsigned int iFlags) {
    LLIST* p_return = NULL;
    p_return = (LLIST*)malloc(sizeof(LLIST));

    p_return->p_next     = NULL;
    p_return->p_previous = NULL;

    if(p_new_data != NULL) {
        p_return->p_data   = p_new_data;
    } else {
        p_return->p_data = NULL;
    }

    return p_return; 
}

extern LLIST* getLastNode(LLIST *p_llist) {
    LLIST* p_return = p_llist;

    while(p_return->p_next != NULL) {
        p_return = p_return->p_next;  
    }

    return p_return;
}

extern LLIST* getFirstNode(LLIST *p_llist) {
    LLIST* p_return = p_llist;

    while(p_return->p_previous != NULL) {
        p_return = p_return->p_previous;  
    }

    return p_return;
}

extern void appendNodeAtEnd(LLIST *p_llist, void *p_new_data, unsigned int iFlag) {
    LLIST *p_last_node = NULL;

    p_last_node         = getLastNode(p_llist);
    p_last_node->p_next = createLinkedListNode(p_new_data, iFlag);
    p_last_node->p_next->p_previous = p_last_node;
}

extern void appendNodeAtStart(LLIST *p_llist, void *p_new_data, unsigned int iFlag) {
    LLIST *p_start_node = NULL;
    LLIST *p_new_node  = NULL;

    p_start_node             = getFirstNode(p_llist);

    p_new_node = createLinkedListNode(p_new_data, iFlag);
    p_new_node->p_next = p_start_node;
    p_start_node->p_previous = p_new_node;
}

extern void deleteNodeWithIndex(LLIST *p_llist, int iIndex) {
    LLIST *p_node = getFirstNode(p_llist);

    for(int i = 0; i < iIndex; i++) {
        p_node = p_node->p_next;

        if(p_node == NULL) {
            return;
        }
    }


}
