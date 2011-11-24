typedef struct point {
  float x;
  float y;
  float z;
} point;

typedef struct tsr {
  point t; /* translation */  
  point s; /* scale */
  point r; /* rotation */
} tsr;

typedef struct cube_s {
  tsr tsr;
} cube_s;
