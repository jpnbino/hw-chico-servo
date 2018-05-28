/******************************************************************************
  Helper functions implementation.

  Company:      
	Ecxus

  File Name:    
	utils.c

  Summary:      
    API for helper functions

  Description:
    Various functions used in diffeents modules such as itoa(), are implemented
	here.
******************************************************************************/
/******************************************************************************
* Includes
******************************************************************************/
#include "utils.h"
/******************************************************************************
* Function Implementation
******************************************************************************/

/*itoa*/
char itoa( uint8_t uint_data )
{
	uint8_t c_data = 0;
	
	if ( uint_data <= 9)
	{
		c_data = uint_data + '0';
	}
	else
	{
		c_data = uint_data + ('0' + 7 );					
	}
	return c_data;
}

/*atoi*/
uint8_t atoi( char* str )
{
	 uint8_t res = 0; // Initialize result
  	uint8_t i = 0;
    // Iterate through all characters of input string and
    // update result
    for (i = 0; str[i] != '\0'; ++i)
        res = res*10 + str[i] - '0';
  
    // return result.
    return res;
}


uint16_t Rescale_Value (uint16_t x , uint16_t xa, uint16_t xb, uint16_t ya, uint16_t yb )
{
	/**
	Algorithm:
		1 - Find a linear equation;
		2 - Calculate equation considering rounding;
	 
	Explanation:
		- A equation of the line correlates two different range of values. The equation
		is given by the following formula,		
	
		y = ((yb - ya)*(x - xa))/(xb - xa)) + ya;
	
		where,
			(xa,ya) and (xb,yb) -> are known points in the line.
			
		OBS: to complete understand solution search equatio of the line theory.


	Considerations:
		y will be written as a/b + ya
		where,
		a = (yb - ya)*(x - xa)
		b = (xb - xa)
	*/
	
	uint16_t y;
	
	//multiplication of two 16bits gives a 32bits integer
	uint32_t a;
	uint16_t b;

	a = (yb - ya)*(x - xa);
	b = (xb - xa);
	
	/**
	In the matter of integers calculation rounding must be considered.
	Then, y is calculated using the round half up method
	So, a/b is aproximated as (a/b + 1/2), but as calculation is performed by integers
	1/2 = 0 (zero), then (a/b + 1/2) is rewritten as((a + b/2)/b).
	*/
	y = ((a + b/2)/b) + ya; 
		
    return y ;   
}