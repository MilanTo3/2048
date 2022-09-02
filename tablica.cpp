#include <iostream>
#include "tablica.h"
#include "time.h"
#include "stdlib.h"

using namespace std;

tablica::tablica(){

    int i;
    int j;
    srand(time(0));
    undokaunter = 0;
    potezi = 0;

    for(i = 0; i<TSIZE; i++){
        for(j = 0; j<TSIZE; j++){
            tabla[i][j] = 0;
        }
    }

    int random1;
    int random2;

    do{

    random1 = (rand()%15)/4;
    random2 = (rand()%15)/4;
    }while(random1 == random2);

    tabla[random1][random2] = 2;
    tabla[random2][random1] = 4;

}

void tablica::ispisitablu(){

    int i;
    int j;

    cout<<endl;
    cout<<endl;
    cout<<"   Table:\tBroj Poteza: "<<potezi<<"\tNajveci blok: "<<getnajveciblok()<<endl;
    if(getnajveciblok() == 2048){
        cout<<"Congratulations you've won the game, but keep on going."<<endl;
    }
    cout<<endl;
    cout<<endl;

    for(i = 0; i<TSIZE; i++){
        for(j = 0; j<TSIZE; j++){
            if(tabla[i][j] != 0){
                cout<<"|\t"<<tabla[i][j]<<"\t|";
            }else{
                cout<<"|\t_\t|";
            }
        }
        cout<<"\n\n"<<endl;
    }
    potezi++;

    cout<<endl;

}

bool tablica::emptyblock(int i, int j){

    if(i >= 0 && i <= TSIZE && j >= 0 && j <= TSIZE){
        if(tabla[i][j] == 0){
            return true;
        }
    }
    //cout<<"Empty metoda radi."<<endl;
    return false;
}

void tablica::swipe(direction d){

    int i = 0;
    int j;
    int kaunter = 0;
    int privremeni;

    switch(d){
        case rightd:
            for(i = 0; i < TSIZE; i++){
                for(j = TSIZE-2; j>=0; j--){ // Tsize - 2 zbog toga sto ivicni element ne moze da se pomeri.
                    if(emptyblock(i, j) == false){
                        privremeni = tabla[i][j];
                        kaunter = j+1;

                        while(emptyblock(i, kaunter) == true  && kaunter < TSIZE-1){ // Do TSIZE-1 moze se uvecavati kaunter, kako je to vrednost 3, a se uvecava svakim ulaskom u petlju.
                            kaunter++;
                        }

                        if(privremeni == tabla[i][kaunter]){
                            tabla[i][kaunter] = privremeni+tabla[i][kaunter];
                            tabla[i][j] = 0;
                            continue;
                        }

                        if(emptyblock(i, kaunter) == false){
                            kaunter--;
                            //cout<<"Odradio korekciju."<<endl;
                        }

                        tabla[i][kaunter] = privremeni;
                        if(kaunter != j){ //VAZNO
                            tabla[i][j] = 0;
                        }
                    }
                }
            }
            break;
        case leftd:
            for(i = 0; i < TSIZE; i++){
                for(j = 1; j< TSIZE; j++){
                    if(emptyblock(i, j) == false){
                        privremeni = tabla[i][j];
                        kaunter = j-1;

                        while(emptyblock(i, kaunter) == true  && kaunter > 0){ // Do TSIZE-1 moze se uvecavati kaunter, kako je to vrednost 3, a se uvecava svakim ulaskom u petlju.
                            kaunter--;
                        }

                        if(privremeni == tabla[i][kaunter]){
                            tabla[i][kaunter] = privremeni+tabla[i][kaunter];
                            tabla[i][j] = 0;
                            continue;
                        }

                        if(emptyblock(i, kaunter) == false){
                            kaunter++;
                            //cout<<"Odradio korekciju."<<endl;
                        }

                        tabla[i][kaunter] = privremeni;
                        if(kaunter != j){
                            tabla[i][j] = 0;
                        }
                    }
                }
            }
            break;
        case upd: // Ovaj pogledati
            for(i = 1; i < TSIZE; i++){
                for(j = 0; j< TSIZE; j++){
                    if(emptyblock(i, j) == false){
                        privremeni = tabla[i][j];
                        kaunter = i-1;

                        while(emptyblock(kaunter, j) == true  && kaunter > 0 && kaunter < TSIZE-1){ // Do TSIZE-1 moze se uvecavati kaunter, kako je to vrednost 3, a se uvecava svakim ulaskom u petlju.
                            kaunter--;
                        }

                        if(privremeni == tabla[kaunter][j]){
                            tabla[kaunter][j] = privremeni+tabla[kaunter][j];
                            tabla[i][j] = 0;
                            continue;
                        }

                        if(emptyblock(kaunter, j) == false){
                            kaunter++;
                            //cout<<"Odradio korekciju."<<endl;
                        }

                        tabla[kaunter][j] = privremeni;
                        if(kaunter != i){
                            tabla[i][j] = 0;
                            }
                    }
                }
            }
            break;
        case downd:
            for(i = TSIZE-2; i >= 0; i--){
                for(j = 0; j < TSIZE; j++){
                    if(emptyblock(i, j) == false){
                        privremeni = tabla[i][j];
                        kaunter = i+1;

                        while(emptyblock(kaunter, j) == true  && kaunter < TSIZE-1 && kaunter>0){ // Do TSIZE-1 moze se uvecavati kaunter, kako je to vrednost 3, a se uvecava svakim ulaskom u petlju.
                            kaunter++;
                        }

                        if(privremeni == tabla[kaunter][j]){
                            tabla[kaunter][j] = privremeni + tabla[kaunter][j];
                            tabla[i][j] = 0;
                            continue;
                        }

                        if(emptyblock(kaunter, j) == false){
                            kaunter--;
                            //cout<<"Odradio korekciju."<<endl;
                        }

                        tabla[kaunter][j] = privremeni;
                        if(kaunter != i){
                            tabla[i][j] = 0;
                            }
                    }
                }
            }
    }

}

