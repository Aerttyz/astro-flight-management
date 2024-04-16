#include "astronauta.h"
#include <iostream>
#include "voo.h"
using namespace std;

astronauta::astronauta(string nome, string cpf, int idade, vector<int> voo_feitos, string status) {
    this->cpf = cpf;
    this->nome = nome;
    this->idade = idade;
    this->voo_feitos = voo_feitos;
    this->status = status;
}

void astronauta::kill_astro(){
    status = "MORTO";
}

string astronauta::getStatusAstro(){
    return status;
}

bool astronauta::astro_in_voo(int id_voo,vector<voo>& voo_list){
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
vector<int> astronauta::getVoo_feitos() const {
    return voo_feitos;
}

void astronauta::add_voo_to_astro(int id_voo){
    voo_feitos.push_back(id_voo);
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

void listar_astronautas(const vector<astronauta>& astro_list) {
    cout << "Lista de Astronautas:" << endl;
    int i=0;
    for (const astronauta& a : astro_list) {
        cout << "ID: " << i << endl;
        a.listar_astronauta();
        i++;
        cout << endl;
    }
}

void cadastrar_astronauta(vector<astronauta>& astro_list) {
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

    vector<int> voo_feitos;
    astronauta Astronauta(nome, cpf, idade, voo_feitos);
    astro_list.push_back(Astronauta);
}
