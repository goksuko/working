#include "push_swap.h"

// t_stack *ps_array_to_stack_a(int *array, t_stack **a)
// {
// 	t_stack		*new_t_stack;
// 	t_stack		*current;
// 	int			i;
// 	int			length;
// 	int			*temp_array;

// 	temp_array = array;
// 	length = sizeof(temp_array) / sizeof(int);
// 	i = 0;
// 	while (i < length)
// 	{
// 		new_t_stack = calloc(1, sizeof(t_stack));
// 		if (new_t_stack == NULL)
// 			return (NULL);
// 		new_t_stack->value = array[i];
// 		new_t_stack->next = NULL;
// 		current = *a;
// 		if (current == NULL)	
// 			*a = new_t_stack;
// 		else
// 		{
// 			while (current->next != NULL)
// 				current = current->next;
// 			current->next = new_t_stack;
// 		}
// 		i++;
// 	}
// 	return(*a);	
// }

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != 0)
		n++;
	return (n);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dst == NULL || src == NULL || !size)
		return (src_len);
	while (*src && --size)
		*dst++ = *src++;
	*dst = '\0';
	return (src_len);
}


char	*ft_strdup(const char *s)
{
	char	*temp;
	size_t	i;

	if (!s)
		return (NULL);
	temp = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (s[i])
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!s)
		return (0);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

static char	**clean(char **matrix, size_t string_no)
{
	while (string_no--)
		free(matrix[string_no]);
	free(matrix);
	return (NULL);
}

static int	count_strings(const char *s, char delimiter)
{
	size_t	string_nb;

	string_nb = 0;
	while (*s)
	{
		while (*s == delimiter && *s)
			s++;
		if (*s != delimiter && *s)
		{
			string_nb++;
			while (*s != delimiter && *s)
				s++;
		}
	}
	return (string_nb);
}

static char	**fill_matrix(char **matrix, const char *s, char c)
{
	size_t	i;
	size_t	string_no;
	size_t	string_len;
	size_t	start;

	i = 0;
	string_no = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			string_len = i - start;
			matrix[string_no] = ft_substr(s, start, string_len);
			if (matrix[string_no] == NULL)
				return (clean(matrix, string_no));
			string_no++;
		}
	}
	matrix[string_no] = NULL;
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	int		string_nb;
	char	**matrix;

	if (s == NULL)
		return (NULL);
	string_nb = count_strings(s, c);
	matrix = (char **)malloc(sizeof(char *) * (string_nb + 1));
	if (matrix == NULL)
		return (NULL);
	matrix = fill_matrix(matrix, s, c);
	if (matrix == NULL)
		return (NULL);
	matrix[string_nb] = NULL;
	return (matrix);
}


static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (nptr[i] != '\0')
	{
		while (ft_isspace(nptr[i]) == 1)
			i++;
		if (nptr[i] == '-')
			sign = -1;
		if (nptr[i] == '-' || nptr[i] == '+')
			i++;
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			nb = (10 * nb) + (nptr[i] - '0');
			i++;
		}
	}
	return (sign * nb);
}

t_stack *ps_string_to_stack_a(char *string, t_stack **a)
{
	char		**array;
	t_stack		*new_t_stack;
	t_stack		*current;
	int			i;
	int			nb;

	array = ft_split(string, ' ');
	i = 0;
	while (array[i])
	{
		nb = ft_atoi(array[i]);
		new_t_stack = calloc(1, sizeof(t_stack));
		if (new_t_stack == NULL)
			return (NULL);
		new_t_stack->value = nb;
		new_t_stack->next = NULL;
		current = *a;
		if (current == NULL)	
			*a = new_t_stack;
		else
		{
			while (current->next != NULL)
				current = current->next;
			current->next = new_t_stack;
		}
		i++;
	}
	return(*a);	
}


t_stack *ps_arguments_to_stack_a(char *string, t_stack **a)
{
	t_stack		*new_t_stack;
	t_stack		*current;
	int			nb;

	nb = ft_atoi(string);
	new_t_stack = calloc(1, sizeof(t_stack));
	if (new_t_stack == NULL)
		return (NULL);
	new_t_stack->value = nb;
	new_t_stack->next = NULL;
	current = *a;
	if (current == NULL)	
		*a = new_t_stack;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new_t_stack;
	}
	return(*a);	
}