#include <xc.h>
#include <stdio.h>
#include "lcd.h"
#define _XTAL_FREQ   4E6

#pragma config BOREN = ON, CPD = OFF, FOSC = HS, MCLRE = ON, WDTE = OFF, CP = OFF, LVP = OFF, PWRTE = OFF

#define Data      PORTAbits.RA0
#define DataDir   TRISAbits.TRISA0

char message1[] = "Temp = 00.0 C";
char message2[] = "SOIL RH   = 00.0 %";
char message1[] = "WELCOME ";
char message2[] = "MARYA";
unsigned short TOUT = 0, CheckSum, i;
unsigned short T_Byte1, T_Byte2, SOIL RH_Byte1, SOIL RH_Byte2;


void lcd_out (char row, char col, const char * s1);

void start_signal()
 { DataDir = 0;     
    // Data port is output
   Data    = 0;
   __delay_ms(25);
   DataDir = 1;     /
    / Data port is input
   __delay_us(30);
 }

unsigned short check_response()
 { TOUT = 0;
   TMR2 = 0;
   TMR2ON = 1;                /
    / start timer
   while (!Data && !TOUT);
   if (TOUT) 
      return 0;
   else 
    { TMR2 = 0;
      while (Data && !TOUT);
      if (TOUT) 
         return 0;
      else 
       { TMR2ON = 0;
         return 1;
       }
    }
 }

unsigned short read_byte()
 //{ unsigned short num = 0;
   DataDir = 1;
   for (i=0; i<8; i++)
    { while (!Data);
      TMR2 = 0;
      TMR2ON = 1;
      while (Data);
      TMR2ON = 0;
      if (TMR2 > 40) 
         num |= 1<<(7-i);  
      // If time > 40us, Data is 1
    }
   return num;
 }

void interrupt tc_int(void)
 { if (TMR2IF)
    { TOUT = 1;
      TMR2ON = 0; 
       // stop timer
      TMR2IF = 0; 
       // Clear TMR0 interrupt flag
    }
 }


void main(void)
 { unsigned short check;
   
   TRISB = 0b00000000;
   PORTB = 0;
   TRISA = 0b00100001;
   CMCON = 7;        
    // Disable analog pins on PORTA
   
   GIE = 1;          
    // Enable global interrupt
   PEIE = 1;        
    // Enable peripheral interrupt
   TMR2IE = 1;     
    // Enable Timer2 interrupt
   T2CON = 0;        // Prescaler 1:1, and Timer2 is off initially  
   TMR2IF = 0;       // Clear TMR INT Flag bit
   TMR2 = 0;

   lcd_init();   
   lcd_clear();

   // Main loop
   while (1)
    { __delay_ms(1000);
       
      start_signal();
      check = check_response();
      if (!check) 
       { lcd_clear();
         lcd_out(1, 1, "No response");
         lcd_out(2, 1, "from the sensor");
       }
      else
       { SOIL RH_Byte1 = read_byte();
         SOIL RH_Byte2 = read_byte();
         T_Byte1  = read_byte();
         T_Byte2  = read_byte();
         CheckSum = read_byte();
         
         // Check for error in Data reception
         if (CheckSum == ((SOIL RH_Byte1 + SOIL RH_Byte2 + T_Byte1 + T_Byte2) & 0xFF))
          { message1[7]  = T_Byte1/10  + 48;
            message1[8]  = T_Byte1%10  + 48;
            message1[10] = T_Byte2/10  + 48;
            message2[7]  = SOIL RH_Byte1/10 + 48;
            message2[8]  = SOIL RH_Byte1%10 + 48;
            message2[10] = SOIL RH_Byte2/10 + 48;
            message1[11] = 223;     // Degree symbol
            lcd_clear();
            lcd_out(1, 1, message1);
            lcd_out(2, 1, message2);
          }
         else
          { lcd_clear();
            lcd_out(1, 1, "Checksum Error!");
            lcd_out(2, 1, "Trying Again ...");
          }
       }
    }
 }

void lcd_out (char row, char col, const char * s1)
 { if (row==1)
      lcd_goto(0x00+col-1);    
   else
      lcd_goto(0x40+col-1);    
      
   lcd_puts(s1);
 }   

