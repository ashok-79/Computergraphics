#include<stdio.h>
#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;
float m,xa,xb,ya,yb;
void drawpixel(float x,float y)
{
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();

}
void slope_less(float xa,float ya,float xb,float yb)
{
    int  temp;
    if(xa>xb)
    {
        swap(xa,xb);
        swap(ya,yb);

    }
    int dx=abs(xb-xa);
    int dy=abs(yb-ya);
    int p=2*dy-dx;
    int pp=2*(dy-dx);
    int pn=2*dy;
    int x=xa;
    int y=ya;
    drawpixel(x,y);
    while(x<=xb)
    {
        x++;
        if(p<0)
        {
            p+=pn;

        }
        else{
            p+=pp;
            if(m>0)y++;
            else
                y--;
        }
        drawpixel(x,y);

    }


}
void slope_greater(float xa,float ya,float xb,float yb)
{
    int  temp;
    if(ya>yb)
    {
        swap(xa,xb);
        swap(ya,yb);

    }
    int dx=abs(xb-xa);
    int dy=abs(yb-ya);
    int p=2*dx-dy;
    int pp=2*(dx-dy);
    int pn=2*dx;
    int x=xa;
    int y=ya;
    while(y<=yb)
    {
        y++;
        if(p<0)
        {
            p+=pn;

        }
        else{
            p+=pp;
            if(m>0)x++;
            else
                x--;
        }
        drawpixel(x,y);

    }

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0.3,0.7);
    if(abs(m)<1)
        slope_less(xa,ya,xb,yb);
    else
        slope_greater(xa,ya,xb,yb);
        glColor3f(0.2,0.5,0.7);
    glPointSize(4.0);
    drawpixel(xa,ya);
    drawpixel(xb,yb);
    glFlush();

}
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);

}
int main(int argc,char **argv)
{
    cout<<"enter the values for xa,ya,xb,yb"<<endl;
    cin>>xa>>ya>>xb>>yb;
    m=(yb-ya)/(xb-xa);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Bresenhams line drawing algo");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}
