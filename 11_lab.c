#include <stdio.h>
#include <GL/glut.h>

typedef struct {
    int x, y;
} Point;

// Define the polygon vertices
Point polygon[] = {
    {100, 100},
    {400, 100},
    {400, 200},
    {300, 300},
    {150, 300},
    {150, 500},
    {300, 500},
    {300, 600},
    {100, 600},
};
int numVertices = 9;

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    gluOrtho2D(0, 800, 0, 600);
}

// Function to draw the polygon outline
void drawPolygonOutline() {
    glLineWidth(3.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < numVertices; i++) {
        glVertex2i(polygon[i].x, polygon[i].y);
    }
    glEnd();
}

void scanLineFill() {
    int minY = polygon[0].y, maxY = polygon[0].y;

    for (int i = 1; i < numVertices; i++) {
        if (polygon[i].y < minY) minY = polygon[i].y;
        if (polygon[i].y > maxY) maxY = polygon[i].y;
    }

    for (int y = minY; y <= maxY; y++) {
        int intersectionX[10], count = 0;

        for (int i = 0; i < numVertices; i++) {
            int j = (i + 1) % numVertices;
            int y1 = polygon[i].y, y2 = polygon[j].y;
            int x1 = polygon[i].x, x2 = polygon[j].x;

            if (y1 != y2) {
                if ((y >= y1 && y <= y2) || (y >= y2 && y <= y1)) {
                    int x = x1 + (y - y1) * (x2 - x1) / (y2 - y1);
                    intersectionX[count++] = x;
                }
            }
        }

        // Sort intersection points
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (intersectionX[j] > intersectionX[j + 1]) {
                    int temp = intersectionX[j];
                    intersectionX[j] = intersectionX[j + 1];
                    intersectionX[j + 1] = temp;
                }
            }
        }

        // Fill between pairs of intersections
        glColor3f(1.0f, 0.0f, 0.0f); // Set red color
        glBegin(GL_POINTS);
        for (int i = 0; i < count; i += 2) {
            if (i + 1 < count) {
                for (int x = intersectionX[i]; x <= intersectionX[i + 1]; x++) {
                    glVertex2i(x, y);
                }
            }
        }
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    scanLineFill();       // Fill polygon with red color
    drawPolygonOutline(); // Draw polygon border in white

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Scan Line Fill Algorithm");

    initGL();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}