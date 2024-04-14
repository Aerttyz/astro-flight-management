#ifndef VOO_H
#define VOO_H

#include <vector>
#include "astronauta.h"

class voo {
private:
    int id_voo;
    std::vector<astronauta> astro_voo_list;
    string status_voo;

public:
    voo(int id_voo, std::vector<astronauta> astro_voo_list, string status_voo);
    int getId() const;
    string getStatus() const;
    void setStatus(const std::string& novoStatus="PLANJEADO");
    const std::vector<astronauta>& getAstronautas() const;
};

void listar_voo(const vector<voo>& voo_list, const vector<astronauta>& astro_list);

void cadastrar_voo(vector<voo>& voo_list, const vector<astronauta>& astro_list);

void lancar_voo(string status_voo, vector<voo>& voo_list, vector<astronauta>& astro_list);


#endif

