#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode {
    void* data;
    struct LinkedListNode* next;
} LinkedListNode;

typedef LinkedListNode LinkedList;

LinkedListNode* createLinkedList(void* data);
LinkedListNode* addToLinkedList(LinkedListNode* head, void* data);
void removeFromLinkedList(LinkedListNode* head, void* data);
void deleteLinkedList(LinkedListNode* head);

#define FOR_EACH(ll, code) {\
  LinkedListNode* curr = ll;\
  while(curr != NULL) {\
    void* data = curr->data;\
    code\
    curr = curr->next;\
  }\
}

#endif