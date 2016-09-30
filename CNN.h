////畳み込みニューラルネットワーク
#include "ConvLayer.h"
#include "PoolingLayer.h"
#include <vector>

using namespace std;

class CNN{
public:
    CNN(const vector< vector<double> > &input);
private:
    vector< vector<double> >         mInput;
    ConvLayer                        mConvolutionalLayer;
    PoolingLayer                     mPoolingLayer;
};
