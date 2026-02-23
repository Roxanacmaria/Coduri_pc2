#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<algorithm>
class JocVideo{
protected:
    std::string nume_joc;
    int zi,luna,an;
    std::string tip;
    int nr_note;
    int *note;
public:
    JocVideo(std::string nume_joc,
             int zi,
             int luna,
             int an,
             std::string tip,
             int nr_note,
             int *note):
    nume_joc(nume_joc),zi(zi),luna(luna),an(an),tip(tip),nr_note(nr_note){
        this->note=new int[nr_note];
        for(int i=0;i<nr_note;i++)
        {
            this->note[i]= note[i];
        }
    }
    virtual void display()=0;
    virtual void get_playtime(int a, float b)=0;
    float medie()
    {
        int sum=0;
        for(int i=0;i<nr_note;i++)
        {
            sum+=note[i];
        }
        return (float)sum/nr_note;
    }
    std::string get_nume()
    {
        return this->nume_joc;
    }
    int get_zi()
    {
        return this->zi;
    }
    int get_luna()
    {
        return this->luna;
    }
    int get_an()
    {
        return this->an;
    }
    
    std::string get_tip()
    {
        return this->tip;
    }
};
class SinglePlayer: public JocVideo{
private:
    int nr_nivele;
public:
   SinglePlayer(std::string nume_joc,
                int zi,
                int luna,
                int an,
                std::string tip,
                int nr_note,
                int *note,
                int nr_nivele): JocVideo(nume_joc,zi,luna,an,tip,nr_note,note),nr_nivele(nr_nivele){}

    void display()
    {
      std::cout<<"singleplayer: "<<nume_joc<<" - "<<zi<<" "<<luna<<" "<<an<<" - "<<nr_nivele<<"\n";  
    }
    void get_playtime(int a,float b)
    {
        std::cout<<nume_joc<<": "<<std::fixed<<std::setprecision(2)<<nr_nivele*a*b<<"\n";
    }
};
class MultiPlayer: public JocVideo{
private:
    int nr_meciuri;
public:
    MultiPlayer(std::string nume_joc,
                 int zi,
                 int luna,
                 int an,
                 std::string tip,
                 int nr_note,
                 int *note,
                 int nr_meciuri):JocVideo(nume_joc,zi,luna,an,tip,nr_note,note),nr_meciuri(nr_meciuri){}

    void display(){
        std::cout<<"multiplayer: "<<nume_joc<<" - "<<zi<<" "<<luna<<" "<<an<<" - "<<nr_meciuri<<"\n";
    }
    void get_playtime(int a,float b)
    {
        std::cout<<nume_joc<<": "<<std::fixed<<std::setprecision(2)<<(1.00*nr_meciuri)/a*b<<"\n";
    }
};
class JocVideoHandle{
private:
    std::vector<JocVideo *>jocuri;
public:
    void adauga(JocVideo* j)
    {
        this->jocuri.push_back(j);
    }
    void afisare()
    {
        for(auto j: jocuri)
        {
            j->display();
        }
    }
    void thebest()
    {
        float medie_b=jocuri[0]->medie();
        JocVideo *jv=jocuri[0];
        for(auto j:jocuri)
        {
            if(j->medie()>medie_b)
             {
                 medie_b=j->medie();
                 jv=j;
             }
        }
        std::cout<<std::fixed<<std::setprecision(2)<<jv->get_nume()<<": "<<medie_b<<"\n";
    }
    void filtru(int z,int l,int a)
    {
        //JocVideo *jv=jocuri[0];
        for(auto j: jocuri)
        {
            if(a<j->get_an())
            {
                std::cout<<j->get_nume()<<": "<<j->get_tip()<<"\n";
            }
            if(a==j->get_an())
            {
                if(l<j->get_luna())
                 std::cout<<j->get_nume()<<": "<<j->get_tip()<<"\n";
                else if(l==j->get_luna())
                {
                    if (z<j->get_zi())
                    std::cout<<j->get_nume()<<": "<<j->get_tip()<<"\n";
                }
            }
        }
    }
    void n_v()
    {
        int an_n=jocuri[0]->get_an();
        int an_v=jocuri[0]->get_an();
        int l_n=jocuri[0]->get_luna();
        int l_v=jocuri[0]->get_luna();
        int z_n=jocuri[0]->get_zi();
        int z_v=jocuri[0]->get_zi();
        JocVideo *n=jocuri[0];
        JocVideo *v=jocuri[0];
        for(auto j:jocuri)
        {
            if(j->get_an()>an_n)
            {
                an_n=j->get_an();
                l_n=j->get_luna();
                z_n=j->get_zi();
                n=j;
            }
            if(j->get_an()<an_v)
            {
                an_v=j->get_an();
                l_v=j->get_luna();
                z_v=j->get_zi();
                v=j;
            }
        }
        for(auto j:jocuri)
        {
            if(j->get_an()==an_n)
            {
                if(j->get_luna()>l_n)
                  n=j;
                else if(j->get_luna()==l_n)
                {
                    if(j->get_zi()>z_n)
                    n=j;
                
                }
            }
        }
        for(auto j:jocuri)
        {
            if(j->get_an()==an_v)
            {
                if(j->get_luna()<l_v)
                  v=j;
                else if(j->get_luna()==l_v)
                {
                    if(j->get_zi()<z_v)
                    v=j;
                
                }
            }
        }
        n->display();
        v->display();
        
    }
    void timp(int a,float b)
    {
        for(auto j:jocuri)
        {
            j->get_playtime(a,b);
        }
    }
    
    
};
int main()
{
 int nr_jocuri,test;
 JocVideoHandle JVH;
 JocVideo* JV=nullptr;
 std::string name,type;
 int zi_t,luna_t,an_t,nr_note_t,*note_t,nr_nivele_t,nr_meciuri_t;
 std::cin>>nr_jocuri;
 std::cin.ignore();
 for(int i=0;i<nr_jocuri;i++)
 {
     std::getline(std::cin,name);
     std::cin>>zi_t>>luna_t>>an_t;
     std::cin>>nr_note_t;
     std::cin.ignore();
     note_t=new int[nr_note_t];
     for(int j=0;j<nr_note_t;j++)
     {
        std::cin>>note_t[j];
     }
     std::cin>>type;
     if(type=="singleplayer")
     {
         std::cin>>nr_nivele_t;
         JV= new SinglePlayer(name,zi_t,luna_t,an_t,type,nr_note_t,note_t,nr_nivele_t);
     }
     if(type=="multiplayer")
     {
         std::cin>>nr_meciuri_t;
         JV= new MultiPlayer(name,zi_t,luna_t,an_t,type,nr_note_t,note_t,nr_meciuri_t);
     }
     JVH.adauga(JV);
     std::cin.ignore();
 }
 std::cin>>test;
 if(test==1)
 {
     JVH.afisare();
 }
 if(test==2)
 {
     JVH.thebest();
 }
 if(test==3)
 {
     int z1,l1,a1;
     std::cin>>z1>>l1>>a1;
     JVH.filtru(z1,l1,a1);
 }
 if(test==4)
 {
     JVH.n_v();
 }
 if(test==5)
 {
     int a1;
     float b1;
     std::cin>>a1>>b1;
     JVH.timp(a1,b1);
 }
}