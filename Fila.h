using namespace std;

#ifndef FILA_H
#define FILA_H

const int MaxFila=32;

struct Dados{

    char model[20];
    int curbWeight;
    int engineSize;
    int horsePower;
    int price;
    char group[3];

};//struct para guardar todos as variáveis necessárias

typedef Dados Dados;

class Fila{

    public:
        Fila();
        bool Empty();
        bool Full();
        void Append(Dados Cartas);
        void Serve(Dados &Cartas);
        void Clear();
        int Size();
        void Front(Dados &Cartas);
        void Rear(Dados &Cartas);
        void Embaralhar();
        void Retirar(int atributo);
        void NovoJogador(Fila &Jogador);
    
    private:
        int Head;
        int Tail;
        int Count;
        Dados Entrada[MaxFila+1];

};

#endif