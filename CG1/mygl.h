#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

typedef struct{
  unsigned int x;
  unsigned int y;
  unsigned char r;
  unsigned char g;
  unsigned char b;
  unsigned char a;
} Pixel;

void PutPixel(Pixel p){
  if((p.x>=IMAGE_WIDTH)||(p.y>=IMAGE_HEIGHT)){
    std::clog << "Invalid pixel coordinates";
    return;
  }
  int aux = (p.x + p.y*IMAGE_WIDTH)*4;
  FBptr[aux] = p.r;
  FBptr[aux + 1] = p.g;
  FBptr[aux + 2] = p.b;
  FBptr[aux + 3] = p.a;
}

void oct1(Pixel p1, Pixel p2){
  int dx = p2.x - p1.x;
  int dy = p2.y - p1.y;
  int d = 2* dy - dx;
  int incr_e = 2 * dy;
  int incr_ne = 2 * (dy - dx);

  double dr = (p2.r - p1.r)/((double) dx);
  double dg = (p2.g - p1.g)/((double) dx);
  double db = (p2.b - p1.b)/((double) dx);
  double da = (p2.a - p1.a)/((double) dx);

  Pixel p = p1;
  double r = p.r;
  double g = p.g;
  double b = p.b;
  double a = p.a;
  PutPixel(p);
  while(p.x < p2.x){
    if (d<=0) {
      d += incr_e;
      p.x++;
    }else{
      d += incr_ne;
      p.x++;
      p.y++;
    }
    r += dr;
    g += dg;
    b += db;
    a += da;
    p.r = (unsigned char)(r);
    p.g = (unsigned char)(g);
    p.b = (unsigned char)(b);
    p.a = (unsigned char)(a);

    PutPixel(p);
  }
}

void oct2(Pixel p1, Pixel p2){
  int dx = p2.x - p1.x;
  int dy = p2.y - p1.y;
  int d = 2* dx - dy;
  int incr_e = 2 * dx;
  int incr_ne = 2 * (dx - dy);

  double dr = (p2.r - p1.r)/((double) dy);
  double dg = (p2.g - p1.g)/((double) dy);
  double db = (p2.b - p1.b)/((double) dy);
  double da = (p2.a - p1.a)/((double) dy);

  Pixel p = p1;
  double r = p.r;
  double g = p.g;
  double b = p.b;
  double a = p.a;
  PutPixel(p);
  while(p.y < p2.y){
    if (d<=0) {
      d += incr_e;
      p.y++;
    }else{
      d += incr_ne;
      p.x++;
      p.y++;
    }

    r += dr;
    g += dg;
    b += db;
    a += da;
    p.r = (unsigned char)(r);
    p.g = (unsigned char)(g);
    p.b = (unsigned char)(b);
    p.a = (unsigned char)(a);
    PutPixel(p);
  }
}

void oct3(Pixel p1, Pixel p2){
  int dx = p1.x - p2.x;
  int dy = p2.y - p1.y;
  int d = 2* dx - dy;
  int incr_e = 2 * dx;
  int incr_ne = 2 * (dx - dy);

  double dr = (p2.r - p1.r)/((double) dy);
  double dg = (p2.g - p1.g)/((double) dy);
  double db = (p2.b - p1.b)/((double) dy);
  double da = (p2.a - p1.a)/((double) dy);

  Pixel p = p1;
  double r = p.r;
  double g = p.g;
  double b = p.b;
  double a = p.a;
  PutPixel(p);
  while(p.y < p2.y){
    if (d<=0) {
      d += incr_e;
      p.y++;
    }else{
      d += incr_ne;
      p.x--;
      p.y++;
    }

    r += dr;
    g += dg;
    b += db;
    a += da;
    p.r = (unsigned char)(r);
    p.g = (unsigned char)(g);
    p.b = (unsigned char)(b);
    p.a = (unsigned char)(a);
    PutPixel(p);
  }
}

void oct4(Pixel p1, Pixel p2){
  int dx = p1.x - p2.x;
  int dy = p2.y - p1.y;
  int d = 2* dy - dx;
  int incr_e = 2 * dy;
  int incr_ne = 2 * (dy - dx);

  double dr = (p2.r - p1.r)/((double) dx);
  double dg = (p2.g - p1.g)/((double) dx);
  double db = (p2.b - p1.b)/((double) dx);
  double da = (p2.a - p1.a)/((double) dx);

  Pixel p = p1;
  double r = p.r;
  double g = p.g;
  double b = p.b;
  double a = p.a;
  PutPixel(p);
  while(p.x > p2.x){
    if (d<=0) {
      d += incr_e;
      p.x--;
    }else{
      d += incr_ne;
      p.x--;
      p.y++;
    }

    r += dr;
    g += dg;
    b += db;
    a += da;
    p.r = (unsigned char)(r);
    p.g = (unsigned char)(g);
    p.b = (unsigned char)(b);
    p.a = (unsigned char)(a);
    PutPixel(p);
  }
}

