#include<stdio.h>
#include<iostream>
using namespace std;
#include<GL/glut.h>

class point{
    public:float x,y;
};
int flag=0;
point p1={100,200},p2={200,100},p3={300,200},p4={200,300};
float le[500],re[500];
void edge_detect(point a,point b)
{
    if(a.y>b.y)
        swap(a,b);
    float dx=b.x-a.x;
    float dy=b.y-a.y;
    float mx;
    if(dy!=0)
        mx=dx/dy;
    else
        mx=dx;
        int x=a.x,y=a.y;
    while(y<=b.y)
    {
        if(x<le[y])
            le[y]=x;
        if(x>re[y])
        re[y]=x;
        y++;
        x+=mx;
    }

}
void scanfill(point p1,point p2,point p3,point p4)
{
    for(int i=0;i<500;i++)
    {

        le[i]=500;
        re[i]=0;
    }
    edge_detect(p1,p2);
    edge_detect(p2,p3);
    edge_detect(p3,p4);
    edge_detect(p4,p1);
    glBegin(GL_POINTS);
    for(int y=0;y<500;y++)
    {

        if(le[y]<=re[y])
        {

            for(int x=le[y];x<=re[y];x++)
            {
                glVertex2i(x,y);
            }
        }
    }
    glEnd();


}
void display(){
 glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,0);
    if(flag==1)
        scanfill(p1,p2,p3,p4);
        glBegin(GL_LINE_LOOP);
            glVertex2f(p1.x,p1.y);
            glVertex2f(p2.x,p2.y);
            glVertex2f(p3.x,p3.y);
            glVertex2f(p4.x,p4.y);
        glEnd();
        glFlush();

}
void menu(int id)
{
    switch(id)
    {
        case 1:flag=1;
                break;
        case 0:flag=0;
                break;

    }
    glutPostRedisplay();

}

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,500,0,500);
    glMatrixMode(GL_MODELVIEW);

}
int main(int argc,char **argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("scan line filling!!");
    glutDisplayFunc(display);
    glutCreateMenu(menu);
    glutAddMenuEntry("Fill",1);
    glutAddMenuEntry("Clear",0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    myinit();
    glutMainLoop();
    return 0;

}

