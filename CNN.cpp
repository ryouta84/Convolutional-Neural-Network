#include "CNN.h"

CNN::CNN(const vector< vector<double> > &input)
: mInput(input), mConvolutionalLayer0(input),
 mConvolutionalLayer1(input), mPerceptron(18)
{

    mConvolutionalLayer0.conv(input);
    mConvolutionalLayer1.conv(input);

    mPoolingLayer0.pool(mConvolutionalLayer0.mConvLayer);
    mPoolingLayer1.pool(mConvolutionalLayer1.mConvLayer);

    std::vector<double> v;
    for(auto i : mPoolingLayer0.mPoolingLayer){
        for(auto j : i){
            v.push_back(j);
        }
    }
    for(auto i : mPoolingLayer1.mPoolingLayer){
        for(auto j : i){
            v.push_back(j);
        }
    }
    cout << "perceptron.forward() == " << mPerceptron.forward(v) << endl;
    mPerceptron.learn(1.0);
}


double CNN::input(const vector< vector<double> > &input, double teacher){
    mConvolutionalLayer0.conv(input);
    mConvolutionalLayer1.conv(input);

    mPoolingLayer0.pool(mConvolutionalLayer0.mConvLayer);
    mPoolingLayer1.pool(mConvolutionalLayer1.mConvLayer);

    std::vector<double> v;
    for(auto i : mPoolingLayer0.mPoolingLayer){
        for(auto j : i){
            v.push_back(j);
        }
    }
    cout << endl;
    for(auto i : mPoolingLayer1.mPoolingLayer){
        for(auto j : i){
            v.push_back(j);
        }
    }
    double output = mPerceptron.forward(v);
    mPerceptron.learn(teacher);

    return output;
}

double CNN::input(const vector< vector<double> > &input){
    mConvolutionalLayer0.conv(input);
    mConvolutionalLayer1.conv(input);

    mPoolingLayer0.pool(mConvolutionalLayer0.mConvLayer);
    mPoolingLayer1.pool(mConvolutionalLayer1.mConvLayer);

    std::vector<double> v;
    for(auto i : mPoolingLayer0.mPoolingLayer){
        for(auto j : i){
            v.push_back(j);
        }
    }
    cout << endl;
    for(auto i : mPoolingLayer1.mPoolingLayer){
        for(auto j : i){
            v.push_back(j);
        }
    }
    double output = mPerceptron.forward(v);

    return output;
}
