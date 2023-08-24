//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include <ctime>
#include <fstream>


using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

//prototyping all the functions.
void building1(int []);
void building2(int []);
void building3(int []);
void building4(int []);

void objects();

void passengerDisplay();

void drawCar();
int * carX();
int * carY();

void drawCar2();
int * carX2();
int * carY2();

void drawCar3();
int * carX3();
int * carY3();

void drawCar4();
int * carX4();
int * carY4();

void drawCar5();
int * carX5();
int * carY5();

int * drops();

void moveCar();
void moveCar2();
void moveCar3();
void moveCar4();

int * arrayAddress();
int * objectArrayAddress();
int * passengerArrayAddress();
int * carCoordinates();

bool collision(int *, int *);
int speedFun(int *);

int *taxiColor();
int *score();

bool * menuStatus();
bool * gameStatus();
bool * tMenuStatus();
bool * leaderboardStatus();

void menuCar(int, int, float *);
void MenuDisplay();
void GameDisplay();
void taxiMenu();
bool carClicked(int, int, int, int);

bool passengerCollision(int, int);
void scoreDeduction();

void fileOutput();
void fileInput();

int * scoresRecord();
string * nameRecords();

int * time();

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

// these next few functions helped me remove variables. These function return the pointer to a variable that can be used in other functions as well. 
int * carX(){

	static int xI = 20; // making the varibale static so it could be used later. 
	int *ptr = &xI; // assigning its address to a pointer. 
	return ptr; // returning pointer. 
}
// for car Y coordinate
int * carY(){

	static int yI = 700;
	int *ptr = &yI;
	return ptr;
}
// for car 2 X coordinate
int * carX2(){

	static int xI = 100;
	int *ptr = &xI;
	return ptr;
}
// for car 2 Y coordinate
int * carY2(){

	static int yI = 100;
	int *ptr = &yI;
	return ptr;
}
// for car 3 X coordinate
int * carX3(){

	static int xI = 900;
	int *ptr = &xI;
	return ptr;
}
// for car 3 Y coordinate
int * carY3(){

	static int yI = 100;
	int *ptr = &yI;
	return ptr;
}
// for car 4 X coordinate
int * carX4(){

	static int xI = 500;
	int *ptr = &xI;
	return ptr;
}
// for car 4 X coordinate
int * carY4(){

	static int yI = 350;
	int *ptr = &yI;
	return ptr;
}
// for car 5 X coordinate
int * carX5(){

	static int xI = 300;
	int *ptr = &xI;
	return ptr;
}
// for car 5 X coordinate
int * carY5(){

	static int yI = 400;
	int *ptr = &yI;
	return ptr;
}
// for calculating the number of drops so that with each increase of 2 another car can be added to the canvas. 
int * drops(){

	static int drop = 0;
	int *ptr = &drop;
	return ptr;
}
// this function is used for drawing car and assigning it the coordinates on the screen. next 5 functions are for drawing car. 
void drawCar() {

	int *color = taxiColor();

	int *ptrX = carX();
	int *ptrY = carY();
	switch(*color){ // checking what is the color selected by the user and and the assging the relevant color to the car. 
		case 1: DrawSquare(*ptrX, *ptrY, 40, colors[RED]); break;
		case 2: DrawSquare(*ptrX, *ptrY, 40, colors[ORANGE]); break;
	}
	DrawCircle(*ptrX+5, *ptrY+5, 7,colors[GREEN]);
	DrawCircle(*ptrX+35, *ptrY+5, 7,colors[GREEN]);
	glutPostRedisplay();
}	

