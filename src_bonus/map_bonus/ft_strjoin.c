#include "../include/so_long_bonus.h"
#include "../include/ft_split.h"

char	*ft_strjoin_with_newline(char *s1, char *s2)
{
	char	*ptr;
	char	*start;

	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!ptr)
		return (NULL);
	start = ptr;
	while (*s1)
	{
		*ptr = *s1;
		ptr++;
		s1++;
	}
	*ptr = '\n';
	ptr++;
	while (*s2)
	{
		*ptr = *s2;
		ptr++;
		s2++;
	}
	*ptr = '\0';
	return (start);
}