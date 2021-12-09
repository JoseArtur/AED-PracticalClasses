#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

template <class T>
class MyVector {
    vector<T> values;
public:
    MyVector();
    ~MyVector();
    void push_back(T v1);
    vector<T> getValues() const;
    T max() const;
    bool hasDuplicates() const;
    void removeDuplicates() ;
};


// exception EmptyVector
class EmptyVector
{ };

// methods
template <class T>
MyVector<T>::MyVector() {}

template <class T>
MyVector<T>::~MyVector() {}

template <class T>
void MyVector<T>::push_back(T v1) {
    values.push_back(v1);
}

template <class T>
vector<T> MyVector<T>::getValues() const {
    return values;
}

//---------------------------------

// TODO
template <class T>
T MyVector<T>::max() const {
    if(values.empty() ) throw EmptyVector();
    else{
        T higher = values[0];
        for(int i=1;i<values.size();i++){
            if(values[i]>higher) //1 2 5 1 2 4
                higher = values[i];
        }
        return  higher;
    }
}
// TODO
template<typename T>
bool equals(const T& a, const T& b)
{
    return !(a<b || b<a);
}

template<class T>
bool MyVector<T>::hasDuplicates() const {
 set<T> Myset;
 for(T value:values) {
     Myset.insert(value);
 }
 if(Myset.size()!=values.size()) return true;
return false;
//O(n)
}

// TODO
template<class T>
void MyVector<T>::removeDuplicates() {
    unordered_set<T> Myset = {} ;
    vector<T> Myvec = {};
    /*
    for(T value:values) Myset.insert(value);
    if(Myset.size()!=values.size()){
        */
        auto end = copy_if(values.begin(), values.end(), values.begin(),
                                [&Myset](int const &i) {return Myset.insert(i).second;
                                }); // [&Myset] is been passing by reference,

        values.erase(end, values.end());
    }




