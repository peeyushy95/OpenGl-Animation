#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<bits/stdc++.h>
//#include<windows.h>
//#include<mmsystem.h>

#include "header.cpp"
#include "draw.cpp"
bool fg = 0;
bool flag  = 0,flag1=0;

// to initialize the coordinates of basic structure
void initialize(){

	hinge1[0][0] = 980;	hinge1[0][1] = 450;
	hinge1[1][0] = 895;	hinge1[1][1] = 630;
	hinge1[2][0] = 1020;hinge1[2][1] = 470;
	
	hinge2[0][0] = 1090;	hinge2[0][1] = 550;
	hinge2[1][0] = 1090;	hinge2[1][1] = 580;
	hinge2[2][0] = 1300;	hinge2[2][1] = 580;
	
	block[0][0] = 1260;	block[0][1] = 580;
	block[1][0] = 1260;	block[1][1] = 620;
	block[2][0] = 1300;	block[2][1] = 620;
	block[3][0] = 1300;	block[3][1] = 580;
	
	
	hinge3[0][0] = 1260;	hinge3[0][1] = 460;
	hinge3[1][0] = 1260;	hinge3[1][1] = 572;
	hinge3[2][0] = 1290;	hinge3[2][1] = 572;
	hinge3[3][0] = 1290;	hinge3[3][1] = 460;
	
	points[0][0] = 0;			points[0][1] = 800;
	points[1][0] = points[0][0]+200;	points[1][1] = points[0][1];
	
	points[2][0] = points[1][0];		points[2][1] = points[1][1];
	points[3][0] = points[2][0]+200;	points[3][1] = points[2][1]-400;
	
	points[4][0] = points[3][0];		points[4][1] = points[3][1];
	points[5][0] = points[4][0]+100;	points[5][1] = points[4][1];
	
	points[6][0] = points[5][0];		points[6][1] = points[5][1];
	points[7][0] = points[6][0]+200;	points[7][1] = points[6][1]+200;
	
	points[8][0] = points[7][0];		points[8][1] = points[7][1];
	points[9][0] = points[8][0]+205;	points[9][1] = points[8][1];
	
	// spring line
	points[10][0] = points[9][0]+500;	points[10][1] = points[9][1]-80;
	points[11][0] = points[10][0]+300;	points[11][1] = points[10][1];
	
	//Ball wali Line
	points[12][0] = points[11][0]-330;	points[12][1] = points[11][1]-120;
	points[13][0] = points[12][0]+300;	points[13][1] = points[12][1]-150;
	
	//goose bumps wali line
	points[14][0] = points[13][0];		points[14][1] = points[13][1];
	points[15][0] = points[14][0]+927;	points[15][1] = points[14][1];
	
	//wind blowers line
	points[16][0] = 4150;				points[16][1] = 270;
	points[17][0] = points[16][0]-250;	points[17][1] = points[16][1]-210;
	
    points[18][0] = points[17][0]-100;	points[18][1] = points[17][1];	
	points[19][0] = points[18][0]+250;	points[19][1] = points[18][1]-210;
	
	points[20][0] = points[19][0]+100;	points[20][1] = points[19][1];	
	points[21][0] = points[20][0]-250;	points[21][1] = points[20][1]-210;	
	
	points[22][0] = points[21][0]-100;	points[22][1] = points[21][1];	
	points[23][0] = points[22][0]+250;	points[23][1] = points[22][1]-210;
	
	// zig zag path
	points[24][0] = points[23][0];		points[24][1] = points[23][1];	
	points[25][0] = points[23][0];	    points[25][1] = points[23][1];
	
	points[26][0] = points[23][0];		points[26][1] = points[23][1];	
	points[27][0] = points[24][0]+1000;	points[27][1] = points[26][1];
	
	points[28][0] = points[27][0];	points[28][1] = points[27][1];	
	points[29][0] = points[28][0];	points[29][1] = points[28][1] + 500;
	
	points[30][0] = points[28][0];  points[30][1] = points[28][1];
	points[31][0] = points[28][0];  points[31][1] = points[28][1];
	
	block1[0][0] = points[25][0]-25;	block1[0][1] = points[25][1]+5;
	block1[1][0] = points[25][0]-25;	block1[1][1] = points[25][1]+45;
	block1[2][0] = points[25][0]+15;	block1[2][1] = points[25][1]+45;
	block1[3][0] = points[25][0]+15;	block1[3][1] = points[25][1]+5;

	
	
	// block hitting wall
	
	spring1_wall[0][0] = points[11][0] - 20 ;	spring1_wall[0][1] = points[11][1];
	spring1_wall[1][0] = points[11][0] ;		spring1_wall[1][1] = points[11][1];
	spring1_wall[2][0] = points[11][0] ;		spring1_wall[2][1] = points[11][1] + 70;
	spring1_wall[3][0] = points[11][0] - 20 ;	spring1_wall[3][1] = points[11][1] + 70;
	
	// up_arrow
	init_arrow1();
	init_arrow2();
	init_T();
	init_Bridge();
	init_horizontal_arrow();
	
	    
}

