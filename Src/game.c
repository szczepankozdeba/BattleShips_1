#include "game.h"
#include "main.h"
#include "LCD.h"
#include "keypad.h"
#include "matrix.h"


uint8_t end=0;                          // variable for informing if the player has ended their move
uint8_t ship_current_position_x = 0;   //current position of ship (used during placing)
uint8_t ship_current_position_y = 0;  //current position of ship (used during placing)
uint8_t rotation = 0;                //rotation of ship "0" for vertical (default) or "1" for horizontal (used during placing)
uint8_t winner = 0;                 //variable for winner


void game_init(Player* player1, Matrix_struct* matrix11, Matrix_struct* matrix12,
		Player* player2, Matrix_struct* matrix21, Matrix_struct* matrix22)
{
	player1->matrix_1 = matrix11;
    player1->matrix_2 = matrix12;
    player1->player_total_score = 0;         //setting score to 0 at the start
    player1->LCD_number = lcd_1;

	player2->matrix_1 = matrix21;
    player2->matrix_2 = matrix22;
    player2->player_total_score = 0;       //setting score to 0 at the start
    player2->LCD_number = lcd_2;
}

void move_right(Player* player, uint8_t length)
{
	if( rotation ==0)
	{
	for(uint8_t i=0;i<length; i++)
	matrix_LED_off(player->matrix_1, ship_current_position_x,ship_current_position_y -i );
	ship_current_position_x = ship_current_position_x + 1;
	for(uint8_t i=0; i<length; i++)
	matrix_LED_on(player->matrix_1, ship_current_position_x,ship_current_position_y - i);
	}

	if( rotation ==1)
	{
	for(uint8_t i=0;i<length; i++)
	matrix_LED_off(player->matrix_1, ship_current_position_x -i,ship_current_position_y);
	ship_current_position_x = ship_current_position_x + 1;
	for(uint8_t i=0; i<length; i++)
	matrix_LED_on(player->matrix_1, ship_current_position_x -i,ship_current_position_y);
	}
}
void move_left(Player* player, uint8_t length)
{
	if( rotation ==0)
	{
	for(uint8_t i=0;i<length; i++)
	matrix_LED_off(player->matrix_1, ship_current_position_x,ship_current_position_y - i);
	ship_current_position_x = ship_current_position_x - 1;
	for(uint8_t i=0;i<length; i++)
	matrix_LED_on(player->matrix_1, ship_current_position_x,ship_current_position_y -i );
	}

	if( rotation ==1)
	{
	for(uint8_t i=0;i<length; i++)
	matrix_LED_off(player->matrix_1, ship_current_position_x-i,ship_current_position_y);
	ship_current_position_x = ship_current_position_x - 1;
	for(uint8_t i=0;i<length; i++)
	matrix_LED_on(player->matrix_1, ship_current_position_x-i,ship_current_position_y);
	}
}
void move_up(Player* player, uint8_t length)
{
	if (rotation ==0)
	{
	for(uint8_t i=0;i<length; i++)
	matrix_LED_off(player->matrix_1, ship_current_position_x,ship_current_position_y -i);
	ship_current_position_y = ship_current_position_y + 1;
	for(uint8_t i=0;i<length; i++)
	matrix_LED_on(player->matrix_1, ship_current_position_x,ship_current_position_y -i);
	}

	if (rotation ==1)
	{
	for(uint8_t i=0;i<length; i++)
	matrix_LED_off(player->matrix_1, ship_current_position_x-i,ship_current_position_y);
	ship_current_position_y = ship_current_position_y + 1;
	for(uint8_t i=0;i<length; i++)
	matrix_LED_on(player->matrix_1, ship_current_position_x -i,ship_current_position_y);
	}
}
void move_down(Player* player, uint8_t length)
{
	if (rotation ==0)
	{
	for(uint8_t i=0;i<length; i++)
	matrix_LED_off(player->matrix_1, ship_current_position_x,ship_current_position_y -i );
	ship_current_position_y = ship_current_position_y - 1;
	for(uint8_t i=0;i<length; i++)
	matrix_LED_on(player->matrix_1, ship_current_position_x,ship_current_position_y -i);
	}

	if (rotation ==1)
	{
	for(uint8_t i=0;i<length; i++)
	matrix_LED_off(player->matrix_1, ship_current_position_x -i,ship_current_position_y);
	ship_current_position_y = ship_current_position_y - 1;
	for(uint8_t i=0;i<length; i++)
	matrix_LED_on(player->matrix_1, ship_current_position_x -i,ship_current_position_y);
	}
}

