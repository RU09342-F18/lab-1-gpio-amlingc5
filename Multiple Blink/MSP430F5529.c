#include <msp430.h>
int main(void)

PM5CTL0 &= ~LOCKLPM5 // Needed For F type devices

{
    WDTCTL = WDTPW + WDTHOLD; // Stop watch dog timer
    P1SEL &= ~BIT0;     //Sets select bit to 0 for P1.0
    P1OUT |= BIT0;    //Sets LED in P1.0 to turn on
    P1DIR |= BIT0; //Sets Port 1 direction to output
    P4SEL &= ~BIT7; //Sets select bit to 0 for P4.7 to be configured as I/O
    P4OUT &= ~BIT7; //Sets LED in P4.7 to not be on
    P4DIR |= BIT7; //Sets Port 4 direction to output

    volatile unsigned int n, i;

    i = 10000; //Sets delay for P1.0
    n = 50000; //Sets deflay for P4.7

    for (;;)
        {
        n--;
        i--;

        if (n==0) //checks if the first variable is a high enough value to turn on the LED
        {
          P1OUT ^= BIT0; //XOR to turn on and off first LED
          n = 50000;
         }
          if (i==0) //checks if the first variable is a high enough value to turn on the LED
            {
             P4OUT ^= BIT7; //XOR to turn on and off second LED
             i = 10000;
         }
        }
}
