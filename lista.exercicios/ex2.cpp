#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Music{
    string title;
    string composer;
public:
    Music(string t, string c) : title(t), composer(c){;
        cout << "Music '"<< composer <<"' create \n";        
    }
    ~Music(){
        cout << "Musica '"<< composer <<"' destroy \n";
    }
    string getTitle() {return title;}
};

class Playlist{
    vector<Music> songs;
    string name;
public:
    Playlist(string n) : name(n){
        cout << "Playlist '"<< name<<"' create \n";        
    }
    ~Playlist(){
        cout << "Playlist '"<< name<<"' destroy \n";
    }
    void createsongs(Music m){ 
        songs.push_back(m);
    }
    void listsongs(){
        cout << "Playlist songs '"<< name <<"' \n";
        for(auto p : songs){
            cout << " * " << p.getTitle() << "\n";
        }
    }
        string getName(){return name;}
};
class Profile{
    vector<Playlist> playlists;
    string name;
public:
    Profile(string n) : name(n){
        cout << "Profile'"<<name<<"'create\n";
    }
    ~Profile(){
        cout << "Profile'"<<name<<"'destroy\n";
    }
    void createplaylist(Playlist p){
        playlists.push_back(p);
    }
    void listplaylist(){
        cout << " '"<< name <<"'s' Profile playlists \n";
        for(auto p : playlists){
            cout << " * " << p.getName() << "\n";
        }
    }
};

int main(){
   Music m1("Musica 1", "Autor 1"),
          m2("Musica 2", "Autor 2"),
          m3("Musica 3", "Autor 3"),
          m4("Musica 4", "Autor 4"),
          m5("Musica 5", "Autor 5");

    Playlist p1("Favoritas"), p2("Rock");

    // Adiciona músicas nas playlists ANTES de adicionar ao perfil
    p1.createsongs(m1);
    p1.createsongs(m2);
    p2.createsongs(m3);
    p2.createsongs(m4);
    p2.createsongs(m5);

    Profile pr1("Vitor");

    pr1.createplaylist(p1);
    pr1.createplaylist(p2);

    pr1.listplaylist();
    p1.listsongs();
    p2.listsongs();

}