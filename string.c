#include "monty.h"

/**
 * _strcmp- compares 2 strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if equal, or else
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * _sch- searches for a char
 * @s: the string
 * @c: the char
 * Return: 1 if found or 0
 */
int _sch(char *s, char c)
{
	int counter = 0;

	while (s[counter] != '\0')
	{
		if (s[counter] == c)
			break;
		counter++;
	}
	if (s[counter] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtok- produces tokens
 * @s: the line
 * @d: delimenters
 * Return: first token
 */
char *_strtok(char *s, char *d)
{
	static char *ultimo;
	int i  = 0, j = 0;

	if (!s)
		s = ultimo;
	while (s[i] != '\0')
	{
		if (_sch(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 0)
			i++;
		else if (_sch(d, s[i]) == 0 && _sch(d, s[i + 1]) == 1)
		{
			ultimo = s + i + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
