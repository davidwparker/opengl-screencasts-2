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
  windowName = "OpenGL screenscasts 13: Lighting and Material Part 2: Materials";
  screencastID = 13;
  dim = 4;
  fov = 50;
  th = 0;
  ph = 0;
  ecX = -0.4;
  distance = 5;

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(windowWidth,windowHeight);
  glutCreateWindow(windowName);

  glutDisplayFunc(display);
  glutReshapeFunc(displayReshape);
  glutKeyboardFunc(windowKey);
  glutSpecialFunc(windowSpecial);

  redisplayAll();
  glutMainLoop();
  return 0;
}
