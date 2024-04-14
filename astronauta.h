#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class astronauta {
private:
    string cpf;
    string nome;
    int idade;
    vector<int> voo_feitos;

public:
    astronauta(string nome, string cpf, int idade, vector<int> voo_feitos);
    void listar_astronauta() const;
    vector<int> getVoo_feitos() const;
    void add_voo_to_astro(int id_voo);
};

void listar_astronautas(const vector<astronauta>& astro_list);

void cadastrar_astronauta(vector<astronauta>& astro_list);
#endif

