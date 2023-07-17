#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<GL/glut.h>
using namespace std;
int m=0;
typedef GLfloat point[3];
point v[]={{0,0,1},{-1,-1,0},{0,1,0},{1,-1,0}};

void triangle(point a,point b,point c)
{
    glBegin(GL_TRIANGLES);
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(c);
    glEnd();

}
void divide_triangle(point a,point b,point c,int k)
{
    if(k>1)
    {
        point v1,v2,v3;
        for(int i=0;i<3;i++)
        {
            v1[i]=(a[i]+b[i])/2;
            v2[i]=(a[i]+c[i])/2;
            v3[i]=(b[i]+c[i])/2;

        }
        divide_triangle(a,v1,v2,k-1);
         divide_triangle(b,v1,v3,k-1);
          divide_triangle(c,v2,v3,k-1);


    }
    else{
        triangle(a,b,c);
    }

}
void tetrahedron(int m)
{
    glColor3f(1,0,0);
    divide_triangle(v[1],v[2],v[3],m);
    glColor3f(0,1,0);
    divide_triangle(v[0],v[1],v[2],m);
    glColor3f(0,0,1);
    divide_triangle(v[0],v[1],v[3],m);
    glColor3f(1,1,0);
    divide_triangle(v[0],v[2],v[3],m);

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
    tetrahedron(m);

    glBegin(GL_POINTS);
    glVertex3f(0,0,0);
    glEnd();
    glFlush();



}
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2,2,-2,2,-2,2);
    glMatrixMode(GL_MODELVIEW);


}
int main(int argc,char **argv)
{
    cout<<"Enter the number of stages:"<<endl;
    cin>>m;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB |GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("sipherski gasket");
    myinit();
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
