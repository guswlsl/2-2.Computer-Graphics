#include <iostream>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <math.h>
using namespace std;

#define PI 3.141592

int shoulder = 0, elbow = 0, wrist = 0, neck = 0, bodyX = 0, bodyY = 0, bodyZ = 0, leg = 0;
int bodyRotateX = 0, bodyRotateY = 0, bodyRotateZ = 0;

void drawAxes() {
    glBegin(GL_LINES);
    
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, -1.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    
    glEnd();
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glLoadIdentity();
    drawAxes();
    
    glTranslatef(bodyX, bodyY, bodyZ);
        glRotatef(bodyRotateX, 1.0, 0.0, 0.0);
        glRotatef(bodyRotateY, 0.0, 1.0, 0.0);
        glRotatef(bodyRotateZ, 0.0, 0.0, 1.0);

    // 몸통
    glPushMatrix();
    glScalef(0.5, 0.5, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    glutSolidCube(1.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();
    
    // 오른쪽 팔
    glPushMatrix();
    glTranslatef(0.25, 0.2, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.4, 0.1, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCube(1.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();

    // 오른쪽 팔
    glPushMatrix();
    glTranslatef(0.2, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 1.0);
    glColor3f(1.0, 1.0, 0.0);
    glutSolidCube(1.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();

    // 손목
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.1, 0.1, 1.0);
    glColor3f(0.0, 1.0, 1.0);
    glutSolidCube(1.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
    
    // 왼쪽 팔
    glPushMatrix();
    glTranslatef(-0.25, 0.2, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(-0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.4, 0.1, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCube(1.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();

    // 왼쪽 팔
    glPushMatrix();
    glTranslatef(-0.2, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(-0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 1.0);
    glColor3f(1.0, 1.0, 0.0);
    glutSolidCube(1.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();

    // 왼쪽 손목
    glTranslatef(-0.15, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
    glPushMatrix();
    glScalef(0.1, 0.1, 1.0);
    glColor3f(0.0, 1.0, 1.0);
    glutSolidCube(1.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();


    // 머리
    glPushMatrix();
    glTranslatef(0.0, 0.42, 0.0);
    glRotatef((GLfloat)neck, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.02, 0.0);
    glScalef(0.2, 0.2, 1.0);
    glColor3f(1.0, 1.0, 0.0);
    glutSolidSphere(1.0,10.0,10.0);
    glColor3f(0.0, 0.0, 0.0);
    glPopMatrix();
    
    // 왼쪽 다리
    glPushMatrix();
    glTranslatef(-0.2, -0.2, 0.0);
    glRotatef((GLfloat)leg, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -0.2, 0.0);
    glPushMatrix();
    glScalef(0.1, 0.4, 1.0);
    glColor3f(0.0, 1.0, 0.0);
    glutSolidCube(1.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();

    // 왼쪽 다리
    glPushMatrix();
    glTranslatef(0.0, -0.2, 0.0);
    glRotatef((GLfloat)neck, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -0.15, 0.0);
    glPushMatrix();
    glScalef(0.1, 0.3, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    glutSolidCube(1.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    // 오른쪽 다리
    glPushMatrix();
    glTranslatef(0.2, -0.2, 0.0);
    glRotatef((GLfloat)leg, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -0.2, 0.0);
    glPushMatrix();
    glScalef(0.1, 0.4, 1.0);
    glColor3f(0.0, 1.0, 0.0);
    glutSolidCube(1.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();

    // 오른쪽 다리
    glPushMatrix();
    glTranslatef(0.0, -0.2, 0.0);
    glRotatef((GLfloat)neck, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -0.15, 0.0);
    glPushMatrix();
    glScalef(0.1, 0.3, 1.0);
    glColor3f(0.0, 0.0, 1.0);
    glutSolidCube(1.0);
    glColor3f(0.0, 0.0, 0.0);
    glutWireCube(1.0);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

    
    // Wrist
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
    
    glPopMatrix();

    glPopMatrix();
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's': shoulder = (shoulder + 5) % 360; break;
    case 'S': shoulder = (shoulder - 5) % 360; break;
    case 'e': elbow = (elbow + 5) % 360; break;
    case 'E': elbow = (elbow - 5) % 360; break;
    case 'w': wrist = (wrist + 5) % 360; break;
    case 'W': wrist = (wrist - 5) % 360; break;
    case 'n': neck = (neck + 5) % 360; break;
    case 'N': neck = (neck - 5) % 360; break;
                case 't': bodyRotateX = (bodyRotateX + 5) % 360; break;
                case 'T': bodyRotateX = (bodyRotateX - 5) % 360; break;
    case 'l': leg = (leg + 5) % 360; break;
    case 'L': leg = (leg - 5) % 360; break;
    default: break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
