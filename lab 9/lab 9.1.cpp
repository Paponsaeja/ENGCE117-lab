#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
 char name[ 20 ] ;
 int age ;
 char sex ;
 float gpa ;
 struct studentNode *next ;
} ;

class LinkedList {
 protected :
  struct studentNode *start, **now ;
 public :
  LinkedList() ;
  ~LinkedList() ;
  void InsNode( char n[], int a, char s, float g ) ;
  void DelNode() ;
  void GoNext() ;
  void GoFirst() ;
  void GoLast() ;
  void ShowAll() ;
  int FindNode( char n[] ) ;
  struct studentNode *NowNode() ;
  void EditNode( char n[], int a, char s, float g ) ;
} ; //end class

void EditData( LinkedList *ll ) ;
void AddData( LinkedList *ll ) ;
void FindData( LinkedList *ll ) ;
void readfile( LinkedList *ll ) ;
void writefile( LinkedList *ll ) ;

LinkedList::LinkedList() {
    start = NULL;
    now = &start;
}

LinkedList::~LinkedList() {
    struct studentNode* temp;
    while (start) {
        temp = start->next;
        delete start;
        start = temp;
    }
}

void LinkedList::InsNode(char n[], int a, char s, float g) {
    struct studentNode* temp = new studentNode;
    strcpy(temp->name, n);
    temp->age = a;
    temp->sex = s;
    temp->gpa = g;
    temp->next = NULL;
    *now = temp;
    now = &temp->next;
}

void LinkedList::DelNode() {
    if (start) {
        struct studentNode* temp = start->next;
        delete start;
        start = temp;
        now = &start;
    }
}

void LinkedList::GoNext() {
    if (*now) {
        now = &((*now)->next);
    }
}

void LinkedList::GoFirst() {
    now = &start;
}

void LinkedList::GoLast() {
    now = &start;
    while (*now) {
        now = &((*now)->next);
    }
    now = &((*now)->next);
}

void LinkedList::ShowAll() {
    struct studentNode* temp = start;
    while (temp) {
        printf("Name: %s\n", temp->name);
        printf("Age: %d\n", temp->age);
        printf("Sex: %c\n", temp->sex);
        printf("GPA: %.2f\n", temp->gpa);
        printf("\n");
        temp = temp->next;
    }
}

int LinkedList::FindNode(char n[]) {
    struct studentNode* temp = start;
    int index = 0;
    while (temp) {
        if (strcmp(temp->name, n) == 0) {
            return index;
        }
        index++;
        temp = temp->next;
    }
    return -1;
}

struct studentNode* LinkedList::NowNode() {
    if (*now) {
        return *now;
    }
    return NULL;
}

void LinkedList::EditNode(char n[], int a, char s, float g) {
    if (*now) {
        strcpy((*now)->name, n);
        (*now)->age = a;
        (*now)->sex = s;
        (*now)->gpa = g;
    }
}
void EditData(LinkedList* ll) {
    char name[20];
    int age;
    char sex;
    float gpa;

    printf("Enter student name to edit: ");
    scanf("%s", name);

    int index = ll->FindNode(name);

    if (index >= 0) {
        printf("Enter updated data:\n");
        printf("Name: ");
        scanf("%s", name);
        printf("Age: ");
        scanf("%d", &age);
        printf("Sex: ");
        scanf(" %c", &sex);
        printf("GPA: ");
        scanf("%f", &gpa);

        ll->GoFirst();
        for (int i = 0; i < index; i++) {
            ll->GoNext();
        }
        ll->EditNode(name, age, sex, gpa);
        printf("Data updated successfully.\n");
    } else {
        printf("Student not found.\n");
    }
}

void AddData(LinkedList* ll) {
    char name[20];
    int age;
    char sex;
    float gpa;

    printf("Enter student data:\n");
    printf("Name: ");
    scanf("%s", name);
    printf("Age: ");
    scanf("%d", &age);
    printf("Sex: ");
    scanf(" %c", &sex);
    printf("GPA: ");
    scanf("%f", &gpa);

    ll->InsNode(name, age, sex, gpa);
    printf("Data added successfully.\n");
}

void FindData(LinkedList* ll) {
    char name[20];
    printf("Enter student name to find: ");
    scanf("%s", name);

    int index = ll->FindNode(name);

    if (index >= 0) {
        printf("Student found at index %d.\n", index);
    } else {
        printf("Student not found.\n");
    }
}

void readfile(LinkedList* ll) {
    FILE* fp = fopen("data.bin", "rb");
    if (fp != NULL) {
        struct studentNode temp;
        while (fread(&temp, sizeof(struct studentNode), 1, fp)) {
            ll->InsNode(temp.name, temp.age, temp.sex, temp.gpa);
        }
        fclose(fp);
    }
}

void writefile(LinkedList* ll) {
    FILE* fp = fopen("data.bin", "wb");
    if (fp != NULL) {
        struct studentNode* temp = ll->NowNode();
        while (temp) {
            fwrite(temp, sizeof(struct studentNode), 1, fp);
            temp = temp->next;
        }
        fclose(fp);
    }
}


int main() {
 LinkedList listA ;
 int menu ;
 readfile( &listA ) ;
 printf( "  Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Edit : " ) ;
 scanf( "%d", &menu ) ;
 while( menu != 0 ) {
  switch( menu ) {
   case 1 : AddData( &listA ) ; break ;
   case 2 : EditData( &listA ) ; break ;
   case 3 : listA.DelNode() ; break ;
   case 4 : FindData( &listA ) ; break ;
   case 5 : listA.ShowAll() ; break ;
  }//end switch
  printf( "  Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Edit : " ) ;
  scanf( "%d", &menu ) ;
 }//end while
 writefile( &listA ) ;
 return 0 ;
}//end function
