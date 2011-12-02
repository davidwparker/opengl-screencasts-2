#include "screencasts.h"

/*
 *  displayInit
 *  -------
 *  Initializes display
 */
void displayInit(void)
{
  glClearColor(0.0,0.0,0.0,0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glLoadIdentity();
}

/*
 * displayEye()
 * ------
 * Set the eye position
 */
void displayEye(void)
{
  double Ex = -2*dim*Sin(th)*Cos(ph);
  double Ey = +2*dim        *Sin(ph);
  double Ez = +2*dim*Cos(th)*Cos(ph);
  /* camera/eye position, aim of camera lens, up-vector */
  gluLookAt(Ex+ecX,Ey,Ez+ecZ , ecX,ecY,ecZ , 0,Cos(ph),0);
}

/*
 *  displayReshape()
 *  ------
 *  GLUT calls this routine when the window is resized
 */
void displayReshape(int width,int height)
{
  asp = (height>0) ? (double)width/height : 1;
  glViewport(0,0, width,height);
  displayProject(fov,asp,dim);
}

/*
 * displayProject()
 * ------
 * Sets the projection
 */
void displayProject(double fov, double asp, double dim)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(fov,asp,dim/16,16*dim);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

/*
 *  display()
 *  ------
 *  Display the scene
 */
void display(void)
{
  /* setup functions */  
  displayInit();
  displayEye();

  /* Draw Scene */
  drawScene();

  glFlush();
  glutSwapBuffers();

  errCheck("display sanity check");
}

/*
 *  redisplayAll
 *  ------
 *  This is called whenever we need to draw the display
 */
void redisplayAll(void)
{
  displayProject(fov,asp,dim);
  glutPostRedisplay();
}
