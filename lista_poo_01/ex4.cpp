# include <iostream>
# include <vector>
# include <memory>

using namespace std ;

class Medico {
public:
    string nome ;
    string id;
public :
    Medico (string n) : nome(n) {
        cout << " Medico ( " << nome << " ) criado \n";
    }
    ~ Medico () { 
        cout << " Medico ( " << nome << " ) destruido \n"; 
    }
    string getNome () { return nome ; }
};
class Paciente {
public:
    string nome ;
    string cpf;
public :
    Paciente (string n) : nome(n) {
        cout << " Paciente ( " << nome << " ) criado \n";
    }
    ~ Paciente () { 
        cout << " Paciente ( " << nome << " ) destruido \n"; 
    }
    string getNome () { return nome ; }
};
class Anotacao {
public:
    string titulo ;
    string infomacoes;
public :
    Anotacao (string t) : titulo(t) {
        cout << " Anotacao ( " << titulo << " ) criado \n";
    }
    ~ Anotacao () { 
        cout << " Anotacao ( " << titulo << " ) destruido \n"; 
    }
    string getNome () { return titulo ; }
};
class Protuario {
public:
    vector<Anotacao> anotacaos;
    string titulo ;
public :
    Protuario (string t) : titulo(t) {
        cout << " Protuario ( " << titulo << " ) criado \n";
    }
    ~ Protuario () { 
        cout << " Protuario ( " << titulo << " ) destruido \n"; 
    }
    string & getNome () { return titulo ; }
};

int main () {

return 0;
}