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

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,currentTexture);
  glPushMatrix();

  /*  Transform */
  glTranslated(x,y,z);
  glScaled(r,h,r);
  glRotated(-90,1,0,0);

  /* sides */
  glBegin(GL_TRIANGLES);
  for (k=0;k<=360;k+=deg){
    if (screencastID < 15) glColor3f(0.0,0.0,1.0);
    glNormal3f(0,0,1);
    /* center of cone is always center of texture */
    glTexCoord2f(0.5,0.5);
    glVertex3f(0,0,1);

    if (screencastID < 15) glColor3f(0.0,1.0,1.0);
    glNormal3f(Cos(k),Sin(k),r);
    glTexCoord2f((double)1/2*Cos(k)+0.5,(double)1/2*Sin(k)+0.5);
    glVertex3f(Cos(k),Sin(k),0);

    if (screencastID < 15) glColor3f(1.0,0.0,1.0);
    glNormal3f(Cos(k+deg),Sin(k+deg),r);
    glTexCoord2f((double)1/2*Cos(k+deg)+0.5,(double)1/2*Sin(k+deg)+0.5);
    glVertex3f(Cos(k+deg),Sin(k+deg),0);
  }
  glEnd();

  /* bottom circle */ 
  /* rotate back */
  glRotated(90,1,0,0);
  glBegin(GL_TRIANGLES);
  if (screencastID < 15) glColor3f(1.0,1.0,0.0);
  glNormal3f(0,-1,0);
  for (k=0;k<=360;k+=deg) {
    glTexCoord2f(0.5,0.5);
    glVertex3f(0,0,0);
    glTexCoord2f(0.5*Cos(k)+0.5,0.5*Sin(k)+0.5);
    glVertex3f(Cos(k),0,Sin(k));
    glTexCoord2f(0.5*Cos(k+deg)+0.5,0.5*Sin(k+deg)+0.5);
    glVertex3f(Cos(k+deg),0,Sin(k+deg));
  }
  glEnd();

  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
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
  /* front => ABCD */
  glBegin(GL_QUADS);
  glNormal3f(0,0,1);
  glTexCoord2f(0,0); glVertex3fv(vertA);
  glTexCoord2f(1,0); glVertex3fv(vertB);
  glTexCoord2f(1,1); glVertex3fv(vertC);
  glTexCoord2f(0,1); glVertex3fv(vertD);
  glEnd();

  /* back => FEHG */
  glBegin(GL_QUADS);
  glNormal3f(0,0,-1);
  glTexCoord2f(0,0); glVertex3fv(vertF);
  glTexCoord2f(1,0); glVertex3fv(vertE);
  glTexCoord2f(1,1); glVertex3fv(vertH);
  glTexCoord2f(0,1); glVertex3fv(vertG);
  glEnd();
  
  /* right => EADH */
  glBegin(GL_QUADS);
  glNormal3f(1,0,0);
  glTexCoord2f(0,0); glVertex3fv(vertE);
  glTexCoord2f(1,0); glVertex3fv(vertA);
  glTexCoord2f(1,1); glVertex3fv(vertD);
  glTexCoord2f(0,1); glVertex3fv(vertH);
  glEnd();

  /* left => BFGC */
  glBegin(GL_QUADS);
  glNormal3f(-1,0,0);
  glTexCoord2f(0,0); glVertex3fv(vertB);
  glTexCoord2f(1,0); glVertex3fv(vertF);
  glTexCoord2f(1,1); glVertex3fv(vertG);
  glTexCoord2f(0,1); glVertex3fv(vertC);
  glEnd();

  /* top => EFBA */
  glBegin(GL_QUADS);
  glNormal3f(0,1,0);
  glTexCoord2f(0,0); glVertex3fv(vertE);
  glTexCoord2f(1,0); glVertex3fv(vertF);
  glTexCoord2f(1,1); glVertex3fv(vertB);
  glTexCoord2f(0,1); glVertex3fv(vertA);
  glEnd();

  /* bottom => DCGH */
  glBegin(GL_QUADS);
  glNormal3f(0,-1,0);
  glTexCoord2f(0,0); glVertex3fv(vertD);
  glTexCoord2f(1,0); glVertex3fv(vertC);
  glTexCoord2f(1,1); glVertex3fv(vertG);
  glTexCoord2f(0,1); glVertex3fv(vertH);
  glEnd();

  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}

/*
 *  cylinder
 *  ------
 *  Draw a cylinder
 *     at (x, y, z)
 *     with radius r and height h
 */
void cylinder(double x,double y,double z,
	      double r,double h)
{
  int i,k;

  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,currentTexture);
  glPushMatrix();

  /*  Transformation */
  glTranslated(x,y,z);
  glScaled(r,h,r);
  /*  sides */
  glBegin(GL_QUAD_STRIP);
  for (k=0;k<=360;k+=DEF_D) {
    glNormal3f(Cos(k),0,Sin(k));
    // TODO: fix these textures
    glTexCoord2f(-Cos(k),Sin(k));
    glVertex3f(Cos(k),+1,Sin(k));

    glTexCoord2f(Cos(k),Sin(k));
    glVertex3f(Cos(k),-1,Sin(k));
  }
  glEnd();

  /* top and bottom circles */
  /* reuse the currentTexture on top and bottom) */
  for (i=1;i>=-1;i-=2) {
    glBegin(GL_TRIANGLE_FAN);
    glNormal3f(0,i,0);
    glTexCoord2f(0.5,0.5);
    glVertex3f(0,i,0);
    for (k=0;k<=360;k+=DEF_D) {
      glTexCoord2f(0.5*Cos(k)+0.5,0.5*Sin(k)+0.5);
      glVertex3f(i*Cos(k),i,Sin(k));
    }
    glEnd();
  }

  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
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
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,currentTexture);
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
  glDisable(GL_TEXTURE_2D);
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
   glTexCoord2d(th/360.0,ph/180.0+0.5);
   glVertex3d(x,y,z);
}
