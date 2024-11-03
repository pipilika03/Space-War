#include<iostream>
#include<string>
#include "iGraphics.h"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 650


int dx = 10, dy = 10;
int bg_x=0, bg_y=0;

int themeImage;

bool gamestart = false;
bool level = false;
bool start = false;
bool how_to_play = false;
bool gameover = false;
char score[100]="0",highscore[10]="1763";
char levels[10] = "1";
int SCORE = 0,LEVELS=0;
int life = 3 ,go1,go2,go3,lifepic;
int levelimage, bg, bg1, bg2, bg3,bbk,playb,htp,about,sc,gv,resume,pause,htpr,close,mm,mr,bgs,load1,load2,load,laser,mmm;

bool d1 = 1, d2 = 1, d3 = 1, d4 = 1, d5 = 1;

int d1x = (SCREEN_WIDTH - 255) / 2 , d2x = (SCREEN_WIDTH - 255) / 2 - 160, d3x = (SCREEN_WIDTH - 255) / 2 - 320, d4x = (SCREEN_WIDTH - 255) / 2 + 160, d5x = (SCREEN_WIDTH - 255) / 2 + 320, d1y = 550, d2y = 580, d3y = 580, d4y = 580, d5y = 580;
int spx = (SCREEN_WIDTH - 255) / 2, spy = 20;
int bx = 472 + 37,by = 20 + 120;
bool bullet = 0;

void Image()
{
	themeImage = iLoadImage("img\\t7.png");
	levelimage = iLoadImage("Theme\\level.png");
	bg = iLoadImage("img\\t7.png");
	bg1 = iLoadImage("Theme\\bg1.png");
	bg2 = iLoadImage("Theme\\bg2.png");
	bg3 = iLoadImage("Theme\\bg3.png");
	go1 = iLoadImage("Theme\\gover.png");
	go2 = iLoadImage("Theme\\ggov.png");
	go3 = iLoadImage("Theme\\go3.png");
	lifepic = iLoadImage("Theme\\life.png");
	sc = iLoadImage("menu\\score.png");
	gv = iLoadImage("menu\\gmov.png");
	resume = iLoadImage("menu\\resume.png");
	pause = iLoadImage("menu\\pause.png");
	htpr = iLoadImage("img\\rules.png");
	close = iLoadImage("menu\\Close.png");
	mm = iLoadImage("menu\\manu.png");
	mr = iLoadImage("menu\\menur.png");
	bgs = iLoadImage("img\\bg.png");
	load = iLoadImage("img\\spaceship1.png");
	load2 = iLoadImage("img\\demonship2.png");
	load1 = iLoadImage("img\\demonship1.png");
	laser = iLoadImage("img\\laser1.png");
	mmm = iLoadImage("img\\mmm.png");

}




