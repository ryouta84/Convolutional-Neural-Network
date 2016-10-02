#pragma once

#include <memory>
#include <random>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;
/*
一つのデータの要素数と隠れ層のセルの数は同じにする
*/
class Perceptron {
public:
    Perceptron(size_t dSize);
    double  forward(vector<double> &input);
    void    learn(double teacher);
private:
    vector<double> mInput;
    size_t mDataSize;    //一つの教師データの要素数
    size_t mHiddenSize;  //中間層のセルの個数
    double f(double u);
    void outputLayerLearn(double E);
    void init();
    const unique_ptr<double[]> weight;
    const unique_ptr<double[]> threshold;
    const unique_ptr<double[]> output;

    double alpha = 5.0;
};
