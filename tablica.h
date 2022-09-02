#ifndef TABLICA_H_INCLUDED
#define TABLICA_H_INCLUDED
#define TSIZE 4

using namespace std;

enum direction{leftd, rightd, upd, downd};

class tablica{

    private:
        int tabla[TSIZE][TSIZE];
        int rezervnatabla[TSIZE][TSIZE];
        int potezi;
        int undokaunter;

    public:
        tablica();
        void swipe(direction b);
        void undo(int a);
        bool checkmoves();
        bool emptyblock(int i, int j);
        void ispisitablu();
        bool genfreepos();
        void setundopotez(int a);
        int getpotezi() const;
        int getnajveciblok() const;
        int getundokaunter() const;

};

#endif // TABLICA_H_INCLUDED
