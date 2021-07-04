#include<graphics.h>
#include<stdio.h>
#include<time.h>

char start_animation_1()
{
	int animation_time = 2;
	char format;

	while (animation_time < 6)
	{
		setbkcolor(animation_time);
		settextstyle(0, 0, 2);
		outtextxy(120, 210, "WELCOME TO ""SLAP SMASH WIN""");
		settextstyle(0, 0, 1);
		delay(100);
		animation_time++;
		setbkcolor(12);
	}

	delay(800);
	outtextxy(230, 250, "ENTER ANY KEY TO START");
	getch();
	cleardevice();
	setbkcolor(9);
	settextstyle(0, 0, 2);
	outtextxy(210, 185, "SELECT FORMAT");
	settextstyle(0, 0, 1);
	delay(500);
	settextstyle(7, 0, 1);
	outtextxy(220, 215, "1)MULTIPLAYER");
	outtextxy(220, 240, "2)PRACTICE MODE");
	settextstyle(0, 0, 1);
	delay(800);
	outtextxy(260, 280, "PRESS A KEY");
	format = getch();
	return format;
}

void start_animation_2(char format)
{
	int i, j;
	char player_1_name[50];
	char player_2_name[50];
	cleardevice();
	setbkcolor(12);

	if (format == '1')
	{
		settextstyle(0, 0, 2);
		outtextxy(170, 225, "ENTER PLAYER 1 NAME");
		scanf("%s", player_1_name);
		cleardevice();
		setbkcolor(12);
		outtextxy(170, 225, "ENTER PLAYER 2 NAME");
		scanf("%s", player_2_name);
		settextstyle(0, 0, 1);
	}
	else
	{
		settextstyle(0, 0, 2);
		outtextxy(180, 225, "ENTER PLAYER NAME");
		scanf("%s", player_1_name);
		settextstyle(0, 0, 1);
	}

	cleardevice();
	setbkcolor(0);
	//loop for first area
	for (i = 60; i <= 120; i++)
	{
		for (j = 60; j <= 120; j++)
		{
			putpixel(j, i, RED);
		}
	}

	//loop of second area
	for (i = 121; i <= 180; i++)
	{
		for (j = 121; j <= 180; j++)
		{
			putpixel(j, i, GREEN);
		}
	}

	//loop of third area
	for (i = 181; i <= 240; i++)
	{
		for (j = 181; j <= 240; j++)
		{
			putpixel(j, i, BLUE);
		}
	}

	if (format == '1')
	{
		settextstyle(0, 0, 2);
		outtextxy(4, 4, "PLAY MATCH BETWEEN");
		delay(1000);
		outtextxy(195, 150, player_1_name);
		delay(800);
		outtextxy(195, 205, "vs");
		delay(500);
		outtextxy(195, 255, player_2_name);
		delay(1000);
		settextstyle(0, 0, 1);
	}
	else
	{
		delay(1000);
		settextstyle(0, 0, 2);
		outtextxy(195, 205, player_1_name);
		delay(1000);
		settextstyle(0, 0, 1);
	}

	return ;
}

void warning_animation()
{
	int animation_time = 1;

	while (animation_time < 13)
	{
		cleardevice();
		setbkcolor(animation_time);
		settextstyle(0, 0, 2);
		outtextxy(210, 205, "|||WARNING|||");
		settextstyle(0, 0, 1);
		outtextxy(260, 235, "INVALID FORMAT");
		outtextxy(260, 250, "GAME::::::ENDS");
		delay(100);
		animation_time++;
	}

	setbkcolor(4);
	settextstyle(0, 0, 2);
	outtextxy(210, 205, "|||WARNING|||");
	settextstyle(0, 0, 1);
	outtextxy(260, 235, "INVALID FORMAT");
	outtextxy(260, 250, "GAME::::::ENDS");
	getch();
}

char str[10];   // for storing number as string

void int_to_str(int n)
{
	int i = 0, j = 0;
	while (n)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	str[i] = '\0';
	i--;
	while (j < i)
	{
		char tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		j++;
		i--;
	}
	return ;
}

