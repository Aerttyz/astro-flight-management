#include <iostream>
#include <list>
#include "astronauta.h"
#include "voo.h"
#include <cstdlib>
using namespace std;

void limparTerminal(){
    #ifdef _WIN32
        //limpar o terminal no Windows
        system("cls");
    #else
        //limpar o terminal no Linux e macOS
        system("clear");
    #endif
}
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
    int op=-1;
    while (op!=0) {
        cout  <<  "*********************************************************\n";
        cout  <<  "*                  Menu de Operações                    *\n";
        cout  <<  "*********************************************************\n";
        cout  <<  "* 1 - Cadastrar astronauta   * 2 - Cadastrar voo        *\n";
        cout  <<  "* 3 - Listar astronautas     * 4 - Listar voos          *\n";
        cout  <<  "* 5 - Lançar voo             * 6 - Explodir voo         *\n";
        cout  <<  "* 7 - Finalizar voo          * 8 - Remover astr. de voo *\n";
        cout  <<  "* 9 - Adicionar astr. em voo * 10 - Listar mortos       *\n";
        cout  <<  "***************** 0 - Finalizar *************************\n";
        cout  <<  "*********************************************************\n";
        cout  <<  "Escolha uma opção:";
        
        cin >> op;
        limparTerminal();
        
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
            case 0:
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    }

    return 0;
}

