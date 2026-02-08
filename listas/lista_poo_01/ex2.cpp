#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Music{
private:
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
private:
    vector<Music> songs; // Relação de composição
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
    vector<Playlist> playlists; // Relação de agregaçãp (não aplicado no codigo)
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
    cout << "\nCriação das Musicas\n";
   Music m1("Musica 1", "Autor 1"),
          m2("Musica 2", "Autor 2"),
          m3("Musica 3", "Autor 3"),
          m4("Musica 4", "Autor 4"),
          m5("Musica 5", "Autor 5");

    cout << "\nCriação das Playlist\n";
    Playlist p1("Favoritas"), p2("Rock");
    cout << "\nAdicionando as Musicas as playlist\n";
    p1.createsongs(m1);
    p1.createsongs(m2);
    p2.createsongs(m3);
    p2.createsongs(m4);
    p2.createsongs(m5);
    cout << "\nCriação do Profile\n";
    Profile pr1("Vitor");
    cout << "\nCriação da playlist dentro do perfil\n";
    pr1.createplaylist(p1);
    pr1.createplaylist(p2);
    cout << "\n listar playlist e suas musicas\n";
    pr1.listplaylist();
    p1.listsongs();
    p2.listsongs();

}