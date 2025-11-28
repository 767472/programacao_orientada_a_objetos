#ifndef MUSICA_H
#define MUSICA_H

#include "Midia.h" 

class Musica final : public Midia {
private:
    std::string artista_;
    double bitrate_; 

public:
    // Construtor
    Musica(const std::string& titulo, int ano, double duracao,
           const std::string& artista, double bitrate)
        : Midia(titulo, ano, duracao), artista_(artista), bitrate_(bitrate) {
      std::cout << "Musica ("<< titulo <<") CRIADA";
        }

    // Destrutor
    ~Musica() override {
      std::cout << "Musica ("<< titulo <<") DESTRUIDA";
    } 

    void reproduzir() override {
        std::cout << "Reproduzindo Música: |" << titulo << "| de |" << artista_ << "|.\n";
    }

    void infoDetalhada() const override {
        Midia::infoDetalhada(); 
        std::cout << "  > Artista: " << artista_ << ", Bitrate: " << bitrate_ << " kbps\n";
    }

    bool combina(const std::string& filtro) const override {
        if (titulo.find(filtro) != std::string::npos || 
            artista_.find(filtro) != std::string::npos) {
            return true;
        }
        return false;
    }
};

#endif