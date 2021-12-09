#include "funSortProblem.h"
#include <algorithm>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------




// TODO
void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
    if(k<products.size()) {
        sort(products.begin(), products.end());

        products.erase(products.begin() + k, products.end());
        //for(int times = products.size() - k;times!=0;times--) products.pop_back();
    }
}

// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    vector<int>  auxiliar ={};
    for(auto value:values){
        int sig = (int) value;
        auxiliar.push_back(sig);
    }
    sort(auxiliar.begin(),auxiliar.end());
    int min=1000;
// 1 2 3 4
    if(auxiliar.size() < nc) return -1;
    for(int i=0; i<auxiliar.size();i++){ //
        int last = auxiliar[i+nc-1];
        int bigger  = auxiliar[auxiliar.size()-1];
        int temp = (last)-auxiliar[i];
        if(temp<min){ // 1 2 3
            min = temp;
        }
        if((last) == bigger) break;
    }
    return min;
}


// TODO
bool sortbysec(const pair<float,char> &a,
               const pair<float,char> &b)
{
    return (a.first < b.first);
}
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    char arr = 'a';
    char dep = 'd';
    vector<pair<float,char >> map;
    for (float value:arrival){map.push_back(make_pair(value, arr));}  //O(n)
    for (float value:departure){map.push_back(make_pair(value, dep));} //O(n)
    sort(map.begin(),map.end(),sortbysec); 

    int higher = 0;
    int temp = higher;
    for(int i=0;i<map.size();i++){ // (O(2n))
        if(map[i].second == arr){higher++;}
        if(map[i].second == dep){higher--;}
        if(higher>temp) {temp = higher;}
    }
    return temp;
}


// TODO

void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {

for(auto bolt: bolts){

}
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

