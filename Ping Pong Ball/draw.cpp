#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<unistd.h>
//#include<windows.h>
//#include<mmsystem.h>
double temp[8][2],temp1[8][8][2];

void swap(double* a,double* b)
{
	int t=*a;
	*a=*b;
	*b=t;
}


// Mid Point ALgorithm 
void lineAlgo(double x1, double y2, double x2, double y3)
{
	double slopegt1=0;
	double dx,dy,d,incry,incre,incrne;
	dx=abs(x1-x2);
	dy=abs(y2-y3);
	double x,y;


	
	if(dy>dx)
	{
		swap(&x1,&y2);
		swap(&x2,&y3);
		swap(&dx,&dy);
		slopegt1=1;
	}//printf("\n\n  %d\n\n",slopegt1);
	if(x1>x2)
	{
		swap(&x1,&x2);
		swap(&y2,&y3);
	}
	if(y2>y3)
		incry=-1;
	else
		incry=1;
	d=2*dy-dx;
	incre=2*dy;
	incrne=2*(dy-dx);
	x=x1;
	y=y2;
	glBegin(GL_POINTS);
	while(x<x2)
	{
		if(d<=0)
			d+=incre;
		else
		{
			d+=incrne;
			y+=incry;
		}
		x++;
		if(slopegt1)
			glVertex2f(y,x);
		else
			glVertex2f(x,y);
	}
	glEnd();
	//glFlush();
}



// ball moving up
void balldraw1(double x,double y){
	int i;
	int radius = 20;
	int j,r2 = radius*radius;
	glBegin(GL_POINTS);
	 
	for(i=-radius;i<radius;i++){
		//if(x<500) glColor3f (.2+ fmod((float)rand()/(float)(RAND_MAX),.8),0,0);
		glColor3f (.5 + fmod((float)rand()/(float)(RAND_MAX),1.0),.5 + fmod((float)rand()/(float)(RAND_MAX),1.0),0);
		for(j=-radius;j<radius;j++){
			
			if(i*i + j*j <= r2){				
				glVertex2d(X+x+i,Y+y+j);
			}
				
		}
	}
	glEnd();
}
// ball moving horizontally
void balldraw(double center_x, double center_y) { 
        if(center_x>1960 && center_x<=2605) {
        	balldraw1(center_x,center_y);
        	return;
        }
        int i,j; 
        int r = 20;
        float theta,x,y;       
	glBegin(GL_POLYGON); 
	for(j=0;j<=r;j++){
	for( i = 0; i < 100; i++) { 
	    if(j>18 && i>50 && i<88)glColor3f (fmod((float)rand()/(float)(RAND_MAX),1.0),fmod((float)rand()/(float)(RAND_MAX),1.0),fmod((float)rand()/(float)(RAND_MAX),1.0));
	    else if(center_x>1000) glColor3f (1,1,0); 
		else glColor3f (1,0,0); 
		theta = 2.0f *PI*(float)i/(float)100;
		x = j*cosf(theta);
	    y = j*sinf(theta); 
		glVertex2f(X+x + center_x,Y+ y + center_y); 
	} 
    }
	glEnd(); 
}

//simple ball draw
void balldraw4(double center_x, double center_y,double r) { 
        
        int i,j; 
        float theta,x,y;       
	glBegin(GL_POLYGON); 
	
	for(j=0;j<=r;j++){
	for( i = 0; i < 100; i++) { 
		theta = 2.0f *PI*(float)i/(float)100;
		x = j*cosf(theta);
	    y = j*sinf(theta); 
		glVertex2f(X+x + center_x,Y+ y + center_y); 
	} 
    }
	glEnd(); 
}


