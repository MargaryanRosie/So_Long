#ifndef FT_SPLIT_H
# define FT_SPLIT_H

void	free_remaining(char **output, int j);
char	*ft_strncpy(char *dest, char *src, int n);
int		allocate_word(char **output, char *str, int start, int i, int j);
int		process_word(char **output, char *str, int *i, int *j);
int		word_count(char *str);
void	skip_spaces(char *str, int *i);
void	loop_the_word(char *str, int *i);
char	**ft_split(char *str);

#endif