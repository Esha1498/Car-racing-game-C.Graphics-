#include <iostream>
#include <fstream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>

using namespace std;;

float _move1 = 0;
float _move2 = 0;
float _move3 = 0;
float _move4 = 0;
int driverCarPos = 0;
float speed = 0.02;
int carPos = 1;
int carOpPos[] = {0,0,0,0,0,0,0};
float _opCar[] = {0,0,0,0,0,0,0};
int nOp = 6;
int screen = 0;
char start[] = "Start";
char exitGame[] = "Exit";
char scoreText[] = "Score:";
int score = 0;
char buffer[10];
bool collide = false;
int prevOpPos =0;
int timer = 25;
int driverCar = 1;



void drawRoad()
{
    glPushMatrix();

        glColor3ub(213,222,24);
        glBegin(GL_QUADS);
            glVertex3f(-1,-1,0);
            glVertex3f(-1,1,0);
            glVertex3f(1,1,0);
            glVertex3f(1,-1,0);
        glEnd();

        glColor3ub(30,30,30);
        glBegin(GL_QUADS);
            glVertex3f(-.70,-1,0);
            glVertex3f(-.70,1,0);
            glVertex3f(.70,1,0);
            glVertex3f(.70,-1,0);
        glEnd();

            glColor3ub(255,255,255);
            glPushMatrix();
                glTranslatef(0,_move1,0);
                glBegin(GL_QUADS);
                    glVertex3f(-.30,1.70,0);
                    glVertex3f(-.30,1.10,0);
                    glVertex3f(-.20,1.10,0);
                    glVertex3f(-.20,1.70,0);
                glEnd();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0,_move2,0);
                glBegin(GL_QUADS);
                    glVertex3f(-.30,1,0);
                    glVertex3f(-.30,.40,0);
                    glVertex3f(-.20,.40,0);
                    glVertex3f(-.20,1,0);
                glEnd();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0,_move3,0);
                glBegin(GL_QUADS);
                    glVertex3f(-.30,.30,0);
                    glVertex3f(-.30,-.3,0);
                    glVertex3f(-.20,-.3,0);
                    glVertex3f(-.20,.30,0);
                glEnd();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0,_move4,0);
                glBegin(GL_QUADS);
                    glVertex3f(-.30,-.40,0);
                    glVertex3f(-.30,-1,0);
                    glVertex3f(-.20,-1,0);
                    glVertex3f(-.20,-.40,0);
                glEnd();
            glPopMatrix();

            //Right white
            glPushMatrix();
                glTranslatef(0,_move1,0);
                glBegin(GL_QUADS);
                    glVertex3f(.30,1.70,0);
                    glVertex3f(.30,1.10,0);
                    glVertex3f(.20,1.10,0);
                    glVertex3f(.20,1.70,0);
                glEnd();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0,_move2,0);
                glBegin(GL_QUADS);
                    glVertex3f(.30,1,0);
                    glVertex3f(.30,.40,0);
                    glVertex3f(.20,.40,0);
                    glVertex3f(.20,1,0);
                glEnd();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0,_move3,0);
                glBegin(GL_QUADS);
                    glVertex3f(.30,.30,0);
                    glVertex3f(.30,-.3,0);
                    glVertex3f(.20,-.3,0);
                    glVertex3f(.20,.30,0);
                glEnd();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0,_move4,0);
                glBegin(GL_QUADS);
                    glVertex3f(.30,-.40,0);
                    glVertex3f(.30,-1,0);
                    glVertex3f(.20,-1,0);
                    glVertex3f(.20,-.40,0);
                glEnd();
            glPopMatrix();

    glPopMatrix();
}

