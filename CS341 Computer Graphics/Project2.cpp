#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble radius = 3;

void timer(int value) { //Timer Function 
    if (zRotated > 360.0) {
        zRotated -= 360.0 * floor(zRotated / 360.0); // Don't allow overflow
    }
    if (yRotated > 360.0) {
        yRotated -= 360.0 * floor(yRotated / 360.0); // Don't allow overflow
    }
    zRotated += 5.0;
    yRotated += 1.0;
    glutTimerFunc(16, timer, 0);
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDepthMask(GL_FALSE);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    // 2D rendering
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 640, 0, 480, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    {
        glColor3f(1.0, 1.0, 1.0); //set pixel color
        glPointSize(3);
        glBegin(GL_POINTS);
        for (int i = 1; i < 100; i++)
        {
            int x = rand() % 640;
            int y = rand() % 480;
            glVertex2i(x, y);
        }
        glEnd();
    }
    glPopMatrix();

    glDepthMask(GL_TRUE);
    glEnable(GL_DEPTH_TEST);

    // Rendering
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double w = glutGet(GLUT_WINDOW_WIDTH);
    double h = glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(20.0, w / h, 0.1, 80.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -40.0);

    glPushMatrix();
    {    glutSolidSphere(radius, 55, 55);}
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); //initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //set display mode
    glutInitWindowPosition(500, 100); //set top-left display window position
    glutInitWindowSize(850, 600); //set display window width and height 
    glutCreateWindow("Sahar's Project :Night Sky:"); // display window and title

    xRotated = yRotated = zRotated = 0.0;

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}