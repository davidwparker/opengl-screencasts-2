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
  windowName = "OpenGL screenscasts 14: Textures part 1";
  screencastID = 14;
  dim = 4;
  fov = 50;
  th = -25;
  ph = 15;
  ecX = -0.4;
  ecZ = -2.0;
  distance = 2;

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(windowWidth,windowHeight);
  glutCreateWindow(windowName);

  glutDisplayFunc(display);
  glutReshapeFunc(displayReshape);
  glutKeyboardFunc(windowKey);
  glutSpecialFunc(windowSpecial);

  initializeTextures();

  redisplayAll();
  glutMainLoop();
  return 0;
}