void move_cursor_right(Player* player)
{
	matrix_LED_off(player->matrix_2, ship_current_position_x,ship_current_position_y);
	ship_current_position_x = ship_current_position_x + 1;
	matrix_LED_on(player->matrix_2, ship_current_position_x,ship_current_position_y );
}
void move_cursor_left(Player* player)
{
	matrix_LED_off(player->matrix_2, ship_current_position_x,ship_current_position_y );
	ship_current_position_x = ship_current_position_x - 1;
	matrix_LED_on(player->matrix_2, ship_current_position_x,ship_current_position_y );
}
void move_cursor_up(Player* player)
{
	matrix_LED_off(player->matrix_2, ship_current_position_x,ship_current_position_y);
	ship_current_position_y = ship_current_position_y + 1;
	matrix_LED_on(player->matrix_2, ship_current_position_x,ship_current_position_y);
}
void move_cursor_down(Player* player)
{
	matrix_LED_off(player->matrix_2, ship_current_position_x,ship_current_position_y );
	ship_current_position_y = ship_current_position_y - 1;
	matrix_LED_on(player->matrix_2, ship_current_position_x,ship_current_position_y );
}

void move_set(Player* player, uint8_t length)
{
	if (rotation ==0)
	{
	for(uint8_t i=0;i<length; i++)
	player->ship_fixed_positions[ship_current_position_x][ship_current_position_y - i] =  1;
	}

	if (rotation ==1)
	{
	for(uint8_t i=0;i<length; i++)
	player->ship_fixed_positions[ship_current_position_x-i][ship_current_position_y] =  1;
	}
}

void move_rotate(Player* player, uint8_t length)
{
	if (rotation == 0)
	{
		for(uint8_t i=0;i<length; i++)
		matrix_LED_off(player->matrix_1, ship_current_position_x,ship_current_position_y -i );
		for(uint8_t i=0;i<length; i++)
		matrix_LED_on(player->matrix_1, ship_current_position_x-i,ship_current_position_y);
		rotation = 1;
	}
	else
	{
		for(uint8_t i=0;i<length; i++)
		matrix_LED_off(player->matrix_1, ship_current_position_x-i,ship_current_position_y );
		for(uint8_t i=0;i<length; i++)
			matrix_LED_on(player->matrix_1, ship_current_position_x,ship_current_position_y -i);
		rotation =0;
	}
}