// to draw the structure

void structure(){
	int i,j;
	   
	for(i=0,j=0;j<no_of_lines;i+=2,j++){
		if(i>15 && i<24) {
			//glLineWidth(15);
			glPointSize(6);
			glColor3f(1,0,0);
		}
		else if(i==24) 	glLineWidth(5);
		else			glLineWidth(3),glColor3f(0,.7,0);
	
		lineAlgo(X+points[i][0], Y+points[i][1], X+points[i+1][0], Y+points[i+1][1]);
	}
	glPointSize(3);
	//glLineWidth(3);
	glColor3f(0,.7,0);
	
	
	// fix block
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);   
	glVertex2d(X+1120,Y+550);
	glVertex2d(X+1120,Y+450);
	glVertex2d(X+1140,Y+450);
	glVertex2d(X+1140,Y+550);
	glEnd();
	glColor3f (0,.7,0);
}

// code to control the movement of balls and hinges
bool flagg = 0;
void draw(void){
	//glClearColor( 0,1,1,0);
	glClearColor(.2,.2,.2,0);
	//glClearColor(1,1,0,1);
	glClear(GL_COLOR_BUFFER_BIT);
		

	glLoadIdentity();
	gluOrtho2D(wxmin,wxmax,wymin,wymax);
	glLineWidth(3);
	
	int i,j;
	static int p=0,q=1;
	
	
	double diffx,diffy,slope;
	bool ff1=0;
	// first ball
	if(!flagg){	
	if( ball[0][0] <= 875){
	
		move_on_line(p,q,5,0);
	
		if( ball[0][0] >= points[q][0] ){
			p+=2;
			q+=2;
		}
	}
	
	else if( hinge1[1][0]<1108.2)	{	// hinge1
		if(!flag)	{
			//PlaySound("hingehit.wav", NULL, SND_ASYNC|SND_FILENAME);
			flag =1;
		}
		hinge1_flag=1;
		
	}
	
	// ball hitting block
	else if( ball[1][0] <= 1240){
		hinge1_flag = 0;
		//PlaySound("hingehit.wav", NULL, SND_ASYNC|SND_FILENAME);	
		// second ball
		diffx = hinge2[2][0] - hinge2[1][0];
		diffy = hinge2[2][1] - hinge2[1][1];
		slope = (double)( diffy )/diffx;
		
		ball[1][0] += 5;
		ball[1][1] += 5*slope;	
	}
	
	// block movement towards right
	else if( block[3][0] <= spring1_wall[0][0] && block_going_right == 1){
		
		if( block[0][0] <= points[10][0] + 100 && block[0][1] >= points[10][1] ){
			diffx = points[10][0] + 100 - hinge2[2][0];
			diffy = points[10][1] - hinge2[2][1];
			slope = (double)( diffy )/diffx;
		}
		else if( block[3][0] <= spring1_wall[0][0] ){
			diffx = points[11][0] - points[10][0];
			diffy = points[11][1] - points[10][1];
			slope = (double)( diffy )/diffx;
		}
		if( block[3][0] >= spring1_wall[0][0] ){
			//PlaySound("hingehit.wav", NULL, SND_ASYNC|SND_FILENAME);
			block_going_right = 0;
		}
		block[0][0] += 5;	block[0][1] += 5*slope;
		block[1][0] += 5;	block[1][1] += 5*slope;
		block[2][0] += 5;	block[2][1] += 5*slope;
		block[3][0] += 5;	block[3][1] += 5*slope;
		
	}
	
	// block movement towards left
	else if( block[0][0] > hinge3[3][0] && block_going_right == 0 ){
		block[0][0] -= 5;
		block[1][0] -= 5;
		block[2][0] -= 5;
		block[3][0] -= 5;
		
	}
	
	// rotation of hinge2 and hinge3
	else if( hinge3[1][1] > hinge3[0][1] ){
		hinge3_flag = 1;
		hinge2_flag = 1;
		if(!flag1){
			//PlaySound("hingehit.wav", NULL, SND_ASYNC|SND_FILENAME);
			flag1=1;
		}
		slope = 2;
		block[0][0] += 1;	block[0][1] -= 5*slope;
		block[1][0] += 1;	block[1][1] -= 5*slope;
		block[2][0] += 1;	block[2][1] -= 5*slope;
		block[3][0] += 1;	block[3][1] -= 5*slope;
		
		if( ball[1][0] < hinge2[2][0] ){
			diffx = hinge2[2][0] - hinge2[1][0];
			diffy = hinge2[2][1] - hinge2[1][1];
			slope = (double)( diffy )/diffx;
		
			ball[1][0] += 5;
			ball[1][1] += 5*slope;
		}
		else{
			slope = -2;
		
			ball[1][0] += 5;
			ball[1][1] += 5*slope;
		}
	}
	
	// ball moving on wind blowers slant line
	else if( ball[1][0]  < points[13][0] ){
		hinge3_flag = 0;
		hinge2_flag = 0;
		
		slope = -2;
		block[0][0] += 1;	block[0][1] += 5*slope;
		block[1][0] += 1;	block[1][1] += 5*slope;
		block[2][0] += 1;	block[2][1] += 5*slope;
		block[3][0] += 1;	block[3][1] += 5*slope;
		
		if( ball[1][1] - 20 > points[12][1] ){
			slope = -2;
		}
		else{
			diffx = points[13][0] - points[12][0];
			diffy = points[13][1] - points[12][1];
			slope = (double)( diffy )/diffx;
		}
		ball[1][0] += 5;
		ball[1][1] += 5*slope;
	}
	
	// ball moving on wind blowers line
	else if( ball[1][0]  < points[14][0] + 270 ){
		
		move_on_line(14,15,5,1);
		//PlaySound("breeze.wav", NULL, SND_ASYNC|SND_FILENAME);
	}
	
	// ball movement due to boiler1
	else if( ball[1][0]  < points[14][0] + 330 ){
		ball[1][0] += 1;
		ball[1][1] += 4;
	}
	
	// ball movenment between boiler1 and boiler2
	else if( ball[1][0]  < points[14][0] + 470 ){
		ball[1][0] += 2;
		ball[1][1] -= 1;
	}
	
	// ball movement due to boiler2
	else if( ball[1][0]  < points[14][0] + 530 ){
		ball[1][0] += 1;
		if(ball[1][1] < points[14][1] + 400)
			ball[1][1] += 4;
	}
	
	// ball movenment between boiler2 and boiler3
	else if( ball[1][0]  < points[14][0] + 670 ){
		ball[1][0] += 2;
		ball[1][1] -= 1;
	}
	
	// ball movement due to boiler3
	else if( ball[1][0]  < points[14][0] + 730 ){
		ball[1][0] += 1;
		if(ball[1][1] < points[14][1] + 600)
			ball[1][1] += 4;
	}
	
	// ball movement after boiler3
	else if( ball[1][0]  < points[15][0] ){
		ball[1][0] += 1;
	}
	
	else if(ball[1][0] == points[15][0]){
		if(ball[1][1]>280)	ball[1][1] -= 10;
		else ball[1][0]+=1;
	}
	else if(ball[1][0]<=4000 && ball[1][1]>=200){
		ball[1][0]+=3;
		//printf("%f\n",ball[1][0]);
	}
	else if(ball[1][0]<4050 && ball[1][1]>=224.4){
		ball[1][0]+=3;
		ball[1][1]-=2;
		Y+=2;
		p=16;
		q=17;
	}
	
	// ball movement on zig zag path
	else if( ball[1][1] -20 > points[23][1] ){
		if( ball[1][1] >= points[q][1]-9){
			if(p%4==0) 	move_on_line(p,q,-3,1);
			else 		move_on_line(p,q,3,1);
		}
		else{
			
			p+=2;
			q+=2;
			
		}
		Y+=2;
	
	}
	
	else if (ball[1][0] <= points[28][0] - 45 ){
	
		ball[1][0]+=2;
		Y+=.8;
		X-=2;
		fg= 1;
		usleep(10*1000);
	}
	else flagg = 1;

	}
	// end part
	else {
	//	usleep(100*1000);
		
		if(rr<730){
		
		translate(&points[30][0],&points[30][1],-1,.1);
		translate(&points[31][0],&points[31][1],+.02,.1);
		//printf("%f %f\n",points[30][0],points[30][1]);
		rr+=.6;
	}
	}
	
	glColor3f (1,0,0);
	balldraw(ball[0][0],ball[0][1]);
	glColor3f (1,1,0);
	balldraw(ball[1][0],ball[1][1]);
	glColor3f (.5,.5,.5);
	blockdraw();
	glColor3f (0,.7,0);
	draw_Spring1_wall();
	
	

	glColor3f(0,.7,0);
	
	draw_arrow();
	draw_T();
	if(ball[1][0]<3550)draw_Bridge();
	//else PlaySound(NULL, 0, 0);	
	structure();
	hinge1_func();
	hinge2_func();
	hinge3_func();
	if(fg){
		glColor3f(.4,.7,.66);
		//glColor3f (.2,.31,.5);
		balldraw3(points[30][0]-40,points[30][1]+32);
		glColor3f(0.5,.4,.6);
		balldraw5(points[31][0]-40,points[31][1]+32);
   }
	if(hinge1_flag ){
		move_hinge1(-5);
	}
	
	if(hinge2_flag){
		move_hinge2(-1.5);
	}
	
	if(hinge3_flag){
		move_hinge3(5);
	}
	if(hinge1[1][0] > 900 && X>-2500)
		X-=2;
	glFlush();
	int xx=0;
	if(!fg)usleep(15*1000);
	glutPostRedisplay();	
}



