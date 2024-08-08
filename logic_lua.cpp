#include "logic_lua.h"
#include <Lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <SPI.h>
#include <SD.h>
#include "Lua_compiler.h"

lua_State *L;

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
  char fullPath[30];
  sprintf(fullPath, "/app/%s.lua", filename);
  if (luaL_dofile(L, fullPath) == LUA_OK) {
    Serial.print("Skrypt Lua ");
    Serial.print(filename);
    Serial.println(" uruchomiony pomyślnie.");
  } else {
    Serial.print("Błąd podczas uruchamiania skryptu Lua ");
    Serial.println(filename);
  }
}

void installLuaApps() {
  File appDir = SD.open("/app");
  int appCount = 1;

  while (true) {
    File entry = appDir.openNextFile();
    if (!entry) {
      break;
    }
    if (entry.isDirectory()) {
      String appName = entry.name();
      appName.remove(0, 4);
      char outputFilename[30];
      sprintf(outputFilename, "/app/app%d.lua", appCount);
      if (compileLuaApp(entry.name(), outputFilename)) {
        Serial.print("Zainstalowano aplikację ");
        Serial.print(appCount);
        Serial.print(": ");
        Serial.println(appName);
        appCount++;
      }
    }
    entry.close();
  }
  appDir.close();
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

void setKeyFunction(char key, const char* functionName) {
  // TODO: Zaimplementuj zapisywanie przypisania klawisza
  Serial.print("Przypisano funkcję '");
  Serial.print(functionName);
  Serial.print("' do klawisza '");
  Serial.print(key);
  Serial.println("'.");
}

void setAppForButton(char key, const char* appName) {
  // TODO: Zaimplementuj zapisywanie przypisania aplikacji do przycisku
  Serial.print("Przypisano aplikację '");
  Serial.print(appName);
  Serial.print("' do klawisza '");
  Serial.print(key);
  Serial.println("'.");
}
