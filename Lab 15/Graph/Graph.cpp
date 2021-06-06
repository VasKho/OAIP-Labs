#include "Graph.h"

GLuint prog;
GLuint VBO;
double vert[160];

void display();


void Draw_Graph(int* argc, char** argv, float* x, double* y, int num_of_vetr)
{
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(500, 300);
    glutCreateWindow("Graph");
    glewInit();
    Create_Buffer(x, y, num_of_vetr);
    glutDisplayFunc(display);
    glutMainLoop();
}

void display()
{
    glLineWidth(1);
    glBegin(GL_LINES);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(-0.95, 0.0, 0.0);
        glVertex3f(0.95, 0.0, 0.0);
        glVertex3f(0.0, 0.95, 0.0);
        glVertex3f(0.0, -0.95, 0.0);

        glVertex3f(0.95, 0.0, 0.0);
        glVertex3f(0.90, 0.02, 0.0);
        glVertex3f(0.95, 0.0, 0.0);
        glVertex3f(0.90, -0.02, 0.0);

        glVertex3f(0.0, 0.95, 0.0);
        glVertex3f(0.02, 0.90, 0.0);
        glVertex3f(0.0, 0.95, 0.0);
        glVertex3f(-0.02, 0.90, 0.0);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glColor3f(1.0, 0.0, 0.0);
        for (int i = 0; i < 160; i += 2) 
            glVertex3f(vert[i] / 20, vert[i + 1] / 20, 0.0);
    glEnd();
    glutSwapBuffers();
}

void Create_Buffer(float* x, double* y, int num_of_vetr)
{
    int pos = 0;
    for(int i = 0; i < 160; i += 2)
    {
        vert[i] = x[pos];
        vert[i + 1] = y[pos];
        pos++;
    }
}