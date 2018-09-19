#include <msp430.h>                         //includes header file for msp430

int main(void)                              //initialize main function
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1DIR |= 0x01;                            // Set P1.0 to output direction
  P1DIR &= ~BIT3;                           //Set P1.3 to input direction
  P1REN |= BIT3;                            //Sets pull up resistor

  int j;                                    //creates an integer

  while(1)                                 //creates infinite while loop
  {
    j = P1IN & BIT3;                         //check to see if button is pressed
   if(j !=8)                                // if button is not pressed
   {
       P1OUT ^= 0x01;                       //toggles LED
   }
   else
   {
       P1OUT &= ~BIT0;                      //turns LED off
   }
  }
}

