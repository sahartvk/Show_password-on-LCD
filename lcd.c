/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 1/18/2023
Author  : 
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*******************************************************/

#include <mega16.h>

// Alphanumeric LCD functions
#include <alcd.h>
#include <delay.h>
#include <stdio.h>
#include <string.h>
// Declare your global variables here
int keypad(void);
void lcd(int c);


int i=0;
int j=0;
char str[10];
char input_password[30]="";
char password[30]="1234AB";

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (1<<DDA3) | (1<<DDA2) | (1<<DDA1) | (1<<DDA0);
// State: Bit7=P Bit6=P Bit5=P Bit4=P Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTA=(1<<PORTA7) | (1<<PORTA6) | (1<<PORTA5) | (1<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
MCUCSR=(0<<ISC2);

// USART initialization
// USART disabled
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);

// ADC initialization
// ADC disabled
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTD Bit 0
// RD - PORTD Bit 1
// EN - PORTD Bit 2
// D4 - PORTD Bit 4
// D5 - PORTD Bit 5
// D6 - PORTD Bit 6
// D7 - PORTD Bit 7
// Characters/line: 16
lcd_init(16);

while (1)
      {
     int a=100;
     a=keypad();
     lcd(a);
     
     //check if pin is correct
     if(strcmp(input_password,password)==0){
        lcd_clear();  
        lcd_puts("password is correct");
        strcpy(input_password,"");
        delay_ms(5000);
     }                                  
       
     delay_ms(200);
      } 
                
}

 void lcd(int c){ 
 
        if(c<10 && c!=100){
        sprintf(str,"%d",c);
        strcat(input_password,str);
        lcd_puts(str);
        i++; 
        lcd_gotoxy(i,j);
        }               
        if(c>=10 && c!=14 && c!=15 && c!=100){
            switch(c)
            {
                case 10:
                lcd_putsf("A");
                strcat(input_password,"A");
                i++;
                lcd_gotoxy(i,j);
                break;
                
                case 11:
                lcd_putsf("B");
                strcat(input_password,"B");
                i++;
                lcd_gotoxy(i,j);
                break;           
                
                case 12:
                lcd_putsf("C");
                strcat(input_password,"C");
                i++;
                lcd_gotoxy(i,j);
                break;
                
                case 13:
                lcd_putsf("D");
                strcat(input_password,"D");
                i++;
                lcd_gotoxy(i,j);
                break;
                
                //case 14:
                //lcd_putsf("E");
                //i++;
                //lcd_gotoxy(i,j);
                //break;
                
                //case 15:
                //lcd_putsf("F");
                //i++;
                //lcd_gotoxy(i,j);
                //break;
            }
        }
        
        //back
        if(c==14){
        int len=strlen(input_password); 
        len--;
        input_password[len]='\0';
        lcd_clear();
        lcd_gotoxy(0,0);
        lcd_puts(input_password);
        
        i=len%16;
        j=(len/16)%2;
        
        lcd_gotoxy(i,j);
        }
        
        //lock
        if(c==15){
        i=0;
        j=0;
        lcd_clear();
        lcd_gotoxy(i,j);
        strcpy(input_password,"");      
        }
        
        if(i==16 && j==0){
        i=0;
        j++;
        }   
        
        if(i==16 && j==1){
           i=0;
           j=0;
      }
       
}

int keypad(void){
    //column 1
    int b=100;
    PORTA.3=0;
    PORTA.2=1;
    PORTA.1=1;
    PORTA.0=1;
    //row 4 ->0 
    if(PINA.4==0){ 
        b=15;
    } 
    //row 3 ->7       
    if(PINA.5==0){
        b=7;
    } 
    //row2 -> 4 
    if(PINA.6==0){
        b=4;
    }  
    //row1-> 1 
    if(PINA.7==0){
        b=1;
    }   
    
       
     //column 2
    PORTA.3=1;
    PORTA.2=0;
    PORTA.1=1;
    PORTA.0=1;
    //row 4 ->F 
    if(PINA.4==0){
        b=0;
    } 
    //row 3 ->8       
    if(PINA.5==0){
        b=8;
    } 
    //row2 -> 5
    if(PINA.6==0){
        b=5;
    }  
    //row1-> 2 
    if(PINA.7==0){
        b=2;
    }   
      
    
    
     //column 3
    PORTA.3=1;
    PORTA.2=1;
    PORTA.1=0;
    PORTA.0=1;
    //row 4 ->E 
    if(PINA.4==0){
        b=14;
    } 
    //row 3 ->9      
    if(PINA.5==0){
        b=9;
    } 
    //row2 -> 6
    if(PINA.6==0){
        b=6;
    }  
    //row1-> 3
    if(PINA.7==0){
        b=3;
    } 
    
    
     //column 4
    PORTA.3=1;
    PORTA.2=1;
    PORTA.1=1;
    PORTA.0=0;
    //row 4 ->D 
    if(PINA.4==0){
        b=13;
    } 
    //row 3 ->C       
    if(PINA.5==0){
        b=12;
    } 
    //row2 -> B 
    if(PINA.6==0){
        b=11;
    }  
    //row1-> A 
    if(PINA.7==0){
        b=10;
    }
      
    return b;
}