int var = 0;
// start window
void start_window(){
	glClearColor(0.5, 0, 0, 0.0);
	//glClearColor(0.1, 0.1, 0.1, 0.0);
    	glClear(GL_COLOR_BUFFER_BIT);
    	glLoadIdentity();
    	gluOrtho2D(wxmin,wxmax,wymin,wymax);

	//char str1[500]="EnTeR ChOiCe\n1.SiNgLe PlAyEr \n2.MuLtIplAyEr\n3.PrEsS EsC To ExIt\n";
	char str1[500]="PING PONG BALL";

	glColor3f(1,1,1);
	glRasterPos2f(800.0, 800.0);
	int lo,len = strlen(str1);
	for(lo=0;lo<len;lo++)
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, str1[lo] );
//	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, str1 );
	
	glColor3f(0.5,0.5,0);
	int xxx = 800; int yyy = 690;
	/*glBegin(GL_POLYGON); 
		glVertex2d( xxx , yyy );
		glVertex2d( xxx + 325 , yyy );
		glVertex2d( xxx + 325 , yyy - 60 );
		glVertex2d( xxx , yyy - 60 );
	glEnd();*/
	
	glBegin(GL_POLYGON); 
		glVertex2d( xxx , yyy );
		glVertex2d( xxx + 325 , yyy );
		
		glVertex2d( xxx + 325 , yyy );
		glVertex2d( xxx + 325 , yyy - 60 );
		
		glVertex2d( xxx + 325 , yyy - 60 );
		glVertex2d( xxx , yyy - 60 );
		
		glVertex2d( xxx , yyy - 60 );
		glVertex2d( xxx , yyy );
	glEnd();
		
	glColor3f(0,1,1);
	strcpy(str1,"START ANIMATION");
	glRasterPos2f(820.0, 650.0);
	len = strlen(str1);
	for(lo=0;lo<len;lo++)
		glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, str1[lo] );
	
	strcpy(str1,"PRESS SPACE");
	glRasterPos2f(870.0, 570.0);
	len = strlen(str1);
	for(lo=0;lo<len;lo++)
			glutBitmapCharacter( GLUT_BITMAP_9_BY_15, str1[lo] );
	
	glColor3f(0,1,0);
	strcpy(str1,"DEVELOPERS :");
	glRasterPos2f(1450.0, 260.0);
	len = strlen(str1);
	for(lo=0;lo<len;lo++)
	glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, str1[lo]);
	
	glColor3f(1,1,0.5);
	
	strcpy(str1,"1. HIMANSHU");
	glRasterPos2f(1550.0, 220.0);
	len = strlen(str1);
	for(lo=0;lo<len;lo++)
	glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, str1[lo]);
	
	strcpy(str1,"2. ANKIT BISLA");
	glRasterPos2f(1550.0, 180.0);
	len = strlen(str1);
	for(lo=0;lo<len;lo++)
	glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, str1[lo]);
	
	strcpy(str1,"3. PEEYUSH YADAV");
	glRasterPos2f(1550.0, 140.0);
	len = strlen(str1);
	for(lo=0;lo<len;lo++)
	glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, str1[lo]);


	glFlush();
}




// this is first function which is called by main
void first_function(){
	if( !var )	start_window();
	else		draw();
}

// keyboard function to start the animation
void key_input(GLubyte key, GLint x, GLint y){
	switch(key)
	{
		case ' ':
				var = 1;
				draw();
				break;
		case 27:
				exit(0);
		
	}
}


int main(int argc,char **argv){

 	initialize();
	glutInit(&argc,argv);
	glutInitWindowSize(1200,600);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Ping Pong Ball");
    glutDisplayFunc(first_function);
	glutKeyboardFunc(key_input);
  	glutMainLoop();
}
