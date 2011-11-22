#include "screencasts.h"

/*
 *  main()
 *  ----
 *  Start up GLUT and tell it what to do
 */
int main(int argc,char* argv[])
{
  initializeGlobals();
  /* screencast specific variables */
  windowName = "OpenGL screenscasts 16: Animation part 1";
  screencastID = 16;
  toggleAxes = 0;

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(windowWidth,windowHeight);
  glutInitWindowPosition(450,350);
  glutCreateWindow(windowName);

  glutDisplayFunc(display);
  glutReshapeFunc(displayReshape);
  glutKeyboardFunc(windowKey);
  glutSpecialFunc(windowSpecial);
  // glutIdleFunc. Executed when there is no other event to be handled (event queue is empty).
  //glutIdleFunc(windowIdle);
  // glutVisibilityFunc. Sets the visibility callback for the current window
  // GLUT considers a window visible if any pixel of the window is visible 
  //      or any pixel of descendant window is visible on screen.
  //    state = GLUT_NOT_VISIBLE | GLUT_VISIBLE
  glutVisibilityFunc(windowVisible);

  initializeTextures();

  redisplayAll();
  glutMainLoop();
  return 0;
}
