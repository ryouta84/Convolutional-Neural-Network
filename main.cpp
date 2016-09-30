#include "CNN.h"
#include <iostream>

using namespace std;

int main()
{
    std::vector< std::vector<double> > v;
    for(int i=0; i<11; ++i){
        v.push_back(std::vector<double>{0,0,0,0,0,1,0,0,0,0,0});
    }
    CNN cnn(v);

    return 0;
}
