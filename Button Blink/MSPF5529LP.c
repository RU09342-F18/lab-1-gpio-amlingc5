#include <msp430.h>

int main(void)
PM5CTL0 &= ~LOCKLPM5

{
  WDTCTL = WDTPW+WDTHOLD;   // Stop WDT
  P1DIR |= BIT0;            // Set P1.0 to output direction
  P1DIR &= ~BIT1;           // Set P1.1 to input direction
  P1OUT |= BIT1;            // Set P1.1 resistor to pull-down
  P1REN |= BIT1;            // Set P1.1 resistor to on
  int j;                    // Declaring the j integer variable

  for (;;)                  // Runs the loop indefinitely
  {
      j = P1IN & BIT1;      // Defining integer j

      if (j != 2)           // Checking if P1.1 is being pressed
          P1OUT |= BIT0;    // Enabling the LED on P1.0
      else
          P1OUT &= ~BIT0;   // Disabling the LED on P1.0
  }
}

