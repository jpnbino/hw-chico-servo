/******************************************************************************
 Header File for utils function.

  Company:      
	Ecxus

  File Name:    
	utils.h

  Description:
    Protypes and constants for helper functions.
******************************************************************************/
#ifndef UTILS_H
#define	UTILS_H

/******************************************************************************
* Includes
******************************************************************************/
#include <stdint.h>
/******************************************************************************
* Function Name: itoa()
*******************************************************************************
* Summary:
*	Convert a uint8_t number into an ASCii caractere.
*
* Parameters:
*  uint_data - Value to be converted.
*
* Return:
*  	c_data - Converted uint_data to char
*
* Example:
*	uint8_t i = 0x0a;
	char i_ascii;
	
	i_ascii = itoa( i );
	printf ( i ); // results in 'A';
*
* Note:
* 	None
******************************************************************************/
char itoa( uint8_t uint_data );

/******************************************************************************
* Function Name: atoi()
*******************************************************************************
* Summary:
*	Convert a ASCii caractere number into an uint8_t.
*
* Parameters:
*  c_data - Value to be converted.
*
* Return:
*  	uint_data - Converted char touint_data
*
* Example:
*	uint8_t i = 0x0a;
	char i_ascii;
	
	i_ascii = itoa( i );
	printf ( i ); // results in 'A';
*
* Note:
* 	None
******************************************************************************/
uint8_t atoi( char* str );

/**
  @Description
    This function performs a convertion from one scale X to scale Y. The
	relation between those scale is considered linear. Then, based on the
	paramaters a know value x in scale X is converted to a value y in scale
	Y.

  @Preconditions
    None

  @Param
    x  - is the value to be converted to scale y
	xa - is the minimum scale X value.
	xb - is the maximum scale X value.
	ya - is the minimum scale Y value.
	yb - is the maximum scale Y value.

  @Returns
    The value converted from scale X to scale Y.

  @Comment
    This function uses the round half up method as an integer rounding method

  @Example
    <code>
     #define MIN_X 20
	 #define MAX_X 50
	 
	 #define MIN_Y 1000
	 #define MAX_Y 2000
	 
	 uint16_t y;
	 uint16_t x = 30;
	 
	 y = Rescale_Value( x, MIN_X, MAX_X, MIN_Y, MAX_Y );
	 
    </code>

*/
uint16_t Rescale_Value (uint16_t x , uint16_t xa, uint16_t xb, uint16_t ya, uint16_t yb );



#endif /*DRIVER_WT2600_CACHE_H*/
/* [] END OF FILE */