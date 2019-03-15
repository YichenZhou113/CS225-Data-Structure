#include "StickerSheet.h"
#include "Image.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using namespace cs225;
using namespace std;

StickerSheet::StickerSheet(const Image &picture, unsigned max){
 P_ = picture;
 m_ = max;
 A_ = new Image[m_];
 x_ = new unsigned int[m_];
 y_ = new unsigned int[m_];
 vc_ = new unsigned int[m_];
 index_ = 0;
 for(unsigned int i = 0;i<m_;i++){
   vc_[i] = 0;//invalid right now
 }
}

StickerSheet::~StickerSheet(){
  delete [] A_;
  delete [] x_;
  delete [] y_;
  delete [] vc_;
  A_ = NULL;
  x_ = NULL;
  y_ = NULL;
  vc_ = NULL;
}

StickerSheet::StickerSheet(const StickerSheet &other){
  P_ = other.P_;
  m_ = other.m_;
  index_ = other.index_;
  A_ = new Image[m_];
  x_ = new unsigned int[m_];
  y_ = new unsigned int[m_];
  vc_ = new unsigned int[m_];
  for (unsigned int i = 0; i<m_; i++){
    A_[i] = other.A_[i];
    x_[i] = other.x_[i];
    y_[i] = other.y_[i];
    vc_[i] = other.vc_[i];
  }
  //  cout << "case11" <<endl;
}

const StickerSheet& StickerSheet::operator=	(	const StickerSheet & 	other	){
  this->P_ = other.P_;
  this->m_ = other.m_;
  this->index_ = other.index_;
  this->A_ = new Image[m_];
  this->x_ = new unsigned int[m_];
  this->y_ = new unsigned int[m_];
  this->vc_ = new unsigned int[m_];
  for(unsigned int i = 0; i< m_;i++){
    A_[i] = other.A_[i];
    x_[i] = other.x_[i];
    y_[i] = other.y_[i];
    vc_[i] = other.vc_[i];
  }
  return *this;
}

void StickerSheet::changeMaxStickers	(	unsigned 	max	)	{

  Image *nA = new Image[m_];
  unsigned int *nx = new unsigned int[m_];
  unsigned int *ny = new unsigned int[m_];
  unsigned int *nvc = new unsigned int[m_];

  for(unsigned int i=0; i<m_; i++){
    nA[i] = A_[i];
    nx[i] = x_[i];
    ny[i] = y_[i];
    nvc[i] = vc_[i];
  }
    //  cout<<"lll"<<endl;
  delete []A_;
  delete []x_;
  delete []y_;
  delete []vc_;
  A_ = NULL;
  x_ = NULL;
  y_ = NULL;
  vc_ = NULL;
  A_ = new Image[max];
  x_ = new unsigned int[max];
  y_ = new unsigned int[max];
  vc_ = new unsigned int[max];
  unsigned int c;

  if (max<m_){
    for(unsigned int i=0; i<max; i++){
      A_[i] = nA[i];
      x_[i] = nx[i];
      y_[i] = ny[i];
      vc_[i] = nvc[i];
    }
    index_ = max;
    c = max;
    vc_[max] = 0;
  }else{
    for(unsigned int i=0; i<m_; i++){
      A_[i] = nA[i];
      x_[i] = nx[i];
      y_[i] = ny[i];
      vc_[i] = nvc[i];
    }
    c=m_;
    index_ = m_;
    for(unsigned int i=m_;i<max;i++){
    vc_[i] = 0;
    }
  }
  for(unsigned int i = 0; i< c;i++){
    vc_[i] = 1;
  }
  delete []nA;
  delete []nx;
  delete []ny;
  delete []nvc;
  nA = NULL;
  nx = NULL;
  ny = NULL;
  nvc = NULL;
  //index_ = c;
}


int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y){
  cout<<index_<<m_<<endl;
  if (index_>=m_){
    return -1;
  }
  A_[index_] = sticker;
  x_[index_] = x;
  y_[index_] = y;
  vc_[index_] = 1;
  index_ ++;
  unsigned int r = index_ - 1;
  return r;

}

bool StickerSheet::translate	(	unsigned 	index, unsigned 	x, unsigned 	y){
  if (vc_[index] == 0){
    return false;
  }
  x_[index] = x;
  y_[index] = y;
  return true;
}

void StickerSheet::removeSticker	(	unsigned 	index	)	{
  for(unsigned int i = index; i < m_; i++){
    A_[i] = A_[i+1];
    x_[i] = x_[i+1];
    y_[i] = y_[i+1];
    vc_[i] = vc_[i+1];
  }
  vc_[m_] = 0;
  index_ = index_-1;
}


Image* StickerSheet::getSticker	(	unsigned 	index	)	const{

  if (vc_[index] == 0){
    //cout<<vc_[index]<<endl;
    return NULL;
  }
  cout<<"get"<<endl;
 Image *p = &A_[index];
 return p;
}


Image StickerSheet::render()const{
  PNG *t1 = new PNG();
	Image *t2 = new Image();
	Image PP = P_;
	unsigned int width = P_.width();
	unsigned int height = P_.height();
  unsigned int check = 0;
	t1->resize(width, height);
	t2->resize(width, height);
	for (unsigned int i = 0; i < width; i++)//
	{
		for (unsigned int j = 0; j < height; j++)
		{
			HSLAPixel *o = PP.getPixel(i, j);
			HSLAPixel *n = t1->getPixel(i, j);
			n->h = o->h;
			n->s = o->s;
			n->l = o->l;
			n->a = o->a;
		}
	}
	while (vc_[check] == 1)
	{
		Image pc = A_[check];
		int xx = x_[check];
		int yy = y_[check];
		unsigned int nw = pc.width();
		unsigned int nh = pc.height();
		PNG *ns = new PNG();
    for (unsigned int i = xx; i < xx + nw; i++)
    		{
    			for (unsigned int j = yy; j < yy + nh; j++)
    			{
    				HSLAPixel *l = pc.getPixel(i-xx, j-yy);
    				HSLAPixel *n = t1->getPixel(i, j);
    				if (l->a == 0)
    					continue;
    				n->h = l->h;
    				n->s = l->s;
    				n->l = l->l;
    				n->a = l->a;
    			}
    		}
    		check = check + 1;
    	}
    	t2->resize(t1->width(), t1->height());
    	for (unsigned int i = 0; i < t1->width(); i++)
    	{
    		for (unsigned int j = 0; j < t2->height(); j++)
    		{
    			HSLAPixel *oo = t1->getPixel(i, j);
    			HSLAPixel *nn = t2->getPixel(i, j);
    			nn->l = oo->l;
    			nn->h = oo->h;
    			nn->s = oo->s;
    			nn->a = oo->a;
    		}
    	}
    	PP.resize(t1->width(), t1->height());
    	for (unsigned int i = 0; i < t1->width(); i++)
    	{
    		for (unsigned int j = 0; j < t1->height(); j++)
    		{
    			HSLAPixel *oo = t1->getPixel(i, j);
    			HSLAPixel *nn = PP.getPixel(i, j);
    			nn->h = oo->h;
    			nn->s = oo->s;
    			nn->l = oo->l;
    			nn->a = oo->a;
    		}
    	}
    	delete t1;
    	delete t2;
      t1 = NULL;
      t2 = NULL;
    	return PP;
}
