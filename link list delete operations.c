#include<stdio.h>
typedef struct node
{
    int info;
    struct node *next;
}node;
node* delatb(node*);
node* delate(node*);
node* delak(node*);
node* delbk(node*);
void main()
{
    int ch;
    node *head=NULL;
    while(1)
    {
        printf("Enter Choice\n1 for Deleting node at beginning\n2 for Deleting node @ end\n3 for Deleting node after a given key\n4 for Deleting node before a given key\n5 to Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            head=delatb(head);
            break;
            case 2:
            head=delate(head);
            break;
            case 3:
            head=delak(head);
            break;
            case 4:
            head=delbk(head);
            break;
            case 5:
            exit(0);
        }
    }
}
node* delatb(node *head)
{
    node *p;
    if(head==NULL)
    printf("List is Empty\n");
    else
    {
        p=head;
        head=head->next;
        free(p);
        return head;
    }
}
node* delate(node *head)
{
    node *p;
    if(head==NULL)
    printf("List is Empty\n");
    else
    {
        p=head;
        while((p->next)->next!=NULL)
        p=p->next;
        free(p->next);
        p->next=NULL;
        return head;
    }
}
node* delak(node *head)
{
    node *p,*temp;
    int k;
    printf("Enter Key\n");
    scanf("%d",&k);
    p=head;
    while(p!=NULL&&p->info!=k)
    p=p->next;
    if(p==NULL)
    {
        printf("Key doesn't exist\n");
        return head;
    }
    else
    {
        temp=p->next;
        p->next=temp->next;
        free(temp);
        return head;
    }
}
node* delbk(node *head)
{
    node *p,*temp;
    int k;
    printf("Enter Key\n");
    scanf("%d",&k);
    p=head;
    if(p->info==k)
    return head;
    if((p->next)->info==k)
    {
        head=head->next;
        free(p);
        return head;
    }
    while(p!=NULL&&((p->next)->next)->info!=k)
    p=p->next;
    if(p==NULL)
    {
        printf("Key doesn't exist\n");
        return head;
    }
    else
    {
        temp=p->next;
        p->next=temp->next;
        free(temp);
        return head;
    }
}
