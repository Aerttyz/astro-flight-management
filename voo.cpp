#include "voo.h"
#include "astronauta.h"
#include <algorithm>
#include <limits>
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

list<astronauta>& voo::getAstronautas() {
    return astro_voo_list;
}

void listar_voo( list<voo>& voo_list, list<astronauta>& astro_list){
    cout << "Voos cadastrados:" << endl;
    for (voo& v : voo_list) {
        cout << "ID do Voo: " << v.getId() << endl;
        cout << "Astronautas no Voo:" << endl;
        list<astronauta> astronautas = v.getAstronautas();
        
        for (const astronauta& a : astronautas) {
           printf("--------------------------------\n");
           a.listar_astronauta_voo();
        }
        cout << "Status Voo: " << v.getStatus() <<endl;
        cout << endl;
    }
}

void remover_astro(list<voo>& voo_list, list<astronauta>& astro_list) {
    int id_voo;
    cout << "ID do voo: ";
    while (!(cin >> id_voo)) {
        cout << "Valor inválido. Por favor, insira um valor inteiro: ";
        cin.clear();
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    bool voo_encontrado = false;
    for (voo& v : voo_list) {
        if (id_voo == v.getId()) {
            voo_encontrado = true;

            string cpf_astronauta;
            cout << "CPF do astronauta que deseja remover: ";
            cin >> cpf_astronauta;

            // Armazena a lista de astronautas temporariamente
            list<astronauta>& astronautas_voo = v.getAstronautas();
            auto it = find_if(astronautas_voo.begin(), astronautas_voo.end(), [&](const astronauta& a) {
                return a.getCpf() == cpf_astronauta;
            });
            if(it!=astronautas_voo.end()){
                astronautas_voo.erase(it);
    
                int index = getIndex(astro_list, cpf_astronauta);
                cout << "INDEX: "<< index << endl;
                auto it_ast = astro_list.begin();
                advance(it_ast, index);
                it_ast->voo_feitos.remove(id_voo);

                cout << "Astronauta removido com sucesso do voo." << endl;
            }else{
                cout << "Astronauta não encontrado no voo." << endl;
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
    while (true) {
        cout << "ID do voo: ";
        while (!(cin >> id_voo)) {
            cout << "Valor inválido. Por favor, insira um valor inteiro: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        bool id_repetido = false;
        for (const voo& v : voo_list) {
            if (id_voo == v.getId()) {
                id_repetido = true;
                break;
            }
        }
        if (id_repetido) {
            cout << "ID do voo já existe. Por favor, insira um ID diferente: ";
            cin.clear(); // Limpar a flag de erro do cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpar o buffer
        } else {
            break;
        }
    }

    list<astronauta> astronautas_voo;
    voo novo_voo(id_voo, astronautas_voo, "PLANEJADO");
    voo_list.push_back(novo_voo);
}

void adicionar_astro_voo(list<voo>& voo_list, list<astronauta>& astro_list){
    int id_voo;
    cout << "ID voo: ";
    cin >> id_voo;
    voo* voo_encontrado = nullptr;
    for(voo& t : voo_list){
        if(id_voo==t.getId()){
            voo_encontrado = &t;
            break;
        }
    }
    if(voo_encontrado){
        string cpf;
        cout << "CPF astronauta: ";
        cin >> cpf;
        astronauta* astro_encontrado = nullptr;
        for(astronauta& astro : astro_list){
            if(cpf == astro.getCpf()){
                astro_encontrado = &astro;
                break;
            }
        }
        if (astro_encontrado) {
            // Verifica se o astronauta já está no voo para evitar duplicações
            list<astronauta>& astronautas_voo = voo_encontrado->getAstronautas();
            auto it = find_if(astronautas_voo.begin(), astronautas_voo.end(), [&](const astronauta& a) {
                return a.getCpf() == astro_encontrado->getCpf();
            });
            
            if (it == astronautas_voo.end()) {
                // Adiciona o astronauta ao voo se não estiver já presente
                astronautas_voo.push_back(*astro_encontrado);
                astro_encontrado->add_voo_to_astro(id_voo);
                cout << "Astronauta adicionado com sucesso ao voo." << endl;
            } else {
                cout << "O astronauta já está neste voo." << endl;
            }
        } else {
            cout << "Astronauta não encontrado." << endl;
        }
    } else {
        cout << "Voo não encontrado." << endl;
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
        
        for(voo& v : voo_list){
            if(id_voo == v.getId()){
                
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
            //verifica se há astronautas na lista
            list<astronauta> astronautas = v.getAstronautas();
            if(!astronautas.empty()){
                if(v.getStatus() == "PLANEJADO"){ 
                    // Verifica se algum astronauta tem um voo lançado
                    bool astro_in_voo_lanc = false;
                    for(astronauta& t : astro_list){
                        
                        if(t.astro_in_voo(id_voo, voo_list)){
                            astro_in_voo_lanc = true;
                            
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
            }else{
                cout << "Não há astronautas no voo." << endl;
            }
                
            break;
        }
    }

    // Se o voo não foi encontrado na lista de voos
    if(!status_voo_encontrado){
        cout << "Voo não encontrado." << endl;
    }
}
