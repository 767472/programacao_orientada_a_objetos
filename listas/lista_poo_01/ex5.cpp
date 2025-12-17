#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Professor {
private:
    string nome;
    string siape;
public:
    Professor(const string& n, const string& s) : nome(n), siape(s){
        cout << "Professor: " << nome << " criado\n";
    }
    ~Professor(){ cout << "Professor: " << nome << " destruido\n"; }
    string getNome() const { return nome; }
};

class Aluno {
private:
    string nome;
    string ra;
public:
    Aluno(const string& n, const string& r) : nome(n), ra(r){
        cout << "Aluno: " << nome << " criado\n";
    }
    ~Aluno(){ cout << "Aluno: " << nome << " destruido\n"; }
    string getNome() const { return nome; }
};

class Turma {
private:
    string codigo;
    Professor* prof;
    vector<Aluno> alunos;
public:
    Turma(const string& c, Professor* p) : codigo(c), prof(p){
        cout << "Turma: " << codigo << " criada\n";
    }
    ~Turma(){ cout << "Turma: " << codigo << " destruida\n"; }
    void matricular(const Aluno& a){ alunos.push_back(a); }
    void listar() const{
        cout << "Turma " << codigo << " (prof.: " << prof->getNome() << ")\n";
        for (auto& a : alunos) cout << " - " << a.getNome() << "\n";
    }
};

class Curso {
private:
    string nome;
    vector<Turma> turmas;
public:
    Curso(const string& n) : nome(n){ cout << "Curso: " << nome << " criado\n"; }
    ~Curso(){ cout << "Curso: " << nome << " destruido\n"; }
    void adicionarTurma(const Turma& t){ turmas.push_back(t); }
    void listar() const{
        cout << "Curso: " << nome << "\n";
        for (auto& t : turmas) t.listar();
    }
};

int main(){
    Professor p("Beto", "123456");
    Turma t("POO-2025", &p);
    t.matricular(Aluno("Ana", "RA01"));
    t.matricular(Aluno("Joao", "RA02"));

    Curso c("Engenharia de Computacao");
    c.adicionarTurma(t);
    c.listar();
    return 0;
}
