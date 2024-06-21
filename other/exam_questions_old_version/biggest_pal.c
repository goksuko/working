int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

void now_write(int start, int end, char *str)
{
	while (start <= end)
	{
		write(1, &str[start], 1);
		start++;
	}
	write(1, "\n", 1);
}


int main(int argc, char *argv[])
{
	char *str;
	int len;
	int i;
	int start;
	int end;
	int copy_start;
	int copy_end;
	int copy_i;
	int max_len;

	str = argv[1];
	if (argc != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	len = ft_strlen(str);
	i = 0;
	while (i != len)
	{
		if (str[i] == str[len])
		{
			copy_i = i;
			start = i;
			end = len;
			while (i != len)
			{
				i++;
				len--;
			}
			if ((i == len) || (i == len + 1))
			{
				copy_start = start;
				copy_end = end;
				now_write(copy_start, copy_end, str);
				return 0;
			}
			else
			{
				i = copy_i;
				max_len = copy_end - copy_start;
			}
		}
		i++;
	}
	return 0;
}







// Assignment name  : biggest_pal
// Expected files   : *.c, *.h
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program named biggest_pal that takes a string as argument and prints the
// biggest palindrome included inside this string, followed by a newline.

// This string contains only lowercase characters.

// If there is two palindromes of the same length, you have to print the last one.

// If there is more or less than 1 argument, your program must print only a newline
// only.

// Exemples:

// $> biggest_pal "abcba"
// abcba
// $> biggest_pal "aaaaaaaaaabbcbbaaaa"
// aaaabbcbbaaaa
// $> biggest_pal "aooibdaoiwhoihwdoinzeldaisaboyobasiadlezfdsfnslk"
// zeldaisaboyobasiadlez
// $> biggest_pal "aeibaabaammaabaalek"
// aabaammaabaa
// $> biggest_pal abeb qpinqwjobo qkmnwoiq

// $> biggest_pal

// $>