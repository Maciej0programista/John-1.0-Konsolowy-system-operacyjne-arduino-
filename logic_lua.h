#ifndef LOGIC_LUA_H
#define LOGIC_LUA_H

void setupLua();
void loopLua();
void openLuaScript(const char* filename);
void installLuaScripts();
bool createAppFolder();

#endif