//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void iDraw()
{
	iClear();
	if (!gamestart){
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, themeImage);

		if (how_to_play){
			iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, htpr);
			iShowImage(1000,570,150,50,close);
		}

	}

	if (gamestart)
	{
		iShowImage(bg_x, bg_y, SCREEN_WIDTH, SCREEN_HEIGHT, bgs);
		iShowImage(bg_x, bg_y+650, SCREEN_WIDTH, SCREEN_HEIGHT, bgs);

		if (d1)
			iShowImage(d1x, d1y,70, 80, load2);
		if (d2)
			iShowImage(d2x, d2y,50, 60, load1);
		if (d3)
			iShowImage(d3x,d3y, 50, 60, load1);
		if (d4)
			iShowImage(d4x, d4y, 50, 60, load1);
		if (d5)
			iShowImage(d5x,d5y, 50, 60, load1);

		iShowImage(spx,spy, 90, 120, load);
		if (bullet && start){
			bx = spx + 37;
			iShowBMP2(bx, by, "img\\bullet.bmp", 0);
		}
			

		iShowImage(SCREEN_WIDTH - 255, 0, 255, SCREEN_HEIGHT, bgs);
		iSetColor(0, 255, 0);
		iRectangle(10, 10, SCREEN_WIDTH - 255, SCREEN_HEIGHT - 20);
		iSetColor(255, 0, 0);
		iRectangle(5, 5, SCREEN_WIDTH - 245, SCREEN_HEIGHT - 10);
		iSetColor(0, 255, 0);
		iRectangle(SCREEN_WIDTH - 235, 10, 220, SCREEN_HEIGHT - 20);
		iSetColor(255, 0, 0);
		iRectangle(SCREEN_WIDTH - 240, 5, 230, SCREEN_HEIGHT - 10);
		

		iSetColor(255,255,0);
		iText(SCREEN_WIDTH - 225, 560, "Resume   Pause   Menu", GLUT_BITMAP_9_BY_15);
		iShowImage(SCREEN_WIDTH - 210, 590, 30, 30, resume);
		iShowImage(SCREEN_WIDTH - 130, 590, 30, 30, pause);
		iShowImage(SCREEN_WIDTH - 70, 585, 35, 35, mm);
		//iRectangle(SCREEN_WIDTH -230,550,110,90);
		//iRectangle(SCREEN_WIDTH - 120, 550, 100, 90);

		iText(SCREEN_WIDTH - 150, 510, "Life", GLUT_BITMAP_TIMES_ROMAN_24);
		for (int l = 0; l < life;l++)
		iShowImage(l*30+(SCREEN_WIDTH-160),465 ,20,20, lifepic);

		if ((d1x >= spx && d1x + 70 <= spx + 90 && d1y<spy + 120 && d1) || (d2x >= spx && d2x + 50 <= spx + 90 && d2y<spy + 120 && d2) || (d3x >= spx && d3x + 50 <= spx + 90 && d3y<spy + 120 && d3) || (d4x >= spx && d4x + 50 <= spx + 90 && d4y<spy + 120 && d4) || (d5x >= spx && d5x + 50 <= spx + 90 && d5y<spy + 120 && d5))
		{
			start = false;
			life--;
			d1x = (SCREEN_WIDTH - 255) / 2, d2x = (SCREEN_WIDTH - 255) / 2 - 160, d3x = (SCREEN_WIDTH - 255) / 2 - 320, d4x = (SCREEN_WIDTH - 255) / 2 + 160, d5x = (SCREEN_WIDTH - 255) / 2 + 320, d1y = 550, d2y = 580, d3y = 580, d4y = 580, d5y = 580;
			spx = (SCREEN_WIDTH - 255) / 2, spy = 20;
		}


		if (d1x >= bx && d1x + 70 <= bx + 16 && d1y <= by + 16)
			d1 = 0;




		iText(SCREEN_WIDTH - 180, 410, "Player Name", GLUT_BITMAP_TIMES_ROMAN_24);
		_itoa_s(SCORE, score, 10);
		iText(SCREEN_WIDTH - 150, 310, "Score", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(SCREEN_WIDTH - 150, 265, score, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(SCREEN_WIDTH - 150, 210, "Level", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(SCREEN_WIDTH - 135, 165, levels, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(SCREEN_WIDTH - 180, 110, "High Score", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(SCREEN_WIDTH - 150, 65, highscore, GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(0, 200, 200);
		iRectangle(SCREEN_WIDTH - 230, 450, 210, 50);
		iRectangle(SCREEN_WIDTH - 230, 350, 210, 50);
		iRectangle(SCREEN_WIDTH - 230, 250, 210, 50);
		iRectangle(SCREEN_WIDTH - 230, 150, 210, 50);
		iRectangle(SCREEN_WIDTH - 230, 50, 210, 50);
		

	}
	if (life == 0){
		gameover = true;
	}
	if (gameover) {
		iShowImage(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, go2);
		iShowImage(400, 265, 500, 120, gv);
		iSetColor(255, 255, 0);
		iShowImage(500, 150, 300, 100, sc);
		iText(640, 120, score, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0, 255, 255);
		iRectangle(600, 105, 120, 40);
		iShowImage(620, 15, 80, 80, mr);
	}
	
}


/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
		//iShowImage(500, 350, 200, 80, playb);
		if (mx >= 500 && mx <= 700 && my >= 350 && my <= 350+80)
			gamestart = true;
		/*iText(SCREEN_WIDTH - 225, 560, "Resume   Pause   Menu", GLUT_BITMAP_9_BY_15);
		iShowImage(SCREEN_WIDTH - 210, 590, 30, 30, resume);
		iShowImage(SCREEN_WIDTH - 130, 590, 30, 30, pause);
		iShowImage(SCREEN_WIDTH - 70, 585, 35, 35, mm);
		;*/
		if (mx >= (SCREEN_WIDTH - 210) && mx <= (SCREEN_WIDTH - 210)+30 && my >= 590 && my <= 620 && !start && gamestart)
			start = true;
		if (mx >= (SCREEN_WIDTH - 130) && mx <= (SCREEN_WIDTH - 130)+30 && my >= 590 && my <= 620 && start)
			start = false;
		if (mx >= (SCREEN_WIDTH - 70) && mx <= (SCREEN_WIDTH - 70) + 35 && my >= 585 && my <= 620){
			gamestart = false;
			gameover = false;
			life = 3;
			SCORE = 0;
			_itoa_s(SCORE, score, 10);
			
		}
		//iShowImage(490, 90, 200, 65, about);
		if (mx >= 490 && mx <= 690 && my >= 90 && my <= 90+65)
			how_to_play = true;

		//iShowImage(1000,570,150,50,close);
		if (mx >= 1000 && mx <= 1150 && my >= 570 && my <= 620)
			how_to_play = false;

		//iShowImage(620, 15, 80,80, mr);
		if (mx >= 620 && mx <= 700 && my >= 15 && my <= 95)	{
			gamestart = false;
			gameover = false;
			life = 3;
			SCORE = 0;
			_itoa_s(SCORE, score, 10);
			
		}
			
		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == ' ')
	{
		bullet = 1;
	}
	
	if (key == 'b')
	{
		start = true;
	}

	if (key == 'p')
	{
		start = false;
	}

	/*else if (gamemenu.namefieldactive == true && playerinfo.nameindex <= 9){
		if (key != '\b'){
			playerinfo.playerName[playerinfo.nameindex] = key;
			playerinfo.playerName[playerinfo.nameindex + 1] = '\0';
			playerinfo.nameindex++;
		}
		else{
			playerinfo.playerName[playerinfo.nameindex] = '\0';
			playerinfo.nameindex--;
			if (playerinfo.nameindex < 0)
				playerinfo.nameindex = 0;
		}
	}*/
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/

void iSpecialKeyboard(unsigned char key)
{
	if (start) {


		if (key == GLUT_KEY_RIGHT)
		{
			if (spx <= (SCREEN_WIDTH -350)	)
				spx += 20;
			
		}
		if (key == GLUT_KEY_LEFT)
		{
			if (spx >= 20)
				spx -= 20;
		}

	}
	if (key == GLUT_KEY_UP)
	{
		if (!start)
			start = true;

	}
}



void runbg(){
	if (start){
		bg_y -= 10;
		if (bg_y <= -650)
			bg_y = 0;
	}
}
void enemy(){
	if (start){
		//d1y = 550, d2y = 580, d3y = 580, d4y = 580, d5y = 580;
		d1y -= rand() % 25;
		d2y -= rand() % 25;
		d3y -= rand() % 25;
		d4y -= rand() % 25;
		d5y -= rand() % 25;
		d1x -= rand() % 30;
		d1x += rand() % 30;
		d2x -= rand() % 30;
		d2x += rand() % 30;
		d3x -= rand() % 30;
		d3x += rand() % 30;
		d4x -= rand() % 30;
		d4x += rand() % 30;
		d5x -= rand() % 30;
		d5x += rand() % 30;

		//int bx = spx + 37,by = spy + 120;
		/*if (d1)
			iShowImage(d1x, d1y,70, 80, load2);
		if (d2)
			iShowImage(d2x, d2y,50, 60, load1);
		if (d3)
			iShowImage(d3x,d3y, 50, 60, load1);
		if (d4)
			iShowImage(d4x, d4y, 50, 60, load1);
		if (d5)
			iShowImage(d5x,d5y, 50, 60, load1);

		iShowImage(spx,spy, 90, 120, load);
		if (bullet && start){
			bx = spx + 37;
			iShowBMP2(bx, by, "img\\bullet.bmp", 0);
		}
		
*/

		if (bx > d1x && bx < d1x + 70 && by > d1y && by<d1y + 80) d1 = 0;
		if (bx > d2x && bx < d2x + 50 && by > d2y && by<d2y + 60) d2 = 0;
		if (bx > d3x && bx < d3x + 50 && by > d3y && by<d3y + 60) d3 = 0;
		if (bx > d4x && bx < d4x + 50 && by > d4y && by<d4y + 60) d4 = 0;
		if (bx > d5x && bx < d5x + 50 && by > d5y && by<d5y + 60) d5 = 0;

		if (d1y <= -80){
			d1y = 550;
			d1 = 1; d2 = 1; d3 = 1; d4 = 1; d5 = 1;
		}
		if (d2y <= -60){

			d2y = 580;
			d1 = 1; d2 = 1; d3 = 1; d4 = 1; d5 = 1;
		}
		if (d3y <= -60) {

			d3y = 580;
			d1 = 1; d2 = 1; d3 = 1; d4 = 1; d5 = 1;
		}
		if (d4y <= -60) {
			d4y = 580;
			d1 = 1; d2 = 1; d3 = 1; d4 = 1; d5 = 1;
		}
		if (d5y <= -60)
		{
			d5y = 580;
			d1 = 1; d2 = 1; d3 = 1; d4 = 1; d5 = 1;
		}

	}
}


void bull(){
	if (start){
		if (bullet)
			by += 30;
		if (by >= 650){
			bullet = 0;
			by = spy + 120;
		}
	}
}

void scr(){
	if (start)
		SCORE++;
}

int main()
{
	srand(time(0));
	iSetTimer(40, runbg);
	iSetTimer(700, scr);
	iSetTimer(100, enemy);
	iSetTimer(20, bull);
	///srand((unsigned)time(NULL));
	iInitialize(SCREEN_WIDTH, SCREEN_HEIGHT, "Space War");
	Image();
	PlaySound("music\\music1", NULL, SND_LOOP | SND_ASYNC);
	
	//if (gamestart)
	///updated see the documentations
	iStart();
	return 0;
}