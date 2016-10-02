/*畳み込み層*/
#include <array>
#include <random>
#include <vector>
#include <iostream>

class ConvLayer{
public:
    ConvLayer(const std::vector< std::vector<double> >  &input);
    void conv(const std::vector< std::vector<double> > &input);
    std::vector< std::vector<double> >                  mConvLayer;
private:
    const size_t                                        mFilterSize;
    const std::vector< std::vector<double> >            mInput;
    double  mFilter[3][3];
    double  calcConv(size_t i, size_t j, const std::vector< std::vector<double> > &input);
};
