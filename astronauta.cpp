#include "astronauta.h"
#include <iostream>
#include "voo.h"
using namespace std;

astronauta::astronauta(string nome, string cpf, int idade, vector<int> voo_feitos) {
    this->cpf = cpf;
    this->nome = nome;
    this->idade = idade;
    this->voo_feitos = voo_feitos;
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
    cout << "Voos Participados: ";
    for (const int& voo : voo_feitos) {
        cout << voo << " ";
    }
    cout << endl;
}

void listar_astronautas(const vector<astronauta>& astro_list) {
    cout << "Lista de Astronautas:" << endl;
    for (const astronauta& a : astro_list) {
        a.listar_astronauta();
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
