John 1.0 - Prosty konsolowy system operacyjny na Arduino Mega

Witaj w John 1.0, prostym, ale funkcjonalnym systemie operacyjnym dla Arduino Mega, który pozwala na uruchamianie aplikacji napisanych w Lua! Ten projekt to idealny punkt wyjścia do nauki programowania mikrokontrolerów i tworzenia własnych interaktywnych urządzeń.

Funkcjonalność:

Ekran powitalny: Po uruchomieniu systemu wyświetla się ekran powitalny "Welcome to John 1.0" przez 8 sekund.

Menu główne: Po ekranie powitalnym, system wyświetla listę zainstalowanych aplikacji (maksymalnie 9) wraz z ich numerami.

Uruchamianie aplikacji: Wystarczy wcisnąć odpowiednią cyfrę na klawiaturze, aby uruchomić wybraną aplikację.

Interfejs konsolowy: Wyświetlaj tekst i odczytuj dane wejściowe za pomocą ekranu LCD i klawiatury.

Obsługa podstawowych działań matematycznych: Użyj klawiszy A, B, C, D do wprowadzania znaków +, ×, ÷, =.

Funkcja przewijania: Przewijaj treść ekranu za pomocą przycisku *:

Pojedyncze kliknięcie: Przewiń w dół o 2 linie.

Przytrzymanie: Przewiń w górę o 1 linię na sekundę.

Włączanie/wyłączanie: Przytrzymaj przycisk # przez 5 sekund, aby włączyć lub wyłączyć urządzenie. Przytrzymanie # podczas wyłączonego telefoniku go włączy.

Wymagany sprzęt:

Arduino Mega 2560

Wyświetlacz LCD alfanumeryczny (16x2 lub 20x4)

Klawiatura membranowa 4x4

Karta SD

Moduł ładowania baterii Li-Ion TP4056 (opcjonalnie)

Bateria Li-Ion 3.7V (opcjonalnie)

Przetwornica napięcia (opcjonalnie, jeśli ekran LCD lub klawiatura wymagają innego napięcia)

Rezystory, kondensatory, przewody połączeniowe (zgodnie ze schematem połączeń)

Instalacja i konfiguracja:

Zainstaluj Arduino IDE: Pobierz i zainstaluj Arduino IDE z https://www.arduino.cc/en/software.

Zainstaluj biblioteki: Zainstaluj biblioteki Lua, SD, LiquidCrystal, Keypad i LowPower w Arduino IDE. Możesz to zrobić za pomocą Menedżera Bibliotek w IDE (Sketch -> Include Library -> Manage Libraries...).

Podłącz sprzęt: Połącz Arduino Mega, ekran LCD, klawiaturę i czytnik kart SD zgodnie z dostarczonym schematem połączeń.

Skonfiguruj piny: W pliku logic_main.cpp dostosuj piny klawiatury (rowPins i colPins) do swojego połączenia oraz piny dla LCD, jeśli używasz innych niż domyślne.

Wgraj kod: Skopiuj kod z plików main.cpp, logic_lua.cpp, logic_lua.h, logic_main.cpp i logic_main.h do Arduino IDE i wgraj go na Arduino Mega.

Tworzenie aplikacji w Lua:

Stwórz nowy plik z rozszerzeniem .lua.

Napisz kod Lua w pliku. Możesz korzystać z funkcji standardowej biblioteki Lua oraz funkcji udostępnionych przez John 1.0.

Zapisz plik w folderze /app na karcie SD. Nazwa pliku musi być w formacie appX.lua, gdzie X to cyfra od 1 do 9, odpowiadająca numerowi aplikacji w menu.

Uruchom aplikację: Po włączeniu telefoniku, naciśnij odpowiednią cyfrę na klawiaturze, aby uruchomić aplikację.

Przykładowy skrypt Lua (app1.lua):

print("Witaj w aplikacji Hello!")
-- Dodaj tutaj swój kod Lua
content_copy
Use code with caution.
Lua
Dodatkowe informacje:

Kod źródłowy systemu operacyjnego John 1.0 jest napisany w C++ i korzysta z biblioteki Lua do interpretowania skryptów Lua.

System operacyjny obsługuje maksymalnie 9 aplikacji.

Możesz rozbudować funkcjonalność systemu operacyjnego, dodając nowe funkcje do kodu C++ lub tworząc nowe skrypty Lua.

Ten projekt jest otwarty na modyfikacje i ulepszenia. Zachęcamy do eksperymentowania i tworzenia własnych aplikacji dla John 1.0!
