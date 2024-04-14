#include "voo.h"
#include "astronauta.h"
using namespace std;
voo::voo(int id_voo, std::vector<astronauta> astro_voo_list, string status_voo) {
    this->id_voo = id_voo;
    this->astro_voo_list = astro_voo_list;
    this->status_voo = status_voo;
};

int voo::getId() const {
    return id_voo;
}
void voo::setStatus(const std::string& novoStatus){
    status_voo = novoStatus;
}
string voo::getStatus() const{
    return status_voo;
}
const std::vector<astronauta>& voo::getAstronautas() const {
    return astro_voo_list;
}
void listar_voo(const vector<voo>& voo_list){
    cout << "Voos cadastrados:" << endl;
    for (const voo& v : voo_list) {
        cout << "ID do Voo: " << v.getId() << endl;
        cout << "Astronautas no Voo:" << endl;
        for (const astronauta& a : v.getAstronautas()) {
            a.listar_astronauta();
        }
        cout << "Status Voo: " << v.getStatus() <<endl;
        cout << endl;
    }
}

void cadastrar_voo(vector<voo>& voo_list, vector<astronauta>& astro_list) {
    int qntd;
    int id_voo;
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
        astro_list[index].add_voo_to_astro(id_voo);
    }
    voo novo_voo(id_voo, astronautas_voo, "PLANEJADO");
    voo_list.push_back(novo_voo);
    
}
void lancar_voo(string status_voo, vector<voo>& voo_list){
    int id_voo;
    cout << "ID do voo: ";
    cin >> id_voo;
    for(voo& v : voo_list){
        if(v.getId()==id_voo){
            if(v.getStatus()=="PLANEJADO"){
                v.setStatus("LANCADO");
            }
            else{
                cout << "Este voo não está planejado" << endl;
            }
        }
    }
}
