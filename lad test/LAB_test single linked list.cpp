// papon saeja 65543206021-9 sec 1 
// https://www.youtube.com/watch?v=E11AobnRt9U
#include<stdlib.h>
#include<stdio.h>
typedef struct Node* linknext; // linknext=POINTER NAME 
struct Node {
    int data;
    linknext next;  // LINKFIED = *NEXT
};
// prototype function 
void addnode( linknext* , int ); // linknext = (struct Node*)
void display( linknext );
void showBackward( linknext );
void swap( linknext , int , int );
void update( linknext , int , int );

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
	printf("--------------------------------");
	display(temp);
	swap(temp , 20 , 50 );
	display(temp);
	swap(temp , 10 , 40 );
	display(temp);
	printf("--------------------------------");
	display(temp);
	update(temp, 30 , 29);
	display(temp);
	printf("--------------------------------");
	display(temp);
	update(temp, 30 , 99);
	display(temp);
    return 0;
}

void addnode(linknext* temp, int data) {
    linknext newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *temp;
    *temp = newNode;
}

void display(linknext node) {
    printf("\nLinked List: ");
    while(node!=NULL) {
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

void showBackward(linknext temp) {
    if(temp == NULL) {
        printf("Linked List cannot found \n");
        return;
    }
    printf("(Linked List backward): ");
    linknext check = temp;
    int count = 0;
    while(check != NULL) {
        check = check->next;
        count++;
    }
    check = temp;
    for(int i = count-1; i >= 0; i--) {
        int j = 0;
        while(j != i) {
            check= check->next;
            j++;
        }
        printf("%d ", check->data);
        check = temp;
    }
    printf("\n");
}

void swap(linknext temp, int index1, int index2) {
    linknext check1 = temp; 
    linknext check2 = temp;
    int temp1;
    while(check1 != NULL) {
        if(check1->data == index1) {
            while(check2 != NULL) {
                if(check2->data == index2) {
                    temp1 = check1->data;
                    check1->data = check2->data;
                    check2->data = temp1;
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

void update(linknext temp, int oldValue, int newValue) {
    linknext check = temp;
    while(check != NULL) {
        if(check->data == oldValue) {
            check->data = newValue;
            printf("\nUpdated value change %d to %d", oldValue, newValue);
            return;
        }
        check = check->next;
    }
    printf("\nNew Update change %d to %d is error!\nValue %d is not found in linked list\n", 
	oldValue, 
	newValue, 
	oldValue );
}