void drawCar2() {
	int *ptrX = carX2();
	int *ptrY = carY2();
	DrawSquare(*ptrX, *ptrY, 40, colors[VIOLET]);
	DrawCircle(*ptrX+5, *ptrY+5, 7,colors[GREEN]);
	DrawCircle(*ptrX+35, *ptrY+5, 7,colors[GREEN]);
	glutPostRedisplay();
}	
void drawCar3() {
	int *ptrX = carX3();
	int *ptrY = carY3();
	DrawSquare(*ptrX, *ptrY, 40, colors[VIOLET]);
	DrawCircle(*ptrX+5, *ptrY+5, 7,colors[GREEN]);
	DrawCircle(*ptrX+35, *ptrY+5, 7,colors[GREEN]);
	glutPostRedisplay();
}	
void drawCar4() {
	int *ptrX = carX4();
	int *ptrY = carY4();
	DrawSquare(*ptrX, *ptrY, 40, colors[VIOLET]);
	DrawCircle(*ptrX+5, *ptrY+5, 7,colors[GREEN]);
	DrawCircle(*ptrX+35, *ptrY+5, 7,colors[GREEN]);
	glutPostRedisplay();
}	
void drawCar5() {
	int *ptrX = carX5();
	int *ptrY = carY5();
	DrawSquare(*ptrX, *ptrY, 40, colors[VIOLET]);
	DrawCircle(*ptrX+5, *ptrY+5, 7,colors[GREEN]);
	DrawCircle(*ptrX+35, *ptrY+5, 7,colors[GREEN]);
	glutPostRedisplay();
}	
// next few functions are for moving the dynamic cars on the screen.  
void moveCar() {

	int *dropsCount = drops();
	int speed = speedFun(dropsCount);

	static bool flag = true; // setting a flag and then moving its direction accordinglly. 

	int *ptrX = carX3(); // getting the coordinates of the car
	int *ptrY = carY3();

	
	if (*ptrY > 10 && flag) { // if car is greater than 10 Y coordinates 

		*ptrY -= speed; // it will move towards down
		
	// collision function is ccalled to check if the object collides. If yess than the direction is reversed. 
		if(*ptrY < 100 || (collision(ptrX, ptrY))) // if it is close to the border the flag will be set false. 
			
			flag = false;

	}
	else if (*ptrY < 800 && !flag) { // now the conditions are reversed and the car moves towards up.
		*ptrY += speed;
		if (*ptrY > 750  || (collision(ptrX, ptrY)))
			flag = true;
	}
}
void moveCar2() {

	int *dropsCount = drops();
	int speed = speedFun(dropsCount);

	static bool flag = true;

	int *ptrX = carX2(); // getting the coordinates of the car
	int *ptrY = carY2();

	// collision function is ccalled to check if the object collides. If yess than the direction is reversed. 
	if (*ptrX > 10 && flag) { // if it is close to the border the flag will be set false. 

		*ptrX -= speed;
		if(*ptrX < 100 || (collision(ptrX, ptrY))) // it will move towards left
			
			flag = false;

	}
	else if (*ptrX < 1010 && !flag) { // now the conditions are reversed and the car moves towards right.
	
		*ptrX += speed;
		if (*ptrX > 900  || (collision(ptrX, ptrY))) // if it is close to the border the flag will be set true. 
			flag = true;
	}
}
void moveCar3() {

	int *dropsCount = drops();
	int speed = speedFun(dropsCount);

	static bool flag = true;

	int *ptrX = carX4(); // getting the coordinates of the car
	int *ptrY = carY4();

	// collision function is ccalled to check if the object collides. If yess than the direction is reversed. 
	if (*ptrX > 20 && *ptrY > 20 && flag) { // it will move towards left bottom

		*ptrX -= speed;
		*ptrY -= speed;
		

		if(*ptrX < 100 || *ptrY < 100 || (collision(ptrX, ptrY))) // if it is close to the border the flag will be set false. 
			
			flag = false;

	}
	else if (*ptrX < 1010 && *ptrY < 800 && !flag) { // now the conditions are reversed and the car moves towards right top.
		
		*ptrX += speed;
		*ptrY += speed;
		if (*ptrX > 900  && *ptrY > 750 || (collision(ptrX, ptrY))) // if it is close to the border the flag will be set true.
			flag = true;
	}
}
void moveCar4() {

	int *dropsCount = drops();
	int speed = speedFun(dropsCount);

	

	static bool flag = true;

	int *ptrX = carX5();
	int *ptrY = carY5();

	
	if (*ptrX > 20 && *ptrY < 800 && flag) {  // it will move towards left top

		*ptrX -= speed;
		*ptrY += speed;
		
// collision function is ccalled to check if the object collides. If yess than the direction is reversed. 
		if(*ptrX < 100 || *ptrY > 750 || (collision(ptrX, ptrY))) // if it is close to the border the flag will be set false. 
			
			flag = false;

	}
	else if (*ptrX < 1010 && *ptrY > 100 && !flag) { // now the conditions are reversed and the car moves towards right bottom.
		
		*ptrX += speed;
		*ptrY -= speed;
		if (*ptrX > 900  && *ptrY < 100 || (collision(ptrX, ptrY))) // if it is close to the border the flag will be set true.
			flag = true;
	}
}
// this function is for seting the speed of the dynamic cars based on the number of drops. used this function too reduce repition. 
int speedFun(int *dropsCount){
	int speed = 0;

	switch(*dropsCount){ // checking drop counts at location pointed by this pointer. 
		case 6 ... 100: speed = 12;break; // subsequest speeds are assigned for the number of drops. 
		case 5:
		case 4: speed = 10;break;
		case 3:
		case 2: speed = 7;break;
		case 1:
		case 0: speed = 5;break;
	}

	return speed;
}
// this function returns true if a car is colliding with an obstacle.  used this function too reduce repition. 
bool collision(int *ptrX, int *ptrY){

	// getting array addresses. 
	int *arr = arrayAddress();
	int *passArr = passengerArrayAddress();
	int *carArr = carCoordinates();

	const int obsatacles_num = 10;
	const int sub2 = 4;

	bool flag = false;
	

	for (int i = 0; i < obsatacles_num; i++)
			for (int j = arr[(i*sub2)+0]; j < arr[i*sub2+0] + arr[i*sub2+2]; j++)
				if (j == *ptrX)
					for (int k = arr[i*sub2+1]; k < arr[i*sub2+1] + arr[i*sub2+3]; k++)
						if(k == *ptrY)
							flag = true;

	for (int i = 0; i < 5; i++)
		for (int j = passArr[(i*3)+0]-30; j < passArr[i*3+0] + 30; j++)
			if (j == *ptrX)
				for (int k = passArr[i*3+1]-30; k < passArr[i*3+1] + 30; k++)
					if(k == *ptrY && passArr[i*3+2] == 1)
						flag = true;
	
	for (int i = 0; i < 4; i++)
		if (*ptrX != carArr[(i*3)+0] && *ptrX != carArr[i*3+1])
			for (int j = carArr[(i*3)+0]-40; j < carArr[i*3+0] + 40; j++)
				if (j == *ptrX)
					for (int k = carArr[i*3+1]-40; k < carArr[i*3+1] + 40; k++)
						if(k == *ptrY && carArr[i*3+2] == 1)
							flag = true;		

	return flag;
}
/*
 * Main Canvas drawing function.
 * */
