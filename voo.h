#ifndef VOO_H
#define VOO_H

#include <list>
#include "astronauta.h"
using namespace std;
class astronauta;
class voo {
private:
    int id_voo;
    std::list<astronauta> astro_voo_list;
    string status_voo;

public:
    voo(int id_voo, list<astronauta> astro_voo_list, string status_voo);
    int getId() const;
    string getStatus() const;
    void setStatus(const std::string& novoStatus="PLANJEADO");
    const std::list<astronauta>& getAstronautas();
    string vefStatus(int id_voo,list<voo>& voo_list);
    void finalizar_voo();
    void destro_voo();
   
};

int getIndex(list<astronauta>& astro_list, string cpf);

void listar_voo(const list<voo>& voo_list, const list<astronauta>& astro_list);

void cadastrar_voo(list<voo>& voo_list, const list<astronauta>& astro_list);

void lancar_voo(list<voo>& voo_list, const list<astronauta>& astro_list);

void explodir_voo(list<voo>& voo_list, list<astronauta>& astro_list);

void finalizar_voo_suc(list<voo>& voo_list);

void adicionar_astro_voo(list<voo>& voo_list, list<astronauta>& astro_list);

#endif

