#include "ConvLayer.h"

ConvLayer::ConvLayer(const std::vector< std::vector<double> > &input)
: mInput(input), mConvLayer()
{
    mConvLayer.resize( input.size(), std::vector<double>(input.front().size(), 0.0) );
}

void ConvLayer::conv()
{
    size_t startPoint = mFilterSize / 2;

    try{

    for(size_t i = startPoint; i<mInput.size() - startPoint; ++i){
        for(size_t j = startPoint; j<mInput.at(i).size() - startPoint; ++j){
            mConvLayer.at(i).at(j) = calcConv(i, j);
            //std::cout << i << "," << j << "  ";
        }
        //std::cout << std::endl << std::endl;
    }

    }catch(std::out_of_range &e){
        std::cerr << "out_of_range:ConvLayer::conv() " << e.what() << std::endl;
    }
}

double ConvLayer::calcConv(size_t i, size_t j)
{
    double sum = 0.0;

    for(size_t m=0; m<mFilterSize; ++m){
        for(size_t n=0; n<mFilterSize; ++n){
            std::cout << i - mFilterSize/2 + m << "," << j - mFilterSize / 2 + n << " ";
            sum += mInput.at(i - mFilterSize/2 + m).at(j - mFilterSize / 2 + n) * mFilter[m][n];
        }
    }
    std::cout << std::endl;

    return sum;
}
