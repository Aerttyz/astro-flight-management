#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <iostream>
#include <string>
#include <list>
#include "voo.h"
using namespace std;
class voo;
class astronauta {
private:
    string cpf;
    string nome;
    int idade;
    list<int> voo_feitos;
    string status;

public:
    astronauta(string nome, string cpf, int idade, list<int> voo_feitos, string status="VIVO");
    void listar_astronauta() const;
    void listar_astronauta_voo() const;
    list<int> getVoo_feitos() const;
    void add_voo_to_astro(int id_voo);
    bool astro_in_voo(int id_voo, list<voo>& voo_list);
    void kill_astro();
    string getStatusAstro() const;
    string getCpf() const;
    friend void remover_astro(list<voo>& voo_list, list<astronauta>& astro_list);
    string getNome() const;
};

void listar_mortos(list<astronauta>& astro_list);

void listar_astronautas(const list<astronauta>& astro_list);

void cadastrar_astronauta(list<astronauta>& astro_list);
#endif

