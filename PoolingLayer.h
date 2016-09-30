/*
プーリング層
*/
#include <vector>

using namespace std;

class PoolingLayer{
public:
    PoolingLayer();
    PoolingLayer(const vector< vector<double> > &input);
    vector< vector<double> > mPoolingLayer;
    void    pool(const vector< vector<double> > &input);
private:
    size_t                          mPoolSize;
    size_t                          mPoolOutSize;
    vector< vector<double> >  mInput;
    double  maxPooling(size_t i, size_t j);
};