void tree()
{
    glBegin(GL_POLYGON);
    glColor3ub(128, 64, 0);
	glVertex2f(-0.865f,-0.3f);
	glVertex2f(-0.865f,0.0f);
	glVertex2f(-0.84f,0.0f);
	glVertex2f(-0.84f,-0.3f); //root
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(0, 77, 0);
	glVertex2f(-0.865f,0.0f);
	glVertex2f(-0.91f,0.0f);
	glVertex2f(-0.875f,0.05f);
	glVertex2f(-0.9f,0.05f);
	glVertex2f(-0.862f,0.1f);
	glVertex2f(-0.88f,0.1f);
	glVertex2f(-0.8525f,0.15f);
	glVertex2f(-0.825f,0.1f);
	glVertex2f(-0.838f,0.1f);
	glVertex2f(-0.805f,0.05f);
	glVertex2f(-0.83f,0.05f);
	glVertex2f(-0.795f,0.0f); //left mid
	glVertex2f(-0.865f,0.0f);
	glEnd();
}
void outview()
{
    glBegin(GL_POLYGON);
    glColor3ub(0, 153, 0);
	glVertex2f(0.7f,-1.0f);
	glVertex2f(1.0f,-1.0f);
	glVertex2f(1.0f,1.0f);
	glVertex2f(0.7f,1.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(-0.7f,-1.0f);
	glVertex2f(-1.0f,-1.0f);
	glVertex2f(-1.0f,1.0f);
	glVertex2f(-0.7f,1.0f);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3ub(128, 64, 0);
	glVertex2f(0.865f,-0.3f);
	glVertex2f(0.865f,0.0f);
	glVertex2f(0.84f,0.0f);
	glVertex2f(0.84f,-0.3f); //root
	glEnd();
	glBegin(GL_POLYGON);
    glColor3ub(0, 77, 0);
	glVertex2f(0.865f,0.0f);
	glVertex2f(0.91f,0.0f);
	glVertex2f(0.875f,0.05f);
	glVertex2f(0.9f,0.05f);
	glVertex2f(0.862f,0.1f);
	glVertex2f(0.88f,0.1f);
	glVertex2f(0.8525f,0.15f);
	glVertex2f(0.825f,0.1f);
	glVertex2f(0.838f,0.1f);
	glVertex2f(0.805f,0.05f);
	glVertex2f(0.83f,0.05f);
	glVertex2f(0.795f,0.0f);
	glVertex2f(0.865f,0.0f); //right mid
	glEnd();
	tree();
	glTranslatef(0.088f,0.7f,0.0f);
	tree();
    glLoadIdentity();
	glTranslatef(-0.08f,0.7f,0.0f);
	tree();
	glEnd();
	glLoadIdentity();
	glTranslatef(-0.08f,-0.65f,0.0f);
	tree();
	glLoadIdentity();
	glTranslatef(0.08f,-0.65f,0.0f);
	tree();
	glLoadIdentity();
	glTranslatef(1.62f,-0.65f,0.0f);
	tree();
	glLoadIdentity();
	glTranslatef(1.79f,-0.65f,0.0f);
	tree();
	glLoadIdentity();
	glTranslatef(1.79f,0.7f,0.0f);
	tree();
	glLoadIdentity();
	glTranslatef(1.62f,0.7f,0.0f);
	tree();

}

void drawDriver()
{
    if(carPos == 2)
    {
        glTranslatef(.53,0,0);
    }
    else if(carPos == 3)
    {
        glTranslatef(1.05,0,0);
    }

    glTranslatef(-0.525f, -0.79f, 0.0f);
    glScalef(0.5f,0.5f,0.0f);
	glBegin(GL_POLYGON);
	glColor3ub(102,51,153);
	glVertex2f(-0.05f,-0.3f);
	glVertex2f(0.05f,-0.3f);
	glVertex2f(0.09f,-0.285f);
	glVertex2f(0.1f,-0.21f);
	glVertex2f(0.1f,-0.17f);
	glVertex2f(0.09f,-0.1f);
	glVertex2f(0.09f,0.1f);
	glVertex2f(0.1f,0.17f);
	glVertex2f(0.1f,0.21f);
	glVertex2f(0.09f,0.285f);
	glVertex2f(0.05f,0.3f);
	glVertex2f(-0.05f,0.3f);          //
	glVertex2f(-0.09f,0.285f);
	glVertex2f(-0.1f,0.21f);
	glVertex2f(-0.1f,0.17f);
	glVertex2f(-0.09f,0.1f);
	glVertex2f(-0.09f,-0.1f);
	glVertex2f(-0.1f,-0.17f);
	glVertex2f(-0.1f,-0.21f);
	glVertex2f(-0.095f,-0.285f);
	glEnd();                        //car shape

	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2f(0.025f,-0.22f);
	glVertex2f(0.05f,-0.17f);
	glVertex2f(-0.05f,-0.17f);
	glVertex2f(-0.025f,-0.22f);
	glEnd();
                                    //back shape
    glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2f(0.056f,-0.25f);
	glVertex2f(0.07f,-0.30f);
	glVertex2f(-0.07f,-0.30f);
	glVertex2f(-0.056f,-0.25f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2f(0.05f,0.05f);
	glVertex2f(0.07f,0.15f);
	glVertex2f(-0.07f,0.15f);
	glVertex2f(-0.05f,0.05f);
	glEnd();                        //front shape glass
	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2f(0.075f,-0.18f);
	glVertex2f(0.075f,0.1f);
	glVertex2f(0.053f,0.01f);
	glVertex2f(0.053f,-0.13f);
	glEnd();                          //right side glass
	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2f(-0.075f,-0.18f);
	glVertex2f(-0.075f,0.1f);
	glVertex2f(-0.053f,0.01f);
	glVertex2f(-0.053f,-0.13f);
	glEnd();                          //left side glass

	glBegin(GL_POLYGON);
	glColor3ub(210, 214, 0);
	glVertex2f(0.05f,0.27f);
	glVertex2f(0.08f,0.26f);
	glVertex2f(0.09f,0.285f);
	glVertex2f(0.05f,0.3f);
	glEnd();                  //head light right

	glBegin(GL_POLYGON);
	glColor3ub(210, 214, 0);
	glVertex2f(-0.05f,0.27f);
	glVertex2f(-0.08f,0.26f);
	glVertex2f(-0.09f,0.285f);
	glVertex2f(-0.05f,0.3f);
	glEnd();
}

int getOpCarPos(int opCarPos)
{
    if(opCarPos == 0)
    {
        int i =1;
        int pos = rand() % 4 + 1;
        while(i)
        {
             if(pos == prevOpPos)
                pos = rand() % 4 + 1;
             else
                break;
        }

        prevOpPos = pos;
        return pos;
    }
    else
        return opCarPos;
}
void drawOpCar(int pos)
{
    if(pos == 1)
    {
        glPushMatrix();

            glTranslatef(-0.525f, 0.6f, 0.0f);
            glScalef(-0.5f,-0.5f,0.0f);
            glBegin(GL_POLYGON);
            glColor3ub(255, 51, 51);
            glVertex2f(-0.05f,-0.3f);
            glVertex2f(0.05f,-0.3f);
            glVertex2f(0.09f,-0.285f);
            glVertex2f(0.1f,-0.21f);
            glVertex2f(0.1f,-0.17f);
            glVertex2f(0.09f,-0.1f);
            glVertex2f(0.09f,0.1f);
            glVertex2f(0.1f,0.17f);
            glVertex2f(0.1f,0.21f);
            glVertex2f(0.09f,0.285f);
            glVertex2f(0.05f,0.3f);
            glVertex2f(-0.05f,0.3f);          //
            glVertex2f(-0.09f,0.285f);
            glVertex2f(-0.1f,0.21f);
            glVertex2f(-0.1f,0.17f);
            glVertex2f(-0.09f,0.1f);
            glVertex2f(-0.09f,-0.1f);
            glVertex2f(-0.1f,-0.17f);
            glVertex2f(-0.1f,-0.21f);
            glVertex2f(-0.095f,-0.285f);
            glEnd();                        //car shape

            glBegin(GL_POLYGON);
            glColor3ub(0,0,0);
            glVertex2f(0.025f,-0.22f);
            glVertex2f(0.05f,-0.17f);
            glVertex2f(-0.05f,-0.17f);
            glVertex2f(-0.025f,-0.22f);
            glEnd();                       //back shape
            glBegin(GL_POLYGON);
            glColor3ub(0,0,0);
            glVertex2f(0.05f,0.05f);
            glVertex2f(0.07f,0.15f);
            glVertex2f(-0.07f,0.15f);
            glVertex2f(-0.05f,0.05f);
            glEnd();                        //front shape glass
            glBegin(GL_POLYGON);
            glColor3ub(0,0,0);
            glVertex2f(0.075f,-0.18f);
            glVertex2f(0.075f,0.1f);
            glVertex2f(0.053f,0.01f);
            glVertex2f(0.053f,-0.13f);
            glEnd();                          //right side glass
            glBegin(GL_POLYGON);
            glColor3ub(0,0,0);
            glVertex2f(-0.075f,-0.18f);
            glVertex2f(-0.075f,0.1f);
            glVertex2f(-0.053f,0.01f);
            glVertex2f(-0.053f,-0.13f);
            glEnd();                          //left side glass

            glBegin(GL_POLYGON);
            glColor3ub(210, 214, 0);
            glVertex2f(0.05f,0.27f);
            glVertex2f(0.08f,0.26f);
            glVertex2f(0.09f,0.285f);
            glVertex2f(0.05f,0.3f);
            glEnd();                  //head light right

            glBegin(GL_POLYGON);
            glColor3ub(210, 214, 0);
            glVertex2f(-0.05f,0.27f);
            glVertex2f(-0.08f,0.26f);
            glVertex2f(-0.09f,0.285f);
            glVertex2f(-0.05f,0.3f);
            glEnd();

        glPopMatrix();
    }
    else if(pos == 2)
    {
        glPushMatrix();
            glTranslatef(0.0f, 0.69f, 0.0f);
            glScalef(0.8f,0.65,0.0f);
            glBegin(GL_POLYGON);
            glColor3ub(0, 102, 34);
            glVertex2f(0.07f,-0.2f);
            glVertex2f(0.07f,0.2f);
            glVertex2f(-0.07f,0.2f);
            glVertex2f(-0.07f,-0.2f);   //car shape
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(0, 230, 172);
            glVertex2f(0.06f,-0.17f);
            glVertex2f(0.06f,0.17f);
            glVertex2f(-0.06f,0.17f);
            glVertex2f(-0.06f,-0.17f);   //top shape
            glEnd();
            // 4 wheels
            glBegin(GL_POLYGON);
            glColor3ub(0, 0, 0);
            glVertex2f(0.08f,0.08f);
            glVertex2f(0.08f,0.15f);
            glVertex2f(0.07f,0.15f);
            glVertex2f(0.07f,0.08f);
            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(-0.08f,0.08f);
            glVertex2f(-0.08f,0.15f);
            glVertex2f(-0.07f,0.15f);
            glVertex2f(-0.07f,0.08f);
            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(0.08f,-0.08f);
            glVertex2f(0.08f,-0.15f);
            glVertex2f(0.07f,-0.15f);
            glVertex2f(0.07f,-0.08f);
            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(-0.08f,-0.08f);
            glVertex2f(-0.08f,-0.15f);
            glVertex2f(-0.07f,-0.15f);
            glVertex2f(-0.07f,-0.08f);
            glEnd();
            //front side
            glBegin(GL_POLYGON);
            glColor3ub(0, 153, 115);
            glVertex2f(0.05f,-0.35f);
            glVertex2f(0.05f,-0.2f);
            glVertex2f(-0.05f,-0.2f);
            glVertex2f(-0.05f,-0.35f); //head shape
            glEnd();
            //wheels shape
            glBegin(GL_POLYGON);
            glColor3ub(0, 0, 0);
            glVertex2f(-0.06f,-0.3f);
            glVertex2f(-0.06f,-0.23f);
            glVertex2f(-0.05f,-0.23f);
            glVertex2f(-0.05f,-0.3f);
            glEnd();
            glBegin(GL_POLYGON);
            glColor3ub(0, 0, 0);
            glVertex2f(0.06f,-0.3f);
            glVertex2f(0.06f,-0.23f);
            glVertex2f(0.05f,-0.23f);
            glVertex2f(0.05f,-0.3f);
            glEnd();
            //head top view
            glBegin(GL_POLYGON);
            glColor3ub(0, 77, 57);
            glVertex2f(0.03f,-0.3f);
            glVertex2f(0.03f,-0.2f);
            glVertex2f(-0.03f,-0.2f);
            glVertex2f(-0.03f,-0.3f);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(128, 255, 223);
            glVertex2f(0.032f,-0.285f);
            glVertex2f(0.04f,-0.305f);
            glVertex2f(0.04f,-0.205f);
            glVertex2f(0.032f,-0.215f);
            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(-0.032f,-0.285f);
            glVertex2f(-0.04f,-0.305f);
            glVertex2f(-0.04f,-0.205f);
            glVertex2f(-0.032f,-0.215f);
            glEnd();

            glBegin(GL_POLYGON);
            glVertex2f(0.005f,-0.32f);
            glVertex2f(0.03f,-0.32f);
            glVertex2f(0.025f,-0.305f);
            glVertex2f(0.005f,-0.305f);
            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(-0.005f,-0.32f);
            glVertex2f(-0.03f,-0.32f);
            glVertex2f(-0.025f,-0.305f);
            glVertex2f(-0.005f,-0.305f);
            glEnd();
	glPopMatrix();
    }
    else if(pos == 3)
    {
        glPushMatrix();
            glTranslatef(0.26f, 0.1f, 0.0f);
            glScalef(0.8f,0.65f,0.0f);
            glBegin(GL_POLYGON);
            glColor3ub(255, 153, 0);
            glVertex2f(0.403f,0.55f);
            glVertex2f(0.403f,0.95f);
            glVertex2f(0.263f,0.95f);
            glVertex2f(0.263f,0.55f);  //fist layer
            glEnd();
            glBegin(GL_POLYGON);
            glColor3ub(208, 255, 0);
            glVertex2f(0.393f,0.58f);
            glVertex2f(0.393f,0.92f);
            glVertex2f(0.273f,0.92f);
            glVertex2f(0.273f,0.58f); //second layer
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(0, 0, 0);
            glVertex2f(0.413f,0.84f);
            glVertex2f(0.413f,0.9f);
            glVertex2f(0.403f,0.9f);
            glVertex2f(0.403f,0.84f); //wheel layer
            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(0.413f,0.6f);
            glVertex2f(0.413f,0.66f);
            glVertex2f(0.403f,0.66f);
            glVertex2f(0.403f,0.6f); //wheel layer
            glEnd();
            glBegin(GL_POLYGON);
            glColor3ub(0, 0, 0);
            glVertex2f(0.253f,0.84f);
            glVertex2f(0.253f,0.9f);
            glVertex2f(0.263f,0.9f);
            glVertex2f(0.263f,0.84f); //wheel layer
            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(0.253f,0.6f);
            glVertex2f(0.253f,0.66f);
            glVertex2f(0.263f,0.66f);
            glVertex2f(0.263f,0.6f); //wheel layer
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(232, 214, 102);
            glVertex2f(0.393f,0.655f);
            glVertex2f(0.393f,0.895f);
            glVertex2f(0.273f,0.895f); //under view
            glVertex2f(0.273f,0.655f);
            glEnd();

            glBegin(GL_POLYGON);
            glColor3ub(0, 0, 0);
            glVertex2f(0.368f,0.7f);
            glVertex2f(0.368f,0.85f);
            glVertex2f(0.298f,0.85f);
            glVertex2f(0.298f,0.7f); //top view
            glEnd();
            glBegin(GL_POLYGON);
            glColor3ub(112, 117, 93);
            glVertex2f(0.358f,0.86f);
            glVertex2f(0.368f,0.88f);
            glVertex2f(0.298f,0.88f);
            glVertex2f(0.308f,0.86f); //top view
            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(0.368f,0.67f);
            glVertex2f(0.358f,0.69f);
            glVertex2f(0.308f,0.69f); //top view
            glVertex2f(0.298f,0.67f);
            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(0.383f,0.7f);
            glVertex2f(0.383f,0.85f);
            glVertex2f(0.372f,0.84f); //top view left
            glVertex2f(0.372f,0.71f);
            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(0.283f,0.7f);
            glVertex2f(0.283f,0.85f);
            glVertex2f(0.294f,0.84f); //top view right
            glVertex2f(0.294f,0.71f);
            glEnd();
            glLoadIdentity();
        glPopMatrix();
    }
}

void Sprint( float x, float y, char *st)
{
    int l,i;

    l=strlen( st );
    glColor3ub(255,255,255);
    glRasterPos2f( x, y); // location to start printing text,
    for( i=0; i < l; i++) // loop until i is greater then l,
    {
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);
    }
}

void SprintScore(char ch[],int numtext,float x, float y)//counting the score
{
    int len;
    int k,i;
    k = 0;
    len = numtext - strlen (ch);
    glLoadIdentity ();
    glRasterPos2f( x , y);
    for (i = 0; i <=numtext - 1; i++)
    {
        if ( i < len )
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'0');
        else
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[k]);
            k++;
        }
    }
}