void oct5(Pixel p1, Pixel p2){
  int dx = p1.x - p2.x;
  int dy = p1.y - p2.y;
  int d = 2* dy - dx;
  int incr_e = 2 * dy;
  int incr_ne = 2 * (dy - dx);

  double dr = (p2.r - p1.r)/((double) dx);
  double dg = (p2.g - p1.g)/((double) dx);
  double db = (p2.b - p1.b)/((double) dx);
  double da = (p2.a - p1.a)/((double) dx);

  Pixel p = p1;
  double r = p.r;
  double g = p.g;
  double b = p.b;
  double a = p.a;
  PutPixel(p);
  while(p.x > p2.x){
    if (d<=0) {
      d += incr_e;
      p.x--;
    }else{
      d += incr_ne;
      p.x--;
      p.y--;
    }

    r += dr;
    g += dg;
    b += db;
    a += da;
    p.r = (unsigned char)(r);
    p.g = (unsigned char)(g);
    p.b = (unsigned char)(b);
    p.a = (unsigned char)(a);
    PutPixel(p);
  }
}

void oct6(Pixel p1, Pixel p2){
  int dx = p1.x - p2.x;
  int dy = p1.y - p2.y;
  int d = 2* dx - dy;
  int incr_e = 2 * dx;
  int incr_ne = 2 * (dx - dy);

  double dr = (p2.r - p1.r)/((double) dy);
  double dg = (p2.g - p1.g)/((double) dy);
  double db = (p2.b - p1.b)/((double) dy);
  double da = (p2.a - p1.a)/((double) dy);

  Pixel p = p1;
  double r = p.r;
  double g = p.g;
  double b = p.b;
  double a = p.a;
  PutPixel(p);
  while(p.y > p2.y){
    if (d<=0) {
      d += incr_e;
      p.y--;
    }else{
      d += incr_ne;
      p.x--;
      p.y--;
    }

    r += dr;
    g += dg;
    b += db;
    a += da;
    p.r = (unsigned char)(r);
    p.g = (unsigned char)(g);
    p.b = (unsigned char)(b);
    p.a = (unsigned char)(a);
    PutPixel(p);
  }
}

void oct7(Pixel p1, Pixel p2){
  int dx = p2.x - p1.x;
  int dy = p1.y - p2.y;
  int d = 2* dx - dy;
  int incr_e = 2 * dx;
  int incr_ne = 2 * (dx - dy);

  double dr = (p2.r - p1.r)/((double) dy);
  double dg = (p2.g - p1.g)/((double) dy);
  double db = (p2.b - p1.b)/((double) dy);
  double da = (p2.a - p1.a)/((double) dy);

  Pixel p = p1;
  double r = p.r;
  double g = p.g;
  double b = p.b;
  double a = p.a;
  PutPixel(p);
  while(p.y > p2.y){
    if (d<=0) {
      d += incr_e;
      p.y--;
    }else{
      d += incr_ne;
      p.x++;
      p.y--;
    }

    r += dr;
    g += dg;
    b += db;
    a += da;
    p.r = (unsigned char)(r);
    p.g = (unsigned char)(g);
    p.b = (unsigned char)(b);
    p.a = (unsigned char)(a);
    PutPixel(p);
  }
}

void oct8(Pixel p1, Pixel p2){
  int dx = p2.x - p1.x;
  int dy = p1.y - p2.y;
  int d = 2* dy - dx;
  int incr_e = 2 * dy;
  int incr_ne = 2 * (dy - dx);

  double dr = (p2.r - p1.r)/((double) dx);
  double dg = (p2.g - p1.g)/((double) dx);
  double db = (p2.b - p1.b)/((double) dx);
  double da = (p2.a - p1.a)/((double) dx);

  Pixel p = p1;
  double r = p.r;
  double g = p.g;
  double b = p.b;
  double a = p.a;
  PutPixel(p);
  while(p.x < p2.x){
    if (d<=0) {
      d += incr_e;
      p.x++;
    }else{
      d += incr_ne;
      p.x++;
      p.y--;
    }

    r += dr;
    g += dg;
    b += db;
    a += da;
    p.r = (unsigned char)(r);
    p.g = (unsigned char)(g);
    p.b = (unsigned char)(b);
    p.a = (unsigned char)(a);
    PutPixel(p);
  }
}

void DrawLine(Pixel p1, Pixel p2){
  int dx = p2.x - p1.x;
  int dy = p2.y - p1.y;

  if(dx>=0){
    if(dy>=0){
      if(dx-dy >= 0){
        oct1(p1, p2);
      }else{
        oct2(p1, p2);
      }
    }else{
      if(dx+dy >= 0){
        oct8(p1, p2);
      }else{
        oct7(p1, p2);
      }
    }
  }else{
    if(dy>=0){
      if(dx + dy >= 0){
        oct3(p1, p2);
      }else{
        oct4(p1, p2);
      }
    }else{
      if(dx - dy >= 0){
        oct6(p1, p2);
      }else{
        oct5(p1, p2);
      }
    }
  }
}

void DrawTriangle(Pixel p1, Pixel p2, Pixel p3){
  DrawLine(p1, p2);
  DrawLine(p2, p3);
  DrawLine(p3, p1);
}


#endif // _MYGL_H_
