#include <stdio.h>
#include <GL/glut.h>

void initGL(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10.0f);
    glBegin(GL_POINTS);
        glColor3f(1.0f, 0.0f, 0.0f); // set point color to red
        glVertex2f(0.0f, 0.0f); // center of the window
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);                  
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
    glutInitWindowSize(800, 600); 
    glutCreateWindow("point of width 10px"); 
    glutDisplayFunc(display);  
    initGL();   
    glutMainLoop();    
    return 0;
}