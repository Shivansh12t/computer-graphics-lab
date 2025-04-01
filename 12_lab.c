#include <stdio.h>
#include <GL/glut.h>

float angle = 0.0f;
float height = 0.0f;
int stage = 0;
int rotations = 0;

void initGL(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glPointSize(5.0f);
    glTranslatef(0.0f,0.0f,-2.0f);

    // configurations
    if (stage == 0){
        glTranslatef(0.0f, height, -2.0f);
    }
    if (stage == 1){
        glTranslatef(0.0f, 0.7f, -2.0f);
        glRotatef(angle, 0.0f, 1.0f, 1.0f);
        glScalef(2.0f, 2.0f, 2.0f);
    }
    if (stage == 2){
        glTranslatef(0.0f, height, -2.0f);
    }

    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-0.15f, -0.15f,  0.15f); // Bottom-left
    glVertex3f( 0.15f, -0.15f,  0.15f); // Bottom-right
    glVertex3f( 0.15f,  0.15f,  0.15f); // Top-right
    glVertex3f(-0.15f,  0.15f,  0.15f); // Top-left

    // Back face
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.15f, -0.15f, -0.15f); // Bottom-left
    glVertex3f( 0.15f, -0.15f, -0.15f); // Bottom-right
    glVertex3f( 0.15f,  0.15f, -0.15f); // Top-right
    glVertex3f(-0.15f,  0.15f, -0.15f); // Top-left

    // Left face
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.15f, -0.15f, -0.15f); // Bottom-back
    glVertex3f(-0.15f, -0.15f,  0.15f); // Bottom-front
    glVertex3f(-0.15f,  0.15f,  0.15f); // Top-front
    glVertex3f(-0.15f,  0.15f, -0.15f); // Top-back

    // Right face
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f( 0.15f, -0.15f, -0.15f); // Bottom-back
    glVertex3f( 0.15f, -0.15f,  0.15f); // Bottom-front
    glVertex3f( 0.15f,  0.15f,  0.15f); // Top-front
    glVertex3f( 0.15f,  0.15f, -0.15f); // Top-back

    // Top face
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-0.15f,  0.15f, -0.15f); // Bottom-left
    glVertex3f( 0.15f,  0.15f, -0.15f); // Bottom-right
    glVertex3f( 0.15f,  0.15f,  0.15f); // Top-right
    glVertex3f(-0.15f,  0.15f,  0.15f); // Top-left

    // Bottom face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-0.15f, -0.15f, -0.15f); // Bottom-left
    glVertex3f( 0.15f, -0.15f, -0.15f); // Bottom-right
    glVertex3f( 0.15f, -0.15f,  0.15f); // Top-right
    glVertex3f(-0.15f, -0.15f,  0.15f); // Top-left
    glEnd();

    glutSwapBuffers();
}

void update(int value){
    if (stage == 0){
        if (height < 0.7f){
            height += 0.05f;
        } else {
            stage = 1;
        }
    }
    if (stage == 1){
        angle += 10.0f;
        if (angle > 360.0f){
            rotations += 1;
            angle -= 360.0f;
        } if (rotations == 5){
            rotations = 0;
            stage = 2;
        }
    }
    if (stage == 2){
        if (height > 0.0f){
            height -= 0.05f;
        } else {
            stage = 0;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void reshape(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D transformations");

    initGL();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(25, update, 0);
    glutMainLoop();

    return 0;
}
