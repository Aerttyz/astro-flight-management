#include <iostream>
#include <string>
#include <vector>
using namespace std;

class astronauta{
    private:  
        string cpf;
        string nome;
        int idade;
        vector<int> voo_feitos;
    public:
        astronauta(string nome, string cpf, int idade, vector<int> voo_feitos){
            this->cpf = cpf;
            this->nome = nome;
            this->idade = idade;
            this->voo_feitos = voo_feitos;
        };
};
class voo{
    private:
        int id_voo;
        vector<astronauta> voo_list;
    public:
        voo(int id_voo, vector<astronauta> voo_list){
            this->id_voo = id_voo;
            this->voo_list = voo_list;
        }
};
void cadastrar_astronauta(){
    int idade; 
    string nome,cpf;
    getline(cin, nome);
    getline(cin, cpf);
    cin>>idade;
    cin.ignore();
    vector<int> voo_feitos;
    astronauta Astronauta(nome,cpf,idade, voo_feitos);

};
int main(){
    cadastrar_astronauta();
    cout << "MENU" << endl;
}

