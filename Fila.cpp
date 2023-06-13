#include "Fila.h"
#include<iostream>
#include<time.h>
using namespace std;

Fila::Fila(){
    //pré-condição: Nenhuma
    //pós-condição: A fila é criada e começa vazia

    Count=0;
    Tail=0;
    Head=0;
}

bool Fila::Full(){
    //pré-condição: A fila já foi criada
    //pós-condição: Retorna true se estiver cheia, caso contrário retorna false

    bool flag=false;

    if(Count==(MaxFila)){
        flag=true;
    }
    
    return flag;
}

bool Fila::Empty(){
    //pré-condição: A fila já foi criada
    //pós-condição: Retorna true se estiver vazia, caso contrário retorna false
    bool flag=false;
    
    if(Count==0){
        flag=true;
    }

    return flag;
}

void Fila::Clear(){
    //pré-condição: A fila já foi criada
    //pós-condição: Todos os itens são descartados e a fila se torna vazia
    Count=0;
    Tail=0;
    Head=0;

}

int Fila::Size(){
    //pré-condição: A fila já foi criada
    //pós-condição: Retorna a quantidade de itens da fila
    if(Empty()){
        return 0;
    }else{
        return Count;
    }
}

void Fila::Append(Dados Cartas){
    //pré-condição: A fila já foi criada e não está cheia
    //pós-condição: A variável "Cartas" é armazenado no final da fila
    if(Full()){
        cout << "Deck de cartas cheio." << endl;
        abort();
    }
    
    if(Empty()){
        Head = (Head % MaxFila)+1;
    }

    Tail = (Tail % MaxFila)+1;
    Entrada[Tail] = Cartas;
    Count++;
    
}

void Fila::Serve(Dados &Cartas){
    //pré-condição: A fila já foi criada e não está vazia
    //pós-condição: Remove o item inicial da fila e seu valor é retornado na variável "Cartas"
    if(Empty()){
        cout << "Deck de cartas vazio." << endl;
        abort();
    }

    Cartas=Entrada[Head];
    Head=(Head % MaxFila)+1;
    Count--;
    
}

void Fila::Front(Dados &Cartas){
    //pré-condição: A fila já foi criada e não está vazia
    //pós-condição: A variável "Cartas" recebe uma cópia do valor inicial da fila. A fila fica inalterada
    if(Empty()){
        cout << "Deck de cartas vazio." << endl;
        abort();   
    }
    Cartas = Entrada[Head];

}

void Fila::Rear(Dados &Cartas){
    //pré-condição: A fila já foi criada e não está vazia
    //pós-condição: A variável "Cartas" recebe uma cópia do valor final da fila. A fila fica inalterada
    if(Empty()){
        cout << "Deck de cartas vazio." << endl;
        abort();
    }
    Cartas = Entrada[Tail];
}

void Fila::Embaralhar(){
    //pré-condição: A fila já foi criada e não está vazia
    //pós-condição: Muda de posição os valores da fila para ela ser embaralhada
    if(Empty()){
        cout << "Deck de cartas vazio." << endl;
        abort();
    }

    srand(time(NULL));
    int j=1;
    int num;

    for(int i=1; i<=MaxFila; i++){

        int r = rand() % MaxFila+1;

		Dados temp = Entrada[i];
		Entrada[i] = Entrada[r];
		Entrada[r] = temp;
    }

}   

void Fila::NovoJogador(Fila &Jogador){
    //pré-condição: A fila já foi criada e não está vazia
    //pós-condição: É criada uma nova fila com metade dos valores da fila principal, removendo os 
    //valores que foram transferidos para a nova fila

    if(Empty()){
        cout << "Deck de cartas vazio." << endl;
        abort();
    }

    Dados valor;
    for(int i=1; i<=16; i++){
        Jogador.Append(Entrada[Head]);
        Serve(valor);
    }

}