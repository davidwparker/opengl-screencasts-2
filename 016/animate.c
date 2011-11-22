#include "screencasts.h"

/* redraw the screen approximately every 10ms */
void windowIdle(void)
{
  static int lastTime = 0;
  // glutGet retrieves OpenGL state. See list at http://www.opengl.org/documentation/specs/glut/spec3/node70.html
  int time = glutGet(GLUT_ELAPSED_TIME);
  double t = time/1000.0;
  if ((lastTime == 0 || time >= lastTime + 10) && toggleAnimation) {
    lastTime = time;
    // do some animation here
    if (toggleLight) lightPh = fmod(90*t,360.0);
    rotateCube();
    redisplayAll();
  }
}

/* If window is visible, set idle function */
void windowVisible(int visible)
{
  glutIdleFunc(visible == GLUT_VISIBLE ? windowIdle : NULL);
}

void rotateCube(void)
{
  if (cubeRotation <= 360)
    cubeRotation += 1;
  else
    cubeRotation = 0;
}
