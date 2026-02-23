#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>

class Vehicul{
protected:
    int masa;
    std::string marca;
public:
    Vehicul(int masa,std::string marca):masa(masa),marca(marca){}
    virtual float viteza_maxima()=0;
    virtual int masa_a()=0;
    virtual void display()=0;
    virtual void adauga_bagaj(int a)=0;
    
};
class Motocicleta:public Vehicul{
private:
    std::string tip;
public:
    Motocicleta(int masa, std::string marca,std::string tip):Vehicul(masa,marca),tip(tip){}
    void display(){
        std::cout<<"motocicleta "<<masa<<" "<<marca<<" "<<tip<<"\n";
    }
   int masa_a(){
       int a=70;
      return a;
   }
   float viteza_maxima(){
       return 300000.00/(masa+70);
   }
   void adauga_bagaj(int a){
       std::cout<<70+masa<<"\n";
   }
};
class Masina:public Vehicul{
protected:
    int nr_pasageri;
    int capacitate_portbagaj;
public:
    Masina(int masa, std::string marca,int nr_pasageri,int capacitate_portbagaj):
    Vehicul(masa,marca),nr_pasageri(nr_pasageri),capacitate_portbagaj(capacitate_portbagaj){}
    void adauga_bagaj(int a)
    {
        if(a>capacitate_portbagaj)
        std::cout<<masa+70*(1+nr_pasageri)+a-(a-capacitate_portbagaj)<<"\n";
        else
        std::cout<<masa+70*(1+nr_pasageri)+a<<"\n";
        
    };
    void display(){
        std::cout<<"masina "<<masa<<" "<<marca<<" "<<nr_pasageri<<" "<<capacitate_portbagaj<<"\n";
    }
    int masa_a()
    {
        return 70*(1+nr_pasageri);
    }
    float viteza_maxima(){
        return 300000.00/(masa+70*(1+nr_pasageri));
    }
};
class MasinaElectrica:public Masina{
private:
    int masa_baterie;
public:
    MasinaElectrica(int masa, std::string marca,int nr_pasageri,int capacitate_portbagaj,int masa_baterie):
    Masina(masa,marca,nr_pasageri,capacitate_portbagaj),masa_baterie(masa_baterie){}
    void display(){
        std::cout<<"masina electrica "<<masa<<" "<<marca<<" "<<nr_pasageri<<" "<<capacitate_portbagaj<<" "<<masa_baterie<<"\n";
        
    }
    int masa_a()
    {
        return 70*(1+nr_pasageri)+masa_baterie;
    }
    float viteza_maxima(){
        return 300000.00/(masa+ 70*(1+nr_pasageri)+masa_baterie);
    }
     void adauga_bagaj(int a)
    {
        std::cout<<masa+70*(1+nr_pasageri)+masa_baterie+a<<"\n";
        
    };
    
};
bool cmp(Vehicul *lhs,Vehicul *rhs)
{
    return(lhs->viteza_maxima()>rhs->viteza_maxima());
}
int main()
{
    int nr,test,masa_t,nr_p_t,cap_t,masa_b_t;
    std::string marca_t,tip_t,clasa;
    std::vector<Vehicul*>v;
    std::cin>>nr;
    for(int i=0;i<nr;i++)
    {
        std::cin>>masa_t;
        std::cin>>marca_t;
        std::cin>>clasa;
        if(clasa=="moto")
        {
            std::cin>>tip_t;
            v.push_back(new Motocicleta(masa_t,marca_t,tip_t));
        }
        if(clasa=="auto")
        {
            std::cin>>nr_p_t>>cap_t;
            v.push_back(new Masina(masa_t,marca_t,nr_p_t,cap_t));
        }
        if(clasa=="electric")
        {
            std::cin>>nr_p_t>>cap_t;
            std::cin>>masa_b_t;
            v.push_back(new MasinaElectrica(masa_t,marca_t,nr_p_t,cap_t,masa_b_t));
            
        }
    }
    std::cin>>test;
    if(test==1)
    {
        for(auto *a:v)
        a->display();
    }
    if(test==2)
    {
       for(auto *a:v)
        std::cout<<a->masa_a()<<"\n"; 
    }
    if(test==3)
    {
        for(auto *a:v)
        std::cout<<std::fixed<<std::setprecision(2)<<a->viteza_maxima()<<"\n";
    }
    if(test==4)
    {
        int index,mas1;
        std::cin>>index>>mas1;
        v[index]->adauga_bagaj(mas1);
        
    }
    if(test==5)
    {
        std::sort(v.begin(),v.end(),cmp);
        for(auto *a:v)
        a->display();
    }
}