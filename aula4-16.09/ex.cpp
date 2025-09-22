#include <string>
#include <iostream>
using namespace std;

class Discipline {
  private:
  string cod,name,professor;
  public:
  Discipline(string c, string n, string p) : cod(std::move(c)), name(std::move(n)), professor(std::move(p)){}

};
class Grade {
  private:
  float grade;
  Discipline *discipline;
  public: 
};
class Student {
  private:
  string cpf,name,ra,dt_birth;
  Grade *grade;
  public:
};
class Registration{
  string num;
  Student *student;
}