#include <Arduino.h>
#include "logic_lua.h"
#include "logic_main.h"

void setup() {
  Serial.begin(9600);
  setupLua();
  setupMainLogic();
}

void loop() {
  loopLua();
  loopMainLogic();
}
