#include<iostream>
#include<string>
class Vehicul{
protected:
    std::string nume;
    float pret;
    float greutate;
public:
    Vehicul(std::string nume,float pret,float greutate): nume(nume),pret(pret),greutate(greutate){}
    void afisare()
    {
        std::cout<<"nume: "<<nume<<std::endl<<"pret: "<<pret<<std::endl<<"greutate: "<<greutate<<std::endl;
    }
};
class Autovehicul: public Vehicul{
private:
    int putere;
public:
    Autovehicul(std::string nume,float pret,float greutate,int putere):
     Vehicul(nume,pret,greutate),putere(putere){}
    void afisare()
    {
        Vehicul::afisare();
        std::cout<<"putere: "<<putere<<std::endl;
    }
};
int main()
{
    std::string nume_v,nume_a;
    float greutate_v,greutate_a;
    float pret_v,pret_a;
    int putere_a;
    std::cin>>nume_v>>pret_v>>greutate_v;
    std::cin>>nume_a>>pret_a>>greutate_a>>putere_a;
    Autovehicul a(nume_a,pret_a,greutate_a,putere_a);
    Vehicul v(nume_v,pret_v,greutate_v);
    v.afisare();
    a.afisare();
}