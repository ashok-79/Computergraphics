#include<stdio.h>
#include<stdlib.h>
using namespace std;
#include<iostream>
#include<GL/glut.h>
float v[8][3]={{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1},{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1}};
float theta[3]={0,0,0};
int axis=0;


void polygon(int a,int  b,int  c,int d)
{


    glBegin(GL_POLYGON);
        glVertex3fv(v[a]);
        glVertex3fv(v[b]);
        glVertex3fv(v[c]);
        glVertex3fv(v[d]);
    glEnd();
}


void cube()
{
    glColor3f(1,0,0);
    polygon(0,1,5,4);

    glColor3f(0,1,0);
    polygon(3,2,6,7);

    glColor3f(0,0,1);
    polygon(0,3,7,4);

    glColor3f(1,1,0);
    polygon(1,2,6,5);

    glColor3f(1,0,1);
    polygon(0,1,2,3);

    glColor3f(0,1,1);
    polygon(4,5,6,7);


}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
    glClearColor(1,1,1,1);
    glLoadIdentity();

    glRotatef(theta[0],1,0,0);
    glRotatef(theta[1],0,1,0);
    glRotatef(theta[2],0,0,1);

    cube();
    glutSwapBuffers();
    glFlush();


}

void spin()
{
    theta[axis]+=0.1;
    if(theta[axis]>360)
        theta[axis]=0;
    glutPostRedisplay();

}
void mouse(int button,int status,int x,int y)
{
    if(button==GLUT_RIGHT_BUTTON && status==GLUT_DOWN) axis=0;

    if(button==GLUT_LEFT_BUTTON && status==GLUT_DOWN) axis=1;

    if(button==GLUT_MIDDLE_BUTTON && status==GLUT_DOWN) axis=2;

   // glutPostRedisplay();

}
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glOrtho(-2,2,-2,2,-2,2);
    glMatrixMode(GL_MODELVIEW);

}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("spinning cube");
    myinit();
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMouseFunc(mouse);
    glutIdleFunc(spin);
    glutMainLoop();
    return 0;

}
