#include <stdio.h>
#include <string.h>

struct studentNode {
 char name[ 20 ] ;
 int age ;
 char sex ;
 float gpa ;
 struct studentNode *next ;
} ;

void saveNode( struct studentNode *child, char n[], int a, char s, float g ) ;
void GoNext2( struct studentNode **walk ) ;

int main() {
 struct studentNode *start, *now1, **now2 ;
 start = new struct studentNode ;
 saveNode( start, "one", 6, 'M', 3.11 ) ;
 
 start->next = new struct studentNode ;
 saveNode( start->next, "two", 8, 'F', 3.22 ) ;
 
 start->next->next = new struct studentNode ;
 saveNode( start->next->next, "three", 10, 'M', 3.33 ) ;

 start->next->next->next = new struct studentNode ;
 saveNode( start->next->next->next, "four", 12, 'F', 3.44 ) ;

 now1 = start ;
 now2 = &start ;

 GoNext2( now2 ) ;
 printf( "Name\tage\tsex\tgpa\n%s\t%d\t%c\t%.2f ", now1->name, now1->age, now1->sex, now1->gpa ) ;

 return 0 ;
}//end function

void saveNode( struct studentNode *child, char n[], int a, char s, float g ) {
 strcpy( child->name, n ) ;
 child->age = a ;
 child->sex = s ;
 child->gpa = g ;
}//end function

void GoNext2( struct studentNode **walk ) {
	if ( (*walk) ->next != NULL) {
		*(*walk) = *(*walk)->next ;
	}
}
