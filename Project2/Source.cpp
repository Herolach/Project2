
#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "math_3d.h"

GLuint VBO;

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT); //очистка буфера

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0); //как конвееру воспринимать данные внутри буфера

    glDrawArrays(GL_TRIANGLES, 0, 3); //функция отрисовки 

    glDisableVertexAttribArray(0); 

    glutSwapBuffers(); //меняет фоновый буфер и буфер кадра местами
}


static void CreateVertexBuffer()
{
    Vector3f Vertices[3];
    Vertices[0] = Vector3f(-1.0f, 1.0f, 0.0f);   //левый
    Vertices[1] = Vector3f(1.0f, 1.0f, 0.0f);    //правый
    Vertices[2] = Vector3f(0.0f, -1.0f, 0.0f);   //средний  

    glGenBuffers(1, &VBO); //создание объекта буфера    
    glBindBuffer(GL_ARRAY_BUFFER, VBO); //Связывание буфера 
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW); //запись данных вершин в буффер
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv); //иницализируем GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); //двойная буферизация и буфер цвета
    int width = 1200;
    int height = 600;
    glutInitWindowSize(width, height); //размер окна

    int x = 300;
    int y = 200;
    glutInitWindowPosition(x, y); //позиция окна
    int win = glutCreateWindow("LR1");


    GLenum res = glewInit();
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    } //инициализируем GLEW и проверяем на ошибки

    GLclampf Red = 0.4f, Green = 0.0f, Blue = 0.6f, Alpha = 0.0f; //цвет фона окна
    glClearColor(Red, Green, Blue, Alpha);

    CreateVertexBuffer();

    glutDisplayFunc(RenderSceneCB); //берет на взаимодействие с окном (отрисовка одного кадра)

    glutMainLoop(); //вызов передает управление GLUT'y

    return 0;
}


/*
#include <GL/freeglut.h>
#include <stdio.h>


static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);

    int width = 1200;
    int height = 700;
    glutInitWindowSize(width, height);

    int x = 200;
    int y = 100;
    glutInitWindowPosition(x, y);
    int win = glutCreateWindow("1");


    GLclampf Red = 0.0f, Green = 0.0f, Blue = 0.0f, Alpha = 0.0f;
    glClearColor(Red, Green, Blue, Alpha);

    glutDisplayFunc(RenderSceneCB);

    glutMainLoop();

    return 0;
}
*/
/*
#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "math_3d.h"

GLuint VBO;

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_POINTS, 0, 1);

    glDisableVertexAttribArray(0);

    glutSwapBuffers();
}


static void CreateVertexBuffer()
{
    Vector3f Vertices[1];
    Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    int width = 600;
    int height = 500;
    glutInitWindowSize(width, height);

    int x = 200;
    int y = 100;
    glutInitWindowPosition(x, y);
    int win = glutCreateWindow("2");


    GLenum res = glewInit();
    if (res != GLEW_OK) {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }

    GLclampf Red = 0.0f, Green = 0.0f, Blue = 0.0f, Alpha = 0.0f;
    glClearColor(Red, Green, Blue, Alpha);

    CreateVertexBuffer();

    glutDisplayFunc(RenderSceneCB);

    glutMainLoop();

    return 0;
}
*/
