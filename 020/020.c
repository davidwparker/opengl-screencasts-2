#include "screencasts.h"

/*
 * initializeGlobals()
 * ------
 * Initializes the global variables.
 */
void initializeGlobals(void)
{
  /* WINDOW */
  windowHeight=DEF_WINDOW_HEIGHT;
  windowWidth=DEF_WINDOW_WIDTH;

  /* PROJECTION */
  dim=DEF_DIM;
  th=DEF_TH;
  ph=DEF_PH;
  fov=DEF_FOV;
  asp=DEF_ASP;
  ecX=DEF_ECX;
  ecY=DEF_ECY;
  ecZ=DEF_ECZ;
}

void windowKey(unsigned char key,int x,int y)
{
  /*  Exit on ESC */
  if (key == 27) exit(0);

  /* Change the X angle */
  else if (key=='r') th = (th-5)%360;
  else if (key=='R') th = (th+5)%360;

  redisplayAll();
}

void drawScene(void)
{
  int i;
  const float di = 0.95;
  //  Draw background quad
  glBegin(GL_QUADS);
  glColor3f(1,1,1);
  glVertex2f(-0.8*di,-0.4*di);
  glVertex2f(-0.8*di,+0.4*di);
  glVertex2f(+0.8*di,+0.4*di);
  glVertex2f(+0.8*di,-0.4*di);
  glEnd();

  //  Two X's
  //  Left  aliased
  //  Right anti-aliased
  for (i=-1;i<=1;i+=2) {
    //  Aliased line setup
    if (i<0) {
      glDisable (GL_LINE_SMOOTH);
      glDisable (GL_BLEND);
      glLineWidth (1.5);
    }
    //  Anti-aliased line setup
    else {
      glEnable(GL_LINE_SMOOTH);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      //glHint(TARGET, MODE)
      //TARGET = GL_FRAGMENT_SHADER_DERIVATIVE_HINT, GL_LINE_SMOOTH_HINT, 
      //         GL_TEXTURE_COMPRESSION_HINT, GL_POLYGON_SMOOTH_HINT
      //MODE = GL_DONT_CARE, GL_NICEST, GL_FASTEST
      glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
      //glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
      //glHint(GL_LINE_SMOOTH_HINT, GL_FASTEST);
      glLineWidth(1.5);
    }
    //  Draw X lines
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex2f(-di*Cos(th)+0.05*i,-di*Sin(th));
    glVertex2f(+di*Cos(th)+0.05*i,+di*Sin(th));
    glColor3f(0,0,1);
    glVertex2f(-di*Cos(th)+0.05*i,+di*Sin(th));
    glVertex2f(+di*Cos(th)+0.05*i,-di*Sin(th));
    glEnd();
  }
}

/*
 *  main()
 *  ----
 *  Start up GLUT and tell it what to do
 */
int main(int argc,char* argv[])
{
  initializeGlobals();

  /* screencast specific variables */
  windowName = "OpenGL screenscasts 20: Anti-Aliasing";
  screencastID = 20;

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_ALPHA);
  glutInitWindowSize(windowWidth,windowHeight);
  glutInitWindowPosition(450,350);
  glutCreateWindow(windowName);

  glutDisplayFunc(display);
  glutReshapeFunc(displayReshape);
  glutKeyboardFunc(windowKey);

  redisplayAll();
  glutMainLoop();
  return 0;
}

