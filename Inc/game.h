#include "main.h"
#include "matrix.h"


#ifndef __game_H__
#define __game_H__

typedef struct
{

uint8_t LCD_number;
uint8_t tab_X[14];
uint8_t tab_Y[14];

Matrix_struct* matrix_1;
Matrix_struct* matrix_2;

}Player;

uint8_t A ;
Player player1;
Player player2;


void game_init(Player* player1, Matrix_struct* matrix11, Matrix_struct* matrix12,
		Player* player2, Matrix_struct* matrix21, Matrix_struct* matrix22);
//void make_ship(Player* player);
void set_ships(Player* player);
void battle(Player* player1, Player* player2);
void game(void);
void move_right(Player* player);
void move_left(Player* player);
void move_up(Player* player);
void move_down(Player* player);
void move_set(Player* player);
void move_rotate(Player* player);

#endif
