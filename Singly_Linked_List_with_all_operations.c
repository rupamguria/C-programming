#include <stdio.h>
#include<stdlib.h>

struct ListNode{                    // structure definition of Node
    int data;
    struct ListNode* next;
};
struct ListNode* Head=NULL;                 //Head declaration
int len(struct ListNode* head){                 //length of Linked List
    int count=0;
    struct ListNode* cur=head;
    for(cur=head;cur!=NULL;cur=cur->next) count++;
    return count;
}
struct ListNode* insertAtBeginning(struct ListNode* head,int value){                //insert a Node at beginning
    struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
    temp->data=value;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        struct ListNode* cur=head;
        head=temp;
        head->next=cur;
    }
    return head;
}
struct ListNode* insertAtEnd(struct ListNode*head,int value){               //insert a Node at end
    struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
    temp->data=value;
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        struct ListNode* cur=head;
        for(cur=head;cur->next!=NULL;cur=cur->next);
        cur->next=temp;
    }
    return head;
}
struct ListNode* insertAtGivenPosition(struct ListNode*head,int pos,int value){                 //insert a Node at given position
        if(head==NULL){
            return NULL;
        }
        else{
            struct ListNode* temp=(struct ListNode*)malloc(sizeof(struct ListNode));
            temp->data=value;
            temp->next=NULL;
            struct ListNode* cur=head;
            struct ListNode* helper;
            for(int i=0;i<pos-2;i++){
                cur=cur->next;
            }
            helper=cur->next;
            cur->next=temp;
            temp->next=helper;
            return head;
        }
}
struct ListNode* deleteFirstNode(struct ListNode*head){                 //delete first Node   
    if(head==NULL){
        printf("\nLinked List is empty");
        return NULL;        
    }
    else{
        struct ListNode* cur=head;
        head=head->next;
        free(cur);
        return head;
    }
}
struct ListNode* deleteLastNode(struct ListNode*head){                  //delete last Node
    if(head==NULL){
        printf("\nLinked List is empty");
        return NULL; 
    }
    else{
        struct ListNode* cur=head;
        struct ListNode* temp;
        for(cur=head;cur->next->next!=NULL;cur=cur->next);
        temp=cur->next;
        cur->next=NULL;
        free(temp);
        return head;
    }
}
struct ListNode* deleteNodeAtGivenPosition(struct ListNode* head,int pos){                  //delete a Node at given position
    if(head==NULL){
        printf("\nLinked List is empty");
        return NULL;
    }
    else{
        struct ListNode* cur=head;
        struct ListNode* temp;
        for(int i=0;i<pos-2;i++){
            cur=cur->next;
        }
        temp=cur->next;
        cur->next=cur->next->next;
        free(temp);
        return head;
    }
}
struct ListNode* deleteList(struct ListNode* head){                //delete Linked List
    if(head==NULL){
        printf("\nList is empty");
        return NULL;
    }
    else{
        struct ListNode* cur=head;
        struct ListNode* temp;
        while(cur!=NULL){
            temp=cur;
            cur=cur->next;
            free(temp);
        }
        head=NULL;
        return head;
    }
}      
void display(struct ListNode* head){                    //print the elements of Linked List
    if(head==NULL){
        printf("\nList is empty");
        return;
    }
    else{
        struct ListNode* cur=head;
        printf("\nElements are: ");
        for(cur=head;cur!=NULL;cur=cur->next){
        printf("\t%d",cur->data);
    }
    }
}
int main() {
    printf("\n1: insert Node at beginning\n2: insert Node at end\n3: insert Node at given position");
    printf("\n4: calculate the length of Linked List\n5: print the elements of Linked List\n6: exit the program");
    printf("\n7: delete first Node\n8: delete last Node\n9: delete a Node at given position\n10: delete the List");
    int data,position,choice;
    while(1){
    printf("\n\nEnter choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("\nEnter data: ");
            scanf("%d",&data);
            Head=insertAtBeginning(Head,data);
            break;
        case 2:
            printf("\nEnter data: ");
            scanf("%d",&data);
            Head=insertAtEnd(Head,data);
            break;
        case 3:
            printf("\nEnter data: ");
            scanf("%d",&data);
            printf("\nEnter position: ");
            scanf("%d",&position);
            if(position>1 && position<=len(Head)){
                Head=insertAtGivenPosition(Head,position,data);
            }
            else printf("\nPosition is invalid !");
            break;
        case 4:
            printf("\nLength of Linked List = %d",len(Head));
            break;
        case 5:
            display(Head);
            break;
        case 6:
            exit(1);
        case 7:
            Head=deleteFirstNode(Head);
            break;
        case 8:
            Head=deleteLastNode(Head);
            break;
        case 9:
            printf("\nEnter position: ");
            scanf("%d",&position);
            Head=deleteNodeAtGivenPosition(Head,position);
            break;
        case 10:
            Head=deleteList(Head);
            break;
        default:
            printf("\nInvalid choice !");
            break;
        }
    }
    return 0;
}

