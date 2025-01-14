#include <stdio.h>
#include <GL/glut.h>

void initGL(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES); // Start drawing lines
        glColor3f(0.0f, 1.0f, 0.0f); // Set line color to green
        glVertex2f(-0.9f, -0.9f);    // Point 1 (normalized coordinates)
        glVertex2f(0.7f, -0.7f);    // Point 2
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);                  
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
    glutInitWindowSize(800, 600); 
    glutCreateWindow("green line"); 
    glutDisplayFunc(display);  
    initGL();   
    glutMainLoop();    
    return 0;
}