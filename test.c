//gioco craps implementato con funzione di bet

//librerie di funzioni che ci servono
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


//costanti di enumerazione per lo stato del gioco
enum Status{CONTINUE,WON,LOST}; //si
int rolldice(void); //prototipo funzione per tiro dei dadi
int bet(void); //prototipo di funzione per scommesse sul gioco
enum Status gameStatus; //gameStatus conterr� CONTINUE,WON O LOST
int balance=1000; //conto iniziale

int main(void) //funzione principale main
{
    //randomizzo il generatore di numeri casuali
    srand(time(NULL));

    int mypoint; //punteggio per vincere
    // enum Status gameStatus; //gameStatus conterr� CONTINUE,WON O LOST
    int fine=1; //valore sentinella per continuare a giocare

    while(fine != -1)
    { //iterazione per giocare piu' volte
       int temp= bet(); //OK!

        int sum=rolldice(); //primo lancio di dadi ok!

        switch(sum)
        {
            case 7:  //si vince con 7
            case 11:  //si vince con 11
                gameStatus=WON; //si vince al primo tiro
            break;
            case 2:  //si perde con 2
            case 3:  //si perde con 3
            case 12:  //si perde con 12
                gameStatus=LOST; //si perde al primo tiro
            break;
            default: //ricorda il punteggio
                gameStatus=CONTINUE;
                mypoint=sum; //ricorda il punteggio
            printf(" il punteggio e' %d \n",mypoint);
            break;
        }
        while(CONTINUE==gameStatus) //il gioco continua
            {
            sum=rolldice();//lancia di nuovo i dati
            if(sum==mypoint){
                gameStatus=WON; //si vince facendo il punteggio
            }else if (7==sum)
            {
                gameStatus=LOST;
            }
        }
        if(gameStatus==WON){  //il giocatore ha vinto?
                puts("HAI VINTO! \n");
               printf("Il tuo saldo e': %d \n",balance+temp);
               balance=balance+temp;
        }else{
                puts("HAI PERSO! \n");
                printf("Il tuo saldo e': %d \n",balance-temp);
                balance=balance-temp;
        }
        if(balance!=0)
        {
            puts("digita -1 per smettere di giocare, altrimenti digita un qualsiasi numero");
            scanf("%d",&fine);
        } else {
            puts("hai perso tutto, alla prossima!");
            fine=-1;
        }
    }//fine del while per continuare a giocare <--sopra appena dentro il main
}//fine del main


//funzione rolldice che lancia i dadi, calcola la somma e stampa i risultati
int rolldice(void){
    int dice1=1+(rand())%6; //valore primo dado
    int dice2=1+(rand())%6; //valore secondo dado
    //stampa i risultati di questo lancio
    printf("Il risultato dei tuoi dadi e': %d + %d = %d \n",dice1,dice2,dice1+dice2);
    return dice1+dice2; //restituisci la somma dei dadi
}
//qui c'è un problema di sequenza di azioni
//cioè tu prima chiami la funzione di bet dove appunto vedi se hai vinto o perso e POI lanci i dadi?
//guarda nel main


//funzione per le scommesse
int bet(void){
    int scom;
    puts("fai la  tua scommessa");
    scanf("%d",&scom);
    while(scom>balance){
        puts("hai scommesso troppo, riprova");
        scanf("%d",&scom);
    }
    return scom;
}

