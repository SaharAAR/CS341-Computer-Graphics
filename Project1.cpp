#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

//setPixel function :stores current color setting into frame buffer at integer position (x, y).
void setPixel(GLint xCoordinate, GLint yCoordinate) {
	glBegin(GL_POINTS);
	glVertex2i(xCoordinate, yCoordinate);
	glEnd();
	glFlush(); //process all OpenGL functions as quickly as possible
}
//Mid point function
void MidPoint(GLint xc, GLint yc, GLint radius) {
	int x = 0, y = radius; int p = 1 - radius;

	//function 
	void PlotPoints(GLint, GLint, GLint, GLint);
	PlotPoints(xc, yc, x, y); //plot the initial point in each quadrant
	while (x < y) { //calculate the next point and plot in each octant
		x++;
		if (p < 0)
			p += 4 * x + 1;
		else {
			y--;
			p += 4 * (x - y) + 1;
		}
		PlotPoints(xc, yc, x, y);
	}
	//init function to intitlize Opengl
	void init(void) {
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glMatrixMode(GL_PROJECTION);
		gluOrtho2D(0.0, 300.0, 0.0, 300.0);
	}
	//draw function for crescent 
	void drawCrescent(void) {
		glClear(GL_COLOR_BUFFER_BIT); //to set a clear display window
		glPointSize(12); //set point (thickness) size

		glColor3f(1, 0.9, 0); //set pixel color to yellow
		MidPoint(150, 150, 40);
	}


	int main(int argc, char** argv) {
		glutInit(&argc, argv); //initialize GLUT
		glutInitWindowPosition(100, 100); //set top-left display window position
		glutInitWindowSize(800, 600); //set display window width and height 
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //set display mode
		glutCreateWindow("* Ramadan Mubarak *  -  Sahar Alrebdi");
		init();//execute initialization procedure of OpenGL
		glutDisplayFunc(drawCrescent);
		glutMainLoop();
		return 0;
	}