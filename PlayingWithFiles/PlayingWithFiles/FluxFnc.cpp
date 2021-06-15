//
//  FluxFnc.cpp
//  PlayingWithFiles
//
//  Created by Dijoux Jérémy on 15/06/2021.
//

#include "FluxFnc.hpp"
#include <iostream>
#include <fstream>
using namespace std;

string const chemin("/Users/agrume/Documents/learninCPP/PlayingWithFiles/test.txt");
ofstream monFlux(chemin.c_str(), ios::app);
ifstream maLecture(chemin.c_str());
string userName;
int age;
string JVFav;

void writeFile(){
    
    if(monFlux){
        cout << "Entrez votre nom \n";
        cin >> userName;
            if(userName == ""){
                cout << "Erreur lors de la saisie, veuillez entrer votre nom \n";
                cin >> userName;
            }
        cout << "Veuillez entrer votre âge \n";
        cin >> age;
            if(age<=0){
                cout << "Erreur lors de la saisie, veuillez entrer votre âge \n";
                cin >> age;
            }
        cout << "Veuillez entrer votre jeu video favori \n";
        cin >> JVFav;
            if(JVFav==""){
                cout << "Vous n'aimez pas les jeux videos ? Même pas un seul ? \n";
                cin >>JVFav;
            }
        monFlux << "Votre nom est : "<< userName << endl;
        monFlux << "Vous avez : " << age << " ans" <<endl;
        monFlux << "Votre jeu favori est : "<< JVFav << endl;
        
        
    } else {
        cout << "Erreur lors de l'ouverture du fichier \n" << endl;
    }
    
}

void readFile(){
    if(maLecture){
        
        string line;
        
        while(getline(maLecture,line)){
            cout << line << endl;
        }
        
    } else {
        cout << "Erreur lors de l'ouverture du fichier \n" << endl;
    }
}

void knowSize(){
    maLecture.seekg(0,ios::end);
    
    double size;
    size = maLecture.tellg();
    
    cout << "Votre fichier a une taille de : " << size << " octets";
}
