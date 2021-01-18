#include "game.h"
#include "main.h"
#include "LCD.h"
#include "keypad.h"
#include "matrix.h"



uint8_t end=0;
uint8_t ship_current_position_x = 0;
uint8_t ship_current_position_y = 0;
uint8_t rotation = 0;


void game_init(Player* player1, Matrix_struct* matrix11, Matrix_struct* matrix12,
		Player* player2, Matrix_struct* matrix21, Matrix_struct* matrix22)
{
	player1->matrix_1 = matrix11;
    player1->matrix_2 = matrix12;
    player1->player_total_score = 0;

	player2->matrix_1 = matrix21;
    player2->matrix_2 = matrix22;
    player2->player_total_score = 0;
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


	    while(1)
	    {
	         switch(check_button())
	         {
	         case 1:
	        	 move_left(player,length);
	        	 break;
	         case 2:
	         	 move_right(player,length);
	         	 break;
	         case 3:
	        	 move_rotate(player, length);
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

	    while(1)
	   	    {
	   	         switch(check_button())
	   	         {
	   	         case 1:
	   	        	 move_down(player,length);
	   	        	 break;
	   	         case 2:
	   	         	 move_up(player,length);
	   	         	 break;
	   	         case 3:
	   	         	move_set(player, length);
	   	         	end = 1;
	   	         	break;
	   	         default:
	   			 break;
	   	         }

	   	    	 matrix_send_all();
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
		player1->player_total_score++;
	}
	else
	{
		player1->ship_shot_positions[ship_current_position_x][ship_current_position_y]=0;
		matrix_LED_on(player1->matrix_2,ship_current_position_x,ship_current_position_y);
	}
}

void game(void)
{

}



