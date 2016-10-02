#include "PoolingLayer.h"

PoolingLayer::PoolingLayer()
: mPoolSize(3), mPoolOutSize(3)
{
mPoolingLayer.resize( mPoolOutSize, std::vector<double>(mPoolOutSize, 0.0) );
}

void PoolingLayer::pool(const vector< vector<double> > &input)
{
    try{

    for(size_t i=0; i<mPoolOutSize; ++i){
        for(size_t j=0; j<mPoolOutSize; ++j){
            mPoolingLayer.at(i).at(j) = maxPooling(i, j, input);
        }
    }

    }catch(out_of_range &e){
        std::cerr << "out_of_range : PoolingLayer::pool()" << e.what() << std::endl;
    }

}

double PoolingLayer::maxPooling(size_t i, size_t j, const std::vector< std::vector<double> > &input)
{
    double max = 0.0;
    size_t halfPool = mPoolSize / 2;

    try{

    max = input.at(i*mPoolOutSize + 1 + halfPool).at(j*mPoolOutSize+1+halfPool);
    for(size_t m=mPoolOutSize*i + 1; m <= mPoolOutSize*i + 1 + (mPoolSize - halfPool); ++m){
        for(size_t n=mPoolOutSize*j + 1; n<=mPoolOutSize*j + 1 + (mPoolSize - halfPool); ++n){
            if( max < input.at(m).at(n) ) max = input.at(m).at(n);
        }
    }

    }catch(out_of_range &e){
        cerr << "out_of_range : PoolingLayer::maxPooling() " << e.what() << endl;
    }
    return max;
}
