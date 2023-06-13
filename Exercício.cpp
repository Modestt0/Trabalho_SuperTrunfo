#include<iostream>
#include<fstream>
#include<string.h>
#include"Fila.h"
using namespace std;

void SuperTrunfo(Fila Q){
    cout << "SUPER TRUNFO" << endl << endl;
    int aux_jogo=0;
    int opcao, atributo;
    Fila Player1, Computador;
    Dados P1, Cmp, Cards;

    Q.Embaralhar();
    Q.NovoJogador(Player1);
    Q.NovoJogador(Computador);

    while(aux_jogo==0){
        //while para aux_jogo o jogo até acabar as cartas de alguém

        Player1.Front(P1);
        Computador.Front(Cmp);
        cout << "Nome: " << P1.model << endl;
        cout << "Grupo: " << P1.group << endl;
        cout << "Peso Bruto: " << P1.curbWeight << endl;
        cout << "Cilindrada: " << P1.engineSize << endl;
        cout << "Potência: " << P1.horsePower << endl;
        cout << "Preço: " << P1.price << endl << endl;
        
        if(strcmp(P1.group, "1A")==0){
            //if para caso a carta seja a super trunfo

            cout << "--Jogador--" << endl;
            cout << "Nome: " << P1.model << endl;
            cout << "Grupo: " << P1.group << endl;
            cout << "Peso Bruto: "  << P1.curbWeight << endl;
            cout << "Cilindrada: " << P1.engineSize << endl;
            cout << "Potência: " << P1.horsePower << endl;
            cout << "Preço: " << P1.price << endl << endl;
            
            cout << "--Computador--" << endl;
            cout << "Nome: " << Cmp.model << endl;
            cout << "Grupo: " << Cmp.group << endl;
            cout << "Peso Bruto: "  << Cmp.curbWeight << endl;
            cout << "Cilindrada: " << Cmp.engineSize << endl;
            cout << "Potência: " << Cmp.horsePower << endl;
            cout << "Preço: " << Cmp.price << endl << endl;

            cout << "JOGADOR TEM A CARTA SUPER TRUNFO!" << endl;
            if(Cmp.group[1]=='A'){
                cout << "Computador ganhou a rodada!" << endl << endl;
                Computador.Serve(Cards);
                Computador.Append(Cards);
                Player1.Serve(Cards);
                Computador.Append(Cards);    
            }
            else{
                cout << "Jogador ganhou a rodada!" << endl << endl;
                Player1.Serve(Cards);
                Player1.Append(Cards);
                Computador.Serve(Cards);
                Player1.Append(Cards);
            }
        }
        else if(strcmp(Cmp.group, "1A")==0){
            //if para caso a carta seja a super trunfo

            cout << "--Jogador--" << endl;
            cout << "Nome: " << P1.model << endl;
            cout << "Grupo: " << P1.group << endl;
            cout << "Peso Bruto: "  << P1.curbWeight << endl;
            cout << "Cilindrada: " << P1.engineSize << endl;
            cout << "Potência: " << P1.horsePower << endl;
            cout << "Preço: " << P1.price << endl << endl;
            
            cout << "--Computador--" << endl;
            cout << "Nome: " << Cmp.model << endl;
            cout << "Grupo: " << Cmp.group << endl;
            cout << "Peso Bruto: "  << Cmp.curbWeight << endl;
            cout << "Cilindrada: " << Cmp.engineSize << endl;
            cout << "Potência: " << Cmp.horsePower << endl;
            cout << "Preço: " << Cmp.price << endl << endl;

            cout << "COMPUTADOR TEM A CARTA SUPER TRUNFO!" << endl;
            if(P1.group[1]=='A'){
                cout << "Jogador ganhou a rodada!" << endl << endl;
                Player1.Serve(Cards);
                Player1.Append(Cards);
                Computador.Serve(Cards);
                Player1.Append(Cards);    
            }
            else{
                cout << "Computador ganhou a rodada!" << endl << endl;
                Computador.Serve(Cards);
                Computador.Append(Cards);
                Player1.Serve(Cards);
                Computador.Append(Cards);
            }
        }
        else{
            //else para, caso a carta não seja a super trunfo, o jogador escolher um dos atributos

            do{
                //do while para caso o jogador digite um número diferente dos disponíveis

                cout << "Escolha um dos atributos:" << endl;
                cout << "1 - Peso Bruto" << endl;
                cout << "2 - Cilindrada" << endl;
                cout << "3 - Potência" << endl;
                cout << "4 - Preço" << endl;
                cin >> atributo;
                cout << endl;
                if(atributo<1||atributo>4){
                    cout << "Erro, tente novamente" << endl << endl;
                }
            }while(atributo<1||atributo>4);

            cout << "--Jogador--" << endl;
            cout << "Nome: " << P1.model << endl;
            cout << "Grupo: " << P1.group << endl;
            cout << "Peso Bruto: "  << P1.curbWeight << endl;
            cout << "Cilindrada: " << P1.engineSize << endl;
            cout << "Potência: " << P1.horsePower << endl;
            cout << "Preço: " << P1.price << endl << endl;
            
            cout << "--Computador--" << endl;
            cout << "Nome: " << Cmp.model << endl;
            cout << "Grupo: " << Cmp.group << endl;
            cout << "Peso Bruto: "  << Cmp.curbWeight << endl;
            cout << "Cilindrada: " << Cmp.engineSize << endl;
            cout << "Potência: " << Cmp.horsePower << endl;
            cout << "Preço: " << Cmp.price << endl << endl;

            switch(atributo){
                //switch para comparar os atributos escolhidos pelo usuário

                case 1:
                    if(P1.curbWeight>Cmp.curbWeight){
                        cout << "Jogador ganhou a rodada!" << endl << endl;
                        Player1.Serve(Cards);
                        Player1.Append(Cards);
                        Computador.Serve(Cards);
                        Player1.Append(Cards);   
                    }
                    if(P1.curbWeight<Cmp.curbWeight){
                        cout << "Computador ganhou a rodada!" << endl << endl;
                        Computador.Serve(Cards);
                        Computador.Append(Cards);
                        Player1.Serve(Cards);
                        Computador.Append(Cards);   
                    }
                    break;

                case 2:
                    if(P1.engineSize>Cmp.engineSize){
                        cout << "Jogador ganhou a rodada!" << endl << endl;
                        Player1.Serve(Cards);
                        Player1.Append(Cards);
                        Computador.Serve(Cards);
                        Player1.Append(Cards);
                    }
                    if(P1.engineSize<Cmp.engineSize){
                        cout << "Computador ganhou a rodada!" << endl << endl;
                        Computador.Serve(Cards);
                        Computador.Append(Cards);
                        Player1.Serve(Cards);
                        Computador.Append(Cards);   
                    }
                    break;

                case 3:
                    if(P1.horsePower>Cmp.horsePower){
                        cout << "Jogador ganhou a rodada!" << endl << endl;
                        Player1.Serve(Cards);
                        Player1.Append(Cards);
                        Computador.Serve(Cards);
                        Player1.Append(Cards);
                    }
                    if(P1.horsePower<Cmp.horsePower){
                        cout << "Computador ganhou a rodada!" << endl << endl;
                        Computador.Serve(Cards);
                        Computador.Append(Cards);
                        Player1.Serve(Cards);
                        Computador.Append(Cards);   
                    }
                    break;

                case 4:
                    if(P1.price>Cmp.price){
                        cout << "Jogador ganhou a rodada!" << endl << endl;
                        Player1.Serve(Cards);
                        Player1.Append(Cards);
                        Computador.Serve(Cards);
                        Player1.Append(Cards);
                    }
                    if(P1.price<Cmp.price){
                        cout << "Computador ganhou a rodada!" << endl << endl;
                        Computador.Serve(Cards);
                        Computador.Append(Cards);
                        Player1.Serve(Cards);
                        Computador.Append(Cards);   
                    }
                    break;

                default:
                    break;
            }

            cout << "Quantidade de cartas do Jogador: " << Player1.Size() << endl << endl;
            
        }

        if(Player1.Empty()){
            cout  << endl << "VITÓRIA: Computador ganhou o jogo!!" << endl << endl;
            aux_jogo=1;
        }
        if(Computador.Empty()){
            cout << endl << "VITÓRIA: Jogador ganhou o jogo!!" << endl << endl;
            aux_jogo=1;
        }

    }
}

