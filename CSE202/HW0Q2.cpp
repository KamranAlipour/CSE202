#include<iostream>
#include<time.h>
#include<windows.h>
auto const len = 50;
char s[len];
/* function generates the string */
auto generate()
{
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"{}{}{}{}{}{}{}{}{}{}{}{}{}";
	auto n_brackets = 1; // holds the number of brackets, it should be even
	srand(time(0));
	while (n_brackets % 2 != 0)
	{
		Sleep(100);
		srand(time(NULL));
		n_brackets = 0;
		for (int i = 0; i < len; ++i)
		{
			s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
			if (s[i] == '{' || s[i] == '}') n_brackets++;
		}
	}
	return 0; /* determines successful termination*/
} 
auto balance()
{
	auto brackets = 0; // if a bracket opens this inetegr goes one up and if a bracket closes it goes one down.
	for (int i = 0; i < len; ++i)
	{
		if (s[i] == '{') brackets++;
		if (s[i] == '}' && brackets == 0) s[i] = '{';
		if (s[i] == '}') brackets--;
	}
}
int main()
{
	generate();
	printf(s);
	printf("\n");
	balance();
	printf(s);
	printf("\n");
	system("PAUSE");
	return 0;
}