double rr = 30;
//Smiley creation
void balldraw3(double center_x, double center_y) { 
    // printf("%f %f\n",X + center_x,center_y +Y); 
     
    int i; 
    //int r = 30;
    float theta,x,y;       
	glBegin(GL_POLYGON); 
	for( i = 0; i < 1000; i++) { 
	    
		theta = 2.0f *PI*(float)i/(float)1000;
		x = rr*cosf(theta);
	    y = rr*sinf(theta); 
		glVertex2f(X+x + center_x,Y+ y + center_y); 
	} 
	glEnd(); 
	//glColor3f (1,.4,0);
	glColor3f (.2,.31,.5);
	
	 glLineWidth(.1*rr);
	 	glPointSize(3);
		lineAlgo(X + center_x-.7*rr,center_y +Y + .5*rr, 	X + center_x -.2*rr,center_y +Y + .5*rr);
		
		lineAlgo(X + center_x +.7*rr,center_y +Y + .5*rr, 	X + center_x + .2*rr,center_y +Y + .5*rr);
		
		lineAlgo(X + center_x ,center_y +Y + .2*rr,			X + center_x ,center_y +Y - .2*rr);
		
		lineAlgo(X + center_x -.3*rr ,center_y +Y - .5*rr,	X + center_x + .2*rr,center_y +Y - .5*rr);
		
		lineAlgo(X + center_x +.2*rr ,center_y +Y - .5*rr,	X + center_x + .36*rr,center_y +Y - .4*rr);
		
	
		balldraw4(center_x+.4*rr,center_y + .35*rr, .16*rr);
		balldraw4(center_x-.4*rr,center_y + .35*rr, .16*rr);
}

void balldraw5(double center_x, double center_y) { 
    // printf("%f %f\n",X + center_x,center_y +Y); 
     
    int i; 
    //int r = 30;
    float theta,x,y;       
	glBegin(GL_POLYGON); 
	for( i = 0; i < 1000; i++) { 
	    
		theta = 2.0f *PI*(float)i/(float)1000;
		x = rr*cosf(theta);
	    y = rr*sinf(theta); 
		glVertex2f(X+x + center_x,Y+ y + center_y); 
	} 
	glEnd(); 
	glColor3f (.2,.1,.1);
	
	
	 glLineWidth(.1*rr);
		glBegin(GL_LINES);
			glVertex2d(X + center_x-.7*rr,center_y +Y + .5*rr);
			glVertex2d(X + center_x -.2*rr,center_y +Y + .5*rr);
		glEnd();
		glBegin(GL_LINES);
			glVertex2d(X + center_x +.7*rr,center_y +Y + .5*rr);
			glVertex2d(X + center_x + .2*rr,center_y +Y + .5*rr);
		glEnd();
		glBegin(GL_LINES);
			glVertex2d(X + center_x ,center_y +Y + .2*rr);
			glVertex2d(X + center_x ,center_y +Y - .2*rr);
		glEnd();
		
		glBegin(GL_LINES);
			glVertex2d(X + center_x -.3*rr ,center_y +Y - .5*rr);
			glVertex2d(X + center_x + .2*rr,center_y +Y - .5*rr);
		glEnd();
		glBegin(GL_LINES);
			glVertex2d(X + center_x +.2*rr ,center_y +Y - .5*rr);
			glVertex2d(X + center_x + .36*rr,center_y +Y - .4*rr);
		glEnd();
		
		balldraw4(center_x+.4*rr,center_y + .35*rr, .16*rr);
		balldraw4(center_x-.4*rr,center_y + .35*rr, .16*rr);
}

// drawing  block
void blockdraw(){
	glBegin(GL_POLYGON);
	     glColor3f (1,0,0); 
		glVertex2d(X+block[0][0],Y+block[0][1]);
		 glColor3f (0,1,0); 
		glVertex2d(X+block[1][0],Y+block[1][1]);
		 glColor3f (0,0,1); 
		glVertex2d(X+block[2][0],Y+block[2][1]);
		 glColor3f (1,0,0); 
		glVertex2d(X+block[3][0],Y+block[3][1]);
	glEnd();
	
	/*glBegin(GL_POLYGON);
	     glColor3f (1,0,0); 
		glVertex2d(X+block1[0][0],Y+block1[0][1]);
		 glColor3f (0,1,0); 
		glVertex2d(X+block1[1][0],Y+block1[1][1]);
		 glColor3f (0,1,0); 
		glVertex2d(X+block1[2][0],Y+block1[2][1]);
		 glColor3f (1,0,0); 
		glVertex2d(X+block1[3][0],Y+block1[3][1]);
	glEnd();*/
}

// Wall drawing
void draw_Spring1_wall(){
	glBegin(GL_POLYGON);
		glVertex2d(X + spring1_wall[0][0] , Y + spring1_wall[0][1]);
		glVertex2d(X + spring1_wall[1][0] , Y + spring1_wall[1][1]);
		glVertex2d(X + spring1_wall[2][0] , Y + spring1_wall[2][1]);
		glVertex2d(X + spring1_wall[3][0] , Y + spring1_wall[3][1]);
	glEnd();
}
// bridge co-ordinates initialization
void init_T(){
	temp[0][0]= 2600;
	temp[1][0]= 2720;
	temp[2][0]= 2670;
	temp[3][0]= 2670;
	temp[4][0]=	2650;
	temp[5][0]= 2650;
	temp[6][0]= 2600;
	//temp[7][0]= 2600;
	
	temp[0][1]= 250;
	temp[1][1]= 250;
	temp[2][1]= 230;
	temp[3][1]= 180;
	temp[4][1]=	180;
	temp[5][1]= 230;
	temp[6][1]= 230;
//	temp[7][1]= 240;
	
}


// arrow1 co-ordinates initialization
void init_arrow1(){
	up_arrow[0][0][0] = points[14][0] + 300;		up_arrow[0][0][1] = points[14][1] + 20;
	up_arrow[0][1][0] = up_arrow[0][0][0] + 0;		up_arrow[0][1][1] = up_arrow[0][0][1] + 40;
	up_arrow[0][2][0] = up_arrow[0][1][0] - 15;		up_arrow[0][2][1] = up_arrow[0][1][1] + 0;
	up_arrow[0][3][0] = up_arrow[0][2][0] + 30;		up_arrow[0][3][1] = up_arrow[0][2][1] + 30;
	up_arrow[0][4][0] = up_arrow[0][3][0] + 30;		up_arrow[0][4][1] = up_arrow[0][3][1] - 30;
	up_arrow[0][5][0] = up_arrow[0][4][0] - 15;		up_arrow[0][5][1] = up_arrow[0][4][1] + 0;
	up_arrow[0][6][0] = up_arrow[0][5][0] + 0;		up_arrow[0][6][1] = up_arrow[0][5][1] - 40;
	
	up_arrow[1][0][0] = points[14][0] + 500;		up_arrow[1][0][1] = points[14][1] + 20;
	up_arrow[1][1][0] = up_arrow[1][0][0] + 0;		up_arrow[1][1][1] = up_arrow[1][0][1] + 40;
	up_arrow[1][2][0] = up_arrow[1][1][0] - 15;		up_arrow[1][2][1] = up_arrow[1][1][1] + 0;
	up_arrow[1][3][0] = up_arrow[1][2][0] + 30;		up_arrow[1][3][1] = up_arrow[1][2][1] + 30;
	up_arrow[1][4][0] = up_arrow[1][3][0] + 30;		up_arrow[1][4][1] = up_arrow[1][3][1] - 30;
	up_arrow[1][5][0] = up_arrow[1][4][0] - 15;		up_arrow[1][5][1] = up_arrow[1][4][1] + 0;
	up_arrow[1][6][0] = up_arrow[1][5][0] + 0;		up_arrow[1][6][1] = up_arrow[1][5][1] - 40;
}



// arrow2 co-ordinates initialization
void init_arrow2(){
	up_arrow[2][0][0] = points[14][0] + 700;		up_arrow[2][0][1] = points[14][1] + 20;
	up_arrow[2][1][0] = up_arrow[2][0][0] + 0;		up_arrow[2][1][1] = up_arrow[2][0][1] + 40;
	up_arrow[2][2][0] = up_arrow[2][1][0] - 15;		up_arrow[2][2][1] = up_arrow[2][1][1] + 0;
	up_arrow[2][3][0] = up_arrow[2][2][0] + 30;		up_arrow[2][3][1] = up_arrow[2][2][1] + 30;
	up_arrow[2][4][0] = up_arrow[2][3][0] + 30;		up_arrow[2][4][1] = up_arrow[2][3][1] - 30;
	up_arrow[2][5][0] = up_arrow[2][4][0] - 15;		up_arrow[2][5][1] = up_arrow[2][4][1] + 0;
	up_arrow[2][6][0] = up_arrow[2][5][0] + 0;		up_arrow[2][6][1] = up_arrow[2][5][1] - 40;
}

//horizontal arrow co-ordinates initialization
void init_horizontal_arrow(){
	up_arrow[3][0][0] = points[14][0] + 500;		up_arrow[3][0][1] = points[14][1] + 580;
	up_arrow[3][1][0] = up_arrow[3][0][0] + 0;		up_arrow[3][1][1] = up_arrow[3][0][1] + 40;
	up_arrow[3][2][0] = up_arrow[3][1][0] - 15;		up_arrow[3][2][1] = up_arrow[3][1][1] + 0;
	up_arrow[3][3][0] = up_arrow[3][2][0] + 30;		up_arrow[3][3][1] = up_arrow[3][2][1] + 30;
	up_arrow[3][4][0] = up_arrow[3][3][0] + 30;		up_arrow[3][4][1] = up_arrow[3][3][1] - 30;
	up_arrow[3][5][0] = up_arrow[3][4][0] - 15;		up_arrow[3][5][1] = up_arrow[3][4][1] + 0;
	up_arrow[3][6][0] = up_arrow[3][5][0] + 0;		up_arrow[3][6][1] = up_arrow[3][5][1] - 40;

	int i;
	for(i=1;i<7;i++){
		translate(&up_arrow[3][i][0],&up_arrow[3][i][1],-up_arrow[3][0][0],-up_arrow[3][0][1]);
		rotate(&up_arrow[3][i][0],&up_arrow[3][i][1],-90);
		translate(&up_arrow[3][i][0],&up_arrow[3][i][1],up_arrow[3][0][0],up_arrow[3][0][1]);
	}
}


// drawing arrows
void draw_arrow( ){
	int i,j;
	
	for(j=0;j<4;j++){
	glBegin(GL_LINE_LOOP);
		for( i = 0 ; i < 7 ; i++ ){
			glVertex2d(X + up_arrow[j][i][0] , Y + up_arrow[j][i][1]);
		}
	glEnd();
	
	}
	glBegin(GL_LINES);
				glVertex2d(X + 2490 , Y + 800);
				glVertex2d(X + 2580 , Y + 800);
			
	glEnd();
	
	glBegin(GL_LINES);
				glVertex2d(X + 3440 , Y + 250);
				glVertex2d(X + 4000 , Y + 250);
			
	glEnd();
	
	glBegin(GL_LINES);
				glVertex2d(X + 2579 , Y + 800);
				glVertex2d(X + 2579 , Y + 249);
			
	glEnd();
	
	for( i = 0 ; i < 7 ; i++ ){
		translate(&up_arrow[0][i][0] , &up_arrow[0][i][1], 0 , 1);
		translate(&up_arrow[1][i][0] , &up_arrow[1][i][1], 0 , 1);
	}
	
	if( up_arrow[0][4][1] >= points[14][1] + 150 ){
		init_arrow1();
	}
	
	for( i = 0 ; i < 7 ; i++ ){
		translate(&up_arrow[2][i][0] , &up_arrow[2][i][1], 0 , 1.5);
	}
	
	if( up_arrow[2][4][1] >= points[14][1] + 225 ){
		init_arrow2();
	}
	
	for( i = 0 ; i < 7 ; i++ ){
		translate(&up_arrow[3][i][0] , &up_arrow[3][i][1], 4 , 0);
	}
	
	if( up_arrow[3][0][0] >= points[14][0] + 700 ){
		init_horizontal_arrow();
		
	}
}

// Random Background generation
void draw_T( ){
	int i,j;
	int xxxx = temp[0][0] + temp[1][0];
	xxxx>>=1;
	int yyyy = 210;
	//glColor3f (fmod((float)rand()/(float)(RAND_MAX),1.0),fmod((float)rand()/(float)(RAND_MAX),1.0),fmod((float)rand()/(float)(RAND_MAX),1.0));
	glColor3f(.17,.17,.17);
	for(j=0;j<70;j++){	
		glLineWidth(2);
		glBegin(GL_LINE_LOOP);
			for( i = 0 ; i < 6 ; i++ ){
				glVertex2d(X + temp[i][0] + j*120 - 2300 , Y + temp[i][1] + rand()%1000 -240 );
				temp[i][0]-= xxxx;
				temp[i][1]-= yyyy; 
				rotate(&temp[i][0],&temp[i][1],1);
				temp[i][0]+= xxxx;
				temp[i][1]+= yyyy; 
			}
		glEnd();
	}
	
	for(j=0;j<70;j++){	
		glLineWidth(2);
		glBegin(GL_LINE_LOOP);
			for( i = 0 ; i < 6 ; i++ ){
				glVertex2d(X + temp[i][0] + j*120 - 2300 , Y + temp[i][1] + rand()%1000 -1100);
				temp[i][0]-= xxxx;
				temp[i][1]-= yyyy; 
				rotate(&temp[i][0],&temp[i][1],1);
				temp[i][0]+= xxxx;
				temp[i][1]+= yyyy; 
			}
		glEnd();
	}
	glLineWidth(3);
	glColor3f(0,.7,.0);
	for(j=0;j<70;j++){	
		glLineWidth(2);
		glBegin(GL_LINE_LOOP);
			for( i = 0 ; i < 6 ; i++ ){
				glVertex2d(X + temp[i][0] + j*120 - 2300 , Y + temp[i][1] + 780);
				temp[i][0]-= xxxx;
				temp[i][1]-= yyyy; 
				rotate(&temp[i][0],&temp[i][1],1);
				temp[i][0]+= xxxx;
				temp[i][1]+= yyyy; 
			}
		glEnd();
	}
	glLineWidth(3);
	
}
// Bridge co-ordinates intialization
void init_Bridge(){
	temp1[0][0][0]= 2600;
	temp1[0][1][0]= 2720;
	temp1[0][2][0]= 2670;
	temp1[0][3][0]= 2670;
	temp1[0][4][0]= 2650;
	temp1[0][5][0]= 2650;
	temp1[0][6][0]= 2600;	
	temp1[0][0][1]= 250;
	temp1[0][1][1]= 250;
	temp1[0][2][1]= 230;
	temp1[0][3][1]= 180;
	temp1[0][4][1]= 180;
	temp1[0][5][1]= 230;
	temp1[0][6][1]= 230;
	int i,j,k;
	for(i=1;i<8;i++)
		for(j=0;j<7;j++){
			temp1[i][j][1] = temp1[0][j][1];
			temp1[i][j][0] = temp1[0][j][0];
		}
		
	
}

bool flg1[17];
// Ddrawing Bridge
void draw_Bridge(){
	int i,j;
	int xxxx = 3300;
	static int yyyy = 130;
	float o=0,oo=1,ooo=0;
	glColor3f(0,.7,0);
	
	for(j=0;j<7;j++){	
		
		glBegin(GL_LINE_LOOP);
			for( i = 0 ; i < 6 ; i++ ){
				glVertex2d(X + temp1[j][i][0] + j*120, Y + temp1[j][i][1]  );
			}
			//yyyy-=5;
		glEnd();
	}
	glColor3f(0,.7,0);
	int m  = ball[1][0];
	int x = m%2720;
	x/=120;
	
	int k = 120;
	if(ball[1][0]>2720) {
		
	
		while(x>-1){
			
			for(i=0;i<6;i++){
					
				temp1[x][i][1]-=8;
			}
			if(!flg1[x]){
					//PlaySound("fall.wav", NULL, SND_ASYNC|SND_FILENAME);
					flg1[x]=1;
				}
			x--;
		}
	}
}
