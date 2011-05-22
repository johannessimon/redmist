#ifdef OS_MAC
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif

//#include <iostream>
#include <cmath>
#include <limits>
#include "util/vec3d.h"

double collision(Vec3d dPos, Vec3d dVel, double rx, double ry);

using namespace std;

bool keys[256];
double x, y;
double speed = 0.2/1000;
int timestart;

void draw()
{
	//cout << "Drawing." << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	double timediff = (double)glutGet(GLUT_ELAPSED_TIME) - timestart;
	timestart = glutGet(GLUT_ELAPSED_TIME);
    //cout << "timediff: " << timediff << endl;
    bool coll;
	
    Vec3d vA;

	if(keys['a'])
		vA.x -= speed;
	if(keys['d'])
		vA.x += speed;
	if(keys['w'])
		vA.y += speed;
	if(keys['s'])
		vA.y -= speed;
	
    Vec3d posA(-1 + x, y, 0);
    Vec3d posB(1, 0, 0);

    posA += timediff * vA;

    collision(posB - posA, Vec3d() - speedA, &coll);

    if (coll)
        glColor3f(1.0, 0.0, 0.0);

	glLoadIdentity();
	glPushMatrix();
		glTranslatef(posA.x, posA.y, posA.z);
		glutSolidSphere(0.25, 100, 100);
	glPopMatrix();
	
	glTranslatef(posA.x, posA.y, posA.z);
	glutSolidSphere(0.25, 100, 100);
    /*glBegin(GL_TRIANGLES);
		glVertex3f(-0.5,-0.5,0.0);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.5,0.0,0.0);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.0,0.5,0.0);
	glEnd();*/
	
	glutSwapBuffers();
}

void keyPressed(unsigned char key, int, int)
{
	keys[key] = true;
}


void keyReleased(unsigned char key, int, int)
{
	keys[key] = false;
}

double collision(Vec3d dPos, Vec3d dVel, double rx, double ry, bool &coll)
{
	
	double denom = 2 * (dPos.x*dVel.x + dPos.y*dVel.x);
	if (abs(denom) <= numeric_limits<double>::epsilon()) {
		coll = false;
		return 0;
	}
	double nom = dPos.x*dPos.x + dPos.y*dPos.y + dPos.x*dVel.x + dPos.y*dVel.y - (rx + ry)*(rx + ry);
	coll = true;
	
	return abs(nom / denom);
}

int main(int argc, char **argv)
{
	x = y = 0.0;
	timestart = glutGet(GLUT_ELAPSED_TIME);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Soldat-Klon Prototyp, OpenGL-Test");
	
	glutDisplayFunc(draw);
	glutIdleFunc(draw);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyReleased);
	
	glutMainLoop();
	
	return 0;
}