void drawMenu()
{
    glPushMatrix();

        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
            glVertex3f(-.45,.65,0);
            glVertex3f(-.45,-.35,0);
            glVertex3f(.45,-.35,0);
            glVertex3f(.45,.65,0);
        glEnd();

        glColor3ub(0,0,255);
        glBegin(GL_QUADS);
            glVertex3f(-.4,.6,0);
            glVertex3f(-.4,-.3,0);
            glVertex3f(.4,-.3,0);
            glVertex3f(.4,.6,0);
        glEnd();

        glColor3ub(0,0,0);

        glBegin(GL_QUADS);
            glVertex3f(-.31,.41,0);
            glVertex3f(-.31,.19,0);
            glVertex3f(.31,.19,0);
            glVertex3f(.31,.41,0);
        glEnd();

        glBegin(GL_QUADS);
            glVertex3f(-.31,.11,0);
            glVertex3f(-.31,-.11,0);
            glVertex3f(.31,-.11,0);
            glVertex3f(.31,.11,0);
        glEnd();
        glColor3ub(128,128,128);

        glBegin(GL_QUADS);
            glVertex3f(-.3,.4,0);
            glVertex3f(-.3,.2,0);
            glVertex3f(.3,.2,0);
            glVertex3f(.3,.4,0);
        glEnd();

       glBegin(GL_QUADS);
            glVertex3f(-.3,.1,0);
            glVertex3f(-.3,-.1,0);
            glVertex3f(.3,-.1,0);
            glVertex3f(.3,.1,0);
        glEnd();

        //text

        Sprint(-.07,.28,start);
        Sprint(-.08,-.02,exitGame);
    glPopMatrix();
}


