#include "screencasts.h"

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
  // 2D only for this example
  gluOrtho2D(-asp,+asp,-1,+1);
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
  glClear(GL_COLOR_BUFFER_BIT);

  /* Draw Scene */
  drawScene();

  /* Flush and sanity check */
  glFlush();
  errCheck("display sanity check");
}

/*
 *  redisplayAll()
 *  ------
 *  This is called whenever we need to draw the display
 */
void redisplayAll(void)
{
  displayProject(fov,asp,dim);
  glutPostRedisplay();
}