void set_ships(Player* player, uint8_t length)
{
		rotation = 0;

	    ship_current_position_x = 5;
	    ship_current_position_y = 5;

	    for (uint8_t i=0; i<length ; i++)
	    matrix_LED_on(player->matrix_1, ship_current_position_x,ship_current_position_y -i );

	    matrix_send_all();

	    LCD_clear(player->LCD_number);
	    LCD_set_cursor(player->LCD_number, 0,0);
	    LCD_display(player->LCD_number, "[1] [2] [3] [4]");
	    LCD_set_cursor(player->LCD_number, 1,0);
	    LCD_display(player->LCD_number, "[<] [>] [o] [ok]");

	    while(1)
	    {
	         switch(check_button())
	         {
	         case 1:
	        	 move_left(player,length);
	        	 for (uint8_t i = 0;i<8;i++)
	        	 	   	    		 {
	        	 	   	    			 for (uint8_t j=0; j<8; j++)
	        	 	   					 {
	        	 	   	    				 if (player->ship_fixed_positions[i][j] == 1)
	        	 	   	    				 matrix_LED_on(player->matrix_1,  i,j );
	        	 	   					 }
	        	 	   	    		 }
	        	 matrix_send_all();
	        	 break;
	         case 2:
	         	 move_right(player,length);

	         	for (uint8_t i = 0;i<8;i++)
	         		   	    		 {
	         		   	    			 for (uint8_t j=0; j<8; j++)
	         		   					 {
	         		   	    				 if (player->ship_fixed_positions[i][j] == 1)
	         		   	    				 matrix_LED_on(player->matrix_1,  i,j );
	         		   					 }
	         		   	    		 }
	         	matrix_send_all();
	         	 break;
	         case 3:
	        	 move_rotate(player, length);
	        	 for (uint8_t i = 0;i<8;i++)
	        	 	   	    		 {
	        	 	   	    			 for (uint8_t j=0; j<8; j++)
	        	 	   					 {
	        	 	   	    				 if (player->ship_fixed_positions[i][j] == 1)
	        	 	   	    				 matrix_LED_on(player->matrix_1,  i,j );
	        	 	   					 }
	        	 	   	    		 }
	        	 matrix_send_all();
	         	 break;
	         case 4:
	         	end=1;
	         	for (uint8_t i = 0;i<8;i++)
	         		   	    		 {
	         		   	    			 for (uint8_t j=0; j<8; j++)
	         		   					 {
	         		   	    				 if (player->ship_fixed_positions[i][j] == 1)
	         		   	    				 matrix_LED_on(player->matrix_1,  i,j );
	         		   					 }
	         		   	    		 }
	         	matrix_send_all();
	         	break;
	         default:
			 break;
	         }
	    	 if(end==1)
	    	 {
	    		 end =0;
	    		 break;
	    	 }
	    }

	    LCD_clear(player->LCD_number);
	    LCD_set_cursor(player->LCD_number, 0,0);
	    LCD_display(player->LCD_number, "[1] [2] [3]");
	    LCD_set_cursor(player->LCD_number, 1,0);
	    LCD_display(player->LCD_number, "[^] [v] [ok]");

	    while(1)
	   	    {
	   	         switch(check_button())
	   	         {
	   	         case 1:
	   	        	 move_down(player,length);
	   	        	for (uint8_t i = 0;i<8;i++)
	   	        		   	    		 {
	   	        		   	    			 for (uint8_t j=0; j<8; j++)
	   	        		   					 {
	   	        		   	    				 if (player->ship_fixed_positions[i][j] == 1)
	   	        		   	    				 matrix_LED_on(player->matrix_1,  i,j );
	   	        		   					 }
	   	        		   	    		 }
	   	        	 matrix_send_all();
	   	        	 break;
	   	         case 2:
	   	         	 move_up(player,length);
	   	         	for (uint8_t i = 0;i<8;i++)
	   	         		   	    		 {
	   	         		   	    			 for (uint8_t j=0; j<8; j++)
	   	         		   					 {
	   	         		   	    				 if (player->ship_fixed_positions[i][j] == 1)
	   	         		   	    				 matrix_LED_on(player->matrix_1,  i,j );
	   	         		   					 }
	   	         		   	    		 }
	   	         	 matrix_send_all();
	   	         	 break;
	   	         case 3:
	   	         	move_set(player, length);
	   	         for (uint8_t i = 0;i<8;i++)
	   	         	   	    		 {
	   	         	   	    			 for (uint8_t j=0; j<8; j++)
	   	         	   					 {
	   	         	   	    				 if (player->ship_fixed_positions[i][j] == 1)
	   	         	   	    				 matrix_LED_on(player->matrix_1,  i,j );
	   	         	   					 }
	   	         	   	    		 }
	   	         	matrix_send_all();
	   	         	end = 1;
	   	         	break;
	   	         default:
	   			 break;
	   	         }
	   	    	 if(end==1)
	   	    	 {
	   	    		 for (uint8_t i = 0;i<8;i++)
	   	    		 {
	   	    			 for (uint8_t j=0; j<8; j++)
	   					 {
	   	    				 if (player->ship_fixed_positions[i][j] == 1)
	   	    				 matrix_LED_on(player->matrix_1,  i,j );
	   	    				 end = 0;
	   					 }
	   	    		 }
	   	    	 break;
	   	    	 }
	   	    }
}

