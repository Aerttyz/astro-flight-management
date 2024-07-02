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
    for(int id : voo_feitos) {
        
        if(id == id_voo) {
            
            for(voo& v : voo_list) {
                
                
                if(v.getId() == id_voo) {
                    
                    string status = v.vefStatus(id_voo, voo_list); 
                    
                    if(status == "LANCADO") {
                        return true;
                        break;
                    } else {
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
    

    cout << "-------------------------------------" << endl;
    cout <<  "Nome:" << nome << endl;
    cout <<  "CPF:" << cpf << endl;
    cout <<  "Idade:" << idade << endl;
    cout <<  "Status:" << status << endl;

    cout <<  "Voos Participados:";
    if (voo_feitos.empty()) {
        cout << "Nenhum voo registrado" << endl;
    } else {
        cout << endl;
        for (const int& voo : voo_feitos) {
            cout << " - Voo " << voo << endl;
        }
    }

    cout << "-------------------------------------" << endl;
    }


void listar_mortos(list<astronauta>& astro_list) {
    int op = 1;
    while(op){
    string caveira[] = {
        "███████████████████████████",
        "███████▀▀▀░░░░░░░▀▀▀███████",
        "████▀░░░░░░░░░░░░░░░░░▀████",
        "███│░░░░░░░░░░░░░░░░░░░│███",
        "██▌│░░░░░░░░░░░░░░░░░░░│▐██",
        "██░└┐░░░░░░░░░░░░░░░░░┌┘░██",
        "██░░└┐░░░░░░░░░░░░░░░┌┘░░██",
        "██░░┌┘▄▄▄▄▄░░░░░▄▄▄▄▄└┐░░██",
        "██▌░│██████▌░░░▐██████│░▐██",
        "███░│▐███▀▀░░▄░░▀▀███▌│░███",
        "██▀─┘░░░░░░░▐█▌░░░░░░░└─▀██",
        "██▄░░░▄▄▄▓░░▀█▀░░▓▄▄▄░░░▄██",
        "████▄─┘██▌░░░░░░░▐██└─▄████",
        "█████░░▐█─┬┬┬┬┬┬┬─█▌░░█████",
        "████▌░░░▀┬┼┼┼┼┼┼┼┬▀░░░▐████",
        "█████▄░░░└┴┴┴┴┴┴┴┘░░░▄█████",
        "███████▄░░░░░░░░░░░▄███████",
        "██████████▄▄▄▄▄▄▄██████████",
        "███████████████████████████"
    };


    for (const string& linha : caveira) {
        cout <<  linha  << "\n";
    }
    cout << endl;
    
    cout << "Lista de Astronautas Mortos:\n";
    cout << "----------------------------\n";

    // Verifica se a lista está vazia
    if (astro_list.empty()) {
        cout << "Nenhum astronauta morto encontrado.\n";
        cout <<  "----------------------------\n";
        return;
    }

    // Itera pela lista de astronautas
    for (const astronauta& a : astro_list) {
        // Verifica se o status do astronauta é "MORTO"
        if (a.getStatusAstro() == "MORTO") {
            // Exibe informações do astronauta morto
            cout << "Nome: " << a.getNome() << " | CPF: " << a.getCpf() << "\n";
            cout << "Voos feitos: ";
            for (const int& voo : a.getVoo_feitos()) {
                cout << voo << " | ";
            }
            cout << "\n";
        }
    }
    cout << "----------------------------\n";
    cout << "Para sair da exibição digite 0:";
    cin >> op;
    }
}

void listar_astronautas(const list<astronauta>& astro_list) {
        
        if (astro_list.empty()) {
            cout << "Nenhum astronauta cadastrado." << endl;
            return;
        }

        cout << "Lista de Astronautas:" << endl;
        for (const astronauta& a : astro_list) {
            a.listar_astronauta();
            cout << endl;
        }
        cout << "Pressione enter para sair da lista:";
        cin.ignore();
        cin.get();
}
void cadastrar_astronauta(list<astronauta>& astro_list) {
    int idade;
    string nome, cpf;

    cout << "Nome: ";
    cin.ignore(); // Limpa o buffer do teclado
    getline(cin, nome);

    cout << "CPF: ";
    getline(cin, cpf);

    // Verifica se o CPF já está cadastrado
    for (const astronauta& a : astro_list) {
        if (a.getCpf() == cpf) {
            cout << "CPF já cadastrado. Tente novamente com um CPF diferente." << endl;
            return;
        }
    }

    cout << "Idade: ";
    cin >> idade;
    cin.ignore(); // Limpa o buffer do teclado

    list<int> voo_feitos;
    astronauta Astronauta(nome, cpf, idade, voo_feitos);
    astro_list.push_back(Astronauta);
}

