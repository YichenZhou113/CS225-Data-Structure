#include "Image.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using namespace cs225;


void Image::lighten(){
  for (unsigned x = 0; x<width(); x++){
    for(unsigned y = 0; y<height();y++){
      HSLAPixel *p = getPixel(x,y);
      p->l = p->l + 0.1;
      if (p->l > 1){
        p->l = 1;
      }
      if (p->l < 0){
        p->l = 0;
      }
    }
  }
}

void Image::lighten(double amount){
  for (unsigned x = 0; x<width(); x++){
    for(unsigned y = 0; y<height();y++){
      HSLAPixel *p = getPixel(x,y);
      p->l = p->l + amount;
      if (p->l > 1){
        p->l = 1;
      }
      if (p->l < 0){
        p->l = 0;
      }
    }
  }
}

void Image::darken(){
  for (unsigned x = 0; x<width(); x++){
    for(unsigned y = 0; y<height();y++){
      HSLAPixel *p = getPixel(x,y);
      p->l = p->l - 0.1;
      if (p->l > 1){
        p->l = 1;
      }
      if (p->l < 0){
        p->l = 0;
      }
    }
  }
}

void Image::darken(double amount){
  for (unsigned x = 0; x<width(); x++){
    for(unsigned y = 0; y<height();y++){
      HSLAPixel *p = getPixel(x,y);
      p->l = p->l - amount;
      if (p->l > 1){
        p->l = 1;
      }
      if (p->l < 0){
        p->l = 0;
      }
    }
  }
}

void Image::saturate(){
  for (unsigned x = 0; x<width(); x++){
    for(unsigned y = 0; y<height();y++){
      HSLAPixel *p = getPixel(x,y);
      p->s = p->s + 0.1;
      if (p->s > 1){
        p->s = 1;
      }
      if (p->s < 0){
        p->s = 0;
      }
    }
  }
}

void Image::saturate(double amount){
  for (unsigned x = 0; x<width(); x++){
    for(unsigned y = 0; y<height();y++){
      HSLAPixel *p = getPixel(x,y);
      p->s = p->s + amount;
      if (p->s > 1){
        p->s = 1;
      }
      if (p->s < 0){
        p->s = 0;
      }
    }
  }
}

void Image::desaturate(){
  for (unsigned x = 0; x<width(); x++){
    for(unsigned y = 0; y<height();y++){
      HSLAPixel *p = getPixel(x,y);
      p->s = p->s - 0.1;
      if (p->s > 1){
        p->s = 1;
      }
      if (p->s < 0){
        p->s = 0;
      }
    }
  }
}

void Image::desaturate(double amount){
  for (unsigned x = 0; x<width(); x++){
    for(unsigned y = 0; y<height();y++){
      HSLAPixel *p = getPixel(x,y);
      p->s = p->s - amount;
      if (p->s > 1){
        p->s = 1;
      }
      if (p->s < 0){
        p->s = 0;
      }
    }
  }
}

void Image::grayscale(){
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      HSLAPixel *pixel = getPixel(x, y);
      pixel->s = 0;
    }
  }
}

void Image::rotateColor(double degrees){
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      HSLAPixel *pixel = getPixel(x, y);
      pixel->h = pixel->h + degrees;
      if (pixel->h > 360){
        pixel->h = pixel->h-360;
      }
      else if (pixel->h < 0){
        pixel->h = pixel->h +360
      }
    }
  }
}

void Image::illinify(){
  for (unsigned x = 0; x < width(); x++) {
    for (unsigned y = 0; y < height(); y++) {
      HSLAPixel *pixel = getPixel(x, y);
      if (pixel->h>=113.5 && pixel->h<=293.5){
        pixel->h = 216;
      }else{
      pixel->h = 11;
    }
    }
  }
}

void Image::scale(double factor){
  int width = width()/factor;
  int height = height()/factor;
  PNG *newp = new PNG(width(),height());
  for(unsigned x = 0; x < width(); x++){
    for(unsigned y = 0; y < height(); y++){
      HSLAPixel *p1 = newp->getPixel(x,y);
      HSLAPixel *p2 = getPixel(x,y);
      p1->h = p2->h;
      p1->s = p2->s;
      p1->l = p2->l;
      p1->a = p2->a;
    }
  }
  this->resize(width,height);
  for (unsigned x = 0; x < width; x++) {
    for (unsigned y = 0; y < height; y++) {
      //HSLAPixel *pixel = getPixel(floor(x/factor),floor(y/factor));
      HSLAPixel *p2 = newp->getPixel(x/factor,y/factor);
      HSLAPixel *p1 = getPixel(x,y);
      p1->h = p2->h;
      p1->s = p2->s;
      p1->l = p2->l;
      p1->a = p2->a;
    }
  }
  delete newp;
}

void Image::scale(unsigned w, unsigned h){
  int width = width()/w;
  int height = height()/h;
  PNG *newp = new PNG(width(),height());
  for(unsigned x = 0; x < width(); x++){
    for(unsigned y = 0; y < height(); y++){
      HSLAPixel *p1 = newp->getPixel(x,y);
      HSLAPixel *p2 = getPixel(x,y);
      p1->h = p2->h;
      p1->s = p2->s;
      p1->l = p2->l;
      p1->a = p2->a;
    }
  }
  this->resize(width,height);
  for (unsigned x = 0; x < width; x++) {
    for (unsigned y = 0; y < height; y++) {
      //HSLAPixel *pixel = getPixel(floor(x/factor),floor(y/factor));
      HSLAPixel *p2 = newp->getPixel(x/w,y/h);
      HSLAPixel *p1 = getPixel(x,y);
      p1->h = p2->h;
      p1->s = p2->s;
      p1->l = p2->l;
      p1->a = p2->a;
    }
  }
  delete newp;
}
