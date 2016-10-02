/*
プーリング層
*/
#include <iostream>
#include <vector>

using namespace std;

class PoolingLayer{
public:
    PoolingLayer();
    vector< vector<double> > mPoolingLayer;
    void    pool(const vector< vector<double> > &input);
private:
    size_t mPoolSize;
    size_t mPoolOutSize;
    double  maxPooling(size_t i, size_t j, const std::vector< std::vector<double> > &input);
};
