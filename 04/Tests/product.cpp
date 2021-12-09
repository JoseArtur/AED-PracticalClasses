#include "product.h"

Product::Product(string i, float p, float w): id(i), price(p), weight(w) {}

string Product::getId() const {
    return id;
}

float Product::getPrice() const {
    return price;
}

float Product::getWeight() const {
    return weight;
}
bool Product::operator<(const Product &a) const{
    if(price<a.getPrice()) return true;
    if(price == a.getPrice())return (weight<a.getWeight());
    return false;
}