void obstacle(int x, int y, int value)
{
	setcolor(4);
	setlinestyle(5, 0, 3);
	rectangle(x, y, x + 50, y + 30);
	int_to_str(value);
	outtextxy(x + 20, y + 10, str);
	return ;
}

void food(int x, int y, int value)
{
	setcolor(14);
	setlinestyle(5, 0, 5);
	circle(x, y, 20);
	int_to_str(value);
	outtextxy(x, y - 5, str);
	return ;
}

void border()
{
	setcolor(3);
	setlinestyle(5, 0, 2);
	rectangle(10, 10, 626, 445); // outer boundry

	setlinestyle(3, 0, 2);
	line(318, 10, 318, 440);  // center partition
	setlinestyle(3, 0, 2);
	setcolor(12);
	rectangle(10, 450, 626, 476);

}

void object(int x, int player, int score)
{
	int y = 290;
	if (player == 1)
		setcolor(5);
	if (player == 2)
		setcolor(2);
	setlinestyle(5, 0, 2);
	line(x - 25, y + 30, x + 25, y + 30); // base
	line(x - 25, y + 30, x, y); // left side
	line(x + 25, y + 30, x, y); // right side
	int_to_str(score);
	outtextxy(x - 9, y + 15, str);
}

void game_end(int player_1_score, int player_2_score, char format)
{
	cleardevice();
	setbkcolor(4);

	if (format == '1')
	{
		setcolor(15);
		settextstyle(0, 0, 2);
		if ((player_1_score <= 0) && (player_2_score <= 0))
			outtextxy(220, 225, "MATCH IS TIE");
		else if (player_1_score <= 0)
			outtextxy(100, 225, "CONGO PLAYER 2,YOU WON...!!!");
		else if (player_2_score <= 0)
			outtextxy(100, 225, "CONGO PLAYER 1,YOU WON...!!!");
	}
	else
	{
		setcolor(15);
		settextstyle(0, 0, 2);
		outtextxy(245, 225, "GAME OVER");
		settextstyle(0, 0, 1);
	}

	getch();
}

int speed = 7;   // initial frame change rate
int obs_sco[3][6] = {0};  // to store points in obstacle of 1st player

void display_obs(int pos_y1, int pos_y2, int pos_y3)
{
	int no;

	for (no = 0; no < 6; no++)
	{
		int value = obs_sco[0][no];
		if (value != 0)
			obstacle(13 + no * 50, pos_y1, value);
	}

	for (no = 0; no < 6; no++)
	{
		int value = obs_sco[1][no];
		if (value != 0)
			obstacle(13 + no * 50, pos_y2, value);
	}

	for (no = 0; no < 6; no++)
	{
		int value = obs_sco[2][no];
		if (value != 0)
			obstacle(13 + no * 50, pos_y3, value);
	}

	delay(10);
	return;

}

int food_sco[6] = {0};   // to store points in food of 1st player
void display_food(int pos_y1)
{
	int  no;

	for (no = 0; no < 6; no++)
	{
		int value = food_sco[no];
		if (value != 0)
			food(38 + no * 50, pos_y1, value);

	}

	return ;
}

int obs_sco2[3][6] = {0};   // to store points in obstacle of 2nd player
void display_obs2(int pos_y1, int pos_y2, int pos_y3)
{
	int no;

	for (no = 0; no < 6; no++)
	{
		int value = obs_sco2[0][no];
		if (value != 0)
			obstacle(13 + 309 + no * 50, pos_y1, value);

	}

	for (no = 0; no < 6; no++)
	{
		int value = obs_sco2[1][no];
		if (value != 0)
			obstacle(13 + 309 + no * 50, pos_y2, value);

	}

	for (no = 0; no < 6; no++)
	{
		int value = obs_sco2[2][no];
		if (value != 0)
			obstacle(13 + 309 + no * 50, pos_y3, value);

	}

	delay(10);
	return;

}



int food_sco2[6] = {0};     // to store points in food of 2nd player

void display_food2(int pos_y1)
{
	int no;
	for (no = 0; no < 6; no++)
	{
		int value = food_sco2[no];
		if (value != 0)
			food(38 + 309 + no * 50, pos_y1, value);
	}
	return ;
}

