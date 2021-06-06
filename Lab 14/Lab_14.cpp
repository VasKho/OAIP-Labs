#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "stb_image/stb_image.h"

GLuint VBO;
GLuint prog;
GLuint offsetLoc;

void init();
void render_Scene();
void CreateTexture();

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(900, 700);
    glutInitWindowPosition(500, 300);
    glutCreateWindow("Lab_14");
    glewInit();
    CreateTexture();
    init();
    glutDisplayFunc(render_Scene);
    glutMainLoop();
    return 0;
}

void CreateTexture()
{
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    unsigned char *data = stbi_load("./source/wood.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Failed to load texture");
        exit(1);
    }
    stbi_image_free(data);
}

void Compute_Offsets(float* a, float* b)
{
    float time = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    float loopDuration = 10.0;
    float angle = fmodf(time, loopDuration) / loopDuration * 2 * 3.14;
    float radius = 0.5;
    *a = cosf(angle) * radius;
    *b = sinf(angle) * radius;
}

void render_Scene() 
{
    float x, z;
    Compute_Offsets(&x, &z);
    glClearColor(0.3f, 0.4f, 0.4f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(prog);
    glUniform2f(offsetLoc, x, z);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*) 36);
	glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glUseProgram(0);
	glutSwapBuffers();
    glutPostRedisplay();
}

char *readFile(const char *fileName) {
    FILE *f = fopen(fileName, "rb");
    if (!f) {
        perror("fopen failed");
        exit(1);
    }
    if (fseek(f, 0, SEEK_END) == -1) {
        printf("fseek failed");
        exit(1);
    }
    long len = ftell(f);
    if (len == -1) {
        printf("ftell failed");
        exit(1);
    }
    if (fseek(f, 0, SEEK_SET) == -1) {
        printf("fseek failed");
        exit(1);
    }
    char *res = (char*)malloc(len + 1);
    if (!res) {
        printf("malloc failed\n");
        exit(1);
    }
    fread(res, 1, len, f);
    if (fclose(f) == EOF) {
        printf("fclose failed");
        exit(1);
    }
    res[len] = 0;
    return res;
}

void Create_Buffer()
{
    float vert[] = {
        -0.25, -0.25, 0.0,
        0.0, 0.25, 0.0,
        0.25, -0.25, 0.0,

        0.0, -1.0,
        0.0, 1.0,
        1.0, -1.0,
    };
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);
}

void createProg(GLuint* shaders, int len)
{
    int i = 0;
    prog = glCreateProgram();
    if (!prog)
    {
        printf("Failed to create program!");
        exit(1);
    }
    for (; i < len; i++) glAttachShader(prog, shaders[i]);
    glLinkProgram(prog);
    GLint status;
    glGetProgramiv(prog, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        printf("Linking error!");
        exit(1);
    }
}

GLuint createShader(const char* shaderFile, GLenum ShaderType)
{
    const char* strShaderType;
    if (ShaderType == GL_VERTEX_SHADER) strShaderType = "vertex";
    else if (ShaderType == GL_GEOMETRY_SHADER) strShaderType = "geometry";
    else if (ShaderType == GL_FRAGMENT_SHADER) strShaderType = "fragment";
    else
    {
        printf("Unrecognized shader type!\n");
        exit(1);
    }
    GLuint shader = glCreateShader(ShaderType);
    GLchar* content = readFile(shaderFile);
    glShaderSource(shader, 1, (const GLchar**) &content, NULL);
    free(content);
    glCompileShader(shader);
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status != GL_FALSE) return shader;
    else
    {
        printf("Compile error!");
        exit(1);
    }
}

void init()
{
    Create_Buffer();
    GLuint shaders[] = {
        createShader("./shaders/shader.vs", GL_VERTEX_SHADER),
        createShader("./shaders/shader.fs", GL_FRAGMENT_SHADER)
    };
    int len = sizeof(shaders) / sizeof(shaders[0]);
    createProg(shaders, len);
    int i = 0;
    for (; i < len; i++) glDeleteShader(shaders[i]);

    offsetLoc = glGetUniformLocation(prog, "offset");
}