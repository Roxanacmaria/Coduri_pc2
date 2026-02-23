#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
class Carte{
protected:
    std::string titlu, gen;
    int zi, luna, an, recenzii;
    int *note;
public:
    Carte(std::string titlu, std::string gen, int zi,int luna, int an, int recenzii,int *note):
    titlu(titlu), gen(gen),zi(zi),luna(luna),an(an),recenzii(recenzii)
    {
        this->note=new int[recenzii];
        for(int i=0;i<recenzii;i++)
        {
            this->note[i]=note[i];
        }
    }
    virtual void display()=0;
    virtual void nr_pagini(int a,int b)=0; 
    float medie()
    {
        int suma=0;
        for(int i=0;i<this->recenzii;i++)
        {
            suma+=note[i];
        }
        return (float)suma/recenzii;
    }
    void c_data(int zi1,int luna1,int an1)
    {
        if(an1<this->an)
        {
            std::cout<<titlu<<": "<<gen<<std::endl;
            
        }
        else if(an1==this->an)
        {
            if(luna1<this->luna)
            {
            std::cout<<titlu<<": "<<gen<<std::endl; 
            }
            else if(luna1==this->luna)
            {
                if(zi1<=this->an)
                {
                std::cout<<titlu<<": "<<gen<<std::endl; 
                }
            }
            
        }
    }
   
    std::string get_nume ()
    {
        return this->titlu;
    }
    int get_an ()
    {
        return this->an;
        
    }
    int get_luna ()
    {
        return this->luna;
        
    }
    int get_zi ()
    {
        return this->zi;
        
    }
};
class CarteFictiune:public Carte{
private:
    int nr_cap;
public:
    CarteFictiune(std::string titlu, std::string gen, int zi,int luna, int an, int recenzii,int *note,int nr_cap):
    Carte(titlu,gen,zi,luna,an,recenzii,note),nr_cap(nr_cap){}
    void display(){
        std::cout<<"fictiune: "<<titlu<<" - "<<zi<<" "<<luna<<" "<<an<<" - "<<nr_cap<<std::endl;
    }

    void nr_pagini(int a,int b)
    {
        int nr;
        nr=nr_cap*a+b;
        std::cout<<this->titlu<<": "<<nr<<"\n";
    }
};
class CarteNonFictiune:public Carte{
private:
    int nr_pag;
public:
    CarteNonFictiune(std::string titlu, std::string gen, int zi,int luna, int an, int recenzii,int *note,int nr_pag):
    Carte(titlu,gen,zi,luna,an,recenzii,note),nr_pag(nr_pag){}
    void display()
    {
        std::cout<<"nonfictiune: "<<titlu<<" - "<<zi<<" "<<luna<<" "<<an<<" - "<<nr_pag<<std::endl;
    }
    void nr_pagini(int a,int b)
    {
        int nr;
        nr=(nr_pag-b)*a+b;
        std::cout<<this->titlu<<": "<<nr<<"\n";
    }
};
class Biblioteca{
private:
    std::vector<Carte*> carte;
public:
    Biblioteca(){}
    void adauga(Carte * c)
    {
        this->carte.push_back(c);
    }
    void afisare()
    {
        for(auto j:carte){
            j->display();
        }
    }
    void max()
    {
        float med_max=carte[0]->medie();
        Carte *carte_m=carte[0];
        for(auto c:carte)
        {
            if(c->medie()>med_max)
            {
            med_max=c->medie();
            carte_m=c;
                
            }
        }
        std::cout<<std::fixed<<std::setprecision(2);
        std::cout<<carte_m->get_nume()<<": "<<med_max<<std::endl;
        
    }
    void data(int zi,int luna,int an)
    {
        for(auto c:carte)
        {
            c->c_data(zi,luna,an);
        }
    }
    void nou_vechi()
    {
       int an_nou=carte[0]->get_an();
       int an_vechi=carte[0]->get_an();
       int luna_n=carte[0]->get_luna();
       int luna_v=carte[0]->get_luna();
       int zi_n=carte[0]->get_zi();
       int zi_v=carte[0]->get_zi();
       Carte *v=carte[0];
       Carte *n=carte[0];
       for(auto c:carte)
       {
           if(c->get_an()>an_nou){
               an_nou=c->get_an();
               luna_n=c->get_luna();
               zi_n=c->get_zi();
               n=c;
           }
           if(c->get_an()<an_vechi)
           {
               an_vechi=c->get_an();
               luna_v=c->get_luna();
               zi_v=c->get_zi();
               v=c;
           }
       }
        for(auto c:carte)
       {
           if(c->get_an()==an_nou)
           {
               if(c->get_luna()>luna_n)
               {
                   n=c;
               }
               else if(c->get_luna()==luna_n)
               {
                   if(c->get_zi()>zi_n)
                   n=c;
               }
           }
       }
          for(auto c:carte)
       {
           if(c->get_an()==an_vechi)
           {
               if(c->get_luna()<luna_v)
               {
                   v=c;
               }
               else if(c->get_luna()==luna_v)
               {
                   if(c->get_zi()<zi_v)
                   v=c;
               }
           }
       }
       n->display();
       //std::cout<<"\n";
       v->display();
       
    }
    void calcul(int nr1,int nr2)
    {
        for(auto c :carte)
        {
            c->nr_pagini(nr1,nr2);
        }
    }
    
};

int main()
{
    int nr, zi_t,luna_t,an_t,nr_rec,nr_cap_t,nr_pag_t,test,n;
    std::string titlu_t,gen_t;
    int *note_t;
    Biblioteca b;
    std::cin>>nr;
    Carte *ca=nullptr;
    for(int i=0;i<nr;i++)
    {
        std::cin.ignore();
        std::getline(std::cin,titlu_t);
        std::cin>>zi_t>>luna_t>>an_t;
        std::cin>>nr_rec;
        note_t= new int[nr_rec];
        for(int j=0;j<nr_rec;j++)
        {
          std::cin>>note_t[j];
        }
        std::cin>>gen_t;
        if(gen_t=="fictiune")
         {
            std::cin>>nr_cap_t;
            ca=new CarteFictiune(titlu_t,gen_t,zi_t,luna_t,an_t,nr_rec,note_t,nr_cap_t);
         }
        else if(gen_t=="nonfictiune")
        {
         std::cin>>nr_pag_t;
         ca= new CarteNonFictiune(titlu_t,gen_t,zi_t,luna_t,an_t,nr_rec,note_t,nr_pag_t);
        }
        b.adauga(ca);
    }
    std::cin>>test;
    if(test==1)
    {
        b.afisare();
    }
    if(test==2)
    {
        b.max();
    }
    if(test==3)
    {
        int zi2,luna2,an2;
        std::cin>>zi2>>luna2>>an2;
        b.data(zi2,luna2,an2);
    }
    if(test==4)
    {
        b.nou_vechi();
    }
    if(test==5)
    {
        int nr_a,nr_b;
        std::cin>>nr_a>>nr_b;
        b.calcul(nr_a,nr_b);
    }
    
}