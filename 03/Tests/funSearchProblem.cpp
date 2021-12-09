#include "funSearchProblem.h"

FunSearchProblem::FunSearchProblem() {}

//-----------------------------------------------------------------

// TODO
int FunSearchProblem::facingSun(const vector<int> & values) {
   int build = 0;
   int height = 0;
   for (auto i:values){
       if(i>height){
           build++;
           height = i;
        }
    }
    return build;
}

// TODO
int FunSearchProblem::squareR(int num) {
    int i = num/2;
    int j ; //80 40 20 10 5
    if (num == 0 || num == 1 ) return num;
    if (i*i == num) return i;
    bool verify = true;
    while(true){
//80 40 20 10 5 7 9 4 6 9
        if(i*i>num){
            if(!verify || ((i-1)*(i-1))<num){
                return i-1;}
                else{i=i-1;}
            i= i/2;
            //4
        }
        if(i*i<=num){
            j = i;
            i = i+i/2;
            verify = false;
        }


    }}


// TODO
int FunSearchProblem::smallestMissingValue(const vector<int> & values) {
    return 0;
}

// TODO
int FunSearchProblem::minPages(const vector<int> & values, int numSt) {
    return 0;
}

