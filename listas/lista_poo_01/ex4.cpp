#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Medico {
private:
    string nome;
    string crm;
public:
    Medico(const string& n, const string& c) : nome(n), crm(c) {
        cout << "Medico: " << nome << " criado\n";
    }
    ~Medico() { cout << "Medico: " << nome << " destruido\n"; }
    string getNome() const { return nome; }
};

class Paciente {
private:
    string nome;
    string cpf;
public:
    Paciente(const string& n, const string& c) : nome(n), cpf(c) {
        cout << "Paciente: " << nome << " criado\n";
    }
    ~Paciente() { cout << "Paciente: " << nome << " destruido\n"; }
    string getNome() const { return nome; }
};

class Anotacao {
private:
    string data;
    string texto;
public:
    Anotacao(const string& d, const string& t) : data(d), texto(t) {
        cout << "Anotacao: " << data << " criada\n";
    }
    ~Anotacao() { cout << "Anotacao: " << data << " destruida\n"; }
    string info() const { return "[" + data + "] " + texto; }
};

class Prontuario {
private:
    Paciente* paciente;
    Medico* responsavel;
    vector<Anotacao> notas;
public:
    Prontuario(Paciente* p, Medico* m) : paciente(p), responsavel(m) {
        cout << "Prontuario de " << p->getNome() << " criado\n";
    }
    ~Prontuario() { cout << "Prontuario de " << paciente->getNome() << " destruido\n"; }
    void adicionar(const Anotacao& a){ notas.push_back(a); }
    void setMedico(Medico* m){ responsavel = m; }
    void listar() const{
        cout << "Prontuario de " << paciente->getNome()
             << " (resp.: " << responsavel->getNome() << ")\n";
        for (auto& n : notas) cout << " - " << n.info() << "\n";
    }
};

int main(){
    Medico m1("Dra. Ana", "CRM123");
    Medico m2("Dr. Joao", "CRM456");
    Paciente p("Carlos", "11122233344");
    Prontuario pr(&p, &m1);
    pr.adicionar(Anotacao("2025-10-01", "Check-up anual"));
    pr.adicionar(Anotacao("2025-10-05", "Retorno com exames"));
    pr.setMedico(&m2);
    pr.listar();
    return 0;
}
