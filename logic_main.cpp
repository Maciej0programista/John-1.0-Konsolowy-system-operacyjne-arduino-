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

// Flaga wskazująca, czy jesteśmy w aplikacji Ustawienia
bool inSettings = false;

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
  lcd.print("Welcome to John 1.2");
  delay(8000);
  lcd.clear();

  // Sprawdzenie, czy to pierwsze uruchomienie
  if (EEPROM.read(0) == 0) {
    EEPROM.write(0, 1);
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
  }

  isOn = true;
  installLuaApps();
  redrawMainMenu();
}

void loopMainLogic() {
  char keyPressed = readKeypad();

  // Obsługa przycisku # (włączanie/wyłączanie)
  if (keyPressed == '#') {
    if (millis() - lastHashPressTime > 5000) {
      isOn = !isOn;
      if (isOn) {
        lcd.clear();
        lcd.print("John 1.2");
        installLuaApps();
        delay(2000);
        redrawMainMenu();
      } else {
        lcd.clear();
        lcd.print("Wylaczanie...");
        delay(1000);
        LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
      }
    }
  } else {
    lastHashPressTime = millis();
  }

  if (isOn) {
    if (inSettings) {
      handleSettingsInput(keyPressed);
    } else {
      handleMainMenuInput(keyPressed);
    }
  }
}

void handleMainMenuInput(char keyPressed) {
  switch (keyPressed) {
    case '0':
      inSettings = true;
      redrawSettingsMenu();
      break;
    case '1': case '2': case '3': case '4': case '5':
    case '6': case '7': case '8': case '9':
      openLuaScript(String("app") + keyPressed);
      break;
    case '*':
      if (millis() - lastStarPressTime < 500) {
        // Pojedyncze kliknięcie: Scroll down
        cursorY = (cursorY + 1) % 4; // Zakładając 4 linie tekstu na ekranie
      } else if (millis() - lastStarPressTime > 1000) {
        // Przytrzymanie: Scroll up
        cursorY = (cursorY - 1 + 4) % 4;
      }
      redrawMainMenu();
      break;
  }
  lastStarPressTime = millis();
}

void handleSettingsInput(char keyPressed) {
  // TODO: Zaimplementuj obsługę ustawień
  lcd.clear();
  lcd.print("Ustawienia");

  // Przykładowa obsługa powrotu do menu głównego
  if (keyPressed == '#') {
    inSettings = false;
    redrawMainMenu();
  }
}

void redrawMainMenu() {
  lcd.clear();
  lcd.setCursor(0, cursorY);
  for (int i = 1; i <= 9; i++) {
    lcd.print(String("App ") + i);
    lcd.setCursor(0, (cursorY + i) % 4);
  }
}

void redrawSettingsMenu() {
  // TODO: Zaimplementuj rysowanie menu ustawień
  lcd.clear();
  lcd.print("Ustawienia");
}
