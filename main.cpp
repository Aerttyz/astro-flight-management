#include <iostream>
#include <vector>
#include "astronauta.h"
#include "voo.h"
using namespace std;

void listar_astronautas(const vector<astronauta>& astro_list);
void listar_voo(const vector<voo>& voo_list);
void cadastrar_voo(vector<voo>& voo_list, const vector<astronauta>& astro_list);
void cadastrar_astronauta(vector<astronauta>& astro_list);
void lancar_voo(string status_voo, vector<voo>& voo_list);
int main() {
    vector<astronauta> astro_list;
    vector<voo> voo_list;

    cout << "MENU" << endl;
    while (true) {
        int op;
        cout << "1- Cadastrar astronauta" << endl;
        cout << "2- Cadastrar voo" << endl;
        cout << "3- Listar astronautas" << endl;
        cout << "4- Listar voos" << endl;
        cout << "5- lançar voos" << endl;
        cin >> op;

        switch (op) {
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
            case 5:
                lancar_voo("PLANJEADO",voo_list);
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    }

    return 0;
}

