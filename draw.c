#include "screencasts.h"

/*
 * drawAxes()
 * ------
 * Draw the axes
 */
void drawAxes() 
{
  if (toggleAxes) {
    /*  Length of axes */
    double len = 2.0;
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex3d(0,0,0);
    glVertex3d(len,0,0);
    glVertex3d(0,0,0);
    glVertex3d(0,len,0);
    glVertex3d(0,0,0);
    glVertex3d(0,0,len);
    glEnd();
    /*  Label axes */
    glRasterPos3d(len,0,0);
    print("X");
    glRasterPos3d(0,len,0);
    print("Y");
    glRasterPos3d(0,0,len);
    print("Z");
  }
}

/*
 *  drawValues()
 *  ------
 *  Draw the values in the lower left corner
 */
void drawValues()
{
  if (toggleValues) {
    glColor3f(0.8,0.8,0.8);
    printAt(5,5,"View Angle (th, ph) =(%d, %d)", th,ph);
    printAt(5,25,"Projection mode =(%s)", toggleMode?"Perspective":"Orthogonal");
  }
}

void drawScene()
{
  /*
  cube(1,0,1, 1,1,1, 0);
  cube(-1,0,1, 1,1,1, 0);
  cone(0,1,0, 1,1,DEF_D);
  cone(0,-1,0, 1,1,90);
  */

  /* a 'tower' */
  /*
  cube(0,1.5,0, 1,3,1, 0);
  cube(0,3.5,0, 2,1,2, 45);
  spike(0,1,-3.5, 0.5,1, 90, 90,0,0);
  spike(0,1,3.5, 0.5,1, 90, -90,0,0);
  spike(-3.5,1,0, 0.5,1, 90, 0,0,-90);
  spike(3.5,1,0, 0.5,1, 90, 0,0,90);
  */
  tower(0,0,0, 1,1,1, 0);
  tower(4,0,0, 1,1,1.5, 30);
}
