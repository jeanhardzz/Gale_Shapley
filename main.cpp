#include <iostream>
#include "gale_shapley.h"
#include "lista_preferencia.h"
//#include <map>
//#include "Lista_encadeada/lista-encadeada.h"


int main(){
  /*
  ListaPreferencia hospitais;
  ListaPreferencia alunos;  
  
  hospitais.AdicionaPreferencia(1,1);
  hospitais.AdicionaPreferencia(1,2);
  hospitais.AdicionaPreferencia(1,3);

  hospitais.AdicionaPreferencia(2,2);
  hospitais.AdicionaPreferencia(2,1);
  hospitais.AdicionaPreferencia(2,3);

  hospitais.AdicionaPreferencia(3,1);
  hospitais.AdicionaPreferencia(3,2);
  hospitais.AdicionaPreferencia(3,3);

  alunos.AdicionaPreferencia(1,2);
  alunos.AdicionaPreferencia(1,1);
  alunos.AdicionaPreferencia(1,3);

  alunos.AdicionaPreferencia(2,1);
  alunos.AdicionaPreferencia(2,2);
  alunos.AdicionaPreferencia(2,3);

  alunos.AdicionaPreferencia(3,1);
  alunos.AdicionaPreferencia(3,2);
  alunos.AdicionaPreferencia(3,3);

  
  printf("Hospitais:\n");
  hospitais.Imprime();

  printf("Alunos:\n");
  alunos.Imprime();

  std::cout<<"main: "<<hospitais.GetTotal()<<"\n";

  
  */
  GaleShapley match;
  match.Matching();
  match.Imprime();

  return 0;
}