int main(){

    ifstream inCards("cards.csv", ios::in);
    //abertura do arquivo para guardas as cartas na memória

    Fila f;
    Dados cartas;
    string aux_string;  //

    int aux_int = 0;    //variáveis auxiliares 
    char aux_char[50];  //
    int sair = 1;
    
    while(getline(inCards, aux_string)){
        //utilização do while para pegar todas as informações do arquivo "cards.csv"
        if(aux_int==0){
        
        }
        if(aux_int>0){
            int k=0, i=0;
        for(i=0; aux_string[i]!=','; i++){
            cartas.model[i] = aux_string[i];
            k++;
        }
        k++;
        cartas.model[i] = '\0';

        for(i=0; aux_string[k]!=','; i++){
            aux_char[i] = aux_string[k];
            k++;
        }
        k++;
        aux_char[i] = '\0';
        cartas.curbWeight = strtol(aux_char, NULL, 10);

        for(i=0; aux_string[k]!=','; i++){
            aux_char[i] = aux_string[k];
            k++;
        }
        k++;
        aux_char[i] = '\0';
        cartas.engineSize = strtol(aux_char, NULL, 10);

        for(i=0; aux_string[k]!=','; i++){
            aux_char[i] = aux_string[k];
            k++;
        }
        k++;
        aux_char[i] = '\0';
        cartas.horsePower = strtol(aux_char, NULL, 10);

        for(i=0; aux_string[k]!=','; i++){
            aux_char[i] = aux_string[k];
            k++;
        }
        k++;
        aux_char[i] = '\0';
        cartas.price = strtol(aux_char, NULL, 10);

        for(i=0; aux_string[k]!='\0'; i++){
            cartas.group[i] = aux_string[k];
            k++; 
        }
        cartas.group[i] = '\0';
        f.Append(cartas);
        //guardando as infromações das cartas em uma fila
        
        }
        
        aux_int++;

    }
    
    inCards.close();

    SuperTrunfo(f);

}