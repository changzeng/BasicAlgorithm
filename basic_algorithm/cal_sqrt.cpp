#include <cmath>
#include <iostream>

using namespace std;

double sqrt(double val){
    double res = val/2.0, l=0.0, r=val;
    while(abs(res*res-val) > 0.001){
        res = (l+r)/2.0;
        if(res*res-val > 0)
            r=res;
        else
            l=res;
    }
    cout<<endl;
    return res;
}

int main(){
    cout<<sqrt(4.0)<<endl;
    cout<<sqrt(3.0)<<endl;
    return 0;
}
