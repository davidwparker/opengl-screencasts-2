/*  Poor man's approximation of PI */
#define PI 3.1415926535898
/*  Macro for sin & cos in degrees */
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))

/*  Common #defines */
/*  Defaults for window sizing  */
#define DEF_WINDOW_HEIGHT 450
#define DEF_WINDOW_WIDTH 500

/*  Projection  */
#define DEF_ASP 1
#define DEF_DIM 10
#define DEF_TH 340
#define DEF_PH 30
#define DEF_FOV 55
#define DEF_ECX 2
#define DEF_ECY 0
#define DEF_ECZ 4

/*  Draw defaults  */
#define DEF_AXES 1
#define DEF_PARMS 1

/*  Shape degrees  */
#define DEF_D 5

/*  Lighting  */
#define DEF_LIGHT 1
#define DEF_DISTANCE 10
#define DEF_AMBIENT 35
#define DEF_DIFFUSE 100
#define DEF_EMISSION 0
#define DEF_SPECULAR 0
#define DEF_SHININESS 0
#define DEF_L_Y 0
#define DEF_L_PH 90

/*  Textures  */
#define TEX_DEFAULT 0
#define TEX_BRICK 1
#define TEX_CRATE 2
#define TEX_ICE 3
#define TEX_FIRE 4
#define TEX_EARTH 5
#define TEX_WOOD 6
#define TEX_VENUS 7 
