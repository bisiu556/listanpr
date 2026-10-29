#include <iostream>
#include <fstream>

using namespace std;

/*
 * Struktura reprezentująca pojedynczy węzeł (wagon) jednokierunkowej listy wiązanej.
 */
struct lista
{
    int id;               // Pole przechowujące dane liczbowe węzła
    struct lista *next;   // Wskaźnik na kolejny element (wagon) listy
};

/*
 * Inicjalizuje nową, pustą listę.
 * Zwraca wskaźnik na początek listy (NULL).
 */
struct lista* utworz()
{
    return NULL;
}

/*
 * Wczytuje dane z pliku tekstowego i buduje z nich listę, zachowując oryginalną kolejność.
 * Przyjmuje nazwę pliku, zwraca wskaźnik na głowę nowo utworzonej listy.
 */
struct lista* wczytajZPliku(const string &nazwaPliku)
{
    ifstream plik(nazwaPliku);
    struct lista *L = utworz();

    if (plik.is_open())
    {
        int wczytaneId;
        while (plik >> wczytaneId)
        {
            struct lista *nowy = new struct lista;
            nowy->id = wczytaneId;
            nowy->next = NULL;

            // Jeśli lista jest pusta, nowy element staje się głową
            if (L == NULL)
            {
                L = nowy;
            }
            else
            {
                // Wyszukiwanie końca listy za pomocą wskaźnika pomocniczego
                struct lista *temp = L;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                // Podczepienie nowego elementu na końcu listy
                temp->next = nowy;
            }
        }
        plik.close();
        cout << "Wczytano dane z pliku " << nazwaPliku << "." << endl;
    }
    else
    {
        cout << "Blad otwarcia pliku do odczytu (upewnij sie, ze lista.txt istnieje)!" << endl;
    }
    return L;
}

/*
 * Wypisuje zawartość całej listy na ekranie, używając wskaźnika pomocniczego.
 */
void wypisz(struct lista *L)
{
    struct lista *a = L; // Wskaźnik pomocniczy do przechodzenia przez listę
    cout << "Zawartosc listy: ";
    while (a != NULL)
    {
        cout << a->id << " ";
        a = a->next; // Przejście do następnego elementu
    }
    cout << endl;
}

/*
 * Zwalnia dynamicznie przydzieloną pamięć dla wszystkich węzłów listy.
 */
void zwolnijPamiec(struct lista *&L)
{
    while (L != NULL)
    {
        struct lista *temp = L;
        L = L->next;
        delete temp; // Usunięcie węzła z pamięci operacyjnej
    }
    cout << "Zwolniono pamiec." << endl;
}

/*
 * Główna funkcja programu sterująca przebiegiem wykonania.
 */
int main()
{
    // Wczytanie listy bezpośrednio z pliku "lista.txt"
    struct lista *L = wczytajZPliku("lista.txt");

    // Wypisanie wczytanej listy na konsoli
    wypisz(L);

    // Zwolnienie zajmowanej pamięci przed zakończeniem działania programu
    zwolnijPamiec(L);

    return 0;
}
