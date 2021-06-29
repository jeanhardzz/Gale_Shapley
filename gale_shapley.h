#ifndef GALESHAP
#define GALESHAP

#include <map>
#include "Lista_encadeada/lista-encadeada.h"
#include "lista_preferencia.h"

class GaleShapley{
    private:      
        ListaPreferencia a;
        ListaPreferencia b;        
        ListaPreferencia rank_b;
        std::map<TipoChave,TipoChave> m_a;
        std::map<TipoChave,TipoChave> m_b;
         
    public:
        GaleShapley();
        void test();              
        void Rank();
        void Imprime();
        TipoChave Test_Unmatch_a();
        void Matching();

        
};

#endif