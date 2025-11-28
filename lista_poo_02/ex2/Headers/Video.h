#ifndef VIDEO_H
#define VIDEO_H

#include "Midia.h" 
#include <sstream>

class Video final : public Midia {
private:
    std::string resolucao_; 
    std::string codec_;     

public:
    // Construtor
    Video(const std::string& titulo, int ano, double duracao,
    const std::string& resolucao, const std::string& codec): Midia(titulo, ano, duracao), 
    resolucao_(resolucao), codec_(codec) {
      std::cout << "Video ("<< titulo <<") CRIADO";
    }

    // Destrutor
    ~Video() override {
      std::cout << "Video ("<< titulo <<") DESTRUIDO";
    } 
    void reproduzir() override {
        std::cout << "Iniciando reprodução de Vídeo: | " << titulo << " | na resolução | " << resolucao_ << " |.\n";
    }

    void infoDetalhada() const override {
        Midia::infoDetalhada(); 
        std::cout << "  > Resolução: | " << resolucao_ << " |, Codec: | " << codec_ << " |\n";
    }
    bool combina(const std::string& filtro) const override {
        if (titulo.find(filtro) != std::string::npos || 
            resolucao_.find(filtro) != std::string::npos) {
            return true;
        }
        return false;
    }
};

#endif