void update_obs(int num)
{
	int i;

	if (num == 0)
	{
		for (i = 0; i < 6; i++)
		{
			int val = rand() % 10;
			obs_sco[0][i] = val;
			obs_sco2[0][i] = val;
		}
	}

	if (num == 1)
	{
		for (i = 0; i < 6; i++)
		{
			int val = rand() % 10;
			obs_sco[1][i] = val;
			obs_sco2[1][i] = val;
		}
	}

	if (num == 2)
	{
		for (i = 0; i < 6; i++)
		{
			int val = rand() % 10;
			obs_sco[2][i] = val;
			obs_sco2[2][i] = val;
		}
	}

	return ;
}


void update_food()
{
	int i;

	for (i = 0; i < 6; i++)
	{
		int val = rand() % 10;
		food_sco[i] = val;
		food_sco2[i] = val;

	}

	return;
}

int main()
{


	int gd = DETECT, gm, x_1, x_2, player_1_score, player_2_score, food_y; // gd to detect graphics driver
	int pos_y[3] = {11, 200, 300};
	int which_block, which_block2;
	char format;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");  // to init graphics
	format = start_animation_1();
	if (format == '1')        //code for multiplayer
	{
		start_animation_2(format);
		x_1 = 38 + 50 * (rand() % 6);
		x_2 = 347 + 50 * (rand() % 6);
		player_1_score = 20;
		player_2_score = 20;
		food_y = 100;

		update_obs(0);
		update_obs(1);

		while (1)
		{
			cleardevice();
			border();
			if (kbhit())    // if input is there it return 1 otherwise return 0
			{
				char input = getch();
				if (input == 'b')
					break;

				if (input == 'a')
					x_1 -= 50;
				else if (input == 'd')
					x_1 += 50;
				if (input == 'j')
					x_2 -= 50;
				else if (input == 'l')
					x_2 += 50;

			}
			if (x_1 < 38)
				x_1 = 38;
			else if (x_1 > 288)
				x_1 = 288;

			if (x_2 < 347)
				x_2 = 347;
			else if (x_2 > 597)
				x_2 = 597;
			if ((player_1_score <= 0) || (player_2_score <= 0))
			{
				game_end(player_1_score, player_2_score, format);
				game_end(player_1_score, player_2_score, format);
				game_end(player_1_score, player_2_score, format);
				break;
			}
			object(x_1, 1, player_1_score); // to print our object i.e smash ball
			object(x_2, 2, player_2_score);


			display_obs(pos_y[0], pos_y[1], pos_y[2]);
			display_food(food_y);

			display_obs2(pos_y[0], pos_y[1], pos_y[2]);
			display_food2(food_y);

			if (((pos_y[0] + 25) >= 290) && ((pos_y[0] + 25) <= 300))
			{
				which_block = x_1 - 38;
				which_block /= 50;
				player_1_score -= obs_sco[0][which_block];
				obs_sco[0][which_block] = 0;

				which_block2 = x_2 - 38 - 309;

				which_block2 /= 50;
				player_2_score -= obs_sco2[0][which_block2];
				obs_sco2[0][which_block2] = 0;


			}
			else if (((pos_y[1] + 25) >= 290) && ((pos_y[1] + 25) <= 300))
			{
				which_block = x_1 - 38;
				which_block /= 50;
				player_1_score -= obs_sco[1][which_block];
				obs_sco[1][which_block] = 0;

				which_block2 = x_2 - 38 - 309;
				which_block2 /= 50;
				player_2_score -= obs_sco2[1][which_block2];
				obs_sco2[1][which_block2] = 0;
			}
			else if (((pos_y[2] + 25) >= 290) && ((pos_y[2] + 25) <= 300))
			{
				which_block = x_1 - 38;
				which_block /= 50;
				player_1_score -= obs_sco[2][which_block];
				obs_sco[2][which_block] = 0;

				which_block2 = x_2 - 38 - 309;
				which_block2 /= 50;
				player_2_score -= obs_sco2[2][which_block2];
				obs_sco2[2][which_block2] = 0;
			}

			if (((food_y + 25) >= 290) && ((food_y + 25) <= 300))
			{
				which_block = x_1 - 38;
				which_block /= 50;
				player_1_score += food_sco[which_block];
				food_sco[which_block] = 0;

				which_block2 = x_2 - 38 - 309;
				which_block2 /= 50;
				player_2_score += food_sco2[which_block2];
				food_sco2[which_block2] = 0;
			}

			if (pos_y[0] >= 400)
			{
				pos_y[0] = 11;
				update_obs(0);
			}
			if (pos_y[1] >= 400)
			{
				pos_y[1] = 11;
				update_obs(1);
			}
			if (pos_y[2] >= 400)
			{
				pos_y[2] = 11;
				update_obs(2);
			}
			if (food_y >= 400)
			{
				food_y = 11;
				update_food();
			}

			int_to_str(player_1_score);
			outtextxy(15, 460, "SCORE OF PLAYER 1 :: ");
			outtextxy(170, 460, str);
			int_to_str(player_2_score);
			outtextxy(240, 460, "SCORE OF PLAYER 2 :: ");
			outtextxy(400, 460, str);
			delay(10);

			if ((player_1_score >= 25) || (player_2_score >= 25))
				speed = 10;

			pos_y[0] += speed;
			pos_y[1] += speed;
			pos_y[2] += speed;
			food_y += speed;
			delay(50);

		}
	}
	else if (format == '2')    // code for single player
	{
		start_animation_2(format);

		x_1 = 38 + 50 * (rand() % 6);
		player_1_score = 20;
		food_y = 100;

		update_obs(0);
		update_obs(1);

		while (1)
		{
			cleardevice();
			border();
			if (kbhit())
			{
				char input = getch();
				if (input == 'b')
					break;

				if (input == 'a')
					x_1 -= 50;
				else if (input == 'd')
					x_1 += 50;

			}
			if (x_1 < 38)
				x_1 = 38;
			else if (x_1 > 288)
				x_1 = 288;

			if ((player_1_score <= 0))
			{
				game_end(player_1_score, 1, format);
				game_end(player_1_score, 1, format);
				game_end(player_1_score, 1, format);
				break;
			}
			object(x_1, 1, player_1_score);

			display_obs(pos_y[0], pos_y[1], pos_y[2]);
			display_food(food_y);

			if (((pos_y[0] + 25) >= 290) && ((pos_y[0] + 25) <= 300))
			{
				int which_block = x_1 - 38;
				which_block /= 50;
				player_1_score -= obs_sco[0][which_block];
				obs_sco[0][which_block] = 0;
			}
			else if (((pos_y[1] + 25) >= 290) && ((pos_y[1] + 25) <= 300))
			{
				int which_block = x_1 - 38;
				which_block /= 50;
				player_1_score -= obs_sco[1][which_block];
				obs_sco[1][which_block] = 0;
			}
			else if (((pos_y[2] + 25) >= 290) && ((pos_y[2] + 25) <= 300))
			{
				int which_block = x_1 - 38;
				which_block /= 50;
				player_1_score -= obs_sco[2][which_block];
				obs_sco[2][which_block] = 0;
			}

			if (((food_y + 25) >= 290) && ((food_y + 25) <= 300))
			{
				int which_block = x_1 - 38;
				which_block /= 50;
				player_1_score += food_sco[which_block];
				food_sco[which_block] = 0;
			}



			if (pos_y[0] >= 400)
			{
				pos_y[0] = 11;
				update_obs(0);
			}
			if (pos_y[1] >= 400)
			{
				pos_y[1] = 11;
				update_obs(1);
			}
			if (pos_y[2] >= 400)
			{
				pos_y[2] = 11;
				update_obs(2);
			}
			if (food_y >= 400)
			{
				food_y = 11;
				update_food();
			}

			int_to_str(player_1_score);
			outtextxy(15, 460, "SCORE OF PLAYER ::");
			outtextxy(170, 460, str);
			delay(10);

			if (player_1_score >= 25)
				speed = 10;

			pos_y[0] += speed;
			pos_y[1] += speed;
			pos_y[2] += speed;
			food_y += speed;
			delay(50);

		}

	}
	else
	{
		warning_animation();
	}
	closegraph();
	return 0;

}