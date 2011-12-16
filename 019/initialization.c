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
  toggleAnimation=DEF_ANIMATE;

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
  aone=DEF_AONE;
  opaque=DEF_OPAQUE;
  alpha=0.75;

  /* TEXTURES */
  currentTexture=TEX_DEFAULT;
}

/*
 * initializeObjs(void)
 * ------
 * Initializes all of our objects
 */
void initializeObjs(void)
{
  int i;
  cube_s cb[8] = {{{{0,0,0},{1,1,1},{0,0,0}}},
		  {{{2,0,0},{1,1,1},{0,0,0}}},
		  {{{0,2,0},{1,1,1},{0,0,0}}},
		  {{{0,0,2},{1,1,1},{0,0,0}}},
		  {{{2,2,0},{1,1,1},{0,0,0}}},
		  {{{0,2,2},{1,1,1},{0,0,0}}},
		  {{{2,0,2},{1,1,1},{0,0,0}}},
		  {{{2,2,2},{1,1,1},{0,0,0}}}
  };
  for (i = 0; i < 8; i++) {
    cubes[i] = cb[i];
  }
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
    TEX_STAINGLASS 8
   */
  textures[TEX_BRICK] = loadTexBMP("txBrick14.bmp");
  textures[TEX_CRATE] = loadTexBMP("txCrate.bmp");
  textures[TEX_ICE] = loadTexBMP("txIce7.bmp");
  textures[TEX_FIRE] = loadTexBMP("txLava1.bmp");
  textures[TEX_EARTH] = loadTexBMP("txRock5.bmp");
  textures[TEX_WOOD] = loadTexBMP("txWood3.bmp");
  textures[TEX_VENUS] = loadTexBMP("txVenus.bmp");
  textures[TEX_STAINGLASS] = loadTexBMP("txStainglass.bmp");
}
