#include "main.h"

uint8_t matrix_player1_friendly_a [8];
uint8_t matrix_player1_friendly_b [8];
uint8_t matrix_player1_enemy_a [8];
uint8_t matrix_player1_enemy_b [8];
uint8_t matrix_player2_friendly_a [8];
uint8_t matrix_player2_friendly_b [8];
uint8_t matrix_player2_enemy_a [8];
uint8_t matrix_player2_enemy_b [8];

void matrices_init(void);
void matrix_send(uint8_t MATRIX[8], GPIO_TypeDef* PORT, uint16_t PIN);
void matrix_send_all(void);
void matrix_LED_hit(void);
void matrix_LED_miss(void);
