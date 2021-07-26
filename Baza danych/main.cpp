#include <iostream>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <conio.h>
#include <cstring>
#include <stdlib.h>

using namespace std;

fstream plik;
int liczba_elementow=3;
int i=0;
string a;
string b;
string c;
string d;
string e;

void menu();
struct _data{
int dzien;          // DATA URODZIN OSOBY
int miesiac;
int rok;
};

struct _id{
int id;                 // UNIKALNE ID
};

struct _menu{
    char element[32];       // STRUKTURA MENU
}_Menu[10];

struct _osoba{              // TABLICA OSOBY
_id numer;
string nazwisko;
string imie;
_data data;
char pesel[11];
char plec;
};
int i1;
_osoba baza[1000];

void wpisywanie_danych(){
    system("CLS");
    plik.open("baza_danych.txt",ios::in);
    if(plik.good()){
        while(!plik.eof()){
            plik>>baza[i].numer.id; i1=baza[i].numer.id;
            plik>>a;
            plik>>b;
            plik>>c;
            plik>>d;
            plik>>e;

        }
    }
    plik.close();
    i1++;
    baza[i].numer.id=i1;
    cout << baza[i].numer.id << endl;
    cout << "Podaj: " << endl;
    cout<<"Imie... "; cin>>baza[i].imie;
    cout<<"Nazwisko... "; cin>>baza[i].nazwisko;
    cout<<"Rok urodzenia... "; cin>>baza[i].data.rok;
    cout<<"Miesiac urodzenia... "; cin>>baza[i].data.miesiac;
    cout<<"Dzien urodzenia... "; cin>>baza[i].data.dzien;
    cout<<"PESEL... "; cin>>baza[i].pesel;
    cout<<"Meszczyzna/Kobieta... "; cin>>baza[i].plec;

    plik.open("baza.txt",ios::app);
    plik<<baza[i].numer.id<< " "
    <<baza[i].imie<< " "
    <<baza[i].nazwisko<< " "
    <<baza[i].data.rok<< " "
    <<baza[i].data.miesiac<< " "
    <<baza[i].data.dzien<< " "
    <<baza[i].pesel<< " "
    <<baza[i].plec<<endl;
    i++;
    menu();
}

void wyswietl_dane(){

    if(plik.good()) plik.close();

    int id;
    char imie[16], nazwisko[32];
    int rok, miesiac, dzien;
    int pesel;
    char plec;

    plik.open("baza_danych.txt",ios::app);
    if(plik.good()){
        while(!plik.eof()){
            plik>>id;
            plik>>imie;
            plik>>nazwisko;
            plik>>rok;
            plik>>miesiac;
            plik>>dzien;
            plik>>pesel;
            plik>>plec;

            cout<<id;
            cout<<" ";
            cout<<imie<<" "<<nazwisko;
            cout<<" ";
            if(dzien<10)
                cout<<"0";
            cout<<dzien<<" ";
            if(miesiac<10)
                cout<<"0";
            cout<<miesiac<<" ";
            cout<<rok;
            cout<<" ";
            cout<<pesel<<" ";
            cout<<plec;
        }

    }
    plik.close();
}
void drukuj_menu(_menu t[], int poz, int licz_el){
    system("CLS");
    for(int i=0; i<licz_el; i++){
        if(i==poz) cout<<"*";
        else cout<<" ";
        cout<<t[i].element<<endl;
    }

}

void menu(){
    system("CLS");
    char klik;
    int poz=0;
    strcpy(_Menu[0].element,"Wprowadz nowe dane do bazy");
    strcpy(_Menu[1].element,"Wyswietl dane z bazy");
    strcpy(_Menu[2].element,"Koniec");

    drukuj_menu(_Menu, poz, liczba_elementow);

    do{
        klik=getch();
        switch(klik){
            case 72: poz--;
                     break;
            case 80: poz++;
                    break;
            }
            if(poz<0) poz+=liczba_elementow;
            else poz%=liczba_elementow;
            drukuj_menu(_Menu, poz, liczba_elementow);
        if(klik==13){

            switch(poz){
                case 0:  wpisywanie_danych();;
                case 1: // wyswietl_dane(); getch();
                    cout << "Funkcja tymczasowo niedostepna";
                    getch();
                    menu();                 ;
                case 2: exit(0);

            }
        }
    }while (klik!=27);

}


int main(){
    menu();
    return 0;
}
