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
    astronauta(string nome, string cpf, int idade, vector<int> voo_feitos) {
        this->cpf = cpf;
        this->nome = nome;
        this->idade = idade;
        this->voo_feitos = voo_feitos;
    }

    void listar_astronauta() const {
        cout << "Nome: " << nome << endl;
        cout << "CPF: " << cpf << endl;
        cout << "Idade: " << idade << endl;
        cout << "Voos Feitos: ";
        for (int voo : voo_feitos) {
            cout << voo << " ";
        }
        cout << endl;
    }
};

class voo {
private:
    int id_voo;
    vector<astronauta> astro_voo_list;

public:
    voo(int id_voo, vector<astronauta> astro_voo_list) {
        this->id_voo = id_voo;
        this->astro_voo_list = astro_voo_list;
    }
    int getId() const{
        return id_voo;
    }
    const vector<astronauta>& getAstronautas() const{
        return astro_voo_list;
    }

};

void listar_astronautas(const vector<astronauta>& astro_list) {
    cout << "Lista de Astronautas:" << endl;
    for (const astronauta& a : astro_list) {
        a.listar_astronauta();
        cout << endl;
    }
}
void listar_voo(const vector<voo>& voo_list){
    cout << "Voos cadastrados:" << endl;
    for (const voo& v : voo_list) {
        cout << "ID do Voo: " << v.getId() << endl;
        cout << "Astronautas no Voo:" << endl;
        for (const astronauta& a : v.getAstronautas()) {
            a.listar_astronauta();
        }
        cout << endl;
    }

}

void cadastrar_voo(vector<voo>& voo_list, const vector<astronauta>& astro_list) {
    int id_voo, qntd;
    cout << "ID do voo: ";
    cin >> id_voo;
    cout << "Quantos astronautas vão no voo: ";
    cin >> qntd;
    vector<astronauta> astronautas_voo;
    for (int i = 0; i < qntd; i++) {
        int index;
        cout << "Índice do astronauta (de 0 a " << astro_list.size() - 1 << "): ";
        cin >> index;
        astronautas_voo.push_back(astro_list[index]);
    }
    voo novo_voo(id_voo, astronautas_voo);
    voo_list.push_back(novo_voo);
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

int main() {
    vector<astronauta> astro_list;
    vector<voo> voo_list;
    cout << "MENU" << endl;
    while(1){
        int op;
        cout << "1- Cadastrar astronauta" << endl;
        cout << "2- Cadastrar voo" << endl;
        cout << "3-  listar astronauta" << endl;
        cout << "4- listar voo" << endl;
        cin>>op;
        switch (op)
        {
        case 1:
            cadastrar_astronauta(astro_list);
            break;
        case 2:
            cadastrar_voo(voo_list, astro_list);
            break;
        case 3:
            listar_astronautas(astro_list);
            break;
        case 4:
            listar_voo(voo_list);
            break;
        default:
            break;
        }
        break;
    }
    return 0;
}
