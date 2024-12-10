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
void insertNodeByPos(node *head,int data, int pos ){
    node temp=*head;
    node newNode=createNode(data);
    int count=0;
    while (temp->next!=NULL)
    {
        if (count==pos-1)
        {
            (temp->next)->pre=newNode;
            newNode->next=temp->next;
            temp->next=newNode;
            newNode->pre=temp;
            break;
        }
        count++;
        temp=temp->next;
    }
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
    int pos,data;
    printf("Nhap gia tri can tren: ");
    scanf("%d",data);
    printf("Nhap vi tri can tren: ");
    scanf("%d",pos);
    insertNodeByPos(&head,data,pos);
    printf("Danh sach lien ket vua nhap: ");
    node currentNode = head;
    while (currentNode != NULL)
    {
        printf("%d", currentNode->data);
        if (currentNode->next != NULL)
        {
            printf(" <-> ");
        }
        currentNode = currentNode->next;
    }
    printf(" <-> NULL\n");

    currentNode = head;
    while (currentNode != NULL)
    {
        node temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
}
