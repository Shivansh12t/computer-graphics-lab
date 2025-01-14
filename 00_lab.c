#include <stdio.h>
#include <GL/glut.h>

void initGL(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);                  
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); 
    glutInitWindowSize(800, 600); 
    glutCreateWindow("simple window"); 
    glutDisplayFunc(display);  
    initGL();   
    glutMainLoop();    
    return 0;
}