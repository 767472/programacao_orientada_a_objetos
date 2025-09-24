#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Livro{
private:
    string titulo;
    string autor;
    string ano;
public:
    Livro(string t, string au, string an) : titulo(t), autor(au), ano(an){
        cout << "Livro('"<< titulo <<"') criado \n";        
    }
    ~Livro(){
        cout << "Livro('"<< titulo <<"') destruido \n";
    }
    string getTitulo(){return titulo;}
};

class Biblioteca{
private:
    vector<Livro> livros;
public:
    Biblioteca(){
        cout << "Biblioteca criada \n";        
    }
    ~Biblioteca(){
        cout << "Biblioteca destruido \n";
    }
    void registrarlivro(Livro l){ 
        livros.push_back(l);
    }
    void listarlivros(){
        cout << "Acervo da Biblioteca \n";
        for(auto l : livros){
            cout << " * " << l.getTitulo() << "\n";
        }
    }
};

int main(){
    
    Livro l1("Livro 1","autor 1","ano 1"),l2("Livro 2","autor 2","ano 2"),l3("Livro 3","autor 3","ano 3");
    Biblioteca bib;
    bib.registrarlivro(l1);
    bib.registrarlivro(l2);
    bib.listarlivros();
    return 0;

}