#include <stdio.h>
#include <string.h>


char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
		{
			return (0);
		}
		s++;
	}
	return ((char *)s);
}

int main()
{
	char s[] = "privet*test";
	int c = '*';
	printf("my  = %s\n", ft_strchr(s, c));
	printf("lib = %s\n", ft_strchr(s, c));
}