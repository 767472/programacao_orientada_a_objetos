#include <vector>
#include <memory>
#include "Musica.h"
#include "Video.h"
#include "Podcast.h"

int main() {
    std::vector<std::unique_ptr<Midia>> catalogo;

    catalogo.emplace_back(new Musica("Bohemian Rhapsody", 1975, 5.55, "Queen", 320));
    catalogo.emplace_back(new Video("Tutorial C++", 2024, 15.0, "1080p", "H.264"));
    
    // Criando podcast e adicionando convidados.
    auto pod = new Podcast("Tech News #42", 2025, 60.0, "Joao Host");
    pod->adicionarConvidado("Elon Musk");
    pod->adicionarConvidado("Linus Torvalds");
    catalogo.emplace_back(pod);

    std::string busca = "Linus";
    std::cout << "--- Buscando por: " << busca << " ---\n";

    for(const auto& item : catalogo) {
        if(item->combina(busca)) {
            item->infoDetalhada();
            item->reproduzir();
        }
    }

    return 0;
}