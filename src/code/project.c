#include <mega64a.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <alcd.h>

bool is_fahrenheit = false;
bool blink_mode = false;
unsigned int temp_c = 0;
unsigned int temp_f = 0;

unsigned int read_adc(unsigned char adc_input) {
    ADMUX = adc_input | 0x40;
    ADCSRA |= 0x40;
    while ((ADCSRA & 0x10) == 0);
    ADCSRA |= 0x10;
    return ADCW;
}

interrupt [USART0_RXC] void usart0_rx_isr(void) {
    unsigned char data = UDR0;
    
    if (data == 'A') PORTB |= (1<<0);
    if (data == 'a') PORTB &= ~(1<<0);
    if (data == 'B') PORTB |= (1<<1);
    if (data == 'b') PORTB &= ~(1<<1);
    if (data == 'C') PORTB |= (1<<2);
    if (data == 'c') PORTB &= ~(1<<2);
    if (data == 'D') PORTB |= (1<<3);
    if (data == 'd') PORTB &= ~(1<<3);
    
    if (data == 'E') PORTC |= (1<<1);
    if (data == 'e') PORTC &= ~(1<<1);
    if (data == 'F') PORTC |= (1<<2);
    if (data == 'f') PORTC &= ~(1<<2);
    
    if (data == 'G') PORTC |= (1<<0);
    if (data == 'g') PORTC &= ~(1<<0);
    
    if (data == 'H') { PORTC |= (1<<1); PORTC |= (1<<2); }
    if (data == 'h') { PORTC &= ~(1<<1); PORTC &= ~(1<<2); }
    
    if (data == 'U' || data == 'u') is_fahrenheit = !is_fahrenheit;
    
    if (data == 'K') blink_mode = true;
    if (data == 'k') blink_mode = false;
}

void system_init(void) {
    DDRA = 0xFF;
    PORTA = 0x00;

    DDRB = 0x0F; 
    PORTB = 0x00;

    DDRC = 0x07;
    PORTC = 0x00;

    ADMUX = 0x40; 
    ADCSRA = 0x87;

    UCSR0A = 0x02;
    UCSR0B = 0x98; 
    UCSR0C = 0x06;
    UBRR0H = 0x00;
    UBRR0L = 0x0C; 

    lcd_init(20);
    
    #asm("sei")
}

void update_lcd(void) {
    char buffer[21];
    lcd_clear();
    
    if (is_fahrenheit) {
        sprintf(buffer, "Temp:%d F", temp_f);
    } else {
        sprintf(buffer, "Temp:%d C", temp_c);
    }
    lcd_gotoxy(0, 0);
    lcd_puts(buffer);
    
    lcd_gotoxy(13, 0);
    if (PORTC & (1<<0)) lcd_puts("Bzr:on ");
    else lcd_puts("Bzr:off");
    
    lcd_gotoxy(0, 1);
    lcd_puts("L1:");
    if (PORTB & (1<<0)) lcd_puts("on "); else lcd_puts("off");
    lcd_puts(" L2:");
    if (PORTB & (1<<1)) lcd_puts("on "); else lcd_puts("off");
    lcd_puts(" L3:");
    if (PORTB & (1<<2)) lcd_puts("on "); else lcd_puts("off");
    
    lcd_gotoxy(0, 2);
    lcd_puts("L4:");
    if (PORTB & (1<<3)) lcd_puts("on "); else lcd_puts("off");
    lcd_puts(" R1:");
    if (PORTC & (1<<1)) lcd_puts("on "); else lcd_puts("off");
    lcd_puts(" R2:");
    if (PORTC & (1<<2)) lcd_puts("on "); else lcd_puts("off");
}

void main(void) {
    unsigned int timer_500ms = 0;
    system_init();
    
    while (1) {
        temp_c = (read_adc(0) * (unsigned long)500) / 1024;
        temp_f = (temp_c * 9 / 5) + 32;
        
        update_lcd();
        
        if (blink_mode) {
            PORTB ^= 0x0F; 
        }
        
        delay_ms(100);
        timer_500ms += 100;
        
        if (timer_500ms >= 500) {
            if (is_fahrenheit) {
                printf("Temp:%dF, ", temp_f);
            } else {
                printf("Temp:%dC, ", temp_c);
            }
            
            if (PORTC & (1<<1)) printf("R1:ON, ");
            else printf("R1:OFF, ");
            
            if (PORTC & (1<<2)) printf("R2:ON\r\n");
            else printf("R2:OFF\r\n");
            
            timer_500ms = 0;
        }
    }
}