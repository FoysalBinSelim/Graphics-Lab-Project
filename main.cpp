#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include <windows.h>
#include <glut.h>
#define pi (2*acos(0.0))

double cameraHeight;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle;
float r;
double incx=50, incy;
int state;
struct point
{
	double x,y,z;
};

void push_pop(void)
{
    glPushMatrix();
        glRotatef(45, 0, 0, 1);
        glPushMatrix(); // Furthest Triangle, Draw first


            //glRotatef(45, 0, 0, 1);
            glTranslatef(-20, 0, 0);
            //glScaled(2, 1, 0);
            glColor3f(0.0, 0.0, 1.0);
            glBegin(GL_POLYGON);
                glVertex2f(10, 10);
                glVertex2f(10, 0);
                glVertex2f(-10, 0);
            glEnd();
        glPopMatrix();

        glPushMatrix(); // Middle Triangle, Draw 2nd
            glColor3f(0.0, 1.0, 0.0);
            glBegin(GL_POLYGON);
                glVertex2f(10, 10);
                glVertex2f(10, 0);
                glVertex2f(-10, 0);
            glEnd();
        glPopMatrix();

        glPushMatrix(); // Nearest Triangle, Draw last
            glTranslatef(20, 0, 0);
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_POLYGON);
                glVertex2f(10, 10);
                glVertex2f(10, 0);
                glVertex2f(-10, 0);
            glEnd();
        glPopMatrix();



    glPopMatrix();

}


void drawAxes()
{

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);{
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);

			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);

			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);
		}glEnd();

}


void drawGrid()
{
	int i;

    glColor3f(0.6, 0.6, 0.6);	//grey
    glBegin(GL_LINES);{
        for(i=-8;i<=8;i++){

            if(i==0)
                continue;	//SKIP the MAIN axes

            //lines parallel to Y-axis
            glVertex3f(i*10, -90, 0);
            glVertex3f(i*10,  90, 0);

            //lines parallel to X-axis
            glVertex3f(-90, i*10, 0);
            glVertex3f( 90, i*10, 0);
        }
    }glEnd();

}




void drawCircle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
	glBegin(GL_LINE_LOOP);
    {
		for(i = 0; i < int(1000); i++)
		{
			angle = 2* 3.1416 * i / 1000;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

    }

	glEnd();
}


void drawsemiCircle(float radius_x,float radius_y,float radius_z)
{
	int i = 0;
	float angle = 0.0;

    //glColor3f(0,1,0);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i < int(1000); i++)
		{
			angle = 2*3.1416* i / 1000;
			r=radius_x*i/1000;
			//glVertex3f ( cos(angle)*radius_x, sin(angle)*radius_y,radius_z);
            glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
			//glVertex3f ((cos(angle)) * radius_x,sin(angle) * radius_y,sqrt(r*r-radius_z*radius_z));
		}

    }

	glEnd();
}

void sun ()
{

        glColor3f(1,1,0);
        drawsemiCircle(5,5,5);

}
void mer()

{
    glRotatef(25*angle,0,0,1);
    glTranslatef(-20,0,0);
    glColor3f(1,0,1);
    drawsemiCircle(1,1,1);
}

void merx()
{   glColor3f(0.6, 0.6, 0.6);	//grey
    drawCircle(20,20);
}

void ven()

{
    glRotatef(20*angle,0,0,1);
    glTranslatef(-25,0,0);
    glColor3f(0,1,0);
     //glColor3f(0.53 ,0.12,0.47);
    drawsemiCircle(1.8,1.8,1.8);
}
void venx()
{   glColor3f(0.6,0.6,0.6);
    drawCircle(25,25);
}
void er()

{
    glRotatef(15*angle,0,0,1);
     glTranslatef(-30,0,0);
    glColor3f(0,0,1);
     drawsemiCircle(2,2,2);
}
void erx()
{   glColor3f(.6,.6,.6);
    drawCircle(30,30);
}
void mar()

{
    glRotatef(10*angle,0,0,1);
    glTranslatef(-35,0,0);
    glColor3f(1,0,0);
    drawsemiCircle(1.5,1.5,1.5);
}
void marx()
{   glColor3f(.6,.6,.6);
    drawCircle(35,35);
}
void jup()

{
    glRotatef(7*angle,0,0,1);
    glTranslatef(-45,0,0);
    glColor3f(1.0,0.5 ,0.0);
    drawsemiCircle(4,4,4);
}
void jupx()
{   glColor3f(.6,.6,.6);
    drawCircle(45,45);
}

void sat()
{
    glRotatef(5*angle,0,0,1);
    glTranslatef(-55,0,0);
    glColor3f(0.623529 ,0.623529 ,0.372549);
    //glPushMatrix();
    drawCircle(4.4,2.6);
    drawCircle(4.5,2.7);
    drawCircle(4.7,2.8);
    drawCircle(5.5,3);
    //glPopMatrix();
    drawsemiCircle(3,3,3);
}

void satx()
{   glColor3f(.6,.6,.6);
    drawCircle(55,55);
}
void u()

{
    glRotatef(3*angle,0,0,1);
     glTranslatef(-65,0,0);
    glColor3f(0.5,1.0,0.5);
        //glColor3f(0.1,1.0,1.0);
     drawsemiCircle(3,3,3);
}
void ux()
{   glColor3f(.6,.6,.6);
    drawCircle(65,65);
}
void nep()

{
    glRotatef(1.5*angle,0,0,1);
    glTranslatef(-75,0,0);
    glColor3f(0.1,1.0,1.0);
    drawsemiCircle(2.8,2.8,2.8);
}
void nepx()
{   glColor3f(.6,.6,.6);
    drawCircle(75,75);
}

void rec_animation()
{
    glPushMatrix();
    sun();
    glPopMatrix();
    glPushMatrix();
    mer();
    glPopMatrix();
    glPushMatrix();
    merx();
    glPopMatrix();
    glPushMatrix();
    ven();
    glPopMatrix();
    glPushMatrix();
    venx();
    glPopMatrix();
    glPushMatrix();
    er();
    glPopMatrix();
    glPushMatrix();
    erx();
    glPopMatrix();
    glPushMatrix();
    mar();
    glPopMatrix();
    glPushMatrix();
    marx();
    glPopMatrix();
    glPushMatrix();
    jup();
    glPopMatrix();
    glPushMatrix();
    jupx();
    glPopMatrix();
    glPushMatrix();
    sat();
    glPopMatrix();
    glPushMatrix();
    satx();
    glPopMatrix();
    glPushMatrix();
    u();
    glPopMatrix();
    glPushMatrix();
    ux();
    glPopMatrix();
    glPushMatrix();
    nep();
    glPopMatrix();
    glPushMatrix();
    nepx();
    glPopMatrix();

}
void draw_rec()
{
    glColor3f(0,1,0);

//    drawSquare(5);

}



double func(double x)
{
    return x*x;
}

void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera looking?
	//3. Which direction is the camera's UP direction?

	//gluLookAt(100,100,100,	0,0,0,	0,0,1);
	gluLookAt(100*cos(cameraAngle), 100*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	//gluLookAt(0,0,150,	0,0,0,	0,1,0);


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);



	//add objects

	//drawAxes();
	//drawGrid();

	//drawCircle(5,5);
    //drawSS();
    //draw_rec();
    //push_pop();
    //simple_trans();
    rec_animation();







	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}


void animate(){
    //rotation
    angle+=0.005;

	//codes for any changes in Models, Camera
	//linear_oscillation

    /*if(state ==0 && incx>50){ state =1;}
    if(state ==1 && incx <-50){state =0;}

    if(state == 0) incx+=0.05;
    else incx-=0.05;*/

	glutPostRedisplay();
}

void init(){
	//codes for initialization
	drawgrid=0;
	drawaxes=1;
	cameraHeight=150.0;
	cameraAngle=1.0;
	angle=0;

	//clear the screen
	glClearColor(0,0,0,0);


	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(80,	1,	1,	1000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(250,0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("My OpenGL Program");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	//glutKeyboardFunc(keyboardListener);
	//glutSpecialFunc(specialKeyListener);
	//glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}

