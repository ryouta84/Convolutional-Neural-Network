#include "CNN.h"

CNN::CNN(const vector< vector<double> > &input)
: mInput(input), mConvolutionalLayer(input)
{
    mConvolutionalLayer.conv();
    for(auto i : mConvolutionalLayer.mConvLayer){
        for(auto j : i){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    mPoolingLayer.pool(mConvolutionalLayer.mConvLayer);

    for(auto i : mPoolingLayer.mPoolingLayer){
        for(auto j : i){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}
