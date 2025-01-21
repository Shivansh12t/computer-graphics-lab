#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void initGL(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_MODELVIEW);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0f);
    float start_x = 100.0f;
    float start_y = 180.0f;
    float end_x = 500.0f;
    float end_y = 600.0f;
    float del_x = end_x - start_x;
    float del_y = end_y - start_y;
    
    int steps = (fabs(del_x) > fabs(del_y)) ? fabs(del_x) * 100 : fabs(del_y) * 100;

    float x_inc = del_x / steps;
    float y_inc = del_y / steps;
    float x = start_x;
    float y = start_y;

    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);

    for (int i = 0; i <= steps; i++){
        glVertex2d(x, y);
        x += x_inc;
        y += y_inc;
    }

    glEnd();
    glutSwapBuffers();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(800,600);
    glutCreateWindow("Line using DDA Algorithm & Absolute Coordinates");
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
    return 0;
}