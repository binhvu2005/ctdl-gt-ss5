
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
void insertNode(node *head,int delData, int newData){
    node temp=*head;
    int count=0;
    while (temp->next!=NULL)
    {
        if (temp->data==delData)
        {
            count++;
            temp->data=newData;
        }
        temp=temp->next;
    }
    if (count==0)
    {
        printf("Ko tim thay phan tu de thay the");
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
    int oldData,newData;
    printf("Nhap gia tri can thay the");
    scanf("%d",&oldData);
    printf("Nhap gia tri moi");
    scanf("%d",&newData);
    insertNode(&head,oldData,newData);
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

