#include <GL/glut.h>

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-0.5,-0.5,0.0);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.5,0.0,0.0);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.0,0.5,0.0);
	glEnd();
	
	glutSwapBuffers();
}

void keyPressed(unsigned char key, int, int)
{
	
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Soldat-Klon Prototyp, OpenGL-Test");
	
	glutDisplayFunc(draw);
	glutIdleFunc(draw);
	glutKeyboardFunc(keyPressed);
	
	glutMainLoop();
	
	return 0;
}