
#ifndef HSLAPixel_H
#define HSLAPixel_H

namespace cs225{

  class HSLAPixel{
    public:
       double h,s,l,a;
       HSLAPixel ();
       HSLAPixel(double hue, double saturation, double luminance);
       HSLAPixel(double hue, double saturation, double luminance, double alpha);  

  };
}
#endif


