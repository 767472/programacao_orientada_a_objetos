#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Music {
    string title;
    string composer;
public:
    Music(string t, string c) : title(t), composer(c) {
        cout << "Music '" << title << "' created\n";
    }
    ~Music() {
        cout << "Music '" << title << "' destroyed\n";
    }
    string getTitle() const { return title; }
};

class Playlist {
    vector<Music*> songs; // Vetor de ponteiros para Music
    string name;
public:
    Playlist(string n) : name(n) {
        cout << "Playlist '" << name << "' created\n";
    }
    ~Playlist() {
        cout << "Playlist '" << name << "' destroyed\n";
    }
    void createsongs(Music* m) {
        songs.push_back(m);
    }
    void listsongs() const {
        cout << "Playlist songs '" << name << "'\n";
        for (const auto& m : songs) {
            cout << " * " << m->getTitle() << "\n";
        }
    }
    string getName() const { return name; }
};

class Profile {
    vector<Playlist*> playlists; // Vetor de ponteiros para Playlist
    string name;
public:
    Profile(string n) : name(n) {
        cout << "Profile '" << name << "' created\n";
    }
    ~Profile() {
        cout << "Profile '" << name << "' destroyed\n";
            for (auto p : playlists) {
            delete p;
        }
    }
    void createplaylist(Playlist* p) {
        playlists.push_back(p);
    }
    void listplaylist() const {
        cout << " '" << name << "'s Profile playlists\n";
        for (const auto& p : playlists) {
            cout << " * " << p->getName() << "\n";
            p->listsongs();
        }
    }
};

int main() {
    Music m1("Musica 1", "Autor 1"),
          m2("Musica 2", "Autor 2"),
          m3("Musica 3", "Autor 3"),
          m4("Musica 4", "Autor 4"),
          m5("Musica 5", "Autor 5");

    Playlist* p1("Favoritas"), p2("Rock");

    p1.createsongs(&m1);
    p1.createsongs(&m2);
    p2.createsongs(&m3);
    p2.createsongs(&m4);
    p2.createsongs(&m5);

    Profile pr1("Vitor");

    pr1.createplaylist(p1);
    pr1.createplaylist(p2);

    pr1.listplaylist();

    return 0;
}