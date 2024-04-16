#include "voo.h"
#include "astronauta.h"
#include <algorithm>
using namespace std;
voo::voo(int id_voo, list<astronauta> astro_voo_list, string status_voo) {
    this->id_voo = id_voo;
    this->astro_voo_list = astro_voo_list;
    this->status_voo = status_voo;
};

string voo::vefStatus(int id_voo,list<voo>& voo_list){
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

/*
void voo::getIndice(string cpf, list<astronauta>& astro_list){
    
    for(size_t i=0; i<getAstronautas().size();i++){
        if(astro_list[i].getCpf()==cpf){
            return i;
            cout << "retornou" << i << endl;
        }
    }
}
*/

const list<astronauta>& voo::getAstronautas() {
    return astro_voo_list;
}

void listar_voo(const list<voo>& voo_list, const list<astronauta>& astro_list){
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

void remover_astro(list<voo>& voo_list, list<astronauta>& astro_list) {
    int id_voo;
    cout << "ID do voo: ";
    cin >> id_voo;

    bool voo_encontrado = false;
    for (voo& v : voo_list) {
        if (id_voo == v.getId()) {
            voo_encontrado = true;

            string cpf_astronauta;
            cout << "CPF do astronauta que deseja remover: ";
            cin >> cpf_astronauta;

            // Armazena a lista de astronautas temporariamente
            auto astronautas_voo = v.getAstronautas();

            // Procura o astronauta na lista do voo
            auto it = astronautas_voo.begin();
            while (it != astronautas_voo.end()) {
                if (it->getCpf() == cpf_astronauta) {
                    it = astronautas_voo.erase(it); // Remove o astronauta da lista do voo
                    break;
                } else {
                    ++it;
                }
            }

            if (it == astronautas_voo.end()) {
                cout << "Astronauta não encontrado no voo." << endl;
            } else {
                // Atualiza a lista de astronautas do voo
                v = voo(v.getId(), astronautas_voo, v.getStatus());
                // Remover o voo da lista de voos feitos pelo astronauta removido
                int index = getIndex(astro_list, cpf_astronauta);
                auto it_ast = astro_list.begin();
                advance(it_ast, index);
                it_ast->getVoo_feitos().remove(id_voo);
                cout << "Astronauta removido com sucesso do voo." << endl;
            }

            break;
        }
    }

    if (!voo_encontrado) {
        cout << "Voo não encontrado." << endl;
    }
}


void cadastrar_voo(list<voo>& voo_list, list<astronauta>& astro_list) {
    int id_voo;
    cout << "ID do voo: ";
    cin >> id_voo;
    cout << "Quantos astronautas vão no voo: ";
    int qntd;
    cin >> qntd;
    list<astronauta> astronautas_voo;
    for (int i = 0; i < qntd; i++) {
        string cpf;
        cout << "CPF do astronauta: ";
        cin >> cpf;
        for (astronauta& astro : astro_list) { // Corrigido aqui
            if (cpf == astro.getCpf()) {
                astronautas_voo.push_back(astro);
                astro.add_voo_to_astro(id_voo);
                break; // Saia do loop assim que o astronauta for encontrado
            }
        }
    }
    voo novo_voo(id_voo, astronautas_voo, "PLANEJADO");
    voo_list.push_back(novo_voo);
}

void adicionar_astro_voo(list<voo>& voo_list, list<astronauta>& astro_list){
    int id_voo;
    cout << "ID voo: ";
    cin >> id_voo;
    for(voo& t : voo_list){
        if(id_voo==t.getId()){
            string cpf;
            cin >> cpf;
            list<astronauta> astronautas_voo = t.getAstronautas();
            for(astronauta& astro :astro_list){
                if(cpf==astro.getCpf()){
                    astronautas_voo.push_back(astro);
                }
            }
        }
    }
}

int getIndex(list<astronauta>& astro_list, string cpf){
    int index=0;
    for(astronauta& t : astro_list){
        if(cpf==t.getCpf()){
            return index;  
        }index++;
    }return -1;
}


void finalizar_voo_suc(list<voo>& voo_list){
    int id_voo;
    cout << "ID do voo: ";
    cin >> id_voo;
    for(voo& t : voo_list){
        if(id_voo==t.getId()){
            if(t.getStatus()=="PLANEJADO"){
                cout << "Um voo não lançado não pode ser finalizado";
            }else if(t.getStatus()=="LANCADO"){
                t.finalizar_voo();
            }
        }
    }
    
}

void explodir_voo(list<voo>& voo_list, list<astronauta>& astro_list){
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


void lancar_voo(list<voo>& voo_list, list<astronauta>& astro_list){
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
