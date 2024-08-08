#ifndef LOGIC_LUA_H
#define LOGIC_LUA_H

void setupLua();
void loopLua();
void openLuaScript(const char* filename);
void installLuaApps();
bool createAppFolder();
void setKeyFunction(char key, const char* functionName);
void setAppForButton(char key, const char* appName);

#endif
