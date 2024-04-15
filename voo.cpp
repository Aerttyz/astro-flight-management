#include "voo.h"
#include "astronauta.h"
using namespace std;
voo::voo(int id_voo, vector<astronauta> astro_voo_list, string status_voo) {
    this->id_voo = id_voo;
    this->astro_voo_list = astro_voo_list;
    this->status_voo = status_voo;
};

string voo::vefStatus(int id_voo,vector<voo>& voo_list){
    for(const voo& v : voo_list){
        if(v.getStatus() == "LANCADO"){
            return "LANCADO";
        }
    }return "PLANEJADO";
}

void voo::finalizar_voo(){
    status_voo = "FINALIZADO(com sucesso)";
}

void voo::destro_voo(){
    status_voo = "FINALIZADO(explodiu)";
}

int voo::getId() const {
    return id_voo;
}
void voo::setStatus(const string& novoStatus){
    status_voo = novoStatus;
}
string voo::getStatus() const{
    return status_voo;
}
const std::vector<astronauta>& voo::getAstronautas() const {
    return astro_voo_list;
}
void listar_voo(const vector<voo>& voo_list, const vector<astronauta>& astro_list){
    cout << "Voos cadastrados:" << endl;
    for (const voo& v : voo_list) {
        cout << "ID do Voo: " << v.getId() << endl;
        cout << "Astronautas no Voo:" << endl;
        for (const astronauta& a : astro_list) {
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



void explodir_voo(vector<voo>& voo_list, vector<astronauta>& astro_list){
        int id_voo;
        cout << "ID do voo: ";
        cin >> id_voo;
        //bool voo_encontrado = false;
        for(voo& v : voo_list){
            if(id_voo == v.getId()){
                //bool voo_encontrado = true;

                if(v.getStatus() == "PLANEJADO"){
                    cout << "Um voo não lançado não pode ser explodido!" << endl;
                }else if(v.getStatus()=="LANCADO"){
                    for(astronauta& t : astro_list){
                        t.kill_astro();
                        v.destro_voo();
                    }
                }
            }
        }
    }


void lancar_voo(vector<voo>& voo_list, vector<astronauta>& astro_list){
    int id_voo;
    cout << "ID do voo: ";
    cin >> id_voo;

    bool status_voo_encontrado = false; 
    for(voo& v : voo_list){
        if(id_voo == v.getId()){ 
            status_voo_encontrado = true; 

            if(v.getStatus() == "PLANEJADO"){ 
                // Verifica se algum astronauta tem um voo lançado
                bool astro_in_voo_lanc = false;
                for(astronauta& t : astro_list){
                    cout << "entrou for" << endl;
                    if(t.astro_in_voo(id_voo, voo_list)){
                        astro_in_voo_lanc = true;
                        cout << "entrou" << endl;
                        break;
                    }
                }
                if(astro_in_voo_lanc==true){
                    cout << "astro em voo" << endl;
                    return;
                }else if(astro_in_voo_lanc==false){
                    v.setStatus("LANCADO");
                    cout << "voo lançado" << endl;
                }

                
                
            } else {
                cout << "Este voo não está planejado." << endl;
            }
            break;
        }
    }

    // Se o voo não foi encontrado na lista de voos
    if(!status_voo_encontrado){
        cout << "Voo não encontrado." << endl;
    }
}
