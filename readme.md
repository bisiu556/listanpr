# Jednokierunkowa Lista Wiązana w C++

Projekt realizuje własną implementację jednokierunkowej listy wiązanej (dynamicznej struktury danych) w języku C++ bez użycia zewnętrznych bibliotek kontenerowych (np. `<list>`, `<vector>`). Kod odpowiada wymaganiom egzaminacyjnym kwalifikacji **INF.04** oraz podstawowym zagadnieniom z zakresu dynamicznego zarządzania pamięcią.

---

## 🚀 Funkcjonalności

* **Brak użycia bibliotek STLs:** Własna struktura węzła (`struct lista`).
* **Wczytywanie z pliku:** Odczyt danych liczbowych z pliku `lista.txt` i automatyczne budowanie listy z zachowaniem właściwej kolejności.
* **Przechodzenie po liście:** Iterowanie po węzłach za pomocą wskaźnika pomocniczego `a = a->next`.
* **Zarządzanie pamięcią:** Bezpieczne zwalnianie dynamicznie alokowanej pamięci (`delete`) po zakończeniu pracy z listą.

---

## 🛠️ Struktura Danych

Każdy element listy reprezentowany jest przez strukturę `lista` (tzw. "wagon"):

```cpp
struct lista
{
    int id;               // Pole przechowujące wartość liczbową
    struct lista *next;   // Wskaźnik na kolejny element listy (lub NULL)
};
```

---

## 📁 Wymagany plik danych

Przed uruchomieniem programu upewnij się, że w tym samym katalogu znajduje się plik **`lista.txt`** zawierający liczby oddzielone spacjami lub nowymi liniami, np.:

```text
37 1 2
```

---

## ⚙️ Kompilacja i Uruchomienie

### Użycie g++ (Linux / Windows MinGW)

1. **Skompiluj program:**
   ```bash
   g++ -o main main.cpp
   ```

2. **Uruchom program:**
   * **Linux / macOS:**
     ```bash
     ./main
     ```
   * **Windows:**
     ```cmd
     main.exe
     ```

---

## 📋 Schemat działania funkcji

1. **`wczytajZPliku("lista.txt")`** – otwiera plik, alokuje pamięć (`new`) dla kolejnych węzłów i podczepia je na końcu listy.
2. **`wypisz(L)`** – przechodzi przez całą listę i wyświetla zawartość wszystkich węzłów.
3. **`zwolnijPamiec(L)`** – przechodzi po liście i uwalnia zarezerwowaną pamięć (`delete`), aby zapobiec wyciekom pamięci.

---

## ✒️ Licencja

Projekt udostępniany do celów edukacyjnych.