bool tablica::genfreepos(){

    int i;
    int j;
    int priv;
    int rez[15];
    int kaunter = 0;
    int ind;

    for(i = 0; i<TSIZE; i++){
        for(j = 0; j<TSIZE; j++){
            if(emptyblock(i, j) == true){
                priv = i*10+j;
                rez[kaunter] = priv;
                kaunter++;
            }
        }
    }

    if(kaunter < 1 && checkmoves() == true){
        return true;
    }else{
        if(kaunter < 1 && checkmoves() == false){
            return false;
        }
    }

    //cout<<"Izbrojano je "<<kaunter<<"slobodnih mesta."<<endl;
    //kaunter je veci za jedan nego sto bi trebalo.
    ind = rand()%kaunter;
    priv = rez[ind];

    i = 0;
    int sac = priv;
    while(priv >= 10){
        priv = priv/10;
        i++;
    }

    j = sac%10;

    //cout<<"Indeksi slobodne pozicije su "<<i<<" i "<<j<<endl;

    int randomitet = rand()%2;
    if(kaunter > 0){
        if(randomitet == 0){
            tabla[i][j] = 4;

        }else{
            tabla[i][j] = 2;
        }
    }
    //cout<<"Kaunter je "<<kaunter<<endl;
    //cout<<"Vratio false za genfreepos."<<endl;

    return false;
}

bool tablica::checkmoves(){

    int i;
    int j;

    //Proveriti redove i kolone iterativno.
    //cout<<"Usao u check moves proveru."<<endl;
    for(i = 0; i<TSIZE; i++){
        for(j = 0; j<TSIZE; j++){
            if(j+1 < TSIZE){
                if(tabla[i][j] == tabla[i][j+1]){
                    //cout<<"Vratio false"<<endl;
                    return false;
                }
            }
            if(i+1 < TSIZE){
                if(tabla[i][j] == tabla[i+1][j]){
                    //cout<<"Vratio false"<<endl;
                    return false;
                }
            }
            if(j-1 >= 0){
                if(tabla[i][j] == tabla[i][j-1]){
                    //cout<<"Vratio false"<<endl;
                    return false;
                }
            }
            if(i-1 >= 0){
                if(tabla[i][j] == tabla[i-1][j]){
                    //cout<<"Vratio false"<<endl;
                    return false;
                }
            }
        }
    }

    //cout<<"Vratio true"<<endl;
    ispisitablu();
    return true;
}

void tablica::undo(int a){

    //Prov prekopirati matricu prethodnog poteza.
    //Ako se posalje nula samo cemo prekopiratiu rezervnu matricu.

    int i;
    int j;

    if(a == 0){
        //cout<<"Usao u kopirajucu petlju."<<endl;
        for(i = 0; i<TSIZE; i++){
            for(j = 0; j<TSIZE; j++){
                rezervnatabla[i][j] = tabla[i][j];
            }
        }
    }

    //ako je prosledjena jedinica tada uradi undo kopirajuci tablu od poslog poteza.
    if(a == 1){
        //cout<<"Usao u petlju za undo."<<endl;
        for(i = 0; i<TSIZE; i++){
            for(j = 0; j<TSIZE; j++){
                tabla[i][j] = rezervnatabla[i][j];
            }
        }
        undokaunter++;
    }

}

int tablica::getpotezi() const{

    return potezi;
}

int tablica::getnajveciblok() const{

    int i, h;

    int maks = tabla[0][0];

    for(i = 0; i<TSIZE; i++){
        for(h = 0; h<TSIZE; h++){
            if(maks < tabla[i][h]){
                maks = tabla[i][h];
            }
        }
    }

    return maks;
}

void tablica::setundopotez(int a){

    potezi = a;

}

int tablica::getundokaunter() const{

    return undokaunter;
}
