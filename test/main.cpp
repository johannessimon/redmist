#include <GL/glut.h>
#include <GL/gl.h>

#include <iostream>

#include <cstdlib>

void draw()
{
	printf("%d", 3);
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
	
	std::cout << "foobar" << std::endl;
	glutMainLoop();
	
	return 0;
}