// to get the pointer which is pointiing to an array of address of obstacles. 
int * arrayAddress(){
	const int obsatacles_num = 10;
	static int *arr = new int[obsatacles_num * 4];  // dynamic memory allocation. 


	return arr;
}
// to get the pointer which is pointiing to an array of address of scores record. 
int * scoresRecord(){
	static int *arr = new int[10]{0}; 

	return arr;
}
// to get the pointer which is pointiing to an array of address of names record. 
string * nameRecords(){
	static string *arr = new string[10]{"R"}; 

	static int count = 0;

	if (count == 0)
		for (int i = 0; i<10; i++)
			arr[i]= "R";

	return arr;
}
// this function is used for generating random coordinates for object and validating that they dont overlap with other obstacles. 
int * objectArrayAddress(){

	static int *randarr = new int[5 * 2]; 


	const int obsatacles_num = 10;

	bool overlapping = false;
	const int sub2 = 4;

	int *arr = arrayAddress();
	static int count = 0;

	if (count == 0)
		for (int a = 0; a < 5; a++){
			do{
				overlapping = false;
				randarr[((a)*2)+0] = GetRandInRange(100, 900);
				randarr[((a)*2)+1] =  GetRandInRange(100, 700);
				for (int i = 0; i < obsatacles_num; i++)
						for (int j = arr[(i*sub2)+0]; j < arr[i*sub2+0] + arr[i*sub2+2]; j++)
							if (j == randarr[((a)*2)+0])
								for (int k = arr[i*sub2+1]; k < arr[i*sub2+1] + arr[i*sub2+3]; k++)
									if(k == randarr[((a)*2)+1])
										overlapping = true;
			} while(overlapping);

			arr[((a+5) * sub2)+0] = randarr[((a)*2)+0]-40;
			arr[((a+5) * sub2)+1] = randarr[((a)*2)+1]-40;
			arr[((a+5) * sub2)+2] = 40+40;
			arr[((a+5) * sub2)+3] = 40+40;
	    }
	count++;
	return randarr;
}
// this function is used to draw the objects. 
void objects(){

	
	int *randarr = objectArrayAddress();


	for (int a = 0; a < 5; a++){ // all the objects are drawn here and its changes it type alternatively. 

		if (a%2 == 0) {
		DrawSquare(randarr[((a)*2)+0], randarr[((a)*2)+1], 40, colors[BLUE]);
		DrawSquare(randarr[((a)*2)+0]+10, randarr[((a)*2)+1]+10, 20, colors[SILVER]);
		} else {
		DrawSquare(randarr[((a)*2)+0], randarr[((a)*2)+1], 40, colors[BROWN]);
		DrawCircle(randarr[((a)*2)+0]+20, randarr[((a)*2)+1]+20, 10, colors[SILVER]);
		}
	}

}
// function to check the collsion of the passengers with the obstacles. 
bool passengerCollision(int x, int y){

	int *arr = arrayAddress();
	const int obsatacles_num = 10;
	const int sub2 = 4;

	bool flag = false;
	/*for (int i = 0; i < 10; i ++)
		for (int j = 0; j < 4; j ++)
			cout << arr[(i*4)+j] << endl;*/

	for (int i = 0; i < obsatacles_num; i++)
		for (int j = arr[(i*sub2)+0]; j < arr[i*sub2+0] + arr[i*sub2+2]; j++)
			if (j == x)
				for (int k = arr[i*sub2+1]; k < arr[i*sub2+1] + arr[i*sub2+3]; k++)
					if(k == y)
						flag = true;


	return flag;
}

// function for Displaying passengers
void passengerDisplay(){

	int *passengers = passengerArrayAddress();

	for (int a = 0; a < 5; a++){
		if (passengers[((a)*3)+2] == 1){
			DrawRectangle(passengers[((a)*3)+0]+15, passengers[((a)*3)+1], 10, 40, colors[BLACK]);
			DrawCircle(passengers[((a)*3)+0]+20, passengers[((a)*3)+1]+30,10,colors[DARK_CYAN]);
		}

	}
}
// this function was used to calculate the random coordinates for a drop off. and this function made it easier to validate and change the drop off lcoation for 
// each time. 
int * dropOff(){

	static int *randarr = new int[4]; 

	const int obsatacles_num = 10;

	bool overlapping = false;

	const int sub2 = 4;

	int *arr = arrayAddress();
	int *passArr = passengerArrayAddress();

	static int count = 0;

	if (count > 0){
		count = randarr[3];
	}

	if (count == 0)
		for (int a = 0; a < 5; a++){
			do{
				overlapping = false;
		
				randarr[0] = GetRandInRange(100, 900);
				randarr[1] = GetRandInRange(100, 700);
				randarr[2] = 0;
				for (int i = 0; i < obsatacles_num; i++)
						for (int j = arr[(i*sub2)+0]; j < arr[i*sub2+0] + arr[i*sub2+2]; j++)
							if (j == randarr[0])
								for (int k = arr[i*sub2+1]; k < arr[i*sub2+1] + arr[i*sub2+3]; k++)
									if(k == randarr[1])
										overlapping = true;

				for (int i = 0; i < 5; i++)
					for (int j = passArr[(i*3)+0]-30; j < passArr[i*3+0] + 30; j++)
						if (j == randarr[0])
							for (int k = passArr[i*3+1]-30; k < passArr[i*3+1] + 30; k++)
								if(k == randarr[1] && passArr[i*3+2] == 1)
									overlapping = true;	
						
				
			} while(overlapping);
		}
	count++;

	count = randarr[3] = 1;

	if (randarr[2] == 1)
		DrawCircle(randarr[0], randarr[1], 20, colors[LIME_GREEN]);

	return randarr;
}
// function to make an array of all the coordinates of car and later on this array was used to check the collision between cars. 
int * carCoordinates(){
	static int *arr = new int[4*3]; 

	arr[(0*3)+0]= *carX2();
	arr[(0*3)+1]= *carY2();
	arr[(0*3)+2]= 0;

	arr[(1*3)+0]= *carX3();
	arr[(1*3)+1]= *carY3();
	arr[(1*3)+2]= 1;

	arr[(2*3)+0]= *carX4();
	arr[(2*3)+1]= *carY4();
	arr[(2*3)+2]= 0;

	arr[(3*3)+0]= *carX5();
	arr[(3*3)+1]= *carY5();
	arr[(3*3)+2]= 0;


	return arr;	
}
// function pointing to an taxicolor. 
int * taxiColor(){
	static int color = 0;
	int * ptr = &color;
	return ptr;
}

