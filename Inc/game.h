#include "main.h"
//#include "matrix.h"

typedef struct
{

uint8_t LCD_number;
uint8_t tab_X[14];
uint8_t tab_Y[14];

}Player;


//void game_init(Matrix_struct* matrix1);
void make_ship(Player* player);
void set_ships(Player* player);
void battle(Player* player1, Player* player2);
void game(void);
