#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int info;
struct node *next;
}node;

typedef struct{
struct node*first;
}list;

list *makelist(){
list *l;
l=(list*)malloc(sizeof(list));
l->first=NULL;
return(l);
}

void creatlist(list* l,int v){
node *n,*p;
n=(node*)malloc(sizeof(node));
n->info=v;
if(l->first==NULL){
n->next=NULL;
l->first=n;
}else{
p=l->first;
while(p->next!=NULL){
p=p->next;
}
p->next=n;
n->next=NULL;
}
}

void firstnode(list *l, int v){
node *n;
n=(node*)malloc(sizeof(node));
n->info=v;

n->next=l->first;
l->first=n;
}


void maddnode(list *l,int p , int v){
node *n , *t;
n=(node*)malloc(sizeof(node));
n->info=v;
t=l->first;
while(t->info!=p){
t=t->next;
}
n->next=t->next;
t->next=n;
}


void laddnode(list *l, int v){
node *n, *p;
n=(node*)malloc(sizeof(node));
n->info=v;
p=l->first;
while(p->next!=NULL){
p=p->next;
}
n->next=NULL;
p->next=n;
}

void printlist(list *l){
node *t;
t=l->first;
while(t!=NULL){
printf("%d->",t->info);
t=t->next;
}
}

void dellist(list *l , int v){
node *t,*s;
t=l->first;
while(t->info!=v){
s=t;
t=t->next;
}
s->next=t->next;
free(t);
}

int main(){
list *ls;
int a , i , v , p;

ls=makelist();
printf("Enter variable in list:");
for(i=0;i<5;i++){
scanf("%d",&a);
creatlist(ls,a);
}
printlist(ls);
printf("\n Enter first node in list:");
scanf("%d",&v);

firstnode(ls,v);
printlist(ls);
printf("\n Enter node in middle:");
printf("\n Enter previous  node:");
scanf("%d",&p);
printf("\n Enter new node:");
scanf("%d",&v);
maddnode(ls,p,v);
printlist(ls);
printf("\n Enter last node:");
scanf("%d",&v);
laddnode(ls,v);
printlist(ls);
printf("\n");
printf("Enter value yu want to delete =");
scanf("%d",&v);
dellist(ls,v);
printlist(ls);
return 0;
}