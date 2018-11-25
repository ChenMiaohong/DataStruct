#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct Node* LinkList;//链表
int InitList(LinkList* list) {
    Node* node = (Node*)malloc(sizeof(Node));
    (*list) = node;
    node->next = NULL;
}
int InsertNodeFromHead(LinkList list, int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = list->next;
    list->next = node;
    return 0;
}

int InsertNodeFromTail(LinkList list, int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    while(list->next != NULL) {
        list = list->next;
    }
    list->next = node;
    node->next = NULL;
    return 0;
}

int InsertNodeInLocation(LinkList list, int i, int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    int j = 1;
    while(list->next && j < i) {
        list = list->next;
        ++j;
    }
    node->next = list->next;
    list->next = node;
}

int DeleteNodeInLocation(LinkList list, int i)
{
    int j = 1;
    while(list->next && j < i) {
        list = list->next;
        ++j;
    }
    Node* node = list->next;
    list->next = node->next;
    free(node);
    return 0;
}

int PrintListInfo(LinkList list) {
    printf("==================\n");
    while(list->next != NULL) {
        list = list->next;
        printf("%d\n",list->data);
    }
    return 0;
}
LinkList list;

int main(int argc, char const *argv[])
{
    
   
    int i = 1;
    InitList(&list);
    for(i = 1; i<= 5; i++) {
        InsertNodeFromHead(list, i);
    }
    PrintListInfo(list);
    DeleteNodeInLocation(list, 2);
    PrintListInfo(list);
    for(i = 6; i<= 11; i++) {
        InsertNodeFromTail(list, i);
    }
    PrintListInfo(list);
    /* code */
    return 0;
}
