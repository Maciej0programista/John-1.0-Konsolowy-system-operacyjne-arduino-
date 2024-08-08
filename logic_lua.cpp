#include "logic_lua.h"
#include <Lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <SPI.h>
#include <SD.h>

lua_State *L;
File root;

void setupLua() {
  L = luaL_newstate();
  luaL_openlibs(L);

  // Inicjalizacja karty SD
  if (!SD.begin(53)) {
    Serial.println("Błąd inicjalizacji karty SD!");
    return;
  }
}

void loopLua() {
  // ...
}

void openLuaScript(const char* filename) {
  if (luaL_dofile(L, filename) == LUA_OK) {
    Serial.print("Skrypt Lua ");
    Serial.print(filename);
    Serial.println(" uruchomiony pomyślnie.");
  } else {
    Serial.print("Błąd podczas uruchamiania skryptu Lua ");
    Serial.println(filename);
  }
}

void installLuaScripts() {
  root = SD.open("/app");
  int appCount = 0;
  while (true) {
    File entry = root.openNextFile();
    if (!entry) {
      break;
    }
    if (entry.isDirectory()) {
      continue;
    }
    if (entry.name().endsWith(".lua")) {
      appCount++;
      if (appCount <= 9) {
        Serial.print("Zainstalowano aplikację ");
        Serial.print(appCount);
        Serial.print(": ");
        Serial.println(entry.name());
      }
    }
    entry.close();
  }
  root.close();
}

bool createAppFolder() {
  if (!SD.exists("/app")) {
    Serial.println("Tworzenie folderu /app na karcie SD...");
    if (SD.mkdir("/app")) {
      Serial.println("Folder /app utworzony pomyślnie.");
      return true;
    } else {
      Serial.println("Błąd podczas tworzenia folderu /app.");
      return false;
    }
  } else {
    Serial.println("Folder /app już istnieje.");
    return true;
  }
}
