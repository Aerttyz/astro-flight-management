#ifndef VOO_H
#define VOO_H

#include <vector>
#include "astronauta.h"
using namespace std;
class astronauta;
class voo {
private:
    int id_voo;
    std::vector<astronauta> astro_voo_list;
    string status_voo;

public:
    voo(int id_voo, vector<astronauta> astro_voo_list, string status_voo);
    int getId() const;
    string getStatus() const;
    void setStatus(const std::string& novoStatus="PLANJEADO");
    const std::vector<astronauta>& getAstronautas() const;
    string vefStatus(int id_voo,const vector<voo>& voo_list) const;
   
};

void listar_voo(const vector<voo>& voo_list, const vector<astronauta>& astro_list);

void cadastrar_voo(vector<voo>& voo_list, const vector<astronauta>& astro_list);

void lancar_voo(vector<voo>& voo_list, const vector<astronauta>& astro_list);


#endif

