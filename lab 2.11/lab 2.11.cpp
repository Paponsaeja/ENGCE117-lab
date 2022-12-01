#include <stdio.h>
#include <string.h>
#include<stdlib.h> 
int value( int ) ;
void comma( int ) ;

int main() {
	int num , result ;
	char s[100] ;
	printf("please enter your count : " ) ;
	scanf( "%d", &num ) ;
	result = value( num ) ;
	printf( "\b\b= " ) ;
	comma( result ) ;
	return 0 ;
}

int value( int num ) {
	int sum = 0 ;
	int count = 9 , i , j = 0 ;
	for( i = 0 ; i < num ; i++ ) {
		sum = sum + count ;
		printf( "%d + ", count ) ;
		count = count * 10 + 9 ;
	}
	return sum ;
}
void comma( int result ) {
	char s[ 10000 ] , output[ 10000 ] ;
	int New = 0 , com = 3 , err = 2 , i , count ;
	sprintf( s , "%d" , result ) ;
	count = strlen(s) ;
	for( i = 0 ; i < count ; i++ ) {
		output[New] = s[ count-1-i ] ;
		New++ ;
		if( err == count-1 && i == count-1 ) {
			break ;
		}
		else if( New % com == 0 ) {
			output[New] = ',' ;
			New++ ;
			com += 4 ;
			err += 3 ;
		}
	}
	for (int i = New ; i >= 0 ; i-- ) {
        printf("%c", output[i]) ;
    }
}

