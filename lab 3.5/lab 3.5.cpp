#include <stdio.h>
int main() {
	int i ;
	int limit ;
	int v[limit] ;
	int c[limit] ;
	int temp ;
	printf( "input  Array number : " ) ;
	scanf( "%d" , &limit ) ;
	for(  i = 0 ; i < limit ; i++  ) {
		printf( "\nArray[ %d ] : " , i  ) ;
		scanf( "%d" , &v[i] ) ;
	} 
	for( i = 0 ; i < limit ; i++ ) {
		for( int j = i+1 ; j < limit ; ++j ) {
        	if ( v[i] > v[j] ) {
				temp = v[i] ;
				v[i] = v[j] ;
				v[j] = temp ;
        	}
      	}
		if( v[i] < 99 ) { 
			c[i] = 1 ;                           
			for( int j = i+1 ; j < limit ; j++ ) {
				if( v[i] == v[j] ) {          
					c[i]++ ;
					v[j] = 99 ;              
				}
			}
		}
	}
	printf("\n-----------") ;
	for(i = 0 ; i < limit ; i++) {
		if( v[i] != 99 && c[i] != 0 ) { 
			printf("\n%d -> %d " , v[i], c[i]) ;
		}
	}
	return 0 ;
}


