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
  windowName = "OpenGL screenscasts 15: Textures part 2";
  screencastID = 15;
  dim = 4;
  fov = 50;
  th = -25;
  ph = 15;
  ecX = -1.0;
  ecZ = -1.0;
  distance = 2;
  toggleLight = 0;
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

  initializeTextures();

  redisplayAll();
  glutMainLoop();
  return 0;
}
