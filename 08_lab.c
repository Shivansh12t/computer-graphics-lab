#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

#define TOLERANCE 0.005

int onCircle(float x, float y, float x_center, float y_center, float r){
    if (fabs(pow(x - x_center, 2) + pow(y - y_center, 2) - pow(r, 2)) <= TOLERANCE){
        return 1;
    } else return 0;
}

void initGL(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// circle drawing algorithm
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0f);

    float x_center = 0.0f;
    float y_center = 0.0f;
    float r = 0.25f;
    float step = 0.01;

    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (float x = x_center; x < x_center + r; x += step){
        for (float y = y_center; y < y_center + r; y += step){
            if (onCircle(x, y, x_center, y_center, r)){
                glVertex2f(x, y);
                glVertex2f(-x + 2 * x_center, y);
                glVertex2f(x, -y + 2 * y_center);
                glVertex2f(-x + 2 * x_center, -y + 2 * y_center);
            }
        }
    }
    
    glEnd();
    
    glutSwapBuffers();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Logical Circle Drawing Algorithm in OpenGL");
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
    return 0;
}
