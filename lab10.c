#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VALUE 0
#define COUNT 1
/*
	OFFSET:
	if value is 99 + 1 the new length must be + 1, and another + 1 for string ending flag '\0'.
*/
#define OFFSET 2
/*
	DIGITS:
	number of digits in verylong type
*/
#define DIGITS 80
#define ASCII_OFFSET '0'
typedef char* verylong;
char freq_letter( char * );verylong add_verylong( verylong, verylong );verylong input_long();
void main()
{
	char string[] = "happynewnewyear";
	verylong x, y, result;
	printf( "1. '%c' is the most frequent letter in \"%s\".\n", freq_letter( string ), string );
	printf( "2. Enter two verylong numbers:\n   " );
	x = input_long();
	printf( "   " );
	y = input_long();
	result = add_verylong( x, y );
	printf( "   %s\n + %s\n = %s\n", x, y, result );
	system( "pause" );
}

char freq_letter( char *string )
{
	char freq[256] = { 0 };
	unsigned int most_freq[2] = { 0 }, length = strlen( string ), index;
	for( index = 0; index < length; index++)
		if( ++freq[ string[ index ] ] > most_freq[ COUNT ] )
		{
			most_freq[ COUNT ] = freq[ string[ index ] ];
			most_freq[ VALUE ] = string[ index ];
		}
	return most_freq[ VALUE ];
}

verylong add_verylong( verylong x, verylong y )
{
	unsigned int x_length = strlen( x ), y_length = strlen( y ), reminder = 0, size, num;
	char tempstr[ DIGITS ];
	verylong longnum;
	if( x_length > y_length)
		size = x_length + OFFSET;
	else 
		size = y_length + OFFSET;
	longnum = ( char * )malloc( ( size ) * sizeof( char ) );
	tempstr[ 0 ] = '0';
	tempstr[ --size ] = '\0';
	while( ( x_length > 0 ) && ( y_length > 0 ) )
	{
		num = x[ --x_length ] - ASCII_OFFSET + y[ --y_length ] - ASCII_OFFSET + reminder;
		if( num > 9 )
		{
			reminder = num / 10;
			num %= 10;
		}
		else
			reminder = 0;
		tempstr[ --size ] = num + ASCII_OFFSET;
	}
	if( y_length > 0 )
	{
		x = y;
		x_length = y_length;
	}
	while( ( size > 0 ) && ( x_length > 0 ) )
	{
		num = x[ --x_length ] - ASCII_OFFSET + reminder;
		if( num > 9 )
		{
			reminder = num / 10;
			num %= 10;
		}
		else
			reminder = 0;
		tempstr[ --size ] = num + ASCII_OFFSET;
	}
	if( reminder )
		tempstr[ --size ] = reminder + ASCII_OFFSET;
	size = 0;
	if( tempstr[ 0 ] == '0' )
		size++;
	strcpy( longnum, tempstr + size );
	return longnum;
}
verylong input_long()
{
	char tempstr[ 80 ];
	verylong longnum;
	printf( "Enter long number: " );
	gets( tempstr );
	longnum = ( char * )malloc( ( strlen( tempstr ) + 1 ) * sizeof( char ) );
	strcpy( longnum, tempstr );
	return longnum;
}