#ifndef _STICKERSHEET_H
#define _STICKERSHEET_H
#include <string>
#include "Image.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using namespace std;
using namespace cs225;

class StickerSheet{
public:
  StickerSheet(const Image &picture, unsigned max);

  ~StickerSheet();

  StickerSheet(const StickerSheet &other);

  const StickerSheet &	operator= (const StickerSheet &other);

  void changeMaxStickers(unsigned max);

  int addSticker(Image &sticker, unsigned x, unsigned y);

  bool 	translate(unsigned index, unsigned x, unsigned y);

  void 	removeSticker(unsigned index);

  Image *getSticker(unsigned index) const;

  Image render() const;


private:
  Image P_;
  Image *A_;
  unsigned int index_;
  unsigned int *x_;
  unsigned int *y_;
  unsigned int m_;
  unsigned int *vc_;

};
#endif
