#include "parque.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;
ParqueEstacionamento::ParqueEstacionamento(unsigned  lot, unsigned  nMaxCli):
        lotacao(lot), numMaximoClientes(nMaxCli)
        { //vagas=lot;
    }

unsigned ParqueEstacionamento::getNumLugares() const{
    return lotacao;
}

unsigned ParqueEstacionamento::getNumMaximoClientes() const{
    return numMaximoClientes;
}
int ParqueEstacionamento::posicaoCliente(const string & nome) const{

        /*auto finder = std::find(clientes.begin(), clientes.end(), nome);
        if (finder != clientes.end())
            return finder - finder.begin();
        return -1;*/
         for (auto i = 0; i <= clientes.size(); i++) {
            if (clientes[i].nome == nome)
                 return i;
     }
         return -1;
}

bool ParqueEstacionamento::adicionaCliente(const string & nome){
    //- o sucesso (true) ou insucesso (false) na adição/registo de um novo cliente ao parque de estacionamento.
    //ou o cliente está dentro do parque ou o parque está lotado
    if (clientes.size() == numMaximoClientes) return false;
    if (posicaoCliente(nome) != -1) return false;
    return true;
}
bool ParqueEstacionamento::entrar(const string & nome){
//Esta função regista a entrada de um cliente no parque. Retorna false se o cliente não puder entrar (não
//está registado, a sua viatura já está dentro do parque, ou o parque está completo).
    if ((adicionaCliente(nome)==true)  or (posicaoCliente(nome) != -1) or (clientes.size() < numMaximoClientes))  return false;
    return true;
}
bool ParqueEstacionamento::retiraCliente(const string & nome){
    //Esta função retira o registo do cliente de nome nome do parque de estacionamento. A remoção do cliente
    //    só é possível se este estiver atualmente fora do parque
    for (auto it = clientes.begin(); it != clientes.end(); it++)
        if ( (*it).nome == nome ) {
            if ( (*it).presente == false ) {
                clientes.erase(it);
                return true;
            }
            else return false;
        }
    return false;
}

bool ParqueEstacionamento::sair(const string & nome){
    //Esta função regista a saída de um cliente do parque. Retorna false se o cliente não puder sair (não está
    //registado ou a sua viatura não está dentro do parque).
    if (!entrar(nome) or posicaoCliente(nome)==-1) return false;
    return true;

}
unsigned ParqueEstacionamento::getNumLugaresOcupados() const{
    return lotacao-vagas;
}
unsigned ParqueEstacionamento::getNumClientesAtuais() const{
    return clientes.size();
}

