#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>


// Libft functions //

int		ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *big,	const char *little, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

// Main functions //
void	start_exec(char *argv, char **envp);
char	*find_path(char *cmd, char **envp);