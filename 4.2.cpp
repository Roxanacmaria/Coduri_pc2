#include<iostream>
#include<string>
class Echipament_electronic{
protected: 
    float tensiune;
    float intensitate;
public:
    Echipament_electronic(float tensiune,float intensitate):tensiune(tensiune),intensitate(intensitate){}
};
class Telefon:private Echipament_electronic{
protected: 
    std::string nr_tel;
public:
    Telefon(float tensiune,float intensitate,std::string nr_tel):  Echipament_electronic(tensiune,intensitate),nr_tel(nr_tel){}
    void suna(std::string nr)
    {
        std::cout<<"Calling: "<<nr<<std::endl;
    }
    float get_tensiune()
    {
        return this->tensiune;
    }
    float get_intensitate()
    {
        return this->intensitate;
    }
};
class Telefon_mobil:protected Telefon{
private:
    int baterie;
public:
    Telefon_mobil(float tensiune,float intensitate,std::string nr_tel,int baterie): Telefon(tensiune,intensitate,nr_tel),baterie(baterie){}
    void suna(std::string nr,int dur)
    {
        Telefon::suna(nr);
        float putere=get_intensitate()*get_tensiune();
        baterie-=dur*(putere/100);
        if(baterie<0)baterie=0;
        std::cout<<"Outgoing number: "<< nr_tel<<std::endl;
        std::cout<<baterie<<std::endl;
    }
};
int main()
{
    float tensiune_t,intensitate_t;
    std::string nr_t;
    int procent;
    std::string nr_a;
    int durata;
    std::cin>>tensiune_t>>intensitate_t>>nr_t>>procent;
    std::cin>>nr_a>>durata;
    Telefon_mobil t(tensiune_t,intensitate_t,nr_t,procent);
    t.suna(nr_a,durata);
    
}