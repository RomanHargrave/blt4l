#pragma once

#include <cstddef>

static int const LUARegistryIndex   = -10000;
static int const LUAGlobalsIndex    = -10002;
static int const LUAYield           = 1;
static int const LUAErrRun          = 2;
static int const LUAErrSyntax       = 3;
static int const LUAErrMem          = 4;
static int const LUAErrErr          = 5;
static int const LUAErrFile         = 6;

class lua_state;
typedef const char* (*lua_reader) (lua_state*, void*, size_t*);
typedef int (*lua_cfunction) (lua_state*);
typedef void* (*lua_alloc) (void*, void*, size_t, size_t);
typedef struct {
  const char* name;
  lua_cfunction func;
} luaL_Reg;

extern "C" {
   void         lua_call(lua_state*, int, int);
   int          lua_pcall(lua_state*, int, int, int);
   int          lua_gettop(lua_state*);
   void         lua_settop(lua_state*, int);
   const char*  lua_tolstring(lua_state*, int, size_t*);
   int          lua_load(lua_state*, lua_reader*, void*, const char*);
   void         lua_setfield(lua_state*, int, const char*);
   void         lua_createtable(lua_state*, int, int);
   void         lua_insert(lua_state*, int);
   lua_state*   lua_newstate(lua_alloc, void*);
   void         lua_close(lua_state*);
   void         lua_rawset(lua_state*, int);
   void         lua_settable(lua_state*, int);

   void         lua_rawgeti(lua_state*, int, int);
   void         lua_pushnumber(lua_state*, double);
   void         lua_pushinteger(lua_state*, ptrdiff_t);
   void         lua_pushboolean(lua_state*, bool);
   void         lua_pushcclosure(lua_state*, lua_cfunction, int);
   void         lua_pushstring(lua_state*, const char*);
   void         lua_pushlstring(lua_state*, const char*, size_t);
   void         lua_pushvalue(lua_state*, int);

   void*        lua_newuserdata(lua_state*, size_t);

   const char*  luaL_checkstring(lua_state*, int);
   void*        luaL_checkudata(lua_state*, int, const char*);
   int          luaL_loadfile(lua_state*, const char*);
   lua_state*   luaL_newstate(void);
   void         luaL_openlib(lua_state*, const char*, const luaL_Reg*, int);
   void         luaL_register(lua_state*, const char*, luaL_Reg*);
   int          luaL_newmetatable(lua_state*, const char*);
   void         luaL_getmetatable(lua_state*, const char*);
   int          lua_setmetatable(lua_state*, int);
   int          luaL_ref(lua_state*, int);
   void         luaL_unref(lua_state*, int, int);
}
