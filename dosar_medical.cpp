#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
class EvenimentMedical{
protected: 
    std::string tip_ev;//con,int
    int luna,an;
    std::string sectie;
public:
    EvenimentMedical(std::string tip_ev,int luna,int an,std::string sectie):
    tip_ev(tip_ev),luna(luna),an(an),sectie(sectie){}
    virtual void display()=0;
    int get_an(){
        return this->an;
    }
    virtual void display1()=0;
    virtual int get_zile()=0;
    std::string get_tip()
    {
        return this->tip_ev;
    }
    int get_luna(){
        return luna;
    }
    virtual std::string get_diag()=0;
};
class Consultatii:public EvenimentMedical{
private:
    std::string diagnostic;
public:
    Consultatii(std::string tip_ev,int luna,int an,std::string sectie,std::string diagnostic):
    EvenimentMedical(tip_ev,luna,an,sectie),diagnostic(diagnostic){}

    void display(){
        std::cout<<tip_ev<<"\n"<<luna<<"."<<an<<","<<sectie<<":"<<diagnostic<<"\n";
    }
      int get_zile(){
        return 0;
    }
    std::string get_diag(){
        return diagnostic;
    }
    void display1()
    {
    }
};
class Internari:public EvenimentMedical{
private: 
    int nr_zile;
public:
    Internari(std::string tip_ev,int luna,int an,std::string sectie,int nr_zile):
    EvenimentMedical(tip_ev,luna,an,sectie),nr_zile(nr_zile){}
    void display()
    {
        std::cout<<tip_ev<<"\n"<<luna<<"."<<an<<","<<sectie<<":"<<nr_zile<<"\n";
    }
    int get_zile()
    {
        return this->nr_zile;
    }
    std::string get_diag(){
        return "";
    }
  void display1()
    {
        std::cout<<luna<<"."<<an<<":"<<sectie<<":"<<nr_zile<<"\n";
    }
};
bool cmp(EvenimentMedical *lhs,EvenimentMedical*rhs)
{
    return(lhs->get_zile()>rhs->get_zile());
}
class DosarMedical{
protected:
    std::vector<EvenimentMedical*>evenim;
    std::string nume;
    int nr_c;
public:
    DosarMedical(std::string nume,int nr_c):nume(nume),nr_c(nr_c){}
    void adauga(EvenimentMedical *x)
    {
        evenim.push_back(x);
    }
    void afis()
    {
        std::cout<<nume<<"\n";
        for(auto a:evenim)
        {
            a->display();
        }
    }
    void calcul(){
        int nr_c_22=0,nr_i_22=0;
        int nr_c_23=0,nr_i_23=0;
        for(auto a:evenim)
        {
            if(a->get_an()==2022)
            {
                if(a->get_tip()=="Consultatie")nr_c_22++;
                else nr_i_22+=a->get_zile();
            }
            if(a->get_an()==2023)
            {
                 if(a->get_tip()=="Consultatie")nr_c_23++;
                else nr_i_23+=a->get_zile();
            }
        }
        std::cout<<"2022: zile internare="<<nr_i_22<<", consultatii="<<nr_c_22<<"\n";
        std::cout<<"2023: zile internare="<<nr_i_23<<", consultatii="<<nr_c_23<<"\n";
    }
    void ev()
    {
        int nr_i=0,nr_zi=0,nr_com=nr_c,m_luna=0;
        for(auto a:evenim)
        {
            if(a->get_an()==2022)
            {
                if(a->get_luna()==12)
                 {if(a->get_tip()=="Internare")nr_i++;
                  else if(a->get_diag()=="Bolnav")nr_com++;
                 }
                 if(a->get_luna()<12)
                 {
                     if(a->get_diag()=="Bolnav")nr_com++;
                 }
            }
            if(a->get_an()==2023)
            {
                if(a->get_tip()=="Internare")nr_i++;
                if(a->get_luna()>m_luna){m_luna=a->get_luna();nr_zi=a->get_zile();}
            }
        }
        std::cout<<nr_zi+nr_i+nr_com;
    }
    void cmpr()
    {
        std::sort(evenim.begin(),evenim.end(),cmp);
        for(auto a:evenim)
        {
            a->display1();
        }
    }
};
int main()
{
    std::string name,sec,diag,tip;
    int nrc,test,nr_ev,nr_z,l,a;
    std::cin>>nr_ev;
    std::cin.ignore();
    EvenimentMedical *e=nullptr;
   std::getline(std::cin,name);
    std::cin>>nrc;
    
    DosarMedical d(name,nrc);
   
    for(int i=0;i<nr_ev;i++)
    {
        std::cin>>a>>l;
        std::cin.ignore();
        std::getline(std::cin,sec);
        std::cin>> tip;
        if(tip=="Consultatie")
        {
            std::cin>>diag;
            e=new Consultatii(tip,l,a,sec,diag);
        }
        else {
            std::cin>>nr_z;
            e=new Internari(tip,l,a,sec,nr_z);
        }
        d.adauga(e);
    }
    std::cin>>test;
    if(test==1)
    {
        d.afis();
    }
    if(test==2)
    {
        d.calcul();
    }
    if(test==3)
    {
       d.ev(); 
    }
    if(test==4)
    {
        d.cmpr();
    }
    
}