#include<iostream>
#include<string>
#include<iomanip>
class Zbor{
private:
    std::string oras_plecare,oras_sosire;
    int ora_plecare,minut_plecare,ora_sosire,minut_sosire;
public:
    Zbor(std::string oras_plecare,std::string oras_sosire,int ora_plecare,int minut_plecare,int ora_sosire,int minut_sosire):
    oras_plecare(oras_plecare),oras_sosire(oras_sosire),ora_plecare(ora_plecare),ora_sosire(ora_sosire),minut_plecare(minut_plecare),minut_sosire(minut_sosire){}
    void afisare()
    {
        std::cout<<oras_plecare<<" - "<<oras_sosire<<std::endl;
        std::cout<<ora_plecare<<":"<<minut_plecare<<" - "<<ora_sosire<<":"<<minut_sosire<<std::endl;
    }
    std::string get_plecare()const{
        return this->oras_plecare;
    }
    std::string get_sosire()const{
        return this->oras_sosire;
    }
    int get_ora_p()const{
        return this->ora_plecare;
    }
    int get_minut_p()const{
        return this->minut_plecare;
    }
    int get_ora_s()const{
        return this->ora_sosire;
    }
    int get_minut_s()const{
        return this->minut_sosire;
    }
    void afis_dr()
    {
        std::cout<<oras_plecare<<" - "<<oras_sosire<<std::endl;
    }
    
};
class Aeroport{
private:
    int numar_zboruri;
    Zbor **zbor;
    int i=0;
public:
    Aeroport(int numar_zboruri):numar_zboruri(numar_zboruri){
        zbor=new Zbor*[numar_zboruri];
    }
    void set_zbor(std::string oras_plecare,std::string oras_sosire,int ora_plecare,int minut_plecare,int ora_sosire,int minut_sosire)
    {
        
        if(i<numar_zboruri)
        {
            zbor[i]=new Zbor(oras_plecare,oras_sosire,ora_plecare,minut_plecare,ora_sosire,minut_sosire);
            i++;
        }
    }
    void afisare_zbor(int index)
    {
        if(index==0)
        {
            for(int j=0;j<numar_zboruri;j++)
            {
                if(zbor[j]->get_plecare()=="Bucuresti")
                 zbor[j]->afisare();
            }
        }
        else if(index==1)
        {
             for( int j=0;j<numar_zboruri;j++)
            {
                if(zbor[j]->get_sosire()=="Bucuresti")
                 zbor[j]->afisare();
            }
        }
    }
    void afisare_zbor_interval(int ora1,int min1,int ora2, int min2)
    {
        for(int j=0;j<numar_zboruri;j++)
        {
            if((zbor[j]->get_ora_p()>=ora1)&&(zbor[j]->get_minut_p()>=min1)&&(zbor[j]->get_ora_s()<=ora2)&&(zbor[j]->get_minut_s()<=min2))
            zbor[j]->afisare();
        }
    }
    void calcul_viteza(int dist,int index)
    {
        
        int timp1=zbor[index]->get_ora_p()*60+zbor[index]->get_minut_p();
        int timp2=zbor[index]->get_ora_s()*60+zbor[index]->get_minut_s();
        int durata=timp2-timp1;
        if(durata<=0)durata+=24*60;
        float durata_ora=durata/60.00;
        float viteza=dist/durata_ora;
        zbor[index]->afisare();
        std::cout<<std::fixed<<std::setprecision(2)<<viteza<<std::endl;
        
    }
    void profit(int dist,int index)
    {
     int timp1=zbor[index]->get_ora_p()*60+zbor[index]->get_minut_p();
        int timp2=zbor[index]->get_ora_s()*60+zbor[index]->get_minut_s();
        int durata=timp2-timp1;
        if(durata<=0)durata+=24*60;
        float durata_ora=durata/60.00;
        float suma=0.15*400*dist;
        float cost=durata_ora*10000*1;
        zbor[index]->afis_dr();
        std::cout<<std::fixed<<std::setprecision(2)<<suma-cost<<std::endl;
    }
};
int main()
{
    int test,nr_zboruri,min_plecare,min_sosire,ora_tp,ora_ts;
    std::string oras_tp,oras_ts;
    std::cin>>nr_zboruri;
    Aeroport a(nr_zboruri);
    for(int i=0;i<nr_zboruri;i++)
    {
        std::cin>>oras_tp>>oras_ts;
        std::cin>>ora_tp>>min_plecare;
        std::cin>>ora_ts>>min_sosire;
        a.set_zbor(oras_tp,oras_ts,ora_tp,min_plecare,ora_ts,min_sosire);
        //std::cout<<oras_tp<<" - "<<oras_ts<<std::endl;
        //std::cout<<ora_tp<<":"<<min_plecare<<" - "<<ora_ts<<":"<<min_sosire<<std::endl;
    }
    std::cin>>test;
    if(test==1)
    {
        int nr;
        std::cin>>nr;
       a.afisare_zbor(nr);
    }
    if(test==2)
    {
        int o1,o2,m1,m2;
        std::cin>>o1>>m1;
        std::cin>>o2>>m2;
        a.afisare_zbor_interval(o1,m1,o2,m2);
    }
    if(test==3)
    {
        int distanta_zbor;
        for(int i=0;i<nr_zboruri;i++)
        {
            std::cin>>distanta_zbor;
            a.calcul_viteza(distanta_zbor,i);
        }
    }
    if(test==4)
    {
        int distanta_zbor;
        for(int i=0;i<nr_zboruri;i++)
        {
            std::cin>>distanta_zbor;
            a.profit(distanta_zbor,i);
        }
        
    }
}