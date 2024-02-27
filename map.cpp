#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <tuple> // Map'y 3 wartościowe

using namespace std;

int main() {
    
    int paircount;
    string klucz, wartosc;
    
    
    

	map<string, int>przyklad; // DEKLARACJA FUNKCJI 

    /* 
        map - Wywoływanie funkcji deklaracji mapy
        
      <typ1, typ2> - nadanie typu w jakim będzie klucz a jak wartość, może być np. Integer, String itp.
        
      a) typ1 - Klucz
      b) typ2 - Wartość
        
      przyklad - nazwa mapa 
      
    */

    przyklad["Mama"] = 111222333; //    Przykładowe deklaracje wartości string-int
    przyklad["Tata"] = 666999000; //    Przykładowe deklaracje wartości string-int
    przyklad["Pies"] = 888999000; //    Przykładowe deklaracje wartości string-int
    przyklad["Mama"] = 333222111; //    Przykładowe deklaracje wartości string-int
    
    cout << "Numery Telefonu (zwykła mapa):" << endl;
    for (const auto& pair : przyklad) {
        cout << pair.first << " -> " << pair.second << endl;
    }
    
    /* 
        Przy integer'ach jeżeli chcesz mieć więcej niż 1 wartość musisz użyć mapy wielowartościowej
        inaczej znanego jako Multimap inaczej pierwsza wartość zostanie nadpisana przez drugą.
    */
    
    /*
        By wywołać cały map w konsoli musimy wywoływać pary pokolei. Związku z tym
        zapisujemy to w pętle:
        
        const - deklaracja
        
        auto& pair : przyklad - wywoływanie pary, po dwukropku nazwa map'a
        pair.first - pierwsza para
        pair.second - ostania para
    */
    
    multimap<string, pair<int, int>>przyklad_a;
    
    przyklad_a.insert(make_pair("Mama", make_pair(111222333,333222111))); //    Przykładowe deklaracje wartości string-int+int
    przyklad_a.insert(make_pair("Tata", make_pair(666999000,0))); //    Przykładowe deklaracje wartości string-int+int
    
    cout << "Numery Telefonu (multimap):" << endl;
    for (const auto& pair : przyklad_a) {
        cout << pair.first << ": " << pair.second.first << ", " << pair.second.second << endl;
    }
    
    /*
        multimap różni się tym że:
        
        - przy deklaracji, gdy chcemy dopisać wartość musimy powtórczyć to co zrobiliśmy 
        przy deklaracji samej mapy lecz zamiast nazwa mapy dopisujemy pair, czyli para
        wartości
        
        a) przyklad_a.insert - włożenie do mapa przyklad_a pary
        b) make_pair - stworzenie pary
        c) zamiast < ... > używamy (...) 
        
        - przy wyprowadzaniu "pary" musimy zawrzeć że wypluwamy też 2 int'a:
        
        a) pair.second.first - wyprowadzenie 1 wartości
        b) pair.second.second - wyprowadzenie 2 wartości
        
    */
    
    map<string, string>przyklad2;
    
    przyklad2["Samsung"] = "Galaxy A51"; //    Przykładowe deklaracje wartości string-string
    przyklad2["Nokia"] = "Nokia 3310"; //    Przykładowe deklaracje wartości string-string
    przyklad2["Apple"] = "Iphone 12 PRO MAX"; //    Przykładowe deklaracje wartości string-string
    przyklad2["Apple"] = "Iphone 13 PRO MAX"; //    Przykładowe deklaracje wartości string-string
    przyklad2["Motorola"] = "Motorola 30 Edge, Motorola 40 Edge Neo"; //    Przykładowe deklaracje wartości string-string
    
    cout << "Marki Telefonów:" << endl;
    for (const auto& pair : przyklad2) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    /* 
        Przy string'ach pierwsza wartość zostanie nadpisana przez następną. 
        W tym przypadku Iphone 12 PRO MAX zostanie nadpisany przez Iphone 13 PRO MAX. 
        Jeżeli chcesz więcej niż jedna wartość bez użycia mapy wielowartościowej musisz zapisać 
        je po przecinku.
    */
    
    

    map<string, tuple<string, string, string>>przyklad2_a;
    
    przyklad2_a["Xiaomi"] = make_tuple("Redmi Note 12","Redmi Note 13 Pro", "Redmi Note 13C");
    
        cout << "Marki Telefonów (Tuple):" << endl;
    for (const auto& pair : przyklad2_a) {
        cout << pair.first << ": " << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second) << endl;
    }
    
    /*
        Podobnie jak przy 2 wartościowych musimy zadeklarować trio czyli tuple. By to wogóle użyć
        Potrzebujemy biblioteki tuple. Inna wyraźna różnica jest przy wywoływaniu bo wywołujemy to
        jak tablice.
    */
    
    unordered_map<string, string>przyklad3;
    
    cout << endl << "Ile chcesz par?: ";
    cin >> paircount;
    
    for (int i = 0; i < paircount; i++) {
        cout << "Jaki Klucz?: ";
        cin >> klucz;
        cout <<"Jaka Wartość?: ";
        cin >> wartosc;
        
        przyklad3[klucz] = wartosc;
    }
    cout <<"Przykładowa Tablica: " << endl;
    for (const auto& pair : przyklad3) {
        cout << pair.first << ": " << pair.second << endl;
    }
    /*
        By stworzyć pare na bazie inputu użytkownika musimy stworzyć zmienną odpowiadającą za 
        klucz i wartość, w miejsce normalnego klucz i wartości wypisujemy zmienną.
    */
    
    map<int, int>przyklad4;
    
    przyklad4[1] = 37;
    przyklad4[2] = 137;
    
    auto it = przyklad4.find(2);
    
    if (it != przyklad4.end()) {
        cout << "Wartość dla klucza "<< it->first << " to: " << it->second << endl;
    } else {
        cout << "Klucz nie został znaleziony." << endl;
    }
    
    /*
        Iterator szuka klucza (w tym przypadku 2), jeżeli znajdzie to wypluje wartość ukrytą pod 2,
        jeżeli nie znajdzie to powiadomi o tym użytkownika. By znaleść ten klucz używamy funkcję 
        find. Używamy ją:
        
        auto - przypis pętli 
        it - zmienna, skrót od Iterator
        przyklad4 - mapa 
        .find - funkcja szukająca
        (2) - nawias a w środku jego klucz jaki szukamy
    */
}
