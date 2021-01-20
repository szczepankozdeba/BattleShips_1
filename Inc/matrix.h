#include "main.h"

#ifndef __matrix_H__
#define __matrix_H__

#define ll_matrix_number 4


typedef struct
{

GPIO_TypeDef* Port; //port of the matrix CE
uint16_t Pin; //pin of the matrix CE
uint8_t matrix_a; //ID of matrix list (a)
uint8_t matrix_b; //ID of matrix list (b) - this distinction is used for blinking

}Matrix_struct;

void matrix_init(GPIO_TypeDef* PORT, uint16_t PIN, Matrix_struct* matrix_name); //initialize matrix struct and choose its name
void matrix_send_all(void); // update LED on all matrices
void matrix_set_blink_time(uint16_t time); //set blink delay
void matrix_LED_on_row(Matrix_struct* matrix_name, uint8_t row, uint8_t LED); //light on LEDs  chosen row (single byte format)
void matrix_LED_on(Matrix_struct* matrix_name, uint8_t x, uint8_t y); //turn on LED in chosen coordinate
void matrix_LED_off(Matrix_struct* matrix_name, uint8_t x, uint8_t y); //turn off chosen LED
void matrix_LED_blink_row(Matrix_struct* matrix_name, uint8_t row, uint8_t LED);//blink LEDs on chosen row
void matrix_LED_blink(Matrix_struct* matrix_name, uint8_t x, uint8_t y);//blink LED on in coordinate
void matrix_clear(Matrix_struct* matrix_name); // turn off all LEDs on chosen matrix
#endif