void shot(Player* player1, Player* player2)
{

		    ship_current_position_x = 5;
		    ship_current_position_y = 5;

		    matrix_LED_on(player1->matrix_2, ship_current_position_x,ship_current_position_y);

		    matrix_send_all();

		    LCD_clear(player1->LCD_number);
		    LCD_set_cursor(player1->LCD_number, 0,0);
		    LCD_display(player1->LCD_number, "[1] [2] [3] [4]");
		    LCD_set_cursor(player1->LCD_number, 1,0);
		    LCD_display(player1->LCD_number, "[<] [>] [] [ok]");

		    while(1)
		    {
		         switch(check_button())
		         {
		         case 1:
		        	 move_cursor_left(player1);
		        	 break;
		         case 2:
		         	 move_cursor_right(player1);
		         	 break;
		         case 4:
		         	end=1;

		         	break;
		         default:
				 break;
		         }
		         matrix_send_all();
		    	 if(end==1)
		    	 {
		    		 end =0;
		    		 break;
		    	 }
		    }

		    LCD_clear(player1->LCD_number);
		    LCD_set_cursor(player1->LCD_number, 0,0);
		    LCD_display(player1->LCD_number, "[1] [2] [3]");
		    LCD_set_cursor(player1->LCD_number, 1,0);
		    LCD_display(player1->LCD_number, "[^] [v] [ok]");

		    while(1)
		   	    {
		   	         switch(check_button())
		   	         {
		   	         case 1:
		   	        	 move_cursor_down(player1);
		   	        	 break;
		   	         case 2:
		   	         	 move_cursor_up(player1);
		   	         	 break;
		   	         case 3:
		   	         	check_shot(player1,player2);
		   	         	end = 1;
		   	         	break;
		   	         default:
		   			 break;
		   	         }
		   	         matrix_send_all();
		   	    	 if(end==1)
		   	    	 {
		   	    		 end=0;
		   	    		break;
		   	    	 }

		   	    }
}

void check_shot(Player* player1, Player* player2)
{
	if(player2->ship_fixed_positions[ship_current_position_x][ship_current_position_y] ==1)
	{
		player1->ship_shot_positions[ship_current_position_x][ship_current_position_y]=1;
		matrix_LED_blink(player1->matrix_2,ship_current_position_x,ship_current_position_y);
		matrix_LED_blink(player2->matrix_1,ship_current_position_x,ship_current_position_y);
		player1->player_total_score++;

		LCD_clear(player1->LCD_number);
		LCD_set_cursor(player1->LCD_number, 0,0);
		LCD_display(player1->LCD_number, "Trafiles!");
		LCD_set_cursor(player1->LCD_number, 1,0);
		LCD_display(player1->LCD_number, " ");

		LCD_clear(player2->LCD_number);
		LCD_set_cursor(player2->LCD_number, 0,0);
		LCD_display(player2->LCD_number, "Przeciwnik");
		LCD_set_cursor(player2->LCD_number, 1,0);
		LCD_display(player2->LCD_number, "Trafil!");

		HAL_Delay(2000);
	}
	else
	{
		player1->ship_shot_positions[ship_current_position_x][ship_current_position_y]=0;
		matrix_LED_on(player1->matrix_2,ship_current_position_x,ship_current_position_y);

		LCD_clear(player1->LCD_number);
		LCD_set_cursor(player1->LCD_number, 0,0);
		LCD_display(player1->LCD_number, "Spudlowales!");
		LCD_set_cursor(player1->LCD_number, 1,0);
		LCD_display(player1->LCD_number, " ");

		LCD_clear(player2->LCD_number);
		LCD_set_cursor(player2->LCD_number, 0,0);
		LCD_display(player2->LCD_number, "Przeciwnik");
		LCD_set_cursor(player2->LCD_number, 1,0);
		LCD_display(player2->LCD_number, "spudlowal!");

		HAL_Delay(2000);
	}
}

