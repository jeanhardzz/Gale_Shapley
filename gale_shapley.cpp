#include <iostream>
#include "gale_shapley.h"


GaleShapley::GaleShapley(){  
    //tem que preencher a e b pra poder inciar
    this->test();

    /*
    printf("Hospitais:\n");
    this->a.Imprime();

    printf("Alunos:\n");
    this->b.Imprime();
    */

    for(int i=1;i<=this->a.GetTotal();i++){
        this->m_a[i]=0;        
    }
    for(int i=1;i<=this->b.GetTotal();i++){ 
        this->m_b[i]=0;        
    }
    /*
    printf("Matching:\n");        
    for(auto &item : this->m_a){
        std::cout <<"Hospital "<< item.first << " : "<<item.second<<" Aluno\n" ;        
    }

    printf("\nMatching 2:\n");        
    for(auto &item : this->m_b){
        std::cout <<"Aluno "<< item.first << " : "<<item.second<<" Hospital\n" ;        
    }
    */
}

void GaleShapley::Rank(){
    rank_b = this->b.Rank();    
}

void GaleShapley::Imprime(){
    printf("Hospitais:\n");
    this->a.Imprime();

    printf("Alunos:\n");
    this->b.Imprime();
    
    /*
    printf("Rank de Pref dos Alunos:\n");    
    this->rank_b.Imprime();
    */

    printf("Matching A:\n");        
    for(auto &item : this->m_a){
        std::cout <<"Hospital "<< item.first << " : "<<item.second<<" Aluno\n" ;        
    }

    printf("\nMatching B:\n");        
    for(auto &item : this->m_b){
        std::cout <<"Aluno "<< item.first << " : "<<item.second<<" Hospital\n" ;        
    }

}


void GaleShapley::test(){    

  this->a.AdicionaPreferencia(1,2);
  this->a.AdicionaPreferencia(1,1);
  this->a.AdicionaPreferencia(1,4);
  this->a.AdicionaPreferencia(1,5);
  this->a.AdicionaPreferencia(1,3);

  this->a.AdicionaPreferencia(2,4);
  this->a.AdicionaPreferencia(2,2);
  this->a.AdicionaPreferencia(2,1);
  this->a.AdicionaPreferencia(2,3);
  this->a.AdicionaPreferencia(2,5);

  this->a.AdicionaPreferencia(3,2);
  this->a.AdicionaPreferencia(3,5);
  this->a.AdicionaPreferencia(3,3);
  this->a.AdicionaPreferencia(3,4);
  this->a.AdicionaPreferencia(3,1);

  this->a.AdicionaPreferencia(4,1);
  this->a.AdicionaPreferencia(4,4);
  this->a.AdicionaPreferencia(4,3);
  this->a.AdicionaPreferencia(4,2);
  this->a.AdicionaPreferencia(4,5);

  this->a.AdicionaPreferencia(5,2);
  this->a.AdicionaPreferencia(5,4);
  this->a.AdicionaPreferencia(5,1);
  this->a.AdicionaPreferencia(5,5);
  this->a.AdicionaPreferencia(5,3);

  this->b.AdicionaPreferencia(1,5);
  this->b.AdicionaPreferencia(1,1);
  this->b.AdicionaPreferencia(1,2);
  this->b.AdicionaPreferencia(1,4);
  this->b.AdicionaPreferencia(1,3);

  this->b.AdicionaPreferencia(2,3);
  this->b.AdicionaPreferencia(2,2);
  this->b.AdicionaPreferencia(2,4);
  this->b.AdicionaPreferencia(2,1);
  this->b.AdicionaPreferencia(2,5);

  this->b.AdicionaPreferencia(3,2);
  this->b.AdicionaPreferencia(3,3);
  this->b.AdicionaPreferencia(3,4);
  this->b.AdicionaPreferencia(3,5);
  this->b.AdicionaPreferencia(3,1);
  
  this->b.AdicionaPreferencia(4,1);
  this->b.AdicionaPreferencia(4,5);
  this->b.AdicionaPreferencia(4,4);
  this->b.AdicionaPreferencia(4,3);
  this->b.AdicionaPreferencia(4,2);

  this->b.AdicionaPreferencia(5,4);
  this->b.AdicionaPreferencia(5,2);
  this->b.AdicionaPreferencia(5,5);
  this->b.AdicionaPreferencia(5,3);
  this->b.AdicionaPreferencia(5,1);

/*
  this->a.AdicionaPreferencia(1,1);
  this->a.AdicionaPreferencia(1,2);
  this->a.AdicionaPreferencia(1,3);

  this->a.AdicionaPreferencia(2,2);
  this->a.AdicionaPreferencia(2,1);
  this->a.AdicionaPreferencia(2,3);

  this->a.AdicionaPreferencia(3,1);
  this->a.AdicionaPreferencia(3,2);
  this->a.AdicionaPreferencia(3,3);

  this->b.AdicionaPreferencia(1,2);
  this->b.AdicionaPreferencia(1,1);
  this->b.AdicionaPreferencia(1,3);

  this->b.AdicionaPreferencia(2,1);
  this->b.AdicionaPreferencia(2,2);
  this->b.AdicionaPreferencia(2,3);

  this->b.AdicionaPreferencia(3,1);
  this->b.AdicionaPreferencia(3,2);
  this->b.AdicionaPreferencia(3,3);
*/  

  this->Rank();    
}

TipoChave GaleShapley::Test_Unmatch_a(){
    for(auto &item : m_a){
        if(item.second==0){
            return item.first;
        }
    }
    return 0;
}

void GaleShapley::Matching(){

    TipoChave aux_b;
    TipoChave k;
    ListaEncadeada l_rank;

    k=this->Test_Unmatch_a();
    while(k!=0){        
        aux_b=a.PegaProxProposta(k);
        //std::cout<<"olhando hospital: "<<k<<" com aluno: "<<m_b[aux_b]<<std::endl;
        //std::cout<<rank_b.GetLista(aux_b).GetItem(k).GetChave()<<" é menor q"<<rank_b.GetLista(aux_b).GetItem(m_b[aux_b]).GetChave()<<std::endl;
        if(m_b[aux_b]==0){            
            m_a[k]=aux_b;
            m_b[aux_b]=k;
        }else if(rank_b.PegaItemNaLista(aux_b,k)<rank_b.PegaItemNaLista(aux_b,m_b[aux_b])){            
            m_a[m_b[aux_b]]=0;

            m_a[k]=aux_b;            
            m_b[aux_b]=k;
        }else{
        }
        a.AndaProposta(k);                
        k=this->Test_Unmatch_a();
        
    }
}





