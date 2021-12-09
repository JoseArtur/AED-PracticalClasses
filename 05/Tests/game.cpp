#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;


unsigned int Game::numberOfWords(string phrase) {
  if ( phrase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = phrase.find(' ');
  while (pos != string::npos) {
    phrase = phrase.substr(pos+1);
    pos = phrase.find(' ');
    n++;
  }
  return n;
}

Game::Game() {
	this->kids.clear();
}

Game::Game(list<Kid>& l2) {
	this->kids = l2;
}

//-----------------------------------------------------------------

// TODO
void Game::addKid(const Kid k1) {
    kids.push_back(k1);
}

// TODO
list<Kid> Game::getKids() const {
    return (list<Kid>(kids));
}

// TODO
void Game::setKids(const list<Kid>& l1) {
    for(Kid kid:l1){
        kids.push_back(kid);
    }
}
// ALINEA A ACIMA

// TODO
Kid Game::loseGame(string phrase) {

    int i = 0;
    list<Kid>::iterator itg= kids.begin();
    list<Kid>::iterator initial= kids.begin();

    bool v;

    while(kids.size()!=1){
        itg = initial;
        int size = kids.size();
        int n = numberOfWords(phrase);
        int rest = n%size;
        rest = (rest==0) ? size : rest;
        for(itg;itg !=kids.end();){


         i++;
         if(i == rest){ //se a posicao for igual ao resto
             list<Kid>::iterator aux = next(itg,1);
             aux = (aux == kids.end()) ? kids.begin() :aux;
             if(next(itg,1) ==kids.end()){
                  v = true;
             }
              kids.remove(*itg);
              if(v){itg = kids.begin();}
             if(next(initial,1) == kids.end()){
                 initial = kids.begin();
             }else initial = aux;
              i = 0;
              break;
         }
         if(next(itg,1) == kids.end()){
             itg = kids.begin();
         }
         else itg++;
     }
    }
     return Kid(*itg);
}

// TODO
list<Kid> Game::removeOlder(unsigned id) {
    //
    list<Kid> rest ;
    list<Kid>::iterator princ = kids.begin();
    list<Kid>::iterator aux;

    for(princ;princ!=kids.end();){
        if((*princ).getAge() >id){
            rest.push_back((*princ));
            aux = next(princ,1);
            kids.remove(*princ);
            princ = aux;
        }else princ++;
    }
    return (rest);
}

// TODO
queue<Kid> Game::rearrange() {
    list<Kid> boys;
    list<Kid> girls;
    list<Kid> auxiliar;
    queue<Kid> resto;
    for(Kid kid:kids){
      if(kid.getSex() == 'm'){
          boys.push_back(kid);
      }
      else girls.push_back(kid);
    }
    //agora defino o padrao
    list<Kid>::iterator itg = girls.begin();
    list<Kid>::iterator itb = boys.begin();

    int padrao1= boys.size()/girls.size();
    int padrao2= girls.size()/ boys.size();
    //exemplo  ana rui rui ana rui 1 5
    {
    if(boys.size()> girls.size()){
        while(true){
        if(girls.empty() || padrao1>boys.size()){
            for(auto kid:girls){resto.push(kid);}
            for(auto kid:boys){resto.push(kid);}
            break;}
        else
        {auxiliar.push_back(girls.front());
        girls.remove(girls.front());
         //1 menina e m/n menino
        for(int i =1;i<=padrao1;i++) {
            auxiliar.push_back(boys.front());
            boys.remove(boys.front());}}}

        }else
            while(true){
            if(boys.empty() || padrao2>girls.size()){
                for(auto kid:girls){resto.push(kid);}
                for(auto kid:boys){resto.push(kid);}
                break;}else{
                for(int i =1;i<=padrao2;i++) {
                    auxiliar.push_back(girls.front());
                    girls.remove(girls.front());}}
            auxiliar.push_back(boys.front());
            boys.remove(boys.front());}
            //1 menina e m/n menino
   kids = auxiliar;
    return((resto));
}}

// TODO
bool Game::operator==(Game& g2) {
    list<Kid>::iterator princ = kids.begin();
    list<Kid> list2 = g2.getKids();
    list<Kid>::iterator another = list2.begin();
    if(list2.size() != kids.size()) return false;
    for(princ;princ!=kids.end();){
        if(!(*princ == *another) ){
            return false;
        }
        princ++;
        another++;
    }
        return true;
}

// TODO
list<Kid> Game::shuffle() const {
    list<Kid> randomlist = kids;
    int n,last,first,i;
    list<Kid>::iterator itg = randomlist.begin();
    list<Kid>::iterator it2 = randomlist.begin();
    n = randomlist.size();
    for (i = n-1; i > 0; --i) {
        itg = next(itg, i);
        it2 = next(itg, (rand() % (i + 1)));
        if(itg == randomlist.end()) itg = randomlist.begin();
        if(it2 == randomlist.end()) it2 = randomlist.begin();
        swap(*itg, *it2);
    }
	return (randomlist);
}
