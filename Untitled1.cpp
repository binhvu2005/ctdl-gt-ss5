#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *pre;
};
typedef struct Node *node;
node createNode(int data)
{
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->pre = NULL;
    return newNode;
}
int main()
{
    int n;
    printf("Nhap so phan tu cua danh sach lien ket: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Danh sach trong");
        return 0;
    }
    node head = NULL;
    node tail = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        node newNode = createNode(data);
         if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
        }
    }
    
    printf("Danh sach lien ket vua nhap: ");
    node currentNode = tail;
    while (currentNode != NULL)
    {
        printf("%d", currentNode->data);
        if (currentNode->pre != NULL)
        {
            printf(" <-> ");
        }
        currentNode = currentNode->pre;
    }
    printf(" <-> NULL\n");

    currentNode = tail;
    while (currentNode != NULL)
    {
        node temp = currentNode;
        currentNode = currentNode->pre;
        free(temp);
    }
}