void game(void)
{
	LCD_clear(lcd_1);
	LCD_clear(lcd_2);
	LCD_set_cursor(lcd_1, 0,0);
	LCD_display(lcd_1, "Gra w statki");
	LCD_set_cursor(lcd_1, 1,0);
	LCD_display(lcd_1, "************");
	LCD_set_cursor(lcd_2, 0,0);
	LCD_display(lcd_2, "Gra w statki");
	LCD_set_cursor(lcd_2, 1,0);
	LCD_display(lcd_2, "************");

	HAL_Delay(3000);


	LCD_clear(lcd_1);
	LCD_clear(lcd_2);
	LCD_set_cursor(lcd_1, 0,0);
	LCD_display(lcd_1, "Tura przeciwnika");
	LCD_set_cursor(lcd_1, 1,0);
	LCD_display(lcd_1, " ");
	LCD_set_cursor(lcd_2, 0,0);
	LCD_display(lcd_2, "Wybierz pozycje");
	LCD_set_cursor(lcd_2, 1,0);
	LCD_display(lcd_2, "statku");

		HAL_Delay(3000);

	set_ships(&player2,2);
	set_ships(&player2,2);
	set_ships(&player2,3);
	set_ships(&player2,3);
	set_ships(&player2,4);

	LCD_clear(lcd_1);
	LCD_clear(lcd_2);
	LCD_set_cursor(lcd_1, 0,0);
	LCD_display(lcd_1, "Wybierz pozycje");
	LCD_set_cursor(lcd_1, 1,0);
	LCD_display(lcd_1, "statku");
	LCD_set_cursor(lcd_2, 0,0);
	LCD_display(lcd_2, "Tura przeciwnika");
	LCD_set_cursor(lcd_2, 1,0);
	LCD_display(lcd_2, " ");

	HAL_Delay(3000);

	set_ships(&player1,2);
	set_ships(&player1,2);
	set_ships(&player1,3);
	set_ships(&player1,3);
	set_ships(&player1,4);



	while(1)
	{
		LCD_clear(player2.LCD_number);
		LCD_set_cursor(player2.LCD_number, 0,0);
		LCD_display(player2.LCD_number, "Ruch przeciwnika");
		LCD_set_cursor(player2.LCD_number, 1,0);
		LCD_display(player2.LCD_number, " ");

		shot(&player1, &player2);
		if (player1.player_total_score==14)
		{
			winner = 1;
			break;
		}

		LCD_clear(player1.LCD_number);
		LCD_set_cursor(player1.LCD_number, 0,0);
		LCD_display(player1.LCD_number, "Ruch przeciwnika");
		LCD_set_cursor(player1.LCD_number, 1,0);
		LCD_display(player1.LCD_number, " ");

		shot(&player2, &player1);
		if (player2.player_total_score==14)
		{
			winner = 2;
			break;
		}
	}

	if (winner ==1)
	{
		LCD_clear(lcd_1);
		LCD_clear(lcd_2);
		LCD_set_cursor(lcd_1, 0,0);
		LCD_display(lcd_1, "Zwyciezyles!");
		LCD_set_cursor(lcd_2, 1,0);
		LCD_display(lcd_1, " ");
		LCD_set_cursor(lcd_1, 0,0);
		LCD_display(lcd_2, "Przegrales!");
		LCD_set_cursor(lcd_2, 1,0);
		LCD_display(lcd_2, " ");

	}
	else
	{
		LCD_clear(lcd_1);
		LCD_clear(lcd_2);
		LCD_set_cursor(lcd_1, 0,0);
		LCD_display(lcd_1, "Przegrales!");
		LCD_set_cursor(lcd_2, 1,0);
		LCD_display(lcd_1, " ");
		LCD_set_cursor(lcd_1, 0,0);
		LCD_display(lcd_2, "Zwyciezyles!");
		LCD_set_cursor(lcd_2, 1,0);
		LCD_display(lcd_2, " ");

	}
}



