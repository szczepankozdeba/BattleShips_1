#include "main.h"
#include "matrix.h"


#ifndef __game_H__
#define __game_H__

typedef struct
{

uint8_t LCD_number;

Matrix_struct* matrix_1;
Matrix_struct* matrix_2;

uint8_t ship_fixed_positions[8][8];
uint8_t ship_shot_positions[8][8];
uint8_t player_total_score;

}Player;

uint8_t A ;
Player player1;
Player player2;


void game_init(Player* player1, Matrix_struct* matrix11, Matrix_struct* matrix12,
		Player* player2, Matrix_struct* matrix21, Matrix_struct* matrix22);
//void make_ship(Player* player);
void set_ships(Player* player, uint8_t length);
void shot(Player* player1, Player* player2);
void game(void);
void check_shot(Player* player1, Player* player2);
void move_cursor_right(Player* player);
void move_cursor_left(Player* player);
void move_cursor_up(Player* player);
void move_cursor_down(Player* player);
void move_right(Player* player, uint8_t length);
void move_left(Player* player, uint8_t length);
void move_up(Player* player, uint8_t length);
void move_down(Player* player, uint8_t length);
void move_set(Player* player, uint8_t length);
void move_rotate(Player* player, uint8_t length);

#endif
