#include<iostream>
#include<string>
#include<iomanip>
class Criptomoneda
{
private:
    std::string nume;
    float valoare_fractionala;
    float valoare_curenta;
public:
    Criptomoneda(std::string nume,float valoare_fractionala,float valoare_curenta):
    nume(nume),valoare_fractionala(valoare_fractionala),valoare_curenta(valoare_curenta){}
    void afisare_cripto()
    {
        std::cout<<nume<<" "<<std::fixed<<std::setprecision(2)<<valoare_fractionala<<" "<<std::fixed<<std::setprecision(2)<<valoare_curenta<<std::endl;
    }
    std::string get_nume()const{
        return this->nume;
        
    }
    float get_val1()const{
        return this->valoare_fractionala;
        
    }
    float get_val2()const{
        return this->valoare_curenta;
    }
    void set_val1(float cant)
    {
        this->valoare_fractionala=cant;
    }
};
class Portofel{
private:
    float sold_curent;
    int n,i=0;
    Criptomoneda **cripto;
public:
    Portofel(float sold_curent,int n):sold_curent(sold_curent),n(n){
        cripto=new Criptomoneda*[n];
    
    }
    void set_cripto(std::string nume,float valoare1,float valoare2)
    {
        if(i<n)
        {
            cripto[i]=new Criptomoneda(nume,valoare1,valoare2);
            i++;
        }
    }
    void afisare()
    {
        std::cout<<std::fixed<<std::setprecision(2)<<sold_curent<<std::endl;
        for(i=0;i<n;i++)
        {
            cripto[i]->afisare_cripto();
        }
    }
    void cumparare(std::string name,int numar)
    {
        float cantitate;
        for(i=0;i<n;i++)
        {
            if(cripto[i]->get_nume()==name)
            {
                if(numar*cripto[i]->get_val2()<=sold_curent)
                {
                cantitate=numar+cripto[i]->get_val1();
                sold_curent-=numar*cripto[i]->get_val2();
                std::cout<<cripto[i]->get_nume()<<" "<<std::fixed<<std::setprecision(2)<<cantitate<<" "<<std::fixed<<std::setprecision(2)<<cripto[i]->get_val2()<<std::endl;
                }
                else
                {
                    
                    cantitate=sold_curent/cripto[i]->get_val2()+cripto[i]->get_val1();
                    sold_curent=0;
                    std::cout<<cripto[i]->get_nume()<<" "<<std::fixed<<std::setprecision(2)<<cantitate<<" "<<std::fixed<<std::setprecision(2)<<cripto[i]->get_val2()<<std::endl;
                }
            }
            
        }
    }
    void vanzare(std::string name,int numar)
    {
        float cantitate;
        for(i=0;i<n;i++)
        {
            if(cripto[i]->get_nume()==name)
            {
                if(numar <=cripto[i]->get_val1())
                {
                cantitate=cripto[i]->get_val1()-numar;
                sold_curent+=numar*cripto[i]->get_val2();
                std::cout<<cripto[i]->get_nume()<<" "<<std::fixed<<std::setprecision(2)<<cantitate<<" "<<std::fixed<<std::setprecision(2)<<cripto[i]->get_val2()<<std::endl;
                }
                else
                {
                    cantitate =0;
                    sold_curent+=cripto[i]->get_val1()*cripto[i]->get_val2();
                    std::cout<<cripto[i]->get_nume()<<" "<<std::fixed<<std::setprecision(2)<<cantitate<<" "<<std::fixed<<std::setprecision(2)<<cripto[i]->get_val2()<<std::endl;
                }
            }
        }
    }
    float tranzactii(std::string what,int cate,std::string name)
    {
        float cantitate;
        if(what=="cumpara")
        {
            for(i=0;i<n;i++)
        {
            if(cripto[i]->get_nume()==name)
            {
                if(cate*cripto[i]->get_val2()<=sold_curent)
                {
                cantitate=cate+cripto[i]->get_val1();
                cripto[i]->set_val1(cantitate);
                sold_curent-=cate*cripto[i]->get_val2();
                //std::cout<<cripto[i]->get_nume()<<" "<<std::fixed<<std::setprecision(2)<<cantitate<<" "<<std::fixed<<std::setprecision(2)<<cripto[i]->get_val2()<<std::endl;
                
                   // std::cout<<sold_curent;
                }
                else
                {
                    
                    cantitate=sold_curent/cripto[i]->get_val2()+cripto[i]->get_val1();
                    sold_curent=0;
                    cripto[i]->set_val1(cantitate);
                   // std::cout<<cripto[i]->get_nume()<<" "<<std::fixed<<std::setprecision(2)<<cantitate<<" "<<std::fixed<<std::setprecision(2)<<cripto[i]->get_val2()<<std::endl;
                   // std::cout<<sold_curent;
                }
            }
            
        }
        }
        if(what=="vinde")
        {
             for(i=0;i<n;i++)
        {
            if(cripto[i]->get_nume()==name)
            {
                if(cate <=cripto[i]->get_val1())
                {
                    sold_curent+=cate*cripto[i]->get_val2();
                cantitate=cripto[i]->get_val1()-cate;
                cripto[i]->set_val1(cantitate);
                
               // std::cout<<cripto[i]->get_nume()<<" "<<std::fixed<<std::setprecision(2)<<cantitate<<" "<<std::fixed<<std::setprecision(2)<<cripto[i]->get_val2()<<std::endl;
                
                   // std::cout<<sold_curent;
                }
                else
                {
                    sold_curent+=cripto[i]->get_val1()*cripto[i]->get_val2();
                    cantitate =0;
                    cripto[i]->set_val1(cantitate);
                    
                    //std::cout<<cripto[i]->get_nume()<<" "<<std::fixed<<std::setprecision(2)<<cantitate<<" "<<std::fixed<<std::setprecision(2)<<cripto[i]->get_val2()<<std::endl;
               //std::cout<<sold_curent;
                    
                }
            }
        }
        }
          return sold_curent;
        
    }
};
int main()
{
    float sold_initial;
    int nr,cate,cat;
    std::string tip,tip_temp,ce;
    float val1,val2;
    std::cin>>sold_initial;
    std::cin>>nr;
    Portofel p(sold_initial,nr);
    for(int i=0;i<nr;i++)
    {
        std::cin>>tip;
        std::cin>>val1;
        std::cin>>val2;
        p.set_cripto(tip,val1,val2);
    }
    int test;
    std::cin>>test;
    if(test==1)
    {
        p.afisare();
    }
    if(test==2)
    {
        std::cin>>tip_temp>>cate;
        p.cumparare(tip_temp,cate);
    }
    if(test==3)
    {
        std::cin>>tip_temp>>cate;
        p.vanzare(tip_temp,cate);
    }
    if(test==4)
    {
        int num;
        std::cin>>num;
        for(int j=0;j<num;j++)
        {
            std::cin>>ce>>cat>>tip_temp;
            p.tranzactii(ce,cat,tip_temp);
        }
        p.afisare();
        
    }
}