#include <iostream>
#include <fstream>

using namespace std;

bool konwersjaPliku(string nazwaPlikuZrodlowego) {

    fstream plikZrodlowy, nowyPlik;
    int dlugoscNazwyPlikuZrodlowego = nazwaPlikuZrodlowego.length();
    string nazwaPlikuPoKonwersji = nazwaPlikuZrodlowego;
    nazwaPlikuPoKonwersji.insert(dlugoscNazwyPlikuZrodlowego - 4, "_nowy_format");

    plikZrodlowy.open(nazwaPlikuZrodlowego.c_str(), ios::in);
    nowyPlik.open(nazwaPlikuPoKonwersji.c_str(), ios::out);

    string linia;
    int numerLinii = 1;

    if(!plikZrodlowy.good() || !nowyPlik.good())
        return false;
    else {
        while(getline(plikZrodlowy, linia)) {
            nowyPlik << linia << "|";
            if(numerLinii == 6){
                nowyPlik << endl;
                numerLinii = 0;
            }
            numerLinii++;
        }
        plikZrodlowy.close();
        nowyPlik.close();
        return true;
    }
}

int main() {
    string nazwaPlikuZrodlowego;
    cout << "Prosze o podanie nazwy pliku do przekonwertowania: ";
    cin >> nazwaPlikuZrodlowego;

    if(konwersjaPliku(nazwaPlikuZrodlowego))
        cout << "Plik zostal przekonwertowany";
    else cout << "Operacja nieudana";

    return 0;
}
