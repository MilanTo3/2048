#include <iostream>
#include "tablica.h"

using namespace std;

int meni(){

    int ch;
    cout<<"\t\t1. Swipe left."<<endl;
    cout<<"\t\t2. Swipe right."<<endl;
    cout<<"\t\t3. Swipe up."<<endl;
    cout<<"\t\t4. Swipe down."<<endl;
    cout<<"\t\t5. Undo."<<endl;
    cout<<"\t\t6. Exit to main menu."<<endl;
    cout<<"\t\tChoose an option: ";
    cin>>ch;

    return ch;
}

int main()
{
    int ulaz;
    do{
    cout<<endl;
    cout<<"\t .d8888b.   .d8888b.      d8888   .d8888b. "<<endl;
    cout<<"\td88P  Y88b d88P  Y88b    d8P888  d88P  Y88b"<<endl;
    cout<<"\t       888 888    888   d8P 888  Y88b. d88P "<<endl;
    cout<<"\t     .d88P 888    888  d8P  888   'Y88888'  "<<endl;
    cout<<"\t .od888P'  888    888 d88   888  .d8P""Y8b. "<<endl;
    cout<<"\td88P'      888    888 8888888888 888    888 "<<endl;
    cout<<"\t888'       Y88b  d88P       888  Y88b  d88P "<<endl;
    cout<<"\t888888888   'Y8888P'        888   'Y8888P'  "<<endl;
    cout<<endl;
    cout<<endl;
    int opcija;
    cout<<"\t1. Play the game."<<endl;
    cout<<"\t2. Read the instructions."<<endl;
    cout<<"\t3. Exit from the program."<<endl;
    cout<<"\tChoose an option: ";
    cin>>ulaz;
    switch(ulaz){
        case 1:
            {
            tablica t1;
            t1.ispisitablu();
            do{
                opcija = meni();
                //Obavezno postaviti kopiranje poteza za undo.
                switch(opcija){
                    case 1:
                        t1.undo(0); // Dakle, pre svakog poteza kopirati sadasnje stanje table.
                        t1.swipe(leftd);
                        if(t1.genfreepos() == true){
                            opcija = 6;
                            cout<<endl;
                            cout<<"\tGame over, gg mate."<<endl;
                            break;
                        }
                        t1.ispisitablu();
                        break;
                    case 2:
                        t1.undo(0);
                        t1.swipe(rightd);
                        if(t1.genfreepos() == true){
                            opcija = 6;
                            cout<<endl;
                            cout<<"\tGame over, gg mate."<<endl;
                            break;
                        }
                        t1.ispisitablu();
                        break;
                    case 3:
                        t1.undo(0);
                        t1.swipe(upd);
                        if(t1.genfreepos() == true){
                            opcija = 6;
                            cout<<endl;
                            cout<<"\tGame over, gg mate."<<endl;
                            break;
                        }
                        t1.ispisitablu();
                        break;
                    case 4:
                        t1.undo(0);
                        t1.swipe(downd);
                        if(t1.genfreepos() == true){
                            opcija = 6;
                            cout<<endl;
                            cout<<"\tGame over, gg mate."<<endl;
                            break;
                        }
                        t1.ispisitablu();
                        break;
                    case 5:
                        if(t1.getpotezi() >= 15 && t1.getundokaunter() < 5){
                            t1.undo(1);
                            t1.setundopotez(t1.getpotezi() - 1);
                            cout<<"Undo izvrsen."<<endl;
                            t1.ispisitablu();
                        }else{
                            cout<<endl;
                            cout<<"Mozete uraditi undo tek nakon 15 poteza, i samo 5 puta u celoj partiji."<<endl;
                            t1.setundopotez(t1.getpotezi() - 1);
                            t1.ispisitablu();
                        }
                        break;
                    case 6:
                        cout<<"Game over for you my boy."<<endl;
                }
            }while(opcija != 6);
            break;
            }
        case 2:
            cout<<endl;
            cout<<"So heres the deal. Basically you use the swiping to get to the number 2048. Thats like the goal of the game."<<endl;
            cout<<"Same sized blocks can be merged, and after every swipe a block of 2 or 4 is generated on a random place."<<endl;
            cout<<endl;
            cout<<"\t\t ========        ========        ======== "<<endl;
            cout<<"\t\t |      |        |      |        |      | "<<endl;
            cout<<"\t\t |      |        |      |        |      | "<<endl;
            cout<<"\t\t |   2  |   =>   |   2  |   ==   |   4  | "<<endl;
            cout<<"\t\t |      |        |      |        |      | "<<endl;
            cout<<"\t\t ========        ========        ======== "<<endl;
            cout<<endl;
            cout<<"You can undo moves thrice and only after 15 moves had already passed."<<endl;
            cout<<"Also you can use the undo option only 5 times."<<endl;
            cout<<"This program is Skynet VR project, and your brain is directly connected to our server."<<endl;
            cout<<"Have fun."<<endl;
            cout<<endl;
            cout<<"-Skynet VR"<<endl;
            cout<<endl;
            cout<<endl;
            break;
        case 3:
            return 0;
        default:
            return 0;
    }

    }while(ulaz != 3);

    return 0;
}
