#include "PoolingLayer.h"

PoolingLayer::PoolingLayer()
: mPoolSize(3), mPoolOutSize(3)
{
mPoolingLayer.resize( mPoolOutSize, std::vector<double>(mPoolOutSize, 0.0) );
}

PoolingLayer::PoolingLayer(const vector< vector<double> > &input)
: mPoolSize(3), mPoolOutSize(3), mInput(input)
{
    mPoolingLayer.resize( mPoolOutSize, std::vector<double>(mPoolOutSize, 0.0) );
}

void PoolingLayer::pool(const vector< vector<double> > &input)
{
    mInput = input;
    for(size_t i=0; i<mPoolOutSize; ++i){
        for(size_t j=0; j<mPoolOutSize; ++j){
            mPoolingLayer.at(i).at(j) = maxPooling(i, j);
        }
    }
}

double PoolingLayer::maxPooling(size_t i, size_t j)
{
    double max = 0.0;
    size_t halfPool = mPoolSize / 2;

    max = mInput.at(i*mPoolOutSize + 1 + halfPool).at(j*mPoolOutSize+1+halfPool);
    for(size_t m=mPoolOutSize*i + 1; m <= mPoolOutSize*i + 1 + (mPoolSize - halfPool); ++m){
        for(size_t n=mPoolOutSize*j + 1; n<=mPoolOutSize*j + 1 + (mPoolSize - halfPool); ++n){
            if( max < mInput.at(m).at(n) ) max = mInput.at(m).at(n);
        }
    }
    return max;
}
