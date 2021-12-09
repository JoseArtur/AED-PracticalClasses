#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

BST<WordMean> Dictionary::getWords() const {
	return words;
}

// ---------------------------------------------

//TODO

bool WordMean::operator < (const WordMean& a )  const {
    return word < a.getWord();
}
bool WordMean::operator == (const WordMean& a )  const {
    return word == a.getWord();
}

void Dictionary::readFile(ifstream &f) {;
    string name;
    string mean;
    while (!f.eof()){
        getline(f,name);
        getline(f,mean);
        WordMean a(name,mean);
        words.insert(a);
    }

}

//TODO
string Dictionary::consult(string word1, WordMean& previous, WordMean& next) const {
    if (WordMean("", "") == words.find(WordMean(word1,""))) {
        iteratorBST<WordMean> it = words.begin();
        while (it != words.end()) {
            if ((word1 < (*it).getWord())) {
                next = *it;
                return "word not found";
            } else previous = *it;
            it++;
        }
        return "word not found";
    }
    else return  words.find(WordMean(word1,"")).getMeaning();

}
//TODO
bool Dictionary::update(string word1, string mean1) {
    if (words.find(WordMean(word1,""))==WordMean("","")) {
        words.insert(WordMean(word1,mean1));
        return false;
    }
    else {
        words.remove(WordMean(word1,""));
        WordMean(word1,"").setMeaning(mean1);
        words.insert(WordMean(word1,mean1));
        return true;
}}

//TODO
void Dictionary::print() const {
   iteratorBST<WordMean> a =words.begin();
    while(a != words.end()){
       cout<<(*a).getWord()<<endl;
       cout<<(*a).getMeaning()<<endl;
       a++;
    }

    }

