#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#ifndef _GRAPH_H_
#define _GRAPH_H_
void Draw_Graph(int*, char**, float*, double*, int);
GLuint createShader(const char*, GLenum);
void createProg(GLuint*, int);
char *readFile(const char*);
void Create_Buffer(float*, double*, int);
void init(float*, double*, int);
#endif