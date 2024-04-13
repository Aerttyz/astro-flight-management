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
    const std::vector<astronauta>& getAstronautas() const;
};

void listar_voo(const vector<voo>& voo_list);

void cadastrar_voo(vector<voo>& voo_list, const vector<astronauta>& astro_list);


#endif

