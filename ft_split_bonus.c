#include "push_swap_bonus.h"

int count_strings(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == 10 || str[i] == 9 || str[i] == 32 || str[i] == 0))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !(str[i] == 10 || str[i] == 9 || str[i] == 32 || str[i] == 0))
			i++;
	}
	return (count);
}

int ft_strlen_sep(char *str)
{
	int i;

	i = 0;
	while (str[i] && !(str[i] == 10 || str[i] == 9 || str[i] == 32 || str[i] == 0))
		i++;
	return (i);
}

char *ft_word(char *str)
{
	int len_word;
	int i;
	char *word;

	i = 0;
	len_word = ft_strlen_sep(str);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void free_split_2(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char **ft_split(char *str)
{
	char **strings;
	int i;

	i = 0;
	strings = (char **)malloc(sizeof(char *) * (count_strings(str) + 1));
	while (*str != '\0')
	{
		while (*str != '\0' && (*str == 10 || *str == 9 || *str == 32 || *str == 0))
			str++;
		if (*str != '\0')
		{
			strings[i] = ft_word(str);
			if (!strings[i] || atoi(strings[i]) > 2147483647 || atoi(strings[i]) < -2147483648)
			{
				free_split_2(strings);
				return (0);
			}
			i++;
		}
		while (*str && !(*str == 10 || *str == 9 || *str == 32 || *str == 0))
			str++;
	}
	return (strings[i] = 0, strings);
}
