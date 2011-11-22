#include "screencasts.h"

/*
 *  windowKey()
 *  ------
 *  GLUT calls this routine when a non-special key is pressed
 */
void windowKey(unsigned char key,int x,int y)
{
  /*  Exit on ESC */
  if (key == 27) exit(0);
  else if (key == 'x' || key == 'X') toggleAxes = 1-toggleAxes;
  else if (key == 'v' || key == 'V') toggleParams = 1-toggleParams;
  else if (key == 'm' || key == 'M') toggleAnimation = 1-toggleAnimation;
  /*  Change field of view angle */
  else if (key == '-' && key>1) fov--;
  else if (key == '+' && key<179) fov++;
  /*  Change dimensions */
  else if (key == 'I') dim += 0.2;
  else if (key == 'i' && dim>1) dim -= 0.2;
  /*  BEGIN LIGHTING FUNCTIONALITY */
  /*  Toggle lighting */
  else if (key == 'l' || key == 'L') toggleLight = 1-toggleLight;
  /*  Move light (rotation) */
  else if (key == '<') lightPh -= 5;
  else if (key == '>') lightPh += 5;
  /*  Light elevation */
  else if (key == '[') lightY -= 0.5;
  else if (key == ']') lightY += 0.5;
  /*  Light distance */
  else if (key == '{') distance -= 1;
  else if (key == '}') distance += 1;
  /*  Ambient level */
  else if (key == 'a' && ambient>0) ambient -= 5;
  else if (key == 'A' && ambient<100) ambient += 5;
  /*  Diffuse level */
  else if (key == 'd' && diffuse>0) diffuse -= 5;
  else if (key == 'D' && diffuse<100) diffuse += 5;
  /*  Specular level */
  else if (key == 's' && specular>0) specular -= 5;
  else if (key == 'S' && specular<100) specular += 5;
  /*  Emission level */
  else if (key == 'e' && emission>0) emission -= 5;
  else if (key == 'E' && emission<100) emission += 5;
  /*  Shininess level */
  else if (key == 'n' && shininess>-1) shininess -= 1;
  else if (key == 'N' && shininess<7) shininess += 1;

  /*  Translate shininess power to value (-1 => 0) */
  shinyvec[0] = shininess<0 ? 0 : pow(2.0,shininess);

  redisplayAll();
}

/*
 *  windowMenu
 *  ------
 *  Window menu is the same as the keyboard clicks
 */
void windowMenu(int value)
{
  windowKey((unsigned char)value, 0, 0);
}

/*
 *  windowSpecial()
 *  ------
 *  GLUT calls this routine when an arrow key is pressed
 */
void windowSpecial(int key,int x,int y)
{
  int modifiers = glutGetModifiers();
  /*  If holding shift, then rotate/elevate */
  if (modifiers == GLUT_ACTIVE_SHIFT) {
    /*  Right/Left - rotate */
    if (key == GLUT_KEY_RIGHT) th += 5;
    else if (key == GLUT_KEY_LEFT) th -= 5;
    /*  Up/Down - elevation */
    else if (key == GLUT_KEY_UP) ph += 5;
    else if (key == GLUT_KEY_DOWN) ph -= 5;
  }
  /*  Otherwise, just shift the screen */
  else {
    /*  Shift */
    if (key == GLUT_KEY_RIGHT) ecX += .5;
    else if (key == GLUT_KEY_LEFT) ecX -= .5;
    else if (key == GLUT_KEY_DOWN) ecZ += .5;
    else if (key == GLUT_KEY_UP) ecZ -= .5;
  }

  /*  Keep angles to +/-360 degrees */
  th %= 360;
  ph %= 360;

  redisplayAll();
}
