#include <OpenGL/gl.h>
#include <GLUT/glut.h>

using namespace std;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Red Cube
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCube(0.3);
    glPushMatrix();

    // Green Cube 이동
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glTranslatef(0.6, 0.0, 0.0);

    // Green Cube
    glColor3f(0.0, 1.0, 0.0);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    
    // Gray Cube 이동
    glRotatef(-45.0, 0.0, 0.0, 1.0);
    glTranslatef(-0.6, 0.0, 0.0);
    
    // Gray Cube
    glColor3f(0.5, 0.5, 0.5);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    
    // Yellow Cube 이동
    glRotatef(-45.0, 0.0, 0.0, 1.0);
    glTranslatef(0.6, 0.0, 0.0);
    
    // Yellow Cube
    glColor3f(1.0, 1.0, 0.0);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    
    // Pink Cube 이동
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glTranslatef(-0.6, 0.0, 0.0);
    
    // Pink Cube
    glColor3f(1.0, 0.3, 1.0);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    
    // Blue Cube 이동
    glTranslatef(0.6, 0.0, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);
    
    // Blue Cube
    glColor3f(0.0, 0.0, 1.0);
    glutSolidCube(0.3);
    glPopMatrix();
    glPushMatrix();
    
    // SkyBlue Cube 이동
    glTranslatef(0.8, -0.8, 0.0);
    
    // SkyBlue Cube
    glColor3f(0.0, 1.0, 1.0);
    glutSolidCube(0.3);
    
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_SINGLE);
    glutCreateWindow("20221406 이현진");

    glClearColor(1.0, 1.0, 1.0, 0.0);
    
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
