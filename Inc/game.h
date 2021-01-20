#include "main.h"
#include "matrix.h"


#ifndef __game_H__
#define __game_H__

typedef struct
{

uint8_t LCD_number; // one for each player, select "lcd_1" for address 0x4E and "lcd_2" for 0x7E

Matrix_struct* matrix_1; //matrix for ship placement
Matrix_struct* matrix_2; //matrix for shots

uint8_t ship_fixed_positions[8][8]; //list of player ship positions
uint8_t ship_shot_positions[8][8];  //list of player shots
uint8_t player_total_score; // total points, point is scored after each successful shot

}Player;

Player player1; //struct for player 1
Player player2; //struct for player 2


void game_init(Player* player1, Matrix_struct* matrix11, Matrix_struct* matrix12,
		Player* player2, Matrix_struct* matrix21, Matrix_struct* matrix22); //initializing the game, here 2 matrices for each player must be selected
void set_ships(Player* player, uint8_t length); // setting player ships
void shot(Player* player1, Player* player2); // targeting the enemy ship
void game(void);
void check_shot(Player* player1, Player* player2); //checking if the ship has been hit
void move_cursor_right(Player* player); //move cursor when targeting ship
void move_cursor_left(Player* player); //move cursor when targeting ship
void move_cursor_up(Player* player); //move cursor when targeting ship
void move_cursor_down(Player* player); //move cursor when targeting ship
void move_right(Player* player, uint8_t length);//move ship when placing
void move_left(Player* player, uint8_t length);//move ship when placing
void move_up(Player* player, uint8_t length);//move ship when placing
void move_down(Player* player, uint8_t length);//move ship when placing
void move_set(Player* player, uint8_t length);//placing ship on chosen coordinate
void move_rotate(Player* player, uint8_t length);//rotate ship when placing

#endif
