#include<iostream>
#include<string>
#include<iomanip>
class Vagon{
private:
    int maxim,nr_pasageri,clasa;
    float pret;
public:
    Vagon(int maxim,int nr_pasageri,int clasa,float pret):
    maxim(maxim),nr_pasageri(nr_pasageri),clasa(clasa),pret(pret){}
    void afisare()
    {
        std::cout<<nr_pasageri<<"/"<<maxim<<" "<<clasa<<" "<<pret<<std::endl;
    }
    int get_pasageri()const{
        return this->nr_pasageri;
    }
    float get_pret()const{
        return this->pret;
    }
    int get_maxim()const{
        return this->maxim;
    }
    int get_clasa()const{
        return this->clasa;
    }
    void set_pret(float prett)
    {
        this->pret=prett;
    }
    void set_pasageri(int pas)
    {
        this->nr_pasageri=pas;
    }
};
class Tren{
private:
    std::string ruta;
    int nrv;
    int i=0;
    Vagon **vagon;
public:
    Tren(std::string ruta,int nrv):ruta(ruta),nrv(nrv){
        vagon =new Vagon*[nrv];
    }
    void set_vagon(int capacitate,int pasageri,int clasaa,float pretl)
    {
        if(i<nrv)
        {
            vagon[i]=new Vagon(capacitate,pasageri,clasaa,pretl);
            i++;
        }
    }
    void afisare_info()
    {
        std::cout<<ruta<<std::endl;
        for(i=0;i<nrv;i++)
        {
            vagon[i]->afisare();
        }
    }
    void venit()
    {
        float suma=0.00;
        for(int i=0;i<nrv;i++)
        {
            suma+=vagon[i]->get_pasageri()*vagon[i]->get_pret();
        }
        std::cout<<std::fixed<<std::setprecision(2)<<suma<<std::endl;
    }
    void reducere(int index,int reducere)
    {
        float prag=(float)vagon[index]->get_pasageri()/vagon[index]->get_maxim();
       //std::cout<<prag;
       float pret_t;
        if(prag>=0.70)
        {
            pret_t=vagon[index]->get_pret()-reducere*vagon[index]->get_pret()/100;
            //std::cout<<pret_t;
            vagon[index]->set_pret(pret_t);
        }
       
    }
    void redistribuire(int index)
    {
        int pe_langa=vagon[index]->get_pasageri();
       for(i=0;i<nrv;i++)
       {
           if(index!=i)
           {
               if(vagon[index]->get_clasa()==vagon[i]->get_clasa())
               {
                   pe_langa-=(vagon[i]->get_maxim()-vagon[i]->get_pasageri());
                   vagon[i]->set_pasageri(vagon[i]->get_maxim());
                   
               }
           }
       }
       vagon[index]->set_pasageri(0);
       std::cout<<ruta<<std::endl;
        for(i=0;i<nrv;i++)
        {
            vagon[i]->afisare();
        }
        std::cout<<pe_langa<<std::endl;
    }
};
int main()
{
    std::string ruta_temp;
    int nr_v,test;
    int maxim_temp,nr_pasageri_temp,clasa_temp;
    float pret_temp;
    std::getline(std::cin,ruta_temp);
    std::cin>>nr_v;
    Tren t(ruta_temp,nr_v);
    for(int i=0;i<nr_v;i++)
    {
        std::cin>>maxim_temp;
        std::cin>>nr_pasageri_temp;
        std::cin>>clasa_temp;
        std::cin>>pret_temp;
        t.set_vagon(maxim_temp,nr_pasageri_temp,clasa_temp,pret_temp);
    }
    std::cin>>test;
    if(test==1)
    {
        t.afisare_info();
    }
    if(test==2)
    {
        t.venit();
    }
    if(test==3)
    {
        int a,index_t,reducere_t;
        std::cin>>a;
        for(int i=0;i<a;i++)
        {
            std::cin>>index_t>>reducere_t;
            t.reducere(index_t,reducere_t);
        }
        t.venit();
    }
    if(test==4)
    {
        int a;
        std::cin>>a;
        t.redistribuire(a);
        //t.afisare_info();
        
    }
}