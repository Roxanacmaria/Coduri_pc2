#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<algorithm>

class Animal{
    
protected:
    std::string specie;
    int varsta;
    float greutate;
public:
    Animal(std::string specie,int varsta,float greutate):specie(specie),varsta(varsta),greutate(greutate){}
    virtual void display()=0;
    virtual void necesar_hrana()=0;
    virtual float necesar()=0;
    virtual void suprafata_necesara()=0;
    virtual void suprafata_necesara_zbor(float a){};
 ~Animal() {}
};
class Mamifer:public Animal{
    
private:
    float factor_alimentatie;
    float temperatura_corp;
public:
    Mamifer(std::string specie,int varsta,float greutate,float factor_alimentatie,float temperatura_corp):
    Animal(specie,varsta,greutate),factor_alimentatie(factor_alimentatie),temperatura_corp(temperatura_corp){}
    void display(){
        
        std::cout<<"mamifer: "<<specie<<" "<<greutate<<" "<<temperatura_corp<<std::endl;
    }
    void necesar_hrana(){
        float hrana_necesara=this->greutate*this->factor_alimentatie*(1+this->varsta/100.0);
        std::cout<<std::fixed<<std::setprecision(2);
        std::cout<<specie<<" - "<<hrana_necesara<<"\n";
    }
    float necesar()
    {
        return this->greutate*this->factor_alimentatie*(1+this->varsta/100.0);
    }
    void suprafata_necesara()
    {
        std::cout<<specie<<": "<<std::fixed<<std::setprecision(2)<<(this->greutate/10)+(this->varsta*this->temperatura_corp/100.0)<<"\n";
    }
    void suprafata_necesara_zbor(float efort)
    {
        std::cout<<specie<<": "<<std::fixed<<std::setprecision(2)<<(this->greutate/10)+(this->varsta*this->temperatura_corp/100.0)<<"\n";
    }
   
};
class Pasare:public Animal{
protected:
    float lungime_aripi;
public:
    Pasare(std::string specie,int varsta,float greutate,float lungime_aripi):
    Animal(specie,varsta,greutate),lungime_aripi(lungime_aripi){}
    void display(){
        
        std::cout<<"pasare: "<<specie<<" "<<greutate<<" "<<lungime_aripi<<std::endl;
    }
    void necesar_hrana(){
        float hrana_necesara=this->greutate*30/100;
        std::cout<<std::fixed<<std::setprecision(2);
        std::cout<<specie<<" - "<<hrana_necesara<<"\n";
    }
    float necesar()
    {
        return this->greutate*30/100;
        
    }
    void suprafata_necesara()
    {
        std::cout<<specie<<": "<<std::fixed<<std::setprecision(2)<<(greutate*0.5)+varsta*0.3+lungime_aripi*0.2<<"\n";
    }
    void suprafata_necesara_zbor(float efort)
    {
        std::cout<<specie<<" "<<std::fixed<<std::setprecision(2)<<lungime_aripi/greutate*varsta/10.*efort<<"\n";
    }
    
};
class PasarePradatoare:public Pasare{
private:
    float numar_pradatori;
public:
    PasarePradatoare(std::string specie,int varsta,float greutate,float lungime_aripi,int numar_pradatori):
    Pasare(specie,varsta,greutate,lungime_aripi),numar_pradatori(numar_pradatori){}
    void display(){
        
        std::cout<<"pasare pradatoare: "<<specie<<" "<<greutate<<" "<<lungime_aripi<<" "<<numar_pradatori<<std::endl;
    }
    void necesar_hrana(){
        float hrana_necesara=this->greutate*60/100;
        std::cout<<std::fixed<<std::setprecision(2);
        std::cout<<specie<<" - "<<hrana_necesara<<"\n";
        
    }
    float necesar()
    {
        return this->greutate*60/100;
    }
    void suprafata_necesara()
    {
        std::cout<<specie<<": "<<std::fixed<<std::setprecision(2)<<greutate*0.5+varsta*0.3+lungime_aripi*0.2+numar_pradatori<<"\n";
    }
    void suprafata_necesara_zbor(float efort)
    {
        std::cout<<specie<<" "<<std::fixed<<std::setprecision(2)<<lungime_aripi/greutate*varsta/10*efort*1.5<<"\n";
    }
};
bool cmp(Animal *lhs, Animal *rhs){
    return(lhs->necesar()<rhs->necesar());
}
int main()
{
    int nr_a,varsta_a,numar_pradatori_a,test;
    float greutate_a,lungime_a, factor_a,temp_a;
    std::string tip_a,specie_a;
   
    std::vector<Animal*> animal; 
    std::cin>>nr_a;
    std::cin.ignore();
    for(int i=0;i<nr_a;i++)
    {
        Animal *a=nullptr;
       // std::cin.ignore();
        std::getline(std::cin,specie_a);
        std::cin>>varsta_a;
        std::cin>>greutate_a;
        //std::cin.ignore();
        std::cin>>tip_a;
        if(tip_a=="mamifer")
        {
            std::cin>>factor_a>>temp_a;
            a=new Mamifer(specie_a,varsta_a,greutate_a,factor_a,temp_a);
            //animal.push_back(a);
        }
        if(tip_a=="pasare")
        {
            std::cin>>lungime_a;
            a=new Pasare(specie_a,varsta_a,greutate_a,lungime_a);
           // animal.push_back(a);
        }
        if(tip_a=="pradator")
        {
            std::cin>>lungime_a;
            std::cin>>numar_pradatori_a;
            a=new PasarePradatoare(specie_a,varsta_a,greutate_a,lungime_a,numar_pradatori_a);
            
        }
        animal.push_back(a);
        std::cin.ignore();
    }
    std::cin>>test;
    if(test==1)
    {
        for(auto a :animal)
          a->display();
        
    }
    if(test==2)
    {
        for(Animal* a :animal)
        {
        a->necesar_hrana();}
    }
    if(test==3)
    {
        std::sort(animal.begin(),animal.end(),cmp);
        for(auto a: animal)
        {
            a->display();
        }
    }
    if(test==4)
    {
        for(auto a: animal)
        {
            a->suprafata_necesara();
        }
    }
    if(test==5)
    {
        int ind;
        float ef;
        std::cin>>ind>>ef;
        animal[ind]->suprafata_necesara_zbor(ef);
    }
    for(auto a:animal)
    {
        delete a;
    }
    return 0;
}