//Call Stack demo
#include <windows.h>

int fun5()
{
	int m = 50;
	int n = 60;
	m = n;

	MessageBoxA(NULL, "Welcome!", "Hi", 0);

	return 0;
}

int fun4(int a, int b, int c, int d)
{
	int x = 10;
	int y = 20;
	int z = 30;

	x = y;

	return 0;
}

int fun3(int a, int b, int c)
{
	int i = 100;
	int j = 200;

	fun4(7, 8, 9, 10);

	i = j;

	fun5();

	return 0;
}

int fun2(int a, int b)
{
	fun3(4, 5, 6);

	return 0;
}

int fun1(int a)
{
	fun2(2, 3);

	return 0;
}

int main()
{
	fun1(10);

	return 0;
}
