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
void insertNode(node *mainNode, node *childNode,int pos){
    node tempMain=*mainNode;
    node tempChild=*childNode;
    while (tempChild->next!=NULL)
    {
        tempChild=tempChild->next;
    }
    node headChild=*childNode;
    node tailChild=tempChild;
    int count=0;
    while (tempMain!=NULL)
    {
        if (count==pos-1)
        {
            tempMain->next->pre=tailChild;
            tailChild->next=tempMain->next;
            tempMain->next=headChild;
            headChild->pre=tempMain;
            break;
        }
        count++;
        tempMain=tempMain->next;
    }
}
int main()
{
    int n;
    printf("Nhap so phan tu cua danh sach lien ket chinh: ");
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
      int m;
    printf("Nhap so phan tu cua danh sach lien ket phu: ");
    scanf("%d", &m);
    if (m <= 0)
    {
        printf("Danh sach trong");
        return 0;
    }
    node headChild = NULL;
    node tailChild = NULL;
    for (int i = 0; i < m; i++)
    {
        int data;
        scanf("%d", &data);
        node newNode = createNode(data);
         if (headChild == NULL) {
            headChild = newNode;
            tailChild = newNode;
        } else {
            tailChild->next = newNode;
            newNode->pre = tailChild;
            tailChild = newNode;
        }
    }
    printf("Nhap vi tri can tren");
    int pos;
    
    insertNode(&head,&headChild,2);
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
