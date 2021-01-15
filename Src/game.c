#include "game.h"
#include "main.h"
#include "LCD.h"
#include "keypad.h"


uint8_t A ;
Player player1;
Player player2;

//void game_init(Player* player1, Matrix_struct* matrix11, Matrix_struct* matrix12,
	//	Player* player2, Matrix_struct* matrix21, Matrix_struct* matrix22)



void game_init(Matrix_struct* matrix1)
{
	player1->LCD_number = lcd_1;
	for (uint8_t i=0;i<14;i++)
	player1->tab_X[i] = 0;
	for (uint8_t i=0;i<14;i++)
	player1->tab_Y[i] = 0;
	//player1->matrix_1 = matrix11;
    //player1->matrix_2 = matrix12;

	player2->LCD_number = lcd_2;
	for (uint8_t i=0;i<14;i++)
	player2->tab_X[i] = 0;
	for (uint8_t i=0;i<14;i++)
	player2->tab_Y[i] = 0;
	//player2->matrix_1 = matrix21;
    //player2->matrix_2 = matrix22;
}



void make_ship(Player* player)
{
	LCD_display(player->LCD_number,  "    podaj X");
	uint8_t x = 2;
	LCD_display(player->LCD_number,  "    podaj Y");
	uint8_t y = 2;

	for(uint8_t i = 0; i <= 13; i++ )
	{
		if(x == player->tab_X[i] | x == (player->tab_X[i] - 1) |x == (player->tab_X[i] + 1) |
				y == player->tab_Y[i] | y == (player->tab_Y[i] - 1) |y == (player->tab_Y[i] + 1))
		{
			//matrix_LED_on
		    player->tab_X[A] = x ;
		    player->tab_Y[A] = y ;
		    x = 0; y = 0;
		}
		else
		{
		LCD_display(player->LCD_number,  "tu nie możesz!");
		HAL_delay(2500);
		make_ship(player);
		}
		matrix_LED_on(player->matrix_1, 1, 1);
	}
}



void set_ships(Player* player)
{
	   // uint8_t A = 0;
	    //uint8_t x = 0;
	    //uint8_t y = 0;

	    LCD_display(player->LCD_number, "     ustaw ");
	    LCD_set_cursor(lcd_2, 1,0);
	    LCD_display(player->LCD_number, "  2-masztowiec ");
	    HAL_Delay(3500);



		while( A <= 2)                                                 //dwumasztowiec
		{
		  make_ship(&player);

	     A++;
		}A=0;

		LCD_display(player->LCD_number, "     ustaw ");
		LCD_set_cursor(player->LCD_number, 1,0);
	    LCD_display(player->LCD_number, "  2-masztowiec ");
	    HAL_Delay(3000);

	    while( A <= 2)                                                 //dwumasztowiec
	    {
	      make_ship(&player);

	      A++;
	     }A=0;

	    LCD_display(player->LCD_number, "     ustaw ");
	    LCD_set_cursor(player->LCD_number, 1,0);
	    LCD_display(player->LCD_number, "  3-masztowiec ");
	    HAL_Delay(3500);


	    while( A <= 3)                                                   //trzymasztowiec
	    {
	      make_ship(&player);

	     A++;
	    }A=0;

	    LCD_display(player->LCD_number, "     ustaw ");
	    LCD_set_cursor(player->LCD_number, 1,0);
	    LCD_display(player->LCD_number, "  3-masztowiec ");
	    HAL_Delay(3500);

	    while( A <= 3)
	    {
	     make_ship(&player);

	     A++;
	    }A=0;


	    LCD_display(player->LCD_number, "     ustaw ");
	    LCD_set_cursor(player->LCD_number, 1,0);
	    LCD_display(player->LCD_number, "  3-masztowiec ");
	    HAL_Delay(3500);

	    while( A <= 4)
	    {
	    	make_ship(&player);

	     A++;
	    }A=0;

}

void battle(Player* player1, Player* player2)
{
	//
}

void game(void)
{
	//
}
/*
void make_ship(Player player, uint8_t ship_size)
{
	uint8_t tabX2[2] = {0,0};
	uint8_t tabY2[2] = {0,0};

	uint8_t number = 0;

   while(number <= ship_size)
   {
	   LCD_display(player.LCD_number, "podaj kolumnę");

	   number++;
   }

}

*/
