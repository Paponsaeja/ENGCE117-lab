#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct studentNode {
 	char name[ 20 ] ;
 	int age ;
 	char sex ;
 	float gpa ;
 	struct studentNode *next ;
 	struct studentNode *back ;
} ;

void ShowAll( struct studentNode *walk ) {
 	while( walk != NULL ) {
  		printf( "%s ", walk->name ) ;
  		walk = walk->next ;
 	}//end while
 	printf( " \n" ) ;
}//end function

struct studentNode *AddNode( struct studentNode **head, char *name, int age, char sex, float gpa )
{
	struct studentNode *newNode = ( struct studentNode * ) malloc( sizeof( struct studentNode ) ) ;
	strcpy( newNode->name, name ) ;
	newNode->age = age ;
	newNode->sex = sex ;
	newNode->gpa = gpa ;
	newNode->next = NULL ;
	newNode->back = NULL ;
	if( *head == NULL ) {
   		*head = newNode ;
   		return newNode ;
 	}
 	struct studentNode *curr = *head ;
 	while( curr->next != NULL )
   		curr = curr->next ;
 	curr->next = newNode ;
 	newNode->back = curr ;
 	return newNode ;
}


void InsNode( struct studentNode *curr, char *name, int age, char sex, float gpa ) {
	struct studentNode *newNode = ( struct studentNode * ) malloc( sizeof( struct studentNode ) ) ;
	strcpy( newNode->name, name ) ;
	newNode->age = age ;
	newNode->sex = sex ;
	newNode->gpa = gpa ;
	newNode->next = curr->next ;
	newNode->back = curr ;
	curr->next = newNode ;
	if( newNode->next != NULL )
		newNode->next->back = newNode ;
}

void GoBack(struct studentNode **curr) {
	if (*curr == NULL || (*curr)->back == NULL) {
		return;
	}
	*curr = (*curr)->back;
}

void DelNode( struct studentNode *now ) {
 struct studentNode *temp = now->next ;
 now->next = temp->next ;
 free( temp ) ;
}//end function


int main() {
 struct studentNode *start, *now ;
 start = NULL ;
 now = AddNode( &start, "one", 6, 'M', 3.11 ) ; ShowAll( start ) ;
 now = AddNode( &start, "two", 8, 'F', 3.22 ) ; ShowAll( start ) ;
 InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( start ) ;
 InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( start ) ;
 GoBack( &now ) ;
 DelNode( now ) ; ShowAll( start ) ;
 DelNode( now ) ; ShowAll( start ) ;
 DelNode( now ) ; ShowAll( start ) ;
 return 0 ;
}//end function


