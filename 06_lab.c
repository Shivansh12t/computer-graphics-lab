#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

void initGL(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0f);

    float start_x = -0.3f;
    float start_y = -0.4f;
    float end_x = 0.5f;
    float end_y = 0.8f;

    float del_x = end_x - start_x;
    float del_y = end_y - start_y;

    int steps = (fabs(del_x) > fabs(del_y)) ? fabs(del_x) * 100 : fabs(del_y) * 100;  // Increase precision
    float x_inc = del_x / steps;
    float y_inc = del_y / steps;

    float x = start_x;
    float y = start_y;

    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i <= steps; i++){
        glVertex2f(x, y);
        x += x_inc;
        y += y_inc;
    }
    glEnd();
    
    glutSwapBuffers();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Algorithm in OpenGL");
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
    return 0;
}
