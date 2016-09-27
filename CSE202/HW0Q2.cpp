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
auto balance1() // this functions changes the brackets (minimum number of changes) to make the string balanced
{
	char r[len+1]; // stores the result of balance
	auto brackets = 0; // the total number of brackets
	auto passed_brackets = 0; // the number of brackets passed so far

	/* First we count the number of brackets in the string*/
	for (int i = 0; i < len; ++i)
		if (s[i] == '{' || s[i] == '}') brackets++;

	strncpy_s(r, s, len);

	auto dir = 0; // the number of opneded brackets so far - the number of closed brackets so far.
	for (int i = 0; i < len; ++i)
	{
		if (r[i] == '}' && dir == 0) r[i] = '{';
		if (r[i] == '{' && dir == (brackets - passed_brackets)) r[i] = '}';
		if (r[i] == '}') dir--;
		if (r[i] == '{') dir++;
		printf("%d", dir);
		//printf("%d", brackets - passed_brackets);
		if (r[i] == '{' || r[i] == '}') passed_brackets++;
	}
	printf("\n");
	printf(r);
	return r;
}
int main()
{
	for (int j = 1; j < 100; j++)
	{
		Sleep(300);
		srand(time(0));
		generate();
		printf(s);
		printf("\n");

		printf("%c", balance1());
		printf("\n");
		printf("\n");
	}
	system("PAUSE");
	return 0;
}
