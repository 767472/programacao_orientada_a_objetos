# include <iostream>
# include <vector>
# include <memory>

using namespace std ;

class Livro {
    string titulo ;
public :
    Livro ( const string & t ) : titulo ( t ) {
        cout << " Livro ( " << titulo << " ) criado \n";
    }
    ~ Livro () { cout << " Livro ( " << titulo << " ) destruido \n"; }
    const string & getTitulo () const { return titulo ; }
};

class Biblioteca {
    string nome ;
    vector < Livro > acervo ; // COMPOSI \ O
public :
    Biblioteca ( const string & n ) : nome ( n ) {
        cout << " Biblioteca ( " << nome << " ) criada \n";
    }
    ~ Biblioteca () { cout << " Biblioteca ( " << nome << ") destruida \n"; }
    void adicionarLivro ( const Livro & l ) { acervo . push_back ( l ) ; }
    void listar () const {
        cout << " Acervo de " << nome << ":\n";
        for ( const auto & l : acervo ) cout << " - " << l.getTitulo () << "\n";
    }
};
int main () {
{
    Biblioteca bib (" Central ") ;
    Livro l1 ("POO em C++") ;
    Livro l2 (" Estruturas de Dados ") ;
    bib.adicionarLivro ( l1 ) ;
    bib.adicionarLivro ( l2 ) ;
    bib.listar () ;
} // observe a ordem de d e s t r u i o no console
return 0;
}