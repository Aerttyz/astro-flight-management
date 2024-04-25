#include <iostream>
#include <list>
#include "astronauta.h"
#include "voo.h"
using namespace std;

void listar_astronautas(const list<astronauta>& astro_list);
void listar_voo( list<voo>& voo_list,  list<astronauta>& astro_list);
void cadastrar_voo(list<voo>& voo_list, list<astronauta>& astro_list);
void cadastrar_astronauta(list<astronauta>& astro_list);
void lancar_voo(list<voo>& voo_list, list<astronauta>& astro_list);
void explodir_voo(list<voo>& voo_list, list<astronauta>& astro_list);
void finalizar_voo_suc(list<voo>& voo_list);
void remover_astro(list<voo>& voo_list, list<astronauta>& astro_list);
void adicionar_astro_voo(list<voo>& voo_list, list<astronauta>& astro_list);
void listar_mortos(list<astronauta>& astro_list);

int main() {
    list<astronauta> astro_list;
    list<voo> voo_list;

    cout << "MENU" << endl;
    int op=-1;
    while (op!=0) {
        
        cout << "1- Cadastrar astronauta" << endl;
        cout << "2- Cadastrar voo" << endl;
        cout << "3- Listar astronautas" << endl;
        cout << "4- Listar voos" << endl;
        cout << "5- lançar voos" << endl;
        cout << "6- Explodir voo" << endl;
        cout << "7- FInalizar voo" << endl;
        cout << "8- Remover astronauta de voo" << endl;
        cout << "9- Adicionar astronauta em voo" << endl;
        cout << "10- Listar mortos" << endl;
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
                listar_voo(voo_list,astro_list);
                break;
            case 5:
                lancar_voo(voo_list, astro_list);
                break;
            case 6:
                explodir_voo(voo_list, astro_list);
                break;
            case 7:
                finalizar_voo_suc(voo_list);
                break;
            case 8:
                remover_astro(voo_list,astro_list);
                break;
            case 9:
                adicionar_astro_voo(voo_list, astro_list);
                break;
            case 10:
                listar_mortos(astro_list);
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    }

    return 0;
}

