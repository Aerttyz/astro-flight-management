#include "astronauta.h"
#include <iostream>
#include "voo.h"
using namespace std;

astronauta::astronauta(string nome, string cpf, int idade, list<int> voo_feitos, string status) {
    this->cpf = cpf;
    this->nome = nome;
    this->idade = idade;
    this->voo_feitos = voo_feitos;
    this->status = status;
}

void astronauta::kill_astro(){
    status = "MORTO";
}

string astronauta::getNome() const{
    return nome;
}

string astronauta::getCpf() const{
    return cpf;
}


string astronauta::getStatusAstro() const{
    return status;
}

bool astronauta::astro_in_voo(int id_voo,list<voo>& voo_list){
    cout << "entrou na def" << endl;
    for(int id : voo_feitos) {
        cout << "entrou for1" << endl;
        if(id == id_voo) {
            cout << "entrou if1" << endl;
            for(voo& v : voo_list) {
                
                cout << "entrou for2" << endl;
                if(v.getId() == id_voo) {
                    cout << "entrou if2" << endl;
                    string status = v.vefStatus(id_voo, voo_list); 
                    cout << status << endl;
                    if(status == "LANCADO") {
                        cout << "retornou true" << endl;
                        return true;
                        break;
                    } else {
                        cout << "retornou false" << endl;
                        return false;
                        break;
                    }
                }
            }
        }
    }
    return false;
}
list<int> astronauta::getVoo_feitos() const {
    return voo_feitos;
}

void astronauta::add_voo_to_astro(int id_voo){
    voo_feitos.push_back(id_voo);
}

void astronauta::listar_astronauta_voo() const{
    cout << "Nome: " << nome << endl;
    cout << "CPF: " << cpf << endl;
    cout << "Idade: " << idade << endl;
}
void astronauta::listar_astronauta() const {
    cout << "Nome: " << nome << endl;
    cout << "CPF: " << cpf << endl;
    cout << "Idade: " << idade << endl;
    cout << "Status: " << status << endl;
    cout << "Voos Participados: " << endl;
    for (const int& voo : voo_feitos) {
        cout << voo << " " << endl;
    }
    cout << "-----------------" << endl;
}

void listar_mortos(list<astronauta>& astro_list) {
    cout << "Lista de Astronautas Mortos:" << endl;
    
    // Itera pela lista de astronautas
    for (const astronauta& a : astro_list) {
        // Verifica se o status do astronauta é "MORTO"
        if (a.getStatusAstro() == "MORTO") {
            // Exibe informações do astronauta morto
            cout << "Nome: " << a.getNome() << ", CPF: " << a.getCpf() << endl;
            
            // Exibe os voos feitos pelo astronauta morto
            cout << "Voos feitos: ";
            for (const int& voo : a.getVoo_feitos()) {
                cout << voo << "|";
            }
            cout << endl;
        }
    }
}

void listar_astronautas(const list<astronauta>& astro_list) {
    cout << "Lista de Astronautas:" << endl;
    for (const astronauta& a : astro_list) {
        a.listar_astronauta();
        cout << endl;
    }
}

void cadastrar_astronauta(list<astronauta>& astro_list) {
    int idade;
    string nome, cpf;

    cout << "Nome: ";
    cin.ignore(); // Limpa o buffer do teclado
    getline(cin, nome);

    cout << "CPF: ";
    getline(cin, cpf);

    cout << "Idade: ";
    cin >> idade;
    cin.ignore(); // Limpa o buffer do teclado

    list<int> voo_feitos;
    astronauta Astronauta(nome, cpf, idade, voo_feitos);
    astro_list.push_back(Astronauta);
}
