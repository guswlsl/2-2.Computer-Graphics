#include <OpenGL/gl.h>
#include <GLUT/glut.h>

using namespace std;

GLfloat blueAngle = 0.0f;

void display(void)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();

// red circle
glColor3f(1.0f, 0.0f, 0.0f);    // red
glutSolidSphere(0.1f, 100, 100);

// 기준점 red
glPushMatrix();
    
//new yellow circle
glRotatef(1-blueAngle, 0.0f, 0.0f, 1.0f);
glTranslatef(0.25f, 0.0f, 0.0f);
glColor3f(1.0f, 1.0f, 0.0f);    // yellow
glutSolidSphere(0.05f, 100, 100);

//new pink circle
glRotatef(1-blueAngle, 0.0f, 0.0f, 1.0f);
glTranslatef(0.1f, 0.0f, 0.0f);
glColor3f(1.0f, 0.2f, 1.0f);    // pink
glutSolidSphere(0.03f, 100, 100);
glPopMatrix();

// blue circle
glRotatef(blueAngle, 0.0f, 0.0f, 1.0f);
glTranslatef(0.6f, 0.0f, 0.0f);
glColor3f(0.0f, 0.0f, 1.0f);    // blue
glutSolidSphere(0.05f, 100, 100);

    
glPushMatrix();
//중심 blue
glRotatef(1-blueAngle, 0.0f, 0.0f, 1.0f);
glTranslatef(0.1f, 0.0f, 0.0f);
glColor3f(0.0f, 0.0f, 0.0f);    // black
glutSolidSphere(0.03f, 100, 100);
glPopMatrix();

glRotatef(blueAngle, 0.0f, 0.0f, 1.0f);
glTranslatef(0.3f, 0.0f, 0.0f);
glColor3f(0.0f, 1.0f, 0.0f);    // green
glutSolidSphere(0.05f, 100, 100);

glRotatef(blueAngle, 0.0f, 0.0f, 1.0f);
glTranslatef(0.1f, 0.0f, 0.0f);
glColor3f(0.0f, 1.0f, 0.8f);    // skygreen
glutSolidSphere(0.03f, 100, 100);

    
blueAngle += 0.8f;
if(blueAngle == 360) blueAngle=0;
glFlush();
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);

glutInitDisplayMode(GLUT_RGBA |     GLUT_DEPTH | GLUT_SINGLE);
glutCreateWindow("20221406 이현진");
    
glClearColor(1.0, 1.0, 1.0, 0.0);

glutDisplayFunc(display);
glutIdleFunc(display);

glutMainLoop();

return 0;
}
