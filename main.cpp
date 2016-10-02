#include "CNN.h"
#include <iostream>

using namespace std;

int main()
{
    std::vector< std::vector<double> > v[4]; //たて成分があればカテゴリ1、横成分はカテゴリ2
    double teacher[4] = {1.0, 0.0, 0.0, 1.0};

    for(int i=0; i<11; ++i){
        v[0].push_back( vector<double>{0,0,0,0,0,1,0,0,0,0,0} );
    }
    CNN cnn(v[0]);

    for(int i=0; i<11; ++i){
        if(i==5) {
            v[1].push_back( std::vector<double>{1,1,1,1,1,1,1,1,1,1,1} );
        }else{
            v[1].push_back( std::vector<double>{0,0,0,0,0,0,0,0,0,0,0} );
        }
    }

    for(int i=0; i<11; ++i){
        if( (i==4) || (i==5) || (i==6) ){
            v[2].push_back( std::vector<double>{1,1,1,1,1,1,1,1,1,1,1} );
        }else{
            v[2].push_back( std::vector<double>{0,0,0,0,0,0,0,0,0,0,0} );
        }
    }

    for(int i=0; i<11; ++i){
        v[3].push_back( vector<double> {0,0,0,0,1,1,1,0,0,0,0} );
    }
    std::cout << fixed;

    double error = 100.0;
    while(error > 0.001) {
        error = 0.0;
        for(int i=0; i<4; ++i){
            double o = 0.0;
            o = cnn.input(v[i], teacher[i]);
            std::cout << i+1 << " output == "<< o << std::endl;
            error += (teacher[i] - o) * (teacher[i] - o);
            std::cout << "error == " << (o - teacher[i]) * (o - teacher[i]) << std::endl;
        }
        cout << "total error == "<< error << endl;
    }

    size_t index;
    while(true){
        cin >> index;
        if( 1 <= index && index <= 4){
            cout << "category" << (int)(cnn.input(v[index-1])+0.2)<< endl;
        }
        cout << endl;
    }


    return 0;
}
