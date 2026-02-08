#include <string>
#include <iostream>
using namespace std;

class Livro
{
    //modificador de acesso -> nivel de visibilidade dos atributos e metodos
private: 
    /*
    private -> visivel class
    quando os atributos estão privados damos o nome de escapsulmento
    */

    string isbn,titulo,autor;
    bool disponivel{true};

public:
    
    Livro(string i, string t, string a) : isbn(std::move(i)), titulo(std::move(t)), autor(std::move(a)){}
    bool estaDisponivel() const { return disponivel; }
    void marcarIndisponivel() {disponivel = false;}
    void marcarDisponivel() {disponivel = true;}
    string getTitulo() {return titulo;}
};

class Aluno

{
private:
    string ra,name;
public:
    Aluno(string r, string n) : ra(std::move(r)), name(std::move(n)) {}

    string getName() {return name;}                                                                                                                                                                                  
};

class Emprestimo
{
private:
    Livro *livro;
    Aluno *aluno;
    string dataSaida, dataPrevista;
    bool devolvido{false};
public:
    Emprestimo (Livro* l, Aluno* a, string saida, string prevista) : livro(l), aluno(a), dataSaida(std::move(saida)), dataPrevista(std::move(prevista)){}
    
    bool confirmar()
    {
        if (livro && livro->estaDisponivel())
        {
            livro->marcarIndisponivel();
            return true;
        }
        return false;
    }
    void devolver(string dataDevolucao)
    {
        if (livro)
        {
           livro->marcarDisponivel();
           cout << "Livro '" << livro->getTitulo() << "' devolvido em " << dataDevolucao << "\n";
        }
        return; 
    }
};
void test_biblioteca()
{
    cout << "___ Biblioteca ____ \n";
    Livro l("785-123213","prog","orientada a objeto");
    Aluno a("200000","vitor");

    Emprestimo e(&l,&a, "2025-09-09", "2025-09-15");
    e.confirmar();
}

int main()
{
    test_biblioteca();
    return 0;
}