void drawScoreBoard()
{
    glColor3ub(0,0,0);
        glBegin(GL_QUADS);
            glVertex3f(.75,.9,0);
            glVertex3f(.75,.7,0);
            glVertex3f(1,.7,0);
            glVertex3f(1,.9,0);
        glEnd();

        glColor3ub(0,0,255);
        glBegin(GL_QUADS);
            glVertex3f(.77,.88,0);
            glVertex3f(.77,.73,0);
            glVertex3f(.98,.73,0);
            glVertex3f(.98,.88,0);
        glEnd();

    Sprint(.8,.8,scoreText);
    itoa (score, buffer, 10);
    SprintScore(buffer, 6, .8,.75);
}

void update(int value)
{
    //road white
     _move4 -= speed;
     _move3 -= speed;
     _move2 -= speed;
     _move1 -= speed;

    if(_move4 < -.6)
        _move4 = 2.2;
    else if(_move3 < -1.3)
        _move3 = 1.5;
    else if(_move2 < -2)
        _move2 = .8;
    else if(_move1 < -2.7)
        _move1 = .1;

    //car
    for(int i = 1; i <= nOp; i++)
    {
        if(carOpPos[i] > 0)
            _opCar[i] -= speed;

        if(nOp == i)
        {
            if(_opCar[nOp] < -3.0)
            {
                float diff =0;
                for(int i = 1; i <= nOp; i++)
                {
                    carOpPos[i] = 0;
                    _opCar[i] = diff;
                    diff += .7;
                }
            }
        }
    }

    for(int i =1; i <= nOp ; i++)
    {
        if( -1.1 >_opCar[i] && _opCar[i] > -1.7 && carPos == carOpPos[i])
        {
            if(collide)
                collide = false;
            else
                collide = true;
        }
    }

    if(collide)
    {
        if(screen == 1)
        {
            screen = 0;

        }

        collide = false;
    }

    score++;


    glutPostRedisplay();
    glutTimerFunc(timer,update,0);
}


