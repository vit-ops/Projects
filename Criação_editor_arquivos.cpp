#include <bits/stdc++.h>
using namespace std;
void gravar(string& OqueGravar ,string& name_arquivo, int& numero){
    ofstream Ar;
    Ar.open(name_arquivo, ios::app);
    if (numero!= 0){
    Ar << OqueGravar << endl;
    }else{
        
    }
    Ar.close();
    numero++;
}
void ler(string& name_arquivo){
    int B = 1;
    string Espa = "______________________________________________________________________";
    string linhaAr;
    ifstream Ar;
    Ar.open(name_arquivo);
    cout << "itens listados no arquvo:" << endl << Espa << endl;
    if(Ar){
        while (getline(Ar, linhaAr)){
            cout << B << "_ " << linhaAr << endl;
            B++;
        }
    }else{
        cout << "Error" << endl;
    }
    cout << Espa << endl;
    Ar.close();
    
}
void Limpar_tela(){
    system("clear");
}
void Limpar_Ar(string& name_arquivo){

    ofstream Ar;
    Ar.open(name_arquivo,ios::trunc);
    Ar.close();
}
void ler_editar(string& OqueGravar, string& name_arquivo){
    int num = 0;
    string linha;
    vector<string> lista_linhas;
    ifstream Ar;
    Ar.open(name_arquivo);
    if (Ar) {
        while (getline(Ar, linha)) {
            lista_linhas.push_back(linha);
        }
    } else {
        cout << "Error" << endl;
    }
    Ar.close();


    size_t pos = OqueGravar.find('@');
    if (pos != string::npos) {
        int linha_num = stoi(OqueGravar.substr(0, pos)); 
        string novo_conteudo = OqueGravar.substr(pos + 1); 


        if (linha_num > 0 && linha_num <= lista_linhas.size()) {
            lista_linhas[linha_num - 1] = novo_conteudo; 
        } else {
            cout << "Número de linha inválido!" << endl;
            return;
        }
    } else {
        cout << "Formato inválido!" << endl;
        return;
    }

    ofstream Ar_escrita(name_arquivo);
    for (const auto& l : lista_linhas) {
        Ar_escrita << l << endl;
    }
    Ar_escrita.close();
}
void Deletar_linha(string& OqueGravar, string& name_arquivo) {
    int indice;
    indice = stoi(OqueGravar.substr(1));
    string linha;
    vector<string> lista;
    lista.push_back("");
    ifstream entrada(name_arquivo);

    while (getline(entrada, linha)) {
        lista.push_back(linha);
    }
    
    entrada.close();

    lista.erase(lista.begin() + indice);
    ofstream saida(name_arquivo);
    for(int i = 1; i < lista.size(); i++) {
        saida << (lista[i]) << endl;
    }
    saida.close();
}
int main(){

    int Numero = 0;
    string name_arquivo;
    string OqueGravar = "";
    cout << "Qual o nome do seu arquivo? Exemplo(Arquivo.txt) : ";
    getline(cin,name_arquivo);
    gravar(OqueGravar, name_arquivo, Numero);
    ler(name_arquivo);
    while (true){
        getline(cin, OqueGravar);
        if (OqueGravar == "sair"){
            Limpar_tela();
            ler(name_arquivo);
            break;
        }else if(OqueGravar == "clear"){
            Limpar_Ar(name_arquivo);
            Limpar_tela();
            cout << "arquivo limpo!" << endl;
            ler(name_arquivo);

        }else if (OqueGravar == "help"){
            cout << "clear : limpar o arquivo!" << endl;
            cout << "sair : Fechar programa!" << endl;
            cout << "Ou so digite o que deseja que seja integrado ao arquivo!" << endl;
        }else if(OqueGravar[0] == '*' && isdigit(OqueGravar[1])){
            Deletar_linha(OqueGravar, name_arquivo);
            Limpar_tela();
            ler(name_arquivo);
        }else if(isdigit(OqueGravar[0]) && (OqueGravar[1] == '@')){
            ler_editar(OqueGravar, name_arquivo);
            Limpar_tela();
            
            ler(name_arquivo);
        }else{
            Limpar_tela();
            gravar(OqueGravar, name_arquivo, Numero);
            ler(name_arquivo);
        }
    }
    
    return 0;
}
