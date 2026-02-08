# include <iostream>
# include <vector>
# include <memory>

using namespace std ;

class Livro {
public:
    string titulo ;
public :
    Livro ( const string & t ) : titulo ( t ) {
        cout << " Livro ( " << titulo << " ) criado \n";
    }
    ~ Livro () { 
        cout << " Livro ( " << titulo << " ) destruido \n"; 
    }
    const string & getTitulo () const { return titulo ; }
};
int main () {
{ 
    Livro l1 ("POO em C++") ;
    Livro l2 (" Estruturas de Dados ") ;
    bib.adicionarLivro ( l1 ) ;
    bib.adicionarLivro ( l2 ) ;
    bib.listar () ;
} // observe a ordem de d e s t r u i o no console
return 0;
}