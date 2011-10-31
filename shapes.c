#include "screencasts.h"

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

  /*  Transform */
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

/*
 *  cube
 *  ------
 *  Draw a cube
 *     at (x,y,z)
 *     dimensions (dx,dy,dz)
 *     rotated th about the y axis
 *  TODO: Refactor this!!!
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
  /*  Transform */
  glTranslated(x,y,z);
  glRotated(th,0,1,0);
  glScaled(dx,dy,dz);

  glEnable(GL_TEXTURE_2D);
  /* using the current texture */
  glBindTexture(GL_TEXTURE_2D,currentTexture);

  /* Cube */
  glBegin(GL_QUADS);
  /* front => ABCD yellow */
  glNormal3f(0,0,1);
  if (screencastID < 14)
    glColor3f(1.0,1.0,0.0);
  glTexCoord2f(0,0); glVertex3fv(vertA);
  glTexCoord2f(1,0); glVertex3fv(vertB);
  glTexCoord2f(1,1); glVertex3fv(vertC);
  glTexCoord2f(0,1); glVertex3fv(vertD);
  glEnd();

  /* back => FEHG red */
  glBegin(GL_QUADS);
  glNormal3f(0,0,-1);
  if (screencastID < 14)
    glColor3f(1.0,0.0,0.0);
  glTexCoord2f(0,0); glVertex3fv(vertF);
  glTexCoord2f(1,0); glVertex3fv(vertE);
  glTexCoord2f(1,1); glVertex3fv(vertH);
  glTexCoord2f(0,1); glVertex3fv(vertG);
  //glEnd();
  //glBegin(GL_QUADS);
  /* right => EADH green */
  glNormal3f(1,0,0);
  //if (screencastID < 14)
  glColor3f(0.0,1.0,0.0);
  glTexCoord2f(0,0); glVertex3fv(vertE);
  glTexCoord2f(1,0); glVertex3fv(vertA);
  glTexCoord2f(1,1); glVertex3fv(vertD);
  glTexCoord2f(0,1); glVertex3fv(vertH);
  glEnd();
  glDisable(GL_TEXTURE_2D);

  glBegin(GL_QUADS);
  /* left => BFGC blue */
  glNormal3f(-1,0,0);
  if (screencastID < 14)
    glColor3f(0.0,0.0,1.0);
  glVertex3fv(vertB);
  glVertex3fv(vertF);
  glVertex3fv(vertG);
  glVertex3fv(vertC);
  /* top => EFBA turquoise */
  glNormal3f(0,1,0);
  if (screencastID < 14)
    glColor3f(0.0,1.0,1.0);
  glVertex3fv(vertE);
  glVertex3fv(vertF);
  glVertex3fv(vertB);
  glVertex3fv(vertA);
  /* bottom => DCGH pink */
  glNormal3f(0,-1,0);
  if (screencastID < 14)
    glColor3f(1.0,0.0,1.0);
  glVertex3fv(vertD);
  glVertex3fv(vertC);
  glVertex3fv(vertG);
  glVertex3fv(vertH);
  glEnd();

  glPopMatrix();
}

/*
 *  sphere
 *  ------
 *  Draw a sphere
 *     at (x,y,z)
 *     radius (r)
 *     rotated rot around the y axis
 */
void sphere(double x,double y,double z,double r,double rot)
{
  int th,ph;
  float yellow[] = {1.0,1.0,0.0,1.0};
  float emissions[] = {0.0,0.0,0.01*emission,1.0};
  /*
    Material shininess = specular exponent 
    Material specular = specular color of material
    Material emission = simulates original lighting from an object
   */
  glMaterialfv(GL_FRONT,GL_SHININESS,shinyvec);
  glMaterialfv(GL_FRONT,GL_SPECULAR,yellow);
  glMaterialfv(GL_FRONT,GL_EMISSION,emissions);

  glPushMatrix();
  /*  Transform */
  glTranslated(x,y,z);
  glScaled(r,r,r);
  glRotated(rot,0,1,0);

  /*  Bands of latitude */
  for (ph=-90;ph<90;ph+=DEF_D) {
    glBegin(GL_QUAD_STRIP);
    for (th=0;th<=360;th+=2*DEF_D) {
      vertex(th,ph);
      vertex(th,ph+DEF_D);
    }
    glEnd();
  }

  glPopMatrix();
}

/*
 *  vertex
 *  ------
 *  Draw vertex in polar coordinates with normal
 */
void vertex(double th,double ph)
{
   double x = Sin(th)*Cos(ph);
   double y = Cos(th)*Cos(ph);
   double z =         Sin(ph);
   /*  For a sphere at the origin, the position
       and normal vectors are the same */
   glNormal3d(x,y,z);
   glVertex3d(x,y,z);
}
