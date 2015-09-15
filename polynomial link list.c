#include<stdio.h>
typedef struct node
{
    int cons;
    int expo;
    struct node *next;
}node;
void main()
{
    node *a=NULL,*b=NULL,*x=NULL,*y=NULL,*p,*r=NULL,*s=NULL;
    int c,n,i;
    printf("Enter highest degree for polynomial 1 : ");
    scanf("%d",&n);
    for(i=n;i>=0;i--)
    {
        printf("Enter constant for degree %d : ",i);
        scanf("%d",&c);
        if(c!=0)
        {
            p=(node*)malloc(sizeof(node));
            p->cons=c;
            p->expo=i;
            p->next=NULL;
            if(a==NULL&&b==NULL)
            {
                a=p;
                b=p;
            }
            else
            {
                b->next=p;
                b=p;
            }
        }
    }
    printf("Enter highest degree for polynomial 2 : ");
    scanf("%d",&n);
    for(i=n;i>=0;i--)
    {
        printf("Enter constant for degree %d : ",i);
        scanf("%d",&c);
        if(c!=0)
        {
            p=(node*)malloc(sizeof(node));
            p->cons=c;
            p->expo=i;
            p->next=NULL;
            if(x==NULL&&y==NULL)
            {
                x=p;
                y=p;
            }
            else
            {
                y->next=p;
                y=p;
            }
        }
    }
    while(a!=NULL&&x!=NULL)
    {
        p=(node*)malloc(sizeof(node));
        p->next=NULL;
        if(a->expo==x->expo)
        {
            p->cons=a->cons+x->cons;
            p->expo=a->expo;
            a=a->next;
            x=x->next;
        }
        else if(x->expo>a->expo)
        {
            p->cons=x->cons;
            p->expo=x->expo;
            x=x->next;
        }
        else
        {
            p->cons=a->cons;
            p->expo=a->expo;
            a=a->next;
        }
        if(r==NULL&&s==NULL)
        {
            r=p;
            s=p;
        }
        else
        {
            s->next=p;
            s=p;
        }
    }
    if(a!=NULL)
    {
        while(a!=NULL)
        {
            p=(node*)malloc(sizeof(node));
            p->next=NULL;
            p->cons=a->cons;
            p->expo=a->expo;
            s->next=p;
            s=p;
            a=a->next;
        }
    }
    if(x!=NULL)
    {
        while(x!=NULL)
        {
            p=(node*)malloc(sizeof(node));
            p->next=NULL;
            p->cons=x->cons;
            p->expo=x->expo;
            s->next=p;
            s=p;
            x=x->next;
        }
    }
    printf("\nSum is -\n");
    while(r!=NULL)
    {
        printf("Constant at degree %d = %d\n",r->expo,r->cons);
        r=r->next;
    }
}