// next 4 function are used to check the status of each display, which changes respectively. Using fucntions this way helped me to use them in other functions. 
bool * leaderboardStatus(){
	static bool LB = false;
	bool * ptr = &LB;
	return ptr;
}
bool * gameStatus(){
	static bool game = false;
	bool * ptr = &game;
	return ptr;
}
bool * menuStatus(){
	static bool menu = true;
	bool * ptr = &menu;
	return ptr;
}
bool * tMenuStatus(){
	static bool tMenu = false;
	bool * ptr = &tMenu;
	return ptr;
}
// Function which focuses only on the leaderboard display. 
void leaderBoardDisplay(){
	int *scores = scoresRecord();
	string *names = nameRecords();

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	DrawSquare(200, 100, 600, colors[LIGHT_GRAY]);

	DrawRoundRect(400, 650, 150, 30, colors[BLUE], 5);
	DrawString(405, 655, "Leader Board", colors[BLACK]);

	for (int i = 0; i < 10; i++)
		DrawString(250, 600-(i*40), to_string(i+1) + ". " + names[i] + " ---- " + to_string(scores[i]), colors[BLACK]);

	DrawRoundRect(400, 175, 150, 30, colors[BLUE], 5);
	DrawString(430, 180, "BACK", colors[BLACK]);
}
// function for taxi menu. 
void taxiMenu(){

	bool *tMenu = tMenuStatus();
	
	if(*tMenu){

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	
	menuCar(300, 370, colors[RED]);
	menuCar(500, 370, colors[ORANGE]);

	} else
		MenuDisplay();
}
// functon for drawing a menu car. this helped me reduce the code. 
void menuCar(int x, int y, float * color){
	DrawRectangle(x, y, 150, 80, color);
	DrawRoundRect(x+30, y+50, 90, 50, colors[BLUE], 5);

	DrawCircle(x+20, y+20, 10,colors[BLACK]);
	DrawCircle(x+130, y+20, 10,colors[BLACK]);
}
// this function was used to store the name entered by the user. 
char * nameArr(){
	static char name[5];
	char * ptr = name;
	return ptr;
}
// function for displaying menu
void MenuDisplay(){

	bool *game = gameStatus();
	bool *menu = menuStatus();
	bool *tMenu = tMenuStatus();
	int *color = taxiColor();
	char * name = nameArr();

	//name = "riyan";
	if(*menu){
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
				0/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors

		DrawString(380, 500, "RUSH HOUR", colors[YELLOW]);
		
		switch(*color){
			case 1: menuCar(380, 370, colors[RED]); break;
			case 2: menuCar(380, 370, colors[ORANGE]); break;
			default: menuCar(380, 370, colors[WHITE]);
		}
		if (*color == 0)
			DrawString(400, 400, "Select Taxi", colors[BLACK]);

		DrawRoundRect(380, 330, 150, 30, colors[BLUE], 5);
		DrawString(395, 335, "Start Game", colors[BLACK]);

		DrawRoundRect(380, 290, 150, 30, colors[BLUE], 5);
		DrawString(390, 295, "LeaderBoard", colors[BLACK]);

		DrawRoundRect(380, 250, 150, 30, colors[LIME], 5);
		DrawString(390, 255, "Enter Name", colors[BLACK]);

		DrawRoundRect(380, 210, 150, 30, colors[WHITE], 5);
		DrawString(420, 215, name , colors[BLACK]);

	
	
	}else if (*tMenu){
		taxiMenu();
	} else if (*leaderboardStatus){
		leaderBoardDisplay();
		// fileOutput();
		
	}else {
		GameDisplay();
	}

}
// function for generating random coordinates for passenger and validating they dont overlap. 
int * passengerArrayAddress(){
	
	static int *randarr = new int[5 * 3];

	bool *game = gameStatus(); 	

	bool overlapping = false;
	
	static int count1 = 0;

	
	if (count1 == 0)
	
		for (int a = 0; a < 5; a++)
			do{
				overlapping = false;
				
				randarr[((a)*3)+0] = GetRandInRange(100, 900);
				randarr[((a)*3)+1] =  GetRandInRange(100, 700);
				randarr[((a*3)+2)] = 1;
				
				if (passengerCollision(randarr[((a)*3)+0], randarr[((a)*3)+1]))
					overlapping = true;
					

			} while(overlapping);
	if (*game){	
		count1++;
	}
	
	return randarr;
}
// make function  of the game display. 
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.
	 // 0 for x coordinate, 1 for y coordinate, 2 for lenght of the building and 3 for height of the building.  

	int * aptr = arrayAddress();
	int *carArr = carCoordinates();
	char *name = nameArr();
	string nm = name;

	int xI = *carX(), yI = 400;
	
	int *dropsCount = drops();

	bool *game = gameStatus();
	bool *menu = menuStatus();
	
	int *points = score();
	string strPoints = Num2Str(*points);

	int *t = time();
	string strtime = Num2Str(*t);

	bool endGame = false;

	if (*t < 0){
		endGame = true;
	}
	if(!*game)
		MenuDisplay();
	else if (endGame){
		glClearColor(0.7/*Red Component*/, 0.7,	//148.0/255/*Green Component*/,
			0.7/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors

		if(*points > 100)
			DrawString(380, 600, "GAME OVER, YOU WON!!!!", colors[BLACK]);
		else 
			DrawString(380, 600, "GAME OVER, YOU LOST!!!!", colors[BLACK]);
		DrawString(450, 550, nm + " score: " + strPoints, colors[BLACK]);

		DrawRoundRect(450, 500, 150, 30, colors[BLUE], 5);
		DrawString(470, 505, "Main Menu", colors[WHITE]);

	}
	else{
		glClearColor(0.7/*Red Component*/, 0.7,	//148.0/255/*Green Component*/,
				0.7/*Blue Component*/, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors

		

		for (int i = 10; i <= 1010; i += 50)
			DrawLine( i , 10 ,  i , 810 , 1 , colors[BLACK] );

		for (int i = 10; i <= 810; i += 40)
			DrawLine( 10 , i ,  1010 , i , 1 , colors[BLACK] );

		building1(aptr);
		building2(aptr);
		building3(aptr);
		building4(aptr);


		DrawString(100, 820, "score: " + strPoints, colors[BLACK]);
		DrawString(800, 820, "Time Left: " + strtime + " sec", colors[BLACK]);

		objects();

		passengerDisplay();

		dropOff();

		
		drawCar();

		switch(*dropsCount){
			case 6 ... 100: drawCar5(); carArr[(3*3)+2] = 1; 
			case 5:
			case 4: drawCar4(); carArr[(2*3)+2] = 1;
			case 3:
			case 2: drawCar2(); carArr[(0*3)+2] = 1;
			case 1:
			case 0: drawCar3();
		}
	}
	
		

	glutSwapBuffers(); // do not modify this line..

}
// next 4 functions are used to draw buildings and assign their coordinates to an array
void building1(int arr[]){

	const int sub2 = 4;

	static int randx = GetRandInRange(50, 200);
	static int randy =  GetRandInRange(100, 400);
	static int randh =  GetRandInRange(200, 400);

	DrawRectangle(randx, randy, 50, randh, colors[BLACK]);
	DrawRectangle(randx+49, randy+200, 200, 50, colors[BLACK]);

	arr[(0 * sub2)+0] = randx-40;
	arr[(0 * sub2)+1] = randy-40;
	arr[(0 * sub2)+2] = 50+40;
	arr[(0 * sub2)+3] = randh+40;

	arr[(1 * sub2)+0] = randx+49-40;
	arr[(1 * sub2)+1] = randy+200-40;
	arr[(1 * sub2)+2] = 200+40;
	arr[(1 * sub2)+3] = 50+40;

	
}

void building2(int arr[]){

	const int sub2 = 4;

	static int randx = GetRandInRange(400, 450);
	static int randy =  GetRandInRange(400, 500);
	static int randh =  GetRandInRange(200, 300);

	DrawRectangle(randx, randy, 150, randh, colors[BLACK]);

	arr[(2 * sub2)+0] = randx-40;
	arr[(2 * sub2)+1] = randy-40;
	arr[(2 * sub2)+2] = 150+40;
	arr[(2 * sub2)+3] = randh+40;


	
}

void building3(int arr[]){

	const int sub2 = 4;

	static int randx = GetRandInRange(300, 400);
	static int randy =  GetRandInRange(100, 200);
	static int randl =  GetRandInRange(300, 400);

	DrawRectangle(randx, randy, randl, 50, colors[BLACK]);

	arr[(3 * sub2)+0] = randx-40;
	arr[(3 * sub2)+1] = randy-40;
	arr[(3 * sub2)+2] = randl+40;
	arr[(3 * sub2)+3] = 50+40;


	
}
void building4(int arr[]){

	const int sub2 = 4;

	static int randx = GetRandInRange(700, 800);
	static int randy =  GetRandInRange(300, 400);
	static int randh =  GetRandInRange(300, 400);

	DrawRectangle(randx, randy, 50 , randh, colors[BLACK]);

	arr[(4 * sub2)+0] = randx-40;
	arr[(4 * sub2)+1] = randy-40;
	arr[(4 * sub2)+2] = 50+40;
	arr[(4 * sub2)+3] = randh+40;


	
}
// function to store the score. 
int * score(){
	static int points = 0;
	int *ptr = &points;
	return ptr;
}
// function to dedecut score accordingly if collsion is made to which object or passenger etc. 
void scoreDeduction(){

	int *ptrX = carX();
	int *ptrY = carY();

	int *arr = arrayAddress();
	int *passArr = passengerArrayAddress();
	int *carArr = carCoordinates();

	int *points = score();
	int *color = taxiColor();

	const int obsatacles_num = 10;
	const int sub2 = 4;	
	
	for (int i = 0; i < obsatacles_num; i++)
			for (int j = arr[(i*sub2)+0]-10; j < arr[i*sub2+0]+10 + arr[i*sub2+2]; j++)
				if (j == *ptrX)
					for (int k = arr[i*sub2+1]-10; k < arr[i*sub2+1]+10 + arr[i*sub2+3]; k++)
						if(k == *ptrY){
							switch(*color){
								case 1: *points -= 2; break;
								case 2: *points -= 4; break;
							}	
						}

	for (int i = 0; i < 5; i++)
		for (int j = passArr[(i*3)+0]-35; j < passArr[i*3+0] + 35; j++)
			if (j == *ptrX)
				for (int k = passArr[i*3+1]-35; k < passArr[i*3+1] + 35; k++)
					if(k == *ptrY && passArr[i*3+2] == 1){
							switch(*color){
								case 1: *points -= 5; break;
								case 2: *points -= 5; break;
							}	
						}
	
	for (int i = 0; i < 4; i++)
		if (*ptrX != carArr[(i*3)+0] && *ptrX != carArr[i*3+1])
			for (int j = carArr[(i*3)+0]-50; j < carArr[i*3+0] + 50; j++)
				if (j == *ptrX)
					for (int k = carArr[i*3+1]-50; k < carArr[i*3+1] + 50; k++)
						if(k == *ptrY && carArr[i*3+2] == 1){
							switch(*color){
								case 1: *points -= 3; break;
								case 2: *points -= 2; break;
							}	
						}
	
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {

	int *ptrX = carX();
	int *ptrY = carY();

	const int obsatacles_num = 10;
	const int sub2 = 4;
	int *arr = arrayAddress();
	int *passArr = passengerArrayAddress();

	int *color = taxiColor();

	int speed; 

	switch(*color){
		case 1: speed = 6; break;
		case 2: speed = 10; break;
	}

	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		*ptrX -= speed;
		/*for (int i = 5; i < 10; i ++)
			for (int j = 0; j < 4; j ++)
				cout << arr[(i*4)+j] << endl;*/
		
		if (collision(ptrX, ptrY)){
			scoreDeduction();
			*ptrX += speed*2;		
		}
		if (*ptrX < 10){
			*ptrX += speed*2;
		}

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		*ptrX += speed;

		if (collision(ptrX, ptrY)){
			scoreDeduction();
			*ptrX -= speed*2;	
		}
		if (*ptrX > 1030){
			*ptrX -= speed*2;
		}

	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		*ptrY += speed;

		if (collision(ptrX, ptrY)){
			scoreDeduction();
			*ptrY -= speed*2;
			
		}
		if (*ptrY < 10){
			*ptrY -= speed*2;
		}
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		*ptrY -= speed;

		if (collision(ptrX, ptrY)){
			scoreDeduction();
			*ptrY += speed*2;
			
		}
		if (*ptrY > 820){
			*ptrY += speed*2;
		}
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {

	int *ptrX = carX();
	int *ptrY = carY();

	int *passArr = passengerArrayAddress();
	int passengerCount = 0;

	bool * menu = menuStatus();
	bool * game = gameStatus();

	int *dropLoc = dropOff();
	int *dropsCount = drops();
	int *points = score();

	char *name = nameArr();

	static int count = 0;

	if (key == 13){
		count = 0;
	cout << count;}

	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if(key == 32){
		
		for (int i = 0; i < 5; i++)
			for (int j = passArr[(i*3)+0]-60; j < passArr[i*3+0] + 60; j++)
				if (j == *ptrX)
					for (int k = passArr[i*3+1]-60; k < passArr[i*3+1] + 60; k++)
						if(k == *ptrY  && passArr[i*3+2] == 1 && dropLoc[2] == 0){
							passArr[i*3+2] = 0;
							dropLoc[2] = 1;
						}

		for (int j = dropLoc[0]-30; j < dropLoc[0] + 30; j++)
			if (j == *ptrX)
				for (int k = dropLoc[1]-30; k < dropLoc[1] + 30; k++)
					if(k == *ptrY){
						dropLoc[3] = 0;
						dropLoc[2] = 0;

						for (int a = 0; a < 5; a++)
							passengerCount += passArr[((a*3)+2)];
						
						if (passengerCount <= 3)
							for (int a = 0; a < 5; a++)
								passArr[((a*3)+2)] = 1;

						*dropsCount += 1;
						*points += 10;
					}
	}
	if (((key >= 65 && key <= 90 ) || (key >= 97 && key <= 122 )) && (*menu) && count < 5 ){
		name[count] = static_cast<char>(key);
		count ++;
		}
	
	glutPostRedisplay();
}
// this function was used to store the time left.
int * time(){
	static int t = 180;
	int * ptr = &t;
	return ptr;
}
// this function is used for reducing the time in terms of seconds by using glutTimerfun which is based of frames per second. 
void timeDisplay(int m){
	int *t = time();

	bool *game = gameStatus();

	if (*game)
		*t -= 1;

	glutTimerFunc(1000, timeDisplay, 0);
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	int *dropsCount = drops();
	

	switch(*dropsCount){
		case 6 ... 100: moveCar4();
		case 5:
		case 4: moveCar3();
		case 3:
		case 2: moveCar2();
		case 1:
		case 0: moveCar(); 
	}
	
	
	
	

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
bool carClicked(int x, int y, int xI, int yI){

	bool clicked = false;

	for (int j = x; j < x+150; j++)
			if (j == xI)
				for (int k = y; k < y+80; k++)
					if(k == yI) 
						return true;
					
	return clicked;				
}
void MouseClicked(int button, int state, int x, int y) {

	int *color = taxiColor();
	int *t = time();
	int *points = score();

	bool *game = gameStatus();
	bool *menu = menuStatus();
	bool *tMenu = tMenuStatus();
	bool *LB = leaderboardStatus();

	int *ptrX = carX();
	int *ptrY = carY();


	char *name = nameArr();

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		if (state == GLUT_DOWN){
			if(carClicked(380, 370, x, y) && *menu){
				*menu = false;
				*tMenu = true;
			}
			
			else if(carClicked(300, 390, x, y) && *tMenu){
				*color = 1;
				*menu = true;
				*tMenu = false;
			} else if(carClicked(500, 390, x, y) && *tMenu){
				*color = 2;
				*menu = true;
				*tMenu = false;
			}
			for (int j = 380; j < 380+150; j++)
				if (j == x){
					for (int k = 480; k < 510; k++)
						if(k == y && *menu && *color!= 0) {
							*menu = false;
							*game = true;
							
						}
				}
			for (int j = 380; j < 380+150; j++)
				if (j == x){
					for (int k = 520; k < 550; k++)
						if(k == y && *menu) {
							*menu = false;
							*LB = true;
							fileInput();
						}
				}
			for (int j = 400; j < 400+150; j++)
				if (j == x){
					for (int k = 640; k < 670; k++)
						if(k == y && *LB) {
							*menu = true;
							*LB = false;
							
						}
				}
			for (int j = 450; j < 600; j++)
				if (j == x){
					for (int k = 310; k < 340; k++)
						if(k == y) {
							fileOutput();
							*menu = true;
							*game = false;
							*color = 0;
							*t = 180;
							*points = 0;
							for (int a = 0; a < 5; a++)
								name[a] = ' ';
							*ptrX = 50;
							*ptrY = 700;
									
						}
				}
		}

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;
			cout << GLUT_DOWN << " " <<  GLUT_UP <<  endl;

	}
	glutPostRedisplay();
// function for inputing data from a file. 
void fileInput(){
	int *scores = scoresRecord();
	string *names = nameRecords();

	int count = 0;
	int score;
	string name;
	ifstream fin("scores.txt");
	ifstream fin2("names.txt");

	if(!fin)
        cout << "File not found";
    else {
        while(!fin.eof()){
            fin >> score;
            scores[count] = score;
			count++;
        }
		count = 0;
    }
	if(!fin2)
        cout << "File not found";
    else {
        while(!fin.eof()){
            fin2 >> name;
            names[count] = score;
			count++;
        }
	count = 0;
    }

}
// function for outputinmg data to a file. 
void fileOutput(){
	int *scores = scoresRecord();
	string *names = nameRecords();

	int *points = score();
	char *name = nameArr();
	
	int replacingSub;

	
	/*for (int i = 0; i< 10; i++){
		if (*points > scores[i]){
			replacingSub = i; 
			break;
		}		
	}
	for (int i = 9; i >= replacingSub; i--){
		if (i = replacingSub){
			scores[i] = *points;
			names[i] = name;
		}
		else {
			scores[i] = scores[i-1];
			names[i] = names[i-1];	
		}
	} */

	ofstream fout ("scores.txt");
	ofstream fout2 ("names.txt");

    if(fout.is_open()){
        for (int i = 0; i < 10; i++)
			fout << scores[i] << endl;
        fout.close();
    } else {
        cout << "unable to open file!";
    }

	if(fout2.is_open()){
        for (int i = 0; i < 10; i++)
			fout2 << names[i] << endl;
        fout2.close();
    } else {
        cout << "unable to open file!";
    }
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	srand(time(NULL));
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Muhammad Riyan Aslam"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(100.0, Timer, 0);
	glutTimerFunc(1000.0, timeDisplay, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
