#include <stdio.h>

void main(void)
{
   char base_digits[16] =
	 {'0', '1', '2', '3', '4', '5', '6', '7',
	  '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

   int converted_number[64];
   long int number_to_convert;
   int next_digit, base, index=0;

   /* get the number and base */
   printf("Enter number and desired base: ");
   scanf("%ld %i", &number_to_convert, &base);

   /* convert to the indicated base */
   while (number_to_convert != 0)
   {
	 converted_number[index] = number_to_convert % base;
	 number_to_convert /= base;
	 ++index;
   }

   /* now print the result in reverse order */
   --index;  /* back up to last entry in the array */
   printf("\n\nConverted Number = ");
   for(  ; index>=0; index--) /* go backward through array */
   {
	 printf("%c", base_digits[converted_number[index]]);
   }
   printf("\n");
}