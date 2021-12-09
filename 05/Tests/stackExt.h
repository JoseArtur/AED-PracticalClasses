# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
	stack<T> values;
	stack<T> minimums;
public:
	StackExt() {};
	bool empty() const; 
	T& top();
	void pop();
	void push(const T& val);
	T& findMin();
};

//TODO
template <class T> 
bool StackExt<T>::empty() const {
    return values.empty();
}

//TODO
template <class T> 
T& StackExt<T>::top() {
    return *new T(values.top());
}

//TODO
template <class T> 
void StackExt<T>::pop() {
    if(values.top() == minimums.top())
    values.pop();
}

//TODO
template <class T> 
void StackExt<T>::push(const T& val) {
    if(values.empty()) minimums.push(val);
    values.push(val);
    if(values.top()< minimums.top()){
        minimums.pop();
        minimums.push(values.top());
    }
}

//TODO
template <class T> 
T& StackExt<T>::findMin() {
    return minimums.top();
       /* stack<T> copi = values;
        stack<T> min = minimums;
        min.push(copi.top());
        copi.pop();
        while(!copi.empty()){
            
        if(copi.top()< min.top()){
            min.pop();
            min.push(copi.top());
        }
        else {
            copi.pop();
    }}
    return *new T(min.top());*/
}

