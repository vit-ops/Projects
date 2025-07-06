#include <bits/stdc++.h>
using namespace std;
void Gravar(const string& oque_gravar, const int &variavel_line){
    ofstream arquivo("DadosArquivo.py", ios::app);
    arquivo << "Line [" << variavel_line << "] " << " = '"<< oque_gravar << "'" <<  endl;
    arquivo.close();
}
int ler(){
    int ultimoIndice = 0;
    string linha;
    ifstream arquivo("DadosArquivo.py");
    while (getline(arquivo, linha))
    {
     size_t posInicio = linha.find('[');
     size_t posFim = linha.find(']');
     if (posInicio != string::npos && posFim != string::npos && posFim > posInicio + 1) {
            string numeroStr = linha.substr(posInicio + 1, posFim - posInicio - 1);
            int numero = stoi(numeroStr);
            if (numero > ultimoIndice) {
                ultimoIndice = numero;
            }
        }
    }
    arquivo.close();
    return ultimoIndice + 1;
}
string binario(string& oque_gravar, int& Num){
    oque_gravar = "0";
    while (Num > 0)
    {
        if (Num % 2 == 0){
            oque_gravar += "0";
        }else{
            oque_gravar += "1";
        }
        Num -= 1;
    }
    return oque_gravar;
}

int main()
{
    int Num;
    int variavel_line;
    string oque_gravar = "";
    ofstream arquivo("DadosArquivo.py", ios::app);
    arquivo.close();
    
    while (true){
    variavel_line = ler();
    cout << "Line"<< "[" <<  variavel_line << "]  ";
    cin >> Num;
    if (Num == 146533){
        break;
    }else{
        oque_gravar = binario(oque_gravar, Num);
        Gravar(oque_gravar, variavel_line);
        variavel_line++;
    }
    }



}