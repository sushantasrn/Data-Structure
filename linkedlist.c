//Here all the codes of linkedlist are available


#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

    struct node{
        int data;
        struct node *next;
        }*first=NULL,*second=NULL,*third=NULL;

//Creation of Linkedlist from a Array
void create(int A[],int n){
        int i;
        struct node *t=NULL,*last=NULL;
        first=(struct node *)malloc(sizeof(struct node));
        first->data=A[0];
        first->next=NULL;
        last=first;

        for(i=1;i<n;i++){
            t=(struct node *)malloc(sizeof(struct node));
            t->data=A[i];
            t->next=NULL;
            last->next=t;
            last=t;
        }
}

void create2(int A[],int n){
        int i;
        struct node *t=NULL,*last=NULL;
        second=(struct node *)malloc(sizeof(struct node));
        second->data=A[0];
        second->next=NULL;
        last=second;

        for(i=1;i<n;i++){
            t=(struct node *)malloc(sizeof(struct node));
            t->data=A[i];
            t->next=NULL;
            last->next=t;
            last=t;
        }
}

// DIsplay All the data of nodes iteratively
void Dispalay(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

//Dispaly All the data of nodes Recursively
void Rdisplay(struct node *p){
    if(!p)
        return ;
    else
        printf("%d ",p->data);
        return Rdisplay(p->next);
}

// Count Nodes iteratively
int countnodes(struct node *p){
        int count=0;
        while(p){
            count++;
            p=p->next;
        }
        //printf("%d ",count);
}
//Count the Nodes Recursively
int rcounodes(struct node *p){
    if(p==0)
        return 0;
    return rcounodes(p->next)+1;
}

// Sum  of All Elements of a Linked list Iteratively
int add(struct node *p){
    int ans=0;
    while(p!=NULL){
        ans+=p->data;
        p=p->next;
    }
    return ans;
}
// sum of All elements of a linkedlist Recursively
int radd(struct node *p){
    if(p==0)
        return 0;
    return p->data+radd(p->next);
}
//Max Element Iteratively
int maxi(struct node *p){
    int x=-326897;
    while(p!=NULL){
        if(x<p->data)
            x=p->data;
        p=p->next;
    }
    return x;
}
//Max Element Recursively
int Rmaxi(struct node *p){
    int x=-326898;
    if(p==0)
        return 0;
        x=Rmaxi(p->next);
   /* if(x>p->data)
   
        return x;
    return p->data;*/
    return (x>p->data)?x:p->data;
}

////Searching Iteratively
struct node* search(struct node *p,int key){
        while(p!=NULL){
            if(p->data==key)
                return (p);
            p=p->next;
            }
        return NULL;
}
//Searching Recursively
struct node* Rsearch(struct node *p,int key){
        if(p==0)
            return NULL;
        if(key==p->data)
            return p;
        return Rsearch(p->next,key);
}

////Improved Searching Iteratively
struct node* iRsearch(struct node *p,int key){
            struct node *q=NULL;
            while(p!=NULL){
                if(key==p->data){
                    q->next=p->next;
                    p->next=first;
                    first=p;
                    return p;
                }
                q=p;
                p=p->next;

            }
            return NULL;
}
//Insertion of node in a Linkedlist
void insert(int pos,int x){
    struct node*t,*p;
    if(pos==0){
        t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        t->next=first;
        first=t;
    }else if(pos>0){
        p=first;
        for(int i=0;i<pos-1 && p;i++){
            p=p->next;
        }
        if(p){
            t=(struct node*)malloc(sizeof(struct node));
            t->data=x;
            t->next=p->next;
            p->next=t;
        }
    }

    }
// Deletion form a Linkedlist

int delete(struct node *p,int index){
    struct node *q=NULL;
    int x=-1,i;
    if(index<1 || index> rcounodes(p))
        return -1;
    if (index==1){
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }else{
        p=first;
        for(i-0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}


// Remove Duplicate from Sorted Linkedlist

void rem(struct node *p){
    struct node *q=p->next;
    while(q!=NULL){

        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;    //Storing the value for not breaking the linkedlist chain.
            free(q);
            q=p->next;
        }
    }
}

//Reversing a linked list
void Reverse(struct node *q,struct node *p)
{
    if(p!=NULL){
        Reverse(p,p->next);
        p->next=q;
    }else
    {
        first=q;
    }
    
}

void Concat(struct node*p,struct node *q)
{
    third=p;
    while(p->next)
        p=p->next;
    p->next=q;
    q=NULL;
}
// Merge Two Linked List
void Merge(struct node *p,struct node *q){
    struct node *last=NULL;
    if(p->data<q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p&&q){
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p){
        last->next=p;
    }else{
        last->next=q;
    }
}

//

int isloop(struct node *f){
    struct node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while (p && q && p!=q);
    if (p==q)
    {
        return 1;
    }else
    {
    return 0;
    }

    
    
}
int main()
{
    int A[]={20,26,29,36,82};
    create(A,5);
    Dispalay(first);
    delete(first,1);
    Dispalay(first);

	return 0;
}
