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

  /* TOGGLE */
  toggleAxes=DEF_AXES;
  toggleParams=DEF_PARAMS;
  toggleOverlay=DEF_OVERLAY;

  /* PROJECTION */
  dim=DEF_DIM;
  th=DEF_TH;
  ph=DEF_PH;
  fov=DEF_FOV;
  asp=DEF_ASP;
  ecX=DEF_ECX;
  ecY=DEF_ECY;
  ecZ=DEF_ECZ;

  /* LIGHTING */
  toggleLight=DEF_LIGHT;
  distance=DEF_DISTANCE;
  ambient=DEF_AMBIENT;
  diffuse=DEF_DIFFUSE;
  emission=DEF_EMISSION;
  specular=DEF_SPECULAR;
  shininess=DEF_SHININESS;
  lightY=DEF_L_Y;
  lightPh=DEF_L_PH;

  /* TEXTURES */
  currentTexture=TEX_DEFAULT;

  /* ANIMATION */
  toggleAnimation=DEF_ANIMATE;
}

/*
 * initializeObjs(void)
 * ------
 * Initializes all of our objects
 */
void initializeObjs(void)
{
  cube_s cb[8] = {{{{0,0,0},{1,1,1},{0,0,0}}},
		  {{{2,0,0},{1,1,1},{0,0,0}}},
		  {{{0,2,0},{1,1,1},{0,0,0}}},
		  {{{0,0,2},{1,1,1},{0,0,0}}},
		  {{{2,2,0},{1,1,1},{0,0,0}}},
		  {{{0,2,2},{1,1,1},{0,0,0}}},
		  {{{2,0,2},{1,1,1},{0,0,0}}},
		  {{{2,2,2},{1,1,1},{0,0,0}}}
  };
  cubes[0] = cb[0];
  cubes[1] = cb[1];
  cubes[2] = cb[2];
  cubes[3] = cb[3];
  cubes[4] = cb[4];
  cubes[5] = cb[5];
  cubes[6] = cb[6];
  cubes[7] = cb[7];
}

/*
 * initializeTextures()
 * ------
 * Loads all of the textures into textures array for use
 */
void initializeTextures(void)
{
  /*
    TEX_DEFAULT 0
    TEX_BRICK 1
    TEX_CRATE 2
    TEX_ICE 3
    TEX_FIRE 4
    TEX_EARTH 5
    TEX_WOOD 6
    TEX_VENUS 7
   */
  textures[TEX_BRICK] = loadTexBMP("txBrick14.bmp");
  textures[TEX_CRATE] = loadTexBMP("txCrate.bmp");
  textures[TEX_ICE] = loadTexBMP("txIce7.bmp");
  textures[TEX_FIRE] = loadTexBMP("txLava1.bmp");
  textures[TEX_EARTH] = loadTexBMP("txRock5.bmp");
  textures[TEX_WOOD] = loadTexBMP("txWood3.bmp");
  textures[TEX_VENUS] = loadTexBMP("txVenus.bmp");
}
