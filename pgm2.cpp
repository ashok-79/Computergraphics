#include<GL/glut.h>
#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;
float theta;
float triangle[3][3]={{100,200,300},{100,300,100},{1,1,1}};
float rot[3][3]={{0},{0},{0}};
float result[3][3]={{0},{0},{0}};

void multiply()
{
    for(int i=0;i<3;i++)
    {

        for(int j=0;j<3;j++)
        {
            result[i][j]=0;
            for(int k=0;k<3;k++)
            {

                result[i][j]+=rot[i][k]*triangle[k][j];
            }

        }
    }



}
void trotate(int h,int k)
{
    rot[0][0]=cos(theta);
    rot[0][1]= -sin(theta);
    rot[0][2]=h*(1-(cos(theta)))+k*(sin(theta));

    rot[1][0]=sin(theta);
    rot[1][1]= cos(theta);
    rot[1][2]=k*(1-(cos(theta)))-h*(sin(theta));

    rot[2][0]=0;
    rot[2][1]= 0;
    rot[2][2]=1;

    multiply();

}
void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
        glVertex2f(triangle[0][0],triangle[1][0]);
        glVertex2f(triangle[0][1],triangle[1][1]);
        glVertex2f(triangle[0][2],triangle[1][2]);
    glEnd();
    trotate(0,0);
    glColor3f(0,1,0);
    glBegin(GL_TRIANGLES);
        glVertex2f(result[0][0],result[1][0]);
        glVertex2f(result[0][1],result[1][1]);
        glVertex2f(result[0][2],result[1][2]);
    glEnd();
    trotate(200,300);
    glColor3f(0,0,1);
    glBegin(GL_TRIANGLES);
        glVertex2f(result[0][0],result[1][0]);
        glVertex2f(result[0][1],result[1][1]);
        glVertex2f(result[0][2],result[1][2]);
    glEnd();

    glColor3f(1,1,0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
        glVertex2f(0,0);
    glEnd();
    glFlush();

}
void myinit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);
    glMatrixMode(GL_MODELVIEW);

}
int main(int argc,char **argv){
    cout<<"enter the values for theta"<<endl;
    cin>>theta;
    theta=theta*(3.14/180);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500,500);
    glutCreateWindow("Pivot point rotation");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}

