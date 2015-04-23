/*

AUTHOR : PEEYUSH YADAV
PROBLEM : Simple Animation

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<math.h>
#include<unistd.h>
#define PI 3.1415926f

double face[][2]={{10,0}};

double body[][2]={{10,0},{10,-6},{8,-8},  {10,-3} , {8,-4}   };
double body1[][2]={{10,-6},{8,-8},{8,-10},  {8,-4} , {7,-2}  };

double camera[][2]={15,40};
double rod[][2]={  {44,48} ,{44,48}   };

char ch[100]="KEYS : L,R (Movement)";
char ch2[100]="KEYS : A,Z (Gesture)";
char ch1[100]="KEYS : D (Dance)"; 
double temp[8][2],temp1[8][8][2];



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


void effect_init(){
	
	temp[0][0]= 00;
	temp[1][0]= 20;
	temp[2][0]= 70;
	temp[3][0]= 70;
	temp[4][0]=	50;
	temp[5][0]= 50;
	temp[6][0]= 00;
	
	temp[0][1]= 50;
	temp[1][1]= 50;
	temp[2][1]= 20;
	temp[3][1]= 10;
	temp[4][1]=	10;
	temp[5][1]= 20;
	temp[6][1]= 30;
	
}

void effect( ){
	
	
	int magic =(int) (temp[0][0] + temp[1][0]);
	magic>>=1;

	
	glColor3f(1,.17,.17);
	for(int j=0;j<70;j++){	
	
		glLineWidth(2);
		glBegin(GL_LINE_LOOP);
		
			for( int i = 0 ; i < 6 ; i++ ){
				
				glVertex2d( temp[i][0] + 78, temp[i][1] + 39 );
				temp[i][0]-= magic;
				rotate(&temp[i][0],&temp[i][1],1);
				temp[i][0]+= magic;
				
			}
			
		glEnd();
	}
	
}

void circle(float center_x, float center_y, float r) { 
    
	int i; 
    float theta,x,y;       
	glBegin(GL_POLYGON); 
		for( i = 0; i < 1000; i++) { 
			theta = 2.0f *PI*(float)i/(float)1000;
			x = r*cosf(theta);
		        y = r*sinf(theta); 
			glVertex2f(x + center_x, y + center_y); 
		} 
	glEnd(); 
	
}


 void translate(int i){
 	
	 int val = 2;
 	if(i== -1) val = -2;
 	face[0][0] += val;
 	for(int x = 0 ;x<5;x++){
 		
 		body[x][0]+=val;
 		body1[x][0]+=val;
 		
 	}
 	
 }
 
 void translatefull(int i){
 	
	 	int val = 3;
	 	if(i== 0) val = -3;
	 	face[0][1] += val;
	 	for(int x = 0 ;x<5;x++){
	 		body[x][1]+=val;
	 		body1[x][1]+=val;
	 	}
	 	
 }
 
 void trans(int i,double val = .2 ){
 	
 	double val1 = .1;
 	if(!i) {
 		val = -.2;
 		val1 = -.1;
 	}
 	body1[4][0]+=val;
 	body1[2][0]+=val1;
 	
 }
 
 
 
void display(){
	
	glClearColor (0, .2, .1, .1);    
	glClearColor (.7, .1, .1, 0);    
	glClear (GL_COLOR_BUFFER_BIT);
	
	glLoadIdentity ();
	glOrtho(-20,50,-12,50,-1,1);
	//glOrtho(-30,60,-30,60,-30,60);
	//glColor3f(0,.4,0);
    effect();
	   
	glColor3f(1,1,.1);
	glBegin(GL_LINES);
	
		glVertex3f(-20,-10,0);
		glVertex3f(50,-10,0);	
			
	glEnd();
	
	glColor3f(1,1,1);
	
    int leng=strlen(ch),i;
    glRasterPos2f(-18,42);
    for(i=0;i<leng;i++)
   		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int)ch[i]);
   	
   	leng=strlen(ch1),i;
    glRasterPos2f(-18,38);
    for(i=0;i<leng;i++)
   		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int)ch1[i]);
   		
   	leng=strlen(ch2),i;
    glRasterPos2f(-18,40);
    for(i=0;i<leng;i++)
   		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,(int)ch2[i]);
   	
	
	
	glLineWidth(3);
	
	
	glColor3f(.1,.3,1);
	glBegin(GL_POLYGON);
				
			glVertex3f(rod[0][0],rod[0][1],0);
	   	    glVertex3f(camera[0][0] - 1.6,camera[0][1]+1,0);
	   	    
	   	    glVertex3f(camera[0][0] - 1.6,camera[0][1]+1,0);
			glVertex3f(camera[0][0] + 1.1,camera[0][1]-1,0);
	   	    
	   	    glVertex3f(camera[0][0] + 1.1,camera[0][1]-1,0);
	   	    glVertex3f(rod[1][0],rod[1][1],0);		
     	
	glEnd();
	
	
	glBegin(GL_POLYGON);
				
			glVertex3f(-14,rod[0][1],0);
	   	    glVertex3f(camera[0][0] - 1.2,camera[0][1]-1,0);
	   	    
	   	    glVertex3f(camera[0][0] - 1.2,camera[0][1]-1,0);
			glVertex3f(camera[0][0] + 1.1,camera[0][1]+1,0);
	   	    
	   	    glVertex3f(camera[0][0] + 1.1,camera[0][1]+1,0);
	   	    glVertex3f(-14,rod[1][1],0);		
     	
	glEnd();
	
	
	//glColor3f(0,.7,.7);
	glColor3f(0,.68,0);
	glBegin(GL_POLYGON);
			
			glVertex3f(camera[0][0] - .2,camera[0][1]-1.5,0);
	     	glVertex3f(body[0][0]-8,-10,0);  
			 
			glVertex3f(body[0][0]-8,-10,0);
			glVertex3f(body[0][0]+8,-10,0);
			 
			glVertex3f(body[0][0]+8,-10,0);
			glVertex3f(camera[0][0] + .2,camera[0][1]-1.5,0);
	     	     	
	glEnd();
	
	glColor3f(1,1,.3);
	circle(camera[0][0],camera[0][1],1.8);
	
	glLineWidth(4);
	glColor3f(.78,0,0);
	glColor3f(1,1,.1);
	circle(face[0][0],face[0][1],1.5);
	
	glBegin(GL_LINES);
	
		for(int i=0;i<5;i++){
		
			glVertex3f(body[i][0],body[i][1],0);
			glVertex3f(body1[i][0],body1[i][1],0);
			
			glVertex3f(2*body[0][0] - body[i][0],body[i][1],0);
			glVertex3f(2*body[0][0] - body1[i][0],body1[i][1],0);	
     	}
	
	glEnd();
	
	glutPostRedisplay();
	glFlush();
	
}


void dance(){
	
	int x=0;
 	for(int i= 0 ;i<20;i++){
 		
 		for(long long s = 0;s<9000000;s++);
 		
 		x= !x;
 		
 		translatefull(x);
 		
 		for(int j=0; j<25;j++){
 			
 			trans(1);
 			display();
 			
 		}
 		
 		for(int j=0; j<25;j++){
 			
 			trans(0);
 			display();
 			
 		}
 		
 	}
 	
 }

void keyPressed(unsigned char Key, int x, int y){
	
	if(Key == 'r'){
		
		translate(1);
		display();
		
	}
	else if(Key == 'l'){
		
		translate(-1);
		display();
		
	}
	else if(Key == 'a'){
		trans(1);
		display();
	}
	else if(Key == 'z'){
		
		trans(0);
		display();
		
	}
	else if(Key =='d'){
		
		dance();
		display();
		
	}
	else if(Key==27){
		
		exit(0);

	}
	
}


int main(int argc, char** argv){
	
	effect_init();
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1000, 700);
	glutInitWindowPosition (100, 10);
	glutCreateWindow (argv[0]);
	glutKeyboardFunc(keyPressed);
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
	
}
