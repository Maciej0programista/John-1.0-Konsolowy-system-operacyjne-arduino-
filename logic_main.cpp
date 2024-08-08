#include "logic_main.h"
#include <LiquidCrystal.h>
#include "logic_lua.h"
#include <Keypad.h>
#include <EEPROM.h>

// Inicjalizacja ekranu LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Konfiguracja klawiatury
const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // Podłączenie pinów wierszy - dostosuj do swojego układu
byte colPins[COLS] = {5, 4, 3, 2}; // Podłączenie pinów kolumn - dostosuj do swojego układu
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Zmienna do przechowywania stanu włączenia/wyłączenia
bool isOn = false;

// Zmienna do przechowywania czasu ostatniego wciśnięcia przycisku #
unsigned long lastHashPressTime = 0;

// Zmienna do przechowywania czasu ostatniego wciśnięcia przycisku *
unsigned long lastStarPressTime = 0;

// Pozycja kursora na ekranie (dla scrollowania)
int cursorY = 0;

// Funkcja do obsługi klawiatury
char readKeypad() {
  char key = keypad.getKey();
  if (key) {
    return key;
  } else {
    return NO_KEY;
  }
}

void setupMainLogic() {
  lcd.begin(16, 2);
  // Ekran powitalny
  lcd.print("Welcome to John 1.0");
  delay(8000);
  lcd.clear();

  // Sprawdzenie, czy to pierwsze uruchomienie
  if (EEPROM.read(0) == 0) {
    // Ustaw flagę pierwszego uruchomienia
    EEPROM.write(0, 1);

    // Tworzenie folderu "app" na karcie SD
    if (createAppFolder()) {
      lcd.print("Folder /app");
      lcd.setCursor(0, 1);
      lcd.print("utworzony");
      delay(3000);
    } else {
      lcd.print("Błąd tworzenia");
      lcd.setCursor(0, 1);
      lcd.print("folderu /app");
      delay(3000);
    }
  } else {
    Serial.println("Folder /app już istnieje.");
  }

  isOn = true;
  installLuaScripts();
}

void loopMainLogic() {
  // Odczytywanie danych z klawiatury
  char keyPressed = readKeypad();

  // Obsługa przycisku # (włączanie/wyłączanie)
  if (keyPressed == '#') {
    if (millis() - lastHashPressTime > 5000) {
      // Przytrzymanie przycisku # przez 5 sekund
      isOn = !isOn;
      if (isOn) {
        lcd.clear();
        lcd.print("John 1.0");
        installLuaScripts();
      } else {
        lcd.clear();
        lcd.print("Wylaczanie...");
        delay(1000);
        // Przejdź w tryb uśpienia
        LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
      }
    }
  } else {
    lastHashPressTime = millis();
  }

  // Obsługa przycisku * (scroll)
  if (keyPressed == '*' && isOn) {
    if (millis() - lastStarPressTime < 500) {
      // Pojedyncze kliknięcie: Scroll down o 2 piksele
      cursorY = (cursorY + 2) % lcd.rows();
      lcd.setCursor(0, cursorY);
    } else if (millis() - lastStarPressTime > 1000) {
      // Przytrzymanie: Scroll up o 1 piksel na sekundę
      cursorY = (cursorY - 1 + lcd.rows()) % lcd.rows();
      lcd.setCursor(0, cursorY);
    }
  } else {
    lastStarPressTime = millis();
  }

  // Obsługa pozostałych przycisków
  if (isOn) {
    switch (keyPressed) {
      case '1': case '2': case '3': case '4': case '5':
      case '6': case '7': case '8': case '9': case '0':
        // Uruchomienie aplikacji o numerze odpowiadającym wciśniętemu klawiszowi
        openLuaScript(String("/app/app") + keyPressed + ".lua");
        break;
      case 'A': lcd.print("+"); break;
      case 'B': lcd.print("x"); break;
      case 'C': lcd.print("/"); break;
      case 'D': lcd.print("="); break;
    }
  }

  // Obsługa przytrzymania przycisku # (scroll down)
  if (/* Przycisk # jest wciśnięty */ && isOn) {
    if (millis() - lastHashPressTime > 1000) {
      // Przytrzymanie: Scroll down o 1 piksel na sekundę
      cursorY = (cursorY + 1) % lcd.rows();
      lcd.setCursor(0, cursorY);
    }
  }
}
