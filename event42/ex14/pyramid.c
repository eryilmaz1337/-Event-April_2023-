#include <stdio.h>
#include <stdlib.h>

int main(int index, char **str)
{
	if(index != 2)
		return 1;
	int num=4;
	int s_number=3;
	int i=1;
	int k=0;
	int b;
	int tmp = atoi(str[1]);
	while(i != tmp)
	{
		s_number += num;
		num++;
		i++;
	}
	i=0;
	num=1;
	while(i != s_number)
	{
		num += 2;
		i++;
	}
	num += 2;
	b = num / 2 - 1;
	while(i<sum)
	{
		while(k<=b)
			printf(" ");
		printf("/");
		printf("\\\n");
		i++;
	}
	// num=num+2;
}
