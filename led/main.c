#include <avr/io.h>

int main(void)
{
    DDRB |= (1 << PB5);   // LED output
    DDRD &= ~(1 << PD2);  // button input
    PORTD |= (1 << PD2);  // internal pull-up

    while (1) {
        if (!(PIND & (1 << PD2)))
            PORTB |= (1 << PB5);  // pressed
        else
            PORTB &= ~(1 << PB5); // released
    }
}
