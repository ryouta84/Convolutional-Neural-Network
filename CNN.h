////畳み込みニューラルネットワーク
#include "ConvLayer.h"
#include "PoolingLayer.h"
#include "Perceptron.h"
#include <vector>

using namespace std;

class CNN{
public:
    CNN  (const vector< vector<double> > &dummy);
    double input(const vector< vector<double> > &input, double teacher);
    double input(const vector< vector<double> > &input);
private:
    vector< vector<double> > mInput;
    ConvLayer                mConvolutionalLayer0;
    ConvLayer                mConvolutionalLayer1;
    PoolingLayer             mPoolingLayer0;
    PoolingLayer             mPoolingLayer1;
    Perceptron               mPerceptron;
};
