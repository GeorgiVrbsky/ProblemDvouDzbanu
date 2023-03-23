#include <iostream>

using namespace std;

void vypsaniDzbanu(int Dzban1, int Dzban2) { //Funkce na vypsani obsahu dzbanu
    cout << "Dzban1: " << Dzban1 << "  Dzban2: " << Dzban2 << endl;
}


int main() {

    int obsahDzban1 = 0; //aktualni objem dzbanu1
    int obsahDzban2 = 0; //aktualni objem dzbanu2

    int objemDzban1; //Uzivatelem zvoleny objem dzbanu1
    int objemDzban2; //Uzivatelem zvoleny objem dzbanu2

    vyberCisel:

    cout << "Zadejte cislo pro prvni dzban: ";
    cin >> objemDzban1;
    cout << "Zadejte ciso pro druhy dzban: ";
    cin >> objemDzban2;

    if (objemDzban1 % objemDzban2 != 0 && objemDzban2 % objemDzban1 != 0 && objemDzban1<objemDzban2) { //Podminka, ktera overuje, ze muzeme zacit s plnenym dzbanu

        do { //do while loop, ktery jede, dokud ve dzbanu1 neni jeden litr

            if (obsahDzban2 > objemDzban2) { //1)Pokud se v podmince 3 naplni dzban2 pres limit, zde se odecte z dzbanu 1, co je ve dzbanu2 navic a zaroven dzban2 bude naplneny na okraj
                obsahDzban1 = obsahDzban2 - objemDzban2;
                obsahDzban2 = objemDzban2;
                vypsaniDzbanu(obsahDzban1, obsahDzban2);

            }
            if (obsahDzban1 == 0 && obsahDzban1 != 1) { //2)Podminka, kterou plnime dzban1, pokud je prazdny
                obsahDzban1 = objemDzban1;
                vypsaniDzbanu(obsahDzban1, obsahDzban2);
            }
            if (obsahDzban1 == objemDzban1 && obsahDzban1 != 1) {//3)Pokud je dzban1 naplneny, tak se prelije do dzbanu2
                obsahDzban2 = obsahDzban1 + obsahDzban2;
                obsahDzban1 = obsahDzban2 - obsahDzban2;
                if (obsahDzban2 <= objemDzban2) { //4)Pokud je obsah dzbanu2 mensi nebo se rovna objemu dzbanu2, tak se zobrazi vypsani dzbanu. Timto zabranujeme, aby nam v konzoli nevypisovalo dzban2 pres limit, dokud se nedostane k 1)podmince
                    vypsaniDzbanu(obsahDzban1, obsahDzban2);
                }
            }
            if (obsahDzban2 == objemDzban2 && obsahDzban1 != 1) { //5)Podminka, kterou vylivame dzban2, pokud je plny
                obsahDzban2 = 0;
                vypsaniDzbanu(obsahDzban1, obsahDzban2);
            }
            if (obsahDzban2 == 0 && obsahDzban1 > 0 && obsahDzban1 != 1) { //6)Pokud je obsah dzban2 0 a zaroven obsah dzbanu1 vetsi, nez 0, tak se obsah dzbanu1 prelije do dzbanu2
                obsahDzban2 = obsahDzban2 + obsahDzban1;
                obsahDzban1 = 0;
                vypsaniDzbanu(obsahDzban1, obsahDzban2);
            }
        } while (obsahDzban1 != 1);
        obsahDzban2 = 0; //Pokud odejdeme z do while loopu, tak jenom vyprazdnime obsah dzbanu2, protoze jsme uz splnili podminku 1 litru v dzbanu1
        vypsaniDzbanu(obsahDzban1, obsahDzban2);
    }
    else //Pokud uzivatel zada
    {
        cout << "Zadali jste cisla se spatnymi parametry, prosim, opakujte";
        cin.ignore(2);
        system("cls");
        goto vyberCisel;
    }
}

