#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
//#include<windows.h>
//#include<mmsystem.h>

#include<unistd.h>

#define wxmin 0
#define wxmax 2000
#define wymin 0
#define wymax 1000
#define PI 3.14159265


double hinge1[3][2],hinge2[3][2],hinge3[4][2];

double spring1_wall[4][2];

int hinge1_flag=0,hinge2_flag=0,hinge3_flag=0;
double support[3][2],block[4][2],block1[4][2];
double ball[2][2] = {{100,820},{1120,600}};
double points[36][2],no_of_lines=15;
double X=0,Y=0;
int block_going_right = 1 , block_going_left = 1;

double up_arrow[4][7][2];


// Translation 
void translate(double *x,double *y,double tx,double ty){
	*x += tx;
	*y += ty;
}

//Rotation
void rotate(double *x,double *y,double ra){
	int i;
	double a,b,f = (double)(22*ra)/1260;
	
	a=*x;
	b=*y;
	*x =  a*cos(f) - b*sin(f) ;
	*y =  a*sin(f) + b*cos(f) ;
	
}

// Scaling
void scale(double *x,double *y,double tx,double ty){
	*x *= tx;
	*y *= ty;
}


// rotation + translation of hindge 1
void move_hinge1(double rotation_angle){
	int i;
	for(i=0;i<3;i++){
	 	translate(&hinge1[i][0],&hinge1[i][1],-994,-475);
	 	rotate(&hinge1[i][0],&hinge1[i][1],rotation_angle);
		translate(&hinge1[i][0],&hinge1[i][1],994,475);
	}
}

// rotation + translation of hindge 2
void move_hinge2(double rotation_angle){
	int i;
	for(i=0;i<3;i++){
		 	translate(&hinge2[i][0],&hinge2[i][1],-1130,-567);
		 	rotate(&hinge2[i][0],&hinge2[i][1],rotation_angle);
			translate(&hinge2[i][0],&hinge2[i][1],1130,567);
	}
}

// rotation + translation of hindge 3
void move_hinge3(double rotation_angle){
	int i;
	for(i=0;i<4;i++){
	 	translate(&hinge3[i][0],&hinge3[i][1],-1275,-485);
	 	rotate(&hinge3[i][0],&hinge3[i][1],rotation_angle);
		translate(&hinge3[i][0],&hinge3[i][1],1275,485);
	}
}


// ball movement on line
void move_on_line(int p , int q , int x_increment ,int ball_number){
	double diffx = points[q][0] - points[p][0];
	double diffy = points[q][1] - points[p][1];
	double slope = (double)( diffy )/diffx;
	
	ball[ball_number][0] += x_increment;
	ball[ball_number][1] += x_increment*slope;
}


// TO draw hindge1
void hinge1_func(){
	
	int i;
		
	glBegin(GL_POLYGON);   
	for(i=0;i<3;i++){
		glColor3f(.09*(rand()%10),.09*(rand()%10),.09*(rand()%10));
		glVertex2d(X+hinge1[i][0],Y+hinge1[i][1]);
	}
		
	glEnd();

	
	int radius = 10;
	int j,r2 = radius*radius;
	glBegin(GL_POINTS);
	glColor3f (1,.7,0);
	for(i=-radius;i<radius;i++){
		for(j=-radius;j<radius;j++){
			if(i*i + j*j <= r2)
				glVertex2d(X+994+i,Y+475+j);
		}
	}
	glEnd();
	glColor3f (0,.7,0); 
	
}

// TO draw hindge2
void hinge2_func(){


	int i;
	
	glBegin(GL_POLYGON); 
	for(i=0;i<3;i++)
		glVertex2d(X+hinge2[i][0],Y+hinge2[i][1]);
	glEnd();
	
	int radius = 8;
	int j,r2 = radius*radius;
	glBegin(GL_POINTS);
	glColor3f (1,.7,0);
	for(i=-radius;i<radius;i++){
		for(j=-radius;j<radius;j++){
			if(i*i + j*j <= r2)
				glVertex2d(X+1130+i,Y+567+j);
		}
	}
	 glEnd();
	 glColor3f (0,.7,0); 
	
}

// TO draw hindge3
void hinge3_func(){


	int i;
	
	glBegin(GL_POLYGON); 
	for(i=0;i<4;i++)
		glColor3f(.1 +.09*(rand()%10),.1+ .09*(rand()%10),.1+ .09*(rand()%10)),glVertex2d(X+hinge3[i][0],Y+hinge3[i][1]);
	glEnd();
	
	int radius = 8;
	int j,r2 = radius*radius;
	glBegin(GL_POINTS);
	glColor3f (1,.7,0);
	for(i=-radius;i<radius;i++){
		for(j=-radius;j<radius;j++){
			if(i*i + j*j <= r2)
				glVertex2d(X+1275+i,Y+485+j);
		}
	}
	 glEnd();
	 glColor3f (0,.7,0); 
	
}

