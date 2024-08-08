# John 1.0 - Prosty konsolowy system operacyjny na Arduino Mega

Witaj w **John 1.0**, prostym, ale funkcjonalnym systemie operacyjnym dla **Arduino Mega**, który pozwala na uruchamianie aplikacji napisanych w **Lua**! Ten projekt to idealny punkt wyjścia do nauki programowania mikrokontrolerów i tworzenia własnych interaktywnych urządzeń.

## :gear: Funkcjonalność:

* **Ekran powitalny:** Po uruchomieniu systemu wyświetla się ekran powitalny "Welcome to John 1.0" przez 8 sekund.
* **Menu główne:** Po ekranie powitalnym system wyświetla listę zainstalowanych aplikacji (maksymalnie 9) wraz z ich numerami.
* **Uruchamianie aplikacji:** Wystarczy wcisnąć odpowiednią cyfrę na klawiaturze, aby uruchomić wybraną aplikację.
* **Interfejs konsolowy:** Wyświetlaj tekst i odczytuj dane wejściowe za pomocą ekranu LCD i klawiatury.
* **Obsługa podstawowych działań matematycznych:** Użyj klawiszy A, B, C, D do wprowadzania znaków +, ×, ÷, =.
* **Funkcja przewijania:** Przewijaj treść ekranu za pomocą przycisku `*`:
    * :point_down: Pojedyncze kliknięcie: Przewiń w dół o 2 linie.
    * :arrow_up: Przytrzymanie: Przewiń w górę o 1 linię na sekundę.
* **Włączanie/wyłączanie:** 
    * :arrow_right: Przytrzymaj przycisk `#` przez 5 sekund, aby włączyć lub wyłączyć urządzenie.  
    * :arrow_left: Przytrzymanie `#` podczas wyłączonego urządzenia go włączy.

## :electric_plug: Wymagany sprzęt:

* Arduino Mega 2560
* Wyświetlacz LCD alfanumeryczny (16x2 lub 20x4)
* Klawiatura membranowa 4x4 
* Karta SD 
* Moduł ładowania baterii Li-Ion TP4056 (opcjonalnie)
* Bateria Li-Ion 3.7V (opcjonalnie)
* Przetwornica napięcia (opcjonalnie, jeśli ekran LCD lub klawiatura wymagają innego napięcia)
* Rezystory, kondensatory, przewody połączeniowe (zgodnie ze schematem połączeń)

## :computer: Instalacja i konfiguracja:

1. **Zainstaluj Arduino IDE:** Pobierz i zainstaluj Arduino IDE z [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software).
2. **Zainstaluj biblioteki:** Zainstaluj biblioteki **Lua**, **SD**, **LiquidCrystal**, **Keypad** i **LowPower** w Arduino IDE. Możesz to zrobić za pomocą Menedżera Bibliotek w IDE (Sketch -> Include Library -> Manage Libraries...).
3. **Podłącz sprzęt:** Połącz Arduino Mega, ekran LCD, klawiaturę i czytnik kart SD zgodnie z dostarczonym schematem połączeń.
4. **Skonfiguruj piny:** W pliku `logic_main.cpp` dostosuj piny klawiatury (`rowPins` i `colPins`) do swojego połączenia oraz piny dla LCD, jeśli używasz innych niż domyślne.
5. **Wgraj kod:** Skopiuj kod z plików `main.cpp`, `logic_lua.cpp`, `logic_lua.h`, `logic_main.cpp` i `logic_main.h` do Arduino IDE i wgraj go na Arduino Mega.

## :pencil2: Tworzenie aplikacji w Lua:

1. **Stwórz nowy plik z rozszerzeniem `.lua`.** 
2. **Napisz kod Lua w pliku.** Możesz korzystać z funkcji standardowej biblioteki Lua oraz funkcji udostępnionych przez John 1.0.
3. **Zapisz plik w folderze `/app` na karcie SD.** Nazwa pliku musi być w formacie `appX.lua`, gdzie `X` to cyfra od 1 do 9, odpowiadająca numerowi aplikacji w menu.
4. **Uruchom aplikację:** Po włączeniu telefoniku, naciśnij odpowiednią cyfrę na klawiaturze, aby uruchomić aplikację.

**Przykładowy skrypt Lua (app1.lua):**

```lua
print("Witaj w aplikacji Hello!")
-- Dodaj tutaj swój kod Lua
Pamiętaj, że możesz dostosować ten README.md do swoich potrzeb, dodając więcej informacji o swoim projekcie, takie jak:

* **Schemat połączeń:**  Dodaj schemat pokazujący, jak podłączyć wszystkie komponenty.
* **Opis funkcji:** Dokładniej opisz funkcje systemu operacyjnego i dostępne komendy.
* **Przykłady skryptów Lua:** Dodaj więcej przykładowych skryptów Lua, aby pokazać możliwości systemu.
* **Informacje o autorze:**  Dodaj swoje imię i nazwisko lub pseudonim jako autora projektu.
* **Licencja:** Określ licencję na korzystanie z Twojego kodu.
