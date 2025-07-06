// #include "so_long.h"

// char	*ft_strdup(char *s)
// {
// 	int		i;
// 	int		len;
// 	char	*dup;

// 	if (!s)
// 		return (NULL);
// 	len = ft_strlen(s);
// 	dup = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!dup)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		dup[i] = s[i];
// 		i++;
// 	}
// 	dup[i] = '\0';
// 	return (dup);
// }