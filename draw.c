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
    if (toggleLight)
      glEnable(GL_LIGHTING);
  }
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
    float Ambient[]   = {0.01*ambient ,0.01*ambient ,0.01*ambient ,1.0};
    float Diffuse[]   = {0.01*diffuse ,0.01*diffuse ,0.01*diffuse ,1.0};
    float Specular[]  = {0.01*specular,0.01*specular,0.01*specular,1.0};
    /*  Light position */
    float Position[]  = {distance*Sin(lightPh),lightY,distance*Cos(lightPh),1.0};
    /*  Draw light position as sphere (still no lighting here) */
    glColor3fv(white);    
    /*  Disable previous lighting before drawing sphere */
    glDisable(GL_LIGHTING);
    sphere(Position[0],Position[1],Position[2], 0.1,0);
    /*  OpenGL should normalize normal vectors */
    glEnable(GL_NORMALIZE);
    /*  Enable lighting */
    glEnable(GL_LIGHTING);
    /*  glColor sets ambient and diffuse color materials */
    glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    /*  Enable light 0 (up to 8) */
    glEnable(GL_LIGHT0);
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
    glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);
    glLightfv(GL_LIGHT0,GL_POSITION,Position);
  }
  else
    glDisable(GL_LIGHTING);
}

/*
 *  drawParameters()
 *  ------
 *  Draw the parameters in the lower left corner
 */
void drawParameters()
{
  if (toggleParms) {
    glColor3fv(white);
    /*  Display parameters */
    printAt(5,5,"Angle=%d,%d  Dim=%.1f FOV=%d Light=%s",
	    th,ph,dim,fov,toggleLight?"On":"Off");
    if (toggleLight) {
      printAt(5,45,"Distance=%d Elevation=%.1f Ambient=%d",distance,lightY,ambient);
      printAt(5,25,"Diffuse=%d Specular=%d Emission=%d Shininess=%.0f",
	      diffuse,specular,emission,shinyvec[0]);
    }
  }
}

void drawScene()
{
  drawAxes();
  drawParameters();

  if (screencastID == 11) 
    drawScreencast11();
  else if (screencastID == 12)
    drawScreencast12();

}

void drawScreencast11()
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

void drawScreencast12()
{
  // anything with lighting should be drawn after the light
  drawLight();
  cube(0,0,0, 1,1,1, 0);
}
