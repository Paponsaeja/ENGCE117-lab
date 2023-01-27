#include<stdlib.h>
#include<stdio.h>
typedef struct Node *linknext;
struct Node {
    int data;
    linknext next;
};
// prototype function 
void addnode(struct Node** , int );
void display(struct Node* );
void showBackward(struct Node* );
void swap(struct Node* , int , int );
void update(struct Node* , int , int );

int main() {
	linknext temp;
    temp = NULL;

    // Need '&' address as we need to change temp
    addnode(&temp,50);
    addnode(&temp,40);
    addnode(&temp,30);
    addnode(&temp,20);
    addnode(&temp,10);
    
    // No Need for '&' as not changing head in display operation
	display(temp);
	showBackward(temp);
	display(temp);
	swap(temp , 20 , 50 );
	display(temp);
	swap(temp , 10 , 40 );
	display(temp);
	display(temp);
	update(temp, 30 , 29);
	display(temp);
	display(temp);
	update(temp, 30 , 99);
	display(temp);
    return 0;
}

void display(struct Node* node) {
    printf("\nLinked List: ");
    while(node!=NULL){
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

void showBackward(struct Node* head) {
    if(head == NULL){
        printf("Linked List is empty.\n");
        return;
    }
    printf("Linked List (backward): ");
    struct Node* current = head;
    int size = 0;
    while(current != NULL){
        current = current->next;
        size++;
    }
    current = head;
    for(int i = size-1; i >= 0; i--){
        int j = 0;
        while(j != i){
            current = current->next;
            j++;
        }
        printf("%d ", current->data);
        current = head;
    }
    printf("\n");
}

void swap(struct Node* head, int index1, int index2) {
    struct Node* check1 = head; 
    struct Node* check2 = head;
    int temp;
    while(check1 != NULL){
        if(check1->data == index1){
            while(check2 != NULL){
                if(check2->data == index2){
                    temp = check1->data;
                    check1->data = check2->data;
                    check2->data = temp;
                    printf("\nSwapped: %d and %d", check1->data, check2->data);
                    return;
                }
                check2 = check2->next;
            }
        }
        check1 = check1->next;
    }
    printf("Index not found.\n");
}

void update(struct Node* temp, int oldValue, int newValue) {
    struct Node* current = temp;
    while(current != NULL)
    {
        if(current->data == oldValue)
        {
            current->data = newValue;
            printf("\nUpdated value change %d to %d", oldValue, newValue);
            return;
        }
        current = current->next;
    }
    printf("\nNew Update change %d to %d is error!\nValue %d is not found in linked list\n", 
	oldValue, 
	newValue, 
	oldValue );
}

void addnode(struct Node** temp, int data) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *temp;
    *temp = newNode;
}
