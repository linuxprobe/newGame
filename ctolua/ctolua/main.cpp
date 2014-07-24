#include "all.h"
lua_State *L;
int luaAdd(int x, int y)
{
	int sum;
	lua_getglobal(L,"add");
	lua_pushnumber(L,x);
	lua_pushnumber(L,y);
	lua_call(L,2,1);
	sum = (int)lua_tonumber(L,-1);
	lua_pop(L,1);
	return sum;
}
int main()
{
	int sum = 0;
	unsigned int t = 2^31;
	L = lua_open();
	luaL_openlibs(L);
	luaL_dofile(L,"add.lua");
	lua_pcall(L, 0, LUA_MULTRET, 0);
	sum = luaAdd(10,15);
	printf("%d",t);
	lua_close(L);
	return 0;
}