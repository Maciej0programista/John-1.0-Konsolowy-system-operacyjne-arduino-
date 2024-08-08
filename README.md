# John 1.2 - Personalizacja i kontrola w Twoich rękach!
# Jeśli spodobał Ci się ten projekt lub z niego korzystasz, proszę podziel się swoimi wrażeniami i napisz do mnie na adres: bosyjjakub@gmail.com
# Jeśli chcecie się skontaktować lub coś zapytać ruwnierz zapraszam na serwer:https://discord.com/invite/6mCAdnYa
Witaj w **John 1.2**, najnowszej
aktualizacji naszego klasycznego konsolowego systemu operacyjnego dla Arduino Mega! John 1.2 wprowadza szereg ulepszeń, skupiając się na **personalizacji** i **łatwiejszym dostępie** do Twoich aplikacji.

## :sparkles: Co nowego w John 1.2?

* **:gear: Aplikacja Ustawienia:**  
    Teraz możesz dostosować Johna do swoich potrzeb! Otwórz aplikację Ustawienia (klawisz `0`), aby:
    * Zmienić przypisanie klawiszy funkcyjnych. Chcesz, aby `*` działał jak Enter? Żaden problem!
    * Przypisać ulubione aplikacje Lua do dowolnych przycisków. Szybki dostęp do tego, co najważniejsze!

* **:open_file_folder: Ulepszone zarządzanie aplikacjami:**  
    John 1.2 obsługuje teraz wielo-plikowe aplikacje Lua! Organizuj swój kod w logiczne moduły i umieść je w osobnych plikach w folderze aplikacji. John automatycznie skompiluje je w jedną całość podczas uruchamiania.

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
5. **Wgraj kod:** Skopiuj kod z plików `main.cpp`, `logic_lua.cpp`, `logic_lua.h`, `logic_main.cpp`, `logic_main.h`, `Lua_compiler.cpp` i `Lua_compiler.h` do Arduino IDE i wgraj go na Arduino Mega.

## :pencil2: Tworzenie aplikacji w Lua:

1. **Stwórz folder dla swojej aplikacji w katalogu `/app` na karcie SD.** Nazwa folderu będzie nazwą Twojej aplikacji.
2. **Stwórz plik `main.lua` wewnątrz folderu aplikacji.** To będzie główny plik Twojej aplikacji.
3. **Napisz kod Lua w pliku `main.lua`.** 
4. **Uruchom John 1.2:** Po włączeniu, naciśnij odpowiednią cyfrę na klawiaturze, aby uruchomić aplikację. Aby wejść do Ustawień, naciśnij klawisz `0`.

## :information_source:  Funkcje Lua:

* `print(tekst)`: Wyświetla tekst na ekranie LCD.
* `setKeyFunction(klawisz, "nazwa_funkcji")`:  Zmienia przypisanie funkcji do danego klawisza.
* `setAppForButton(klawisz, "nazwa_aplikacji")`:  Przypisuje aplikację do danego przycisku. 

**John 1.2 - Twój spersonalizowany asystent na Arduino!**
