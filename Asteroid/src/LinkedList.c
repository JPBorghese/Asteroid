
#include "LinkedList.h"
#define NULL 0


LinkedListNode* createLinkedList(void* data) {
    LinkedListNode* result = malloc(sizeof(LinkedListNode));
    result->data = data;
    result->next = NULL;
    return result;
    return NULL;
}

LinkedListNode* addToLinkedList(LinkedListNode* head, void* data) {
    if(head == NULL) return NULL;
    LinkedListNode* curr = head;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = createLinkedList(data);
    return NULL;
}

void removeFromLinkedList(LinkedListNode* head, void* data) {
    if(head == NULL) return;
    LinkedListNode* curr = head;
    LinkedListNode* prev = NULL;
    while(curr != NULL && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }
    if(curr->data == data) {
        if(prev != NULL) {
            prev->next = curr->next;
        }
    }
}

void deleteLinkedList(LinkedListNode* head) {
    if(head != NULL) {
        deleteLinkedList(head->next);
        free(head);
    }
}

// imptovrd hversion f nob code
#define FOR_EACH(ll, code) {\
  LinkedListNode* curr = ll;\
  while(curr != NULL) {\
    void* data = curr->data;\
    code\
    curr = curr->next;\
  }\
}