#include "screencasts.h"

/*
 * drawAxes()
 * ------
 * Draw the axes
 */
void drawAxes(void)
{
  if (toggleAxes) {
    /*  Length of axes */
    double len = 2.0;
    glDisable(GL_LIGHTING);
    glColor3fv(white);
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
    if (toggleLight) glEnable(GL_LIGHTING);
  }
}

/*
 * drawCube()
 * ------
 * Draws a cube
 */
void drawCube(cube_s cb)
{
  cube(cb.tsr.t.x,cb.tsr.t.y,cb.tsr.t.z, 
       cb.tsr.s.x,cb.tsr.s.y,cb.tsr.s.z,
       cb.tsr.r.y);
}

/*
 *  drawLight 
 *  ------
 *  Draws the light
 */
void drawLight(void)
{
  /*  Light switch */
  if (toggleLight) {
    /*  Translate intensity to color vectors */
    GLfloat Ambient[]   = {0.01*ambient ,0.01*ambient ,0.01*ambient ,1.0};
    GLfloat Diffuse[]   = {0.01*diffuse ,0.01*diffuse ,0.01*diffuse ,1.0};
    GLfloat Specular[]  = {0.01*specular,0.01*specular,0.01*specular,1.0};
    GLfloat Position[]  = {distance*Sin(lightPh),lightY,distance*Cos(lightPh),1.0};

    /*  Draw light position as sphere (still no lighting here) */
    glColor3fv(white);
    glDisable(GL_LIGHTING);
    sphere(Position[0],Position[1],Position[2], 0.1,0);

    /*  Set ambient, diffuse, specular components and position of light 0 */
    /*
      Light uses the Phong model
      Once light is enabled, colors assigned by glColor* isn't used
      Ambient is light that's been scattered by environment that its direction is impossible to determine
      Diffuse is is light that comes from one direction, so it's brighter if it comes squarely on surface rather than glances off
      Specular is light that comes from a particular direction and bounces off in preferred direction
      Position is the position of our light. In this case it is the same as the sphere.
     */
    glLightfv(GL_LIGHT0,GL_AMBIENT, Ambient);
    glLightfv(GL_LIGHT0,GL_DIFFUSE, Diffuse);
    glLightfv(GL_LIGHT0,GL_POSITION,Position);
    glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING); 
    glEnable(GL_LIGHT0);
  }
  else {
    glDisable(GL_LIGHTING);
  }
}

/*
 * drawOverlay()
 * ------
 * Our overlay is just a 2D picture placed over the 3D scene
 */
void drawOverlay(void)
{
  if (toggleOverlay) {
  glDisable(GL_LIGHTING);
  // Save transform attributes (Matrix Mode and Enabled Modes)
  glPushAttrib(GL_TRANSFORM_BIT|GL_ENABLE_BIT);
  // Save projection matrix and set unit transform
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glOrtho(-asp,+asp,-1,1,-1,1);
  // Save model view matrix and set to identity
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();
  // Draw bottom with texture
  glColor3f(1,1,1);
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D,currentTexture);
  glBegin(GL_QUADS);
  glTexCoord2d(0,0);glVertex2f(-2,-1);
  glTexCoord2d(1,0);glVertex2f(+2,-1);
  glTexCoord2d(1,1);glVertex2f(+2, 0);
  glTexCoord2d(0,1);glVertex2f(-2, 0);
  glEnd();
  glDisable(GL_TEXTURE_2D);
  // Draw the inside in grey
  glColor3f(0.6,0.6,0.6);
  glBegin(GL_QUADS);
  // Left
  glVertex2f(-2,-1);
  glVertex2f(-2,+1);
  glVertex2f(-8,+1);
  glVertex2f(-8,-1);
  // Right
  glVertex2f(+2,-1);
  glVertex2f(+2,+1);
  glVertex2f(+8,+1);
  glVertex2f(+8,-1);
  // Left overhead
  glVertex2f(-2.00,+0.8);
  glVertex2f(-2.00,+1);
  glVertex2f(-0.02,+1);
  glVertex2f(-0.02,+0.9);
  // Right overhead
  glVertex2f(+2.00,+0.8);
  glVertex2f(+2.00,+1);
  glVertex2f(+0.02,+1);
  glVertex2f(+0.02,+0.9);
  // Middle divider
  glVertex2f(-0.02,+1);
  glVertex2f(+0.02,+1);
  glVertex2f(+0.02,+0);
  glVertex2f(-0.02,+0);
  glEnd();
  //  Reset model view matrix
  glPopMatrix();
  //  Reset projection matrix
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  //  Pop transform attributes (Matrix Mode and Enabled Modes)
  glPopAttrib();
  if (toggleLight) glEnable(GL_LIGHTING);
  }
}

/*
 *  drawParameters()
 *  ------
 *  Draw the parameters in the lower left corner
 */
void drawParameters(void)
{
  if (toggleParams) {
    int height = 5;
    glColor3fv(white);
    /*  Display parameters */
    printAt(5,height,"Angle=%d,%d  Dim=%.1f FOV=%d Light=%s",
	    th,ph,dim,fov,toggleLight?"On":"Off");
    if (toggleLight) {
      printAt(5,height+=20,"Diffuse=%d Specular=%d Emission=%d Shininess=%.0f",
	      diffuse,specular,emission,shinyvec[0]);
      printAt(5,height+=20,"Distance=%d Elevation=%.1f Ambient=%d",distance,lightY,ambient);
    }
    if (toggleOverlay) {
      printAt(5,height+=20,"Overlay=%s",toggleOverlay?"On":"Off");
    }
  }
}

/*
 * drawScene()
 * ------
 * Draws the scene with everything we need in it
 */
void drawScene(void)
{
  int i;
  drawAxes();
  drawParameters();
  currentTexture = textures[TEX_DEFAULT];
  drawLight();
  currentTexture = textures[TEX_CRATE];
  for (i = 0; i < Length(cubes); i++)
    drawCube(cubes[i]);
  /* This must be drawn last */
  currentTexture = textures[TEX_VENUS];
  drawOverlay();
  currentTexture = textures[TEX_DEFAULT];
}
