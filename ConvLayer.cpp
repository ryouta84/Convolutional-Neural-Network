#include "ConvLayer.h"

ConvLayer::ConvLayer(const std::vector< std::vector<double> > &dummy)
: mInput(dummy), mConvLayer(), mFilterSize( sizeof(mFilter)/sizeof(mFilter[0]) )
{
    std::cout << "mFilterSize==" << mFilterSize << std::endl;
    std::cout << "dummy size ==" << dummy.size() << std::endl;
    //入力と同じサイズでresize,要素の値は0.0
    mConvLayer.resize( dummy.size(), std::vector<double>(dummy.front().size(), 0.0) );

    //フィルタの初期化（ランダム）
    std::random_device seedGen;
    std::mt19937 engine(seedGen());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);
    for(auto &i : mFilter){
        for(auto &j : i){
            j = dist(engine);
        }
    }
}

void ConvLayer::conv(const std::vector< std::vector<double> > &input)
{
    size_t startPoint = mFilterSize / 2;

    try{

    for(size_t i = startPoint; i<input.size() - startPoint; ++i){
        for(size_t j = startPoint; j<input.front().size() - startPoint; ++j){
            mConvLayer.at(i).at(j) = calcConv(i, j, input);
            //std::cout << i << "," << j << "  ";
        }
        //std::cout << std::endl << std::endl;
    }

    }catch(std::out_of_range &e){
        std::cerr << "out_of_range:ConvLayer::conv() " << e.what() << std::endl;
    }
}

double ConvLayer::calcConv(size_t i, size_t j, const std::vector< std::vector<double> > &input)
{
    double sum = 0.0;

    try{

    for(size_t m=0; m<mFilterSize; ++m){
        for(size_t n=0; n<mFilterSize; ++n){
            //std::cout << i - mFilterSize/2 + m << "," << j - mFilterSize / 2 + n << " ";
            sum += input.at(i - mFilterSize/2 + m).at(j - mFilterSize/2 + n) * mFilter[m][n];
        }
    }

    }catch(std::out_of_range &e){
        std::cerr << "out_of_range : ConvLayer::calcConv()" << e.what() << std::endl;
    }
    //std::cout << std::endl;

    return sum;
}
