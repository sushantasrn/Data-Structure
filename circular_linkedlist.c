#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;

void create(int A[],int n){
    int i;
    struct node *t,*last;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=A[0];
    head->next=head;
    last=head;

    for(int i=1;i<n;i++){
        t=(struct node*)malloc(sizeof(struct node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void display(struct node *h){
    do{
        printf("%d ",h->data);
        h=h->next;
    }while(h!=head);
}

void Rdisplay(struct node *h){
    static int flag=0;
    if(flag==0 || h!=head){
        flag=1;
         printf("%d ",h->data);
        Rdisplay(h->next);
    }
    flag=0;
}

int length(struct node *p){
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=head);
    return len;
}

void Insert(struct node *p,int index,int x){
    struct node *t;
    int i;

    if(index<0 || index>length(p))
        return;

    if(index==0){
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        if(head==NULL){
            head=t;
            head->next=head;
        }else{
            while(p->next!=head){      
            p=p->next;
            }
            p->next=t;
            t->next=head;
            head=t;
        
    }
    }else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }
            t=(struct node*)malloc(sizeof(struct node));
            t->data=x;
            t->next=p->next;
            p->next=t;
    }
}

int Delete(struct node *p,int index){
    struct node *q;
    int i,x;
    if(index==0 || index>length(head))
        return -1;
    if (index==1){
        while(p->next!=head){
            p=p->next;
        }
        x=head->data;
        if(head==p){
            free(head);
            head=NULL;
        }else{
            p->next=head->next;
            free(head);
            head=p->next;
        }
    }else{
        for(i=0;i<index-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    
}
int main(){
    int A[]={2,3,4,5,6};
    create(A,5);
    Delete(head,3);
    Rdisplay(head);
    return 0;
}