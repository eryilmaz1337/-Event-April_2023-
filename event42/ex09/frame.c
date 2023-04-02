#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static char	*ft_word(char *str, const char *s1, int son, int wordlen)
{
	int	i;

	i = 0;
	while (i < wordlen)
	{
		str[i] = s1[son - wordlen + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_place(char **str, char const *s1, char ch, int wordcount)
{
	int		index;
	int		word_len;
	int		word;

	word = 0;
	index = 0;
	word_len = 0;
	while (word < wordcount)
	{
		while (s1[index] != '\0' && s1[index] == ch)
			index++;
		while (s1[index] != '\0' && s1[index] != ch)
		{
			word_len++;
			index++;
		}
		str[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!str)
			return (0);
		ft_word(str[word], s1, index, word_len);
		word_len = 0;
		word++;
	}
	str[word] = 0;
	return (str);
}

static int	strcount(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		wrdcnt;

	if (!s)
		return (0);
	wrdcnt = strcount(s, c);
	str = malloc(sizeof(char *) * (wrdcnt + 1));
	if (!str)
		return (0);
	ft_place(str, s, c, wrdcnt);
	return (str);
}

int ft_max(char **str)
{
	int index=0;
	int length=0;
	while(str[index])
	{
		if(length < strlen(str[index]))
			length = strlen(str[index]);
		index++;
	}
	return(length);
}

int main(int index, char **str_tmp)
{
	char **str;
	int max_line;
	int tmp_index=0;
	if(index == 1)
		return(0);
	else
	{
		index = 0;
		str = ft_split(str_tmp[1],' ');
		max_line = ft_max(str);
		tmp_index=0;
		while(tmp_index < max_line + 4)
		{
			printf("*");
			tmp_index++;
		}
		printf("\n");
		while(str[index])
		{
			int l = strlen(str[index]);
			if(printf("* %s", str[index]) < max_line + 3)
			{
				tmp_index = 0;
				while(l + 2 + tmp_index < max_line + 3)
				{
					printf(" ");
					tmp_index++;
				}
				printf("*\n");
			}
			index++;
		}
		tmp_index=0;
		while(tmp_index < max_line + 4)
		{
			printf("*");
			tmp_index++;
		}
		printf("\n");
	}
	index=0;
	while(str[index])
	{
		free(str[index]);
		index++;
	}
	free(str);
	return(0);
}
