#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

// Function to draw symmetric points
void plotSymmetricPoints(float xc, float yc, int x, int y) {
    glVertex2f(xc + x / 100.0f, yc + y / 100.0f);
    glVertex2f(xc - x / 100.0f, yc + y / 100.0f);
    glVertex2f(xc + x / 100.0f, yc - y / 100.0f);
    glVertex2f(xc - x / 100.0f, yc - y / 100.0f);
    glVertex2f(xc + y / 100.0f, yc + x / 100.0f);
    glVertex2f(xc - y / 100.0f, yc + x / 100.0f);
    glVertex2f(xc + y / 100.0f, yc - x / 100.0f);
    glVertex2f(xc - y / 100.0f, yc - x / 100.0f);
}

// Initialize OpenGL
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Black background
}

// Circle drawing using midpoint algorithm
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0f);

    float xc = 0.0f;  // Circle center X-coordinate
    float yc = 0.0f;  // Circle center Y-coordinate
    int r = 50;       // Circle radius in "pixels"

    int x = 0;
    int y = r;
    int p = 1 - r;  // Initial decision parameter

    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);

    // Plot initial point
    plotSymmetricPoints(xc, yc, x, y);

    // Midpoint circle algorithm
    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * x - 2 * y + 1;
        }
        plotSymmetricPoints(xc, yc, x, y);
    }

    glEnd();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Algorithm in OpenGL");
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
    return 0;
}
