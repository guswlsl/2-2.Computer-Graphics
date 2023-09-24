#include <OpenGL/gl.h>
#include <GLUT/glut.h>

using namespace std;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glBegin(GL_TRIANGLES);
        glVertex3f(0.5f, 0.6f, 0.0f);
        glVertex3f(1.0f, 0.6f, 0.0f);
        glVertex3f(0.75f, 1.0f, 0.0f);
    glEnd();
    
    glBegin(GL_LINES);
        glVertex3f(-0.8f, -0.5f, 0.0f);
        glVertex3f(-0.1f, -0.5f, 0.0f);
    glEnd();
    
    glBegin(GL_LINES);
        glVertex3f(-0.8f, -0.8f, 0.0f);
        glVertex3f(-0.1f, -0.8f, 0.0f);
    glEnd();
    
    glBegin(GL_LINE_STRIP);
        glVertex3f(0.3f, -0.5f, 0.0f);
        glVertex3f(0.8f, -0.5f, 0.0f);
        glVertex3f(0.8f, -0.8f, 0.0f);
        glVertex3f(0.3f, -0.8f, 0.0f);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
        glVertex3f(0.2f, 0.0f, 0.0f);
        glVertex3f(0.3f, 0.3f, 0.0f);
        glVertex3f(0.05f, 0.5f, 0.0f);
        glVertex3f(-0.2f, 0.3f, 0.0f);
        glVertex3f(-0.1f, 0.0f, 0.0f);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
        glVertex3f(-0.5f, 0.58f, 0.0f);
        glVertex3f(-0.55f, 0.73f, 0.0f);
        glVertex3f(-0.4f, 0.82f, 0.0f);
        glVertex3f(-0.59f, 0.86f, 0.0f);
        glVertex3f(-0.67f, 1.0f, 0.0f);
        glVertex3f(-0.76f, 0.86f, 0.0f);
        glVertex3f(-0.95f, 0.82f, 0.0f);
        glVertex3f(-0.8f, 0.73f, 0.0f);
        glVertex3f(-0.85f, 0.58f, 0.0f);
        glVertex3f(-0.67f, 0.68f, 0.0f);
    glEnd();
    
    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
    glutCreateWindow("이현진");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
