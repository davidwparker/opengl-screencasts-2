#include "screencasts.h"

/*
 *  cube
 *  ------
 *  Draw a cube
 *     at (x,y,z)
 *     dimensions (dx,dy,dz)
 *     rotated th about the y axis
 */
void cube(double x,double y,double z,
	  double dx,double dy,double dz,
	  double th)
{
  /*  Cube vertices */
  GLfloat vertA[3] = { 0.5, 0.5, 0.5};
  GLfloat vertB[3] = {-0.5, 0.5, 0.5};
  GLfloat vertC[3] = {-0.5,-0.5, 0.5};
  GLfloat vertD[3] = { 0.5,-0.5, 0.5};
  GLfloat vertE[3] = { 0.5, 0.5,-0.5};
  GLfloat vertF[3] = {-0.5, 0.5,-0.5};
  GLfloat vertG[3] = {-0.5,-0.5,-0.5};
  GLfloat vertH[3] = { 0.5,-0.5,-0.5};

  glPushMatrix();
  /*  Transform cube */
  glTranslated(x,y,z);
  glRotated(th,0,1,0);
  glScaled(dx,dy,dz);

  /* Cube */
  glBegin(GL_QUADS);
  /* front => ABCD yellow */
  glColor3f(1.0,1.0,0.0);
  glVertex3fv(vertA);
  glVertex3fv(vertB);
  glVertex3fv(vertC);
  glVertex3fv(vertD);
  /* back => FEHG red */
  glColor3f(1.0,0.0,0.0);
  glVertex3fv(vertF);
  glVertex3fv(vertE);
  glVertex3fv(vertH);
  glVertex3fv(vertG);
  /* right => EADH green */
  glColor3f(0.0,1.0,0.0);
  glVertex3fv(vertE);
  glVertex3fv(vertA);
  glVertex3fv(vertD);
  glVertex3fv(vertH);
  /* left => BFGC blue */
  glColor3f(0.0,0.0,1.0);
  glVertex3fv(vertB);
  glVertex3fv(vertF);
  glVertex3fv(vertG);
  glVertex3fv(vertC);
  /* top => EFBA turquoise */
  glColor3f(0.0,1.0,1.0);
  glVertex3fv(vertE);
  glVertex3fv(vertF);
  glVertex3fv(vertB);
  glVertex3fv(vertA);
  /* bottom => DCGH pink */
  glColor3f(1.0,0.0,1.0);
  glVertex3fv(vertD);
  glVertex3fv(vertC);
  glVertex3fv(vertG);
  glVertex3fv(vertH);
  glEnd();

  glPopMatrix();
}

/*
 *  cone
 *  ------
 *  Draws a cone
 *     at (x,y,z)
 *     with radius r and height h
 *     with 360/deg sides
 */
void cone(double x,double y,double z,
	  double r,double h,int deg)
{
  int k;
  glPushMatrix();

  /*  Transformation */
  glTranslated(x,y,z);
  glScaled(r,h,r);
  glRotated(-90,1,0,0);

  /* sides */
  glBegin(GL_TRIANGLES);
  for (k=0;k<=360;k+=deg){
    glColor3f(0.0,0.0,1.0);
    glVertex3f(0,0,1);
    glColor3f(0.0,1.0,1.0);
    glVertex3f(Cos(k),Sin(k),0);
    glColor3f(1.0,0.0,1.0);
    glVertex3f(Cos(k+deg),Sin(k+deg),0);
  }
  glEnd();

  /* bottom circle */ 
  /* rotate back */
  glRotated(90,1,0,0);
  glBegin(GL_TRIANGLES);
  glColor3f(1.0,1.0,0.0);
  for (k=0;k<=360;k+=deg) {
    glVertex3f(0,0,0);
    glVertex3f(Cos(k),0,Sin(k));
    glVertex3f(Cos(k+deg),0,Sin(k+deg));
  }
  glEnd();

  glPopMatrix();
}
