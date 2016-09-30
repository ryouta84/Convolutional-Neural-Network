/*畳み込み層*/
#include <array>
#include <vector>
#include <iostream>

class ConvLayer{
public:
    ConvLayer(const std::vector< std::vector<double> >  &input);
    std::vector< std::vector<double> >                  mConvLayer;
    void conv();
private:
    const size_t                                        mFilterSize = 3;
    const std::vector< std::vector<double> >            mInput;
    const double  mFilter[3][3]
    = {
       {0,1,0},
       {0,1,0},
       {0,1,0},
      };
    double  calcConv(size_t i, size_t j);
};
