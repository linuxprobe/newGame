#include "all.h"
using namespace std;
lua_State *L;
thread::id main_id = this_thread::get_id();
class base
{
public:
	base();
	~base();
protected:
private:
};
base::base()
{
	printf("this base new\n");
}
base::~base()
{
	printf("this ~base delete\n");
}

class MyClass : public base
{
public:
	MyClass();
	~MyClass();

private:

};

MyClass::MyClass()
{
	printf("this is myclass new\n");
}

MyClass::~MyClass()
{
	printf("this is myclass delete\n");
}
int a = 100;
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
void hello(void)
{
	a++;
	thread::id id = std::this_thread::get_id();
	//printf("this is hello id = %d\n",id);
	std::cout << "Hello from thread1 " << a << "\n" <<std::endl;
}
void hello2(void)
{
	a ++;
	thread::id id = std::this_thread::get_id();
		//printf("this is hello2 id = %d\n",id);
		//printf("this is hello id = %d\n",id);
	//std::cout << "Hello from thread2 " << id << "\n" << std::endl;
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
	//printf("%d\n",t);
	lua_close(L);

	std::thread t1(hello);
	std::thread t2(hello2);
	t1.join();
	t2.join();
	testClass privateId ;

	cout << privateId.id << "\n" <<endl;
	std::cout<<"Main Thread"<<std::endl;

	MyClass * my = new MyClass();
	delete my;
	return 0;
}