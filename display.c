#include "screencasts.h"

/*
 *  displayInit
 *  -------
 *  Initializes display
 */
void displayInit()
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
void displayEye()
{
  if (toggleMode) {
    double Ex = -2*dim*Sin(th)*Cos(ph);
    double Ey = +2*dim        *Sin(ph);
    double Ez = +2*dim*Cos(th)*Cos(ph);
    /* camera/eye position, aim of camera lens, up-vector */
    gluLookAt(Ex,Ey,Ez , 0,0,0 , 0,Cos(ph),0);
  }
  /*  Orthogonal - set world orientation */
  else {
    glRotatef(ph,1,0,0);
    glRotatef(th,0,1,0);
  }
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
  displayProject();
}

/*
 * displayProject()
 * ------
 * Sets the projection
 */
void displayProject() 
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (toggleMode) {
    /* perspective */
    gluPerspective(fov,asp,dim/4,4*dim);
  }
  else {
    /* orthogonal projection*/
    glOrtho(-dim*asp,+dim*asp, -dim,+dim, -dim,+dim);
  }

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

/*
 *  display()
 *  ------
 *  Display the scene
 */
void display()
{
  /* setup functions */  
  displayInit();
  displayEye();

  /* draw */
  drawAxes();
  drawValues();

  /* magic here */
  drawScene();

  glFlush();
  glutSwapBuffers();

  errCheck("display sanity check");
}
