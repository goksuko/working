#include "ft_printf.h"

int main(void)
{
	char			c = 'G';
	char			*s = "Goksu";
	int				d = -458961230;
	// int				u = 123456789;
	// unsigned int 	x = 123;
	// unsigned int	ux = 123456;
	int				f;
	int				p;

	f = ft_printf("10: NULL %s NULL ", NULL);
	p = printf("10: NULL %s NULL ", NULL);
	printf(" my: %d\norg: %d\n-----\n", f, p);
	f = ft_printf("6: %p %p ", LONG_MIN, LONG_MAX);
	p = printf("6: %p %p ", LONG_MIN, LONG_MAX);
	printf(" my: %d\norg: %d\n-----\n", f, p);
		// f = ft_printf(" %u \n", 101);
	// p = printf(" %u \n", 101);
	// printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf(" %x \n", -100);
	// p = printf(" %x \n", -100);
	// printf(" my: %d\norg: %d\n-----\n", f, p); 
	// f = ft_printf(" %X \n", -100);
	// p = printf(" %X \n", -100);
	// printf(" my: %d\norg: %d\n-----\n", f, p); 
	// f = ft_printf("char: %c\n", c);
	// p = printf("char: %c\n", c);
	// printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf("char: %c, string: %s\n", c, s);
	// p = printf("char: %c, string: %s\n", c, s);
	// printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf("char: %c, string: %s, decimal: %d\n", c, s, d);
	// p = printf("char: %c, string: %s, decimal: %i\n", c, s, d);
	// printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf("char: %c, string: %s, decimal: %d, integer: %d\n", c, s, d, d);
	// p = printf("char: %c, string: %s, decimal: %i, integer: %d\n", c, s, d, d);
	// printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf("integer: %d, unsigned decimal: %u\n", d, u);
	// p = printf("integer: %d, unsigned decimal: %u\n", d, u);
	// printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf("hexa: %x, HEXA: %X\n", x, ux);
	// p = printf("hexa: %x, HEXA: %X\n", x, ux);
	// printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf("pointer: %p\n", s);
	// p = printf("pointer: %p\n", s);
	// printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf(" %d ", 1);
	// p = printf(" %d ", 1);
	// printf(" my: %d\norg: %d\n-----\n", f, p);	
	// f = ft_printf(" NULL %s NULL ", NULL);
	// // p = printf(" NULL %s NULL ", NULL);
	// // printf(" my: %d\norg: %d\n-----\n", f, p);
	// f = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	// // p = printf(" %p %p ", LONG_MIN, LONG_MAX);
	// // printf(" my: %d\norg: %d\n-----\n", f, p);
	f = ft_printf("7: %p %p ", INT_MIN, INT_MAX);
	p = printf("7: %p %p ", INT_MIN, INT_MAX);
	printf(" my: %d\norg: %d\n-----\n", f, p);
	f = ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	p = printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	printf(" my: %d\norg: %d\n-----\n", f, p);
	f = ft_printf(" %p %p ", 0, 0);
	p = printf(" %p %p ", 0, 0);
	printf(" my: %d\norg: %d\n-----\n", f, p);	
	return (0);
}
