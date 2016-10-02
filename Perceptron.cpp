#include "perceptron.h"

Perceptron::Perceptron(size_t dSize)
:  mDataSize(dSize), mHiddenSize(3),
  weight(new double[ mDataSize*mHiddenSize + mHiddenSize ]),
  threshold( new double[mHiddenSize+1] ), output( new double[mHiddenSize+1] )
{
    init();
}

double Perceptron::forward(vector<double> &input)
{
    mInput = input;
try{
    //中間層の計算
    for(size_t i=0; i<mHiddenSize; ++i){
        double hidbuf=0;
        for(int j=0; j<mDataSize; ++j){
            hidbuf += weight[i*mDataSize * j] * mInput.at(j);
        }
        output[i] = f(hidbuf - threshold[i]);
    }
    //出力層の計算
    size_t outputLayerBegin = mDataSize * mHiddenSize;
    double outbuf = 0.0;
    for (size_t i =0; i < mHiddenSize; ++i) {
         outbuf += weight[outputLayerBegin+i] * output[i];
    }
    output[mHiddenSize] = f(outbuf - threshold[mHiddenSize]);

}catch(out_of_range &e){
    std::cerr << "out_of_range : Perceptron::forward()" << e.what() << std::endl;
}

    return output[mHiddenSize];
}

void Perceptron::learn(double teacher)
{
    double E = teacher - output[mHiddenSize];

    //出力層の学習
    outputLayerLearn(E);

    //中間層の学習
    double di =0.0;
    double o = output[mHiddenSize];
    //std::cout << "--------------------weight of hidden layer--------------------" << std::endl;
    for(size_t i=0; i<mHiddenSize; ++i){ //i番目のセル
        di = output[i] * weight[mDataSize*mHiddenSize] * E * o * (1-o);
        for(size_t j=0; j<mDataSize; ++j){ //i番目のセルのj番目の入力
            weight[i*mHiddenSize + j] = weight[i*mHiddenSize + j] + alpha * mInput.at(j) * di;
            //cout << weight[i * mHiddenSize + j] << " ";
        }
        threshold[i] += alpha * (-1.0) * di;
    }
    //std::cout << std::endl << "--------------------------------------------------------------" << std::endl;
}

void Perceptron::outputLayerLearn(double E)
{
    //std::cout << "--------------------weight of ouput layer-------------------" << std::endl;
    for (size_t i = 0; i < mHiddenSize; i++) {
        weight[mDataSize*mHiddenSize + i] += alpha * E * output[mHiddenSize] * (1- output[mHiddenSize] ) * output[i];
        //cout << weight[mDataSize*mHiddenSize + i] << " ";
    }
    threshold[mHiddenSize] += alpha * E * output[mHiddenSize] * (1- output[mHiddenSize] ) * (-1);
    //std::cout << std::endl << "------------------------------------------------------------" << std::endl;
}

double Perceptron::f(double u)
{
    //シグモイド関数
    return 1.0 / ( 1.0 + exp(-u) );
}

void Perceptron::init()
{
    std::random_device seedGen;
    std::mt19937 engine(seedGen());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);

    //重みの初期化
    cout << "-----------weight init-------------" << endl;
    int count=0;
    for(size_t i=0; i<mDataSize*mHiddenSize + mHiddenSize; ++i){
        weight[i] = dist(engine);
        cout << weight[i] << " ";
        count++;
        if( (count % mDataSize) == 0) std::cout << std::endl;
    }
    cout << endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "------------threshold init-------------" << std::endl;
    for(size_t i=0; i<mHiddenSize+1; ++i){
        threshold[i] = dist(engine);
        cout << threshold[i] << " ";
    }
    cout << endl;
    std::cout << "--------------------------------" << std::endl;
}
