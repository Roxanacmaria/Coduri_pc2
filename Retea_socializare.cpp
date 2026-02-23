#include<iostream>
#include<string>
class Profil{
private:
    int id;
    std::string nume;
    int an;
    int luna;
    int zi;
public:
    Profil(int id,std::string nume,int an ,int luna,int zi):
      id(id),nume(nume),an(an),luna(luna),zi(zi){};
      void afisare()
      {
          std::cout<<this->id<<"\n";
          std::cout<<this->nume<<"\n";
          std::cout<<this->an<<" "<<this->luna<<" "<<this->zi<<"\n";
      }
      void check_age(){
          std::cout<<this->id<<"\n";
          if((this->an <1900)||(2021<this->an)||(this->luna<1)||(this->luna>12)||(this->zi<1)||(this->zi>30))
      {
          std::cout<<"EROARE: Data de nastere introdusa nu e valida"<<"\n";
      }
      else {
          std::cout<<this->an<<" "<<this->luna<<" "<<this->zi<<"\n";
      }
      }
      int calcul_varsta(int an,int luna,int zi){
          int data_nastere=(this->an*12+this->luna)*30+this->zi;
          int data_curenta=(an*12+luna)*30+zi;
          int varsta_ani=data_curenta-data_nastere;
          return(varsta_ani/360);
      }
      std::string get_nume()const{
          return this->nume;
      }
      void set_nume(const std::string nume){
          this->nume=nume;
      }
};
class Post{
    int id;
    int minim,maxim;
    std::string cont;
public:
    Post(int id,int minim,int maxim,std::string cont):id(id),minim(minim),maxim(maxim),cont(cont){}
   std::string get_content()const{
       return this->cont;
   }
   int get_id()const{
       return this->id;
   }
   int get_maxim()const{
       return this->maxim;
   }
   int get_minim()const{
       return this->minim;
   }
   
    
};
//class Profil;//forword declaration
class Website{
private:
    int nr_utilizatori;
    Profil **utilizatori;
    Post **postare;
public:
   Website(int nr_utilizatori):nr_utilizatori(nr_utilizatori){
       utilizatori = new Profil*[nr_utilizatori];
       postare =new Post*[nr_utilizatori];
   }
   void set_utilizatori(int i,std::string nume,int an,int luna,int zi)
   {
       utilizatori[i] = new Profil(i,nume,an,luna,zi);
   }
   void afisare_utilizatori()
   {
       for(int i=-0;i<nr_utilizatori;i++){
           utilizatori[i]->afisare();
       }
   }
   void afisare_varsta()
   {
       for(int i=-0;i<nr_utilizatori;i++){
           utilizatori[i]->check_age();
       }
   }
   void verificare_major(int an,int luna,int zi)
   {
       //int an_i,luna_i,zi_i;
       for(int i=0;i<nr_utilizatori;i++){
           int varsta=utilizatori[i]->calcul_varsta( an, luna, zi);
           if(varsta>=18){
               std::cout<<utilizatori[i]->get_nume()<<"\n"<<utilizatori[i]->calcul_varsta(an,luna,zi)<<"\n";
           }
       }
   }

   void categorii(Post **postare ,int numarp,int an,int luna,int zi)
   {
       std::cout<<"News Feed"<<std::endl;
       int count=0;
       int varsta0=utilizatori[0]->calcul_varsta(an,luna,zi);
       for(int i=0;i<numarp;i++)
       {
           if(postare[i]->get_id()==0)
           {
               std::cout<<utilizatori[0]->get_nume()<<std::endl;
               std::cout<<postare[i]->get_content()<<std::endl;
               count++;
           }
           else {
               if((varsta0>=postare[i]->get_minim())&&(varsta0<=postare[i]->get_maxim()))
               {
                   count++;
                   std::cout<<utilizatori[postare[i]->get_id()]->get_nume()<<std::endl;
                   std::cout<<postare[i]->get_content()<<std::endl;
               }
           }
       }
       if(count==0)
       {
           std::cout<<"No posts for you"<<std::endl;
       }
       
   }
   

};

int main()
{
    int comanda,temp_nr_utilizatori,temp_an,temp_zi,temp_luna;
    std::cin>>temp_nr_utilizatori;
    std::string temp_nume;
    Post **postare=nullptr;
    Website w(temp_nr_utilizatori);
    for(int i=0;i<temp_nr_utilizatori;i++)
    {
        std::cin.ignore();
        std::getline(std::cin,temp_nume);
        // std::cout<<i<<"\n";
        // std::cout<<temp_nume<<"\n";
         std::cin>>temp_an;
         std::cin>>temp_luna;
         std::cin>>temp_zi;
        // std::cout<<temp_an<<" "<<temp_luna<<" "<<temp_zi<<"\n";
        w.set_utilizatori(i,temp_nume,temp_an,temp_luna,temp_zi);
        //w.afisare_utilizatori();
    }
    std::cin>>comanda;
    switch(comanda)
    {
        case 1: {
            w.afisare_utilizatori();
            break;
        }
        case 2: {
            w.afisare_varsta();
            break;
        }
        case 3: {
            int an_n,luna_n,zi_n;
            std::cin>>an_n>>luna_n>>zi_n;
            w.verificare_major(an_n,luna_n,zi_n);
            break;
        }
         case 4: {
             int an_n,luna_n,zi_n,nr_post,id_p,min,max;
             std::string continut;
            std::cin>>an_n>>luna_n>>zi_n>>nr_post;
            postare=new Post*[nr_post];
            for(int i=0;i<nr_post;i++)
            {
                std::cin>>id_p>>min>>max;
                std::cin.ignore();
                std::getline(std::cin,continut);
                postare[i]=new Post(id_p,min,max,continut);
            }
             
            w.categorii(postare,nr_post,an_n,luna_n,zi_n);
             
             break;
         }  
    }
}