void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(screen == 0)
        {
            if(x > 280 && x < 517 && y > 240 && y < 320)
            {
                screen = 1;
                for(int i = 1;i <= nOp;i++)
                {
                    _opCar[i] = 0;
                }
                for(int i = 1;i <= nOp;i++)
                {
                   carOpPos[i] = 0;
                }

                float diff = 0;
                for(int i = 1;i <= nOp;i++)
                {
                    _opCar[i] += diff;
                    diff += .7;
                }
                speed = 0.02;
                score = 0;

            }
            else if(x > 280 && x < 517 && y > 360 && y < 440)
            {
                exit(1);
            }
        }
    }
}

void specialkey(int key, int x, int y)
{
    switch(key)
    {
        int Y,X;
        case GLUT_KEY_UP:
        speed += 0.02;
            break;

        case GLUT_KEY_DOWN:
        if(speed >= 0)
        {
            speed -= 0.02;
            break;
        }
        else
        {
            speed = speed;
        }

        case GLUT_KEY_LEFT:
        if(carPos != 1)
            carPos--;


        glutPostRedisplay();
        break;

        case GLUT_KEY_RIGHT:
         if(carPos != 3)
            carPos++;

        glutPostRedisplay();
        break;

    }
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3b(0,0,0);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    if(screen == 0)
    {

        glPushMatrix();
            drawRoad();
            drawMenu();
        glPopMatrix();
        outview();
        tree();

    }
    if(screen == 1)
    {
        glPushMatrix();
            drawRoad();
            drawDriver();
        glPopMatrix();

        outview();
        tree();
        glLoadIdentity();
        for(int i = 1;i <= nOp;i++)
        {
            glPushMatrix();
                glTranslated(0,_opCar[i],0);
                carOpPos[i] = getOpCarPos(carOpPos[i]);
                drawOpCar(carOpPos[i]);
            glPopMatrix();
        }
        drawScoreBoard();
    }
    else if(screen == 2)
    {
        drawRoad();
        drawScoreBoard();
    }
    glutSwapBuffers();
}


int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800,800);
    glutCreateWindow("Car Racing");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutTimerFunc(25, update,0);
    glutSpecialFunc(specialkey);
    //sndPlaySound("Background.wav",SND_ASYNC|SND_LOOP);
    glutMainLoop();

    return 0;
}
