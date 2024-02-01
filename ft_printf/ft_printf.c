/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 03:57:16 by mosh              #+#    #+#             */
/*   Updated: 2023/10/14 23:37:13 by mosh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

size_t ft_putchar_fd(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

size_t ft_putstr_fd(char *str, int fd)
{
	size_t i;

	i = 0;
	if (!str)
		return (ft_putstr_fd("(null)", 1));

	while (str[i])
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
	return (i);
}

size_t ft_putptr_fd(uintptr_t ptr, int fd)
{
	char *hex_digits = "0123456789abcdef";
	char buffer[20];
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (!ptr)
	{
		count += ft_putstr_fd("0x0", fd);
		return (count);
	}
	while (ptr)
	{
		buffer[i++] = hex_digits[ptr % 16];
		ptr /= 16;
	}
	count += ft_putstr_fd("0x", fd);
	while (i--)
		count += ft_putchar_fd(buffer[i], fd);
	return (count);
}

size_t ft_puthex_small(unsigned int num)
{
	char *hex_digits = "0123456789abcdef";
	char buff[10];
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (num == 0)
		return (ft_putchar_fd('0', 1));
	while (num)
	{
		buff[i++] = hex_digits[num % 16];
		num /= 16;
	}
	while (i--)
		count += ft_putchar_fd(buff[i], 1);
	return (count);
}

size_t ft_puthex_big(unsigned int num)
{
	char *hex_digits = "0123456789ABCDEF";
	char buff[10];
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	if (num == 0)
		return (ft_putchar_fd('0', 1));
	while (num)
	{
		buff[i++] = hex_digits[num % 16];
		num /= 16;
	}
	while (i--)
		count += ft_putchar_fd(buff[i], 1);
	return (count);
}

size_t ft_put_unsigned_nbr(unsigned int n)
{
	size_t count;

	count = 0;
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	if (n >= 10)
	{
		count += ft_put_unsigned_nbr(n / 10);
	}
	count += ft_putchar_fd(n % 10 + '0', 1);
	return (count);
}

size_t ft_putnbr_fd(int n, int fd)
{
	size_t count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", 1));
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		count++;
	}
	if (n >= 10)
		count += ft_putnbr_fd(n / 10, fd);
	count += ft_putchar_fd(n % 10 + '0', fd);
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count += ft_putchar_fd(va_arg(ap, int), 1);
			else if (format[i] == 's')
				count += ft_putstr_fd(va_arg(ap, char *), 1);
			else if (format[i] == 'p')
				count += ft_putptr_fd((uintptr_t)va_arg(ap, void *), 1);
			else if (format[i] == 'd' || format[i] == 'i')
				count += ft_putnbr_fd(va_arg(ap, int), 1);
			else if (format[i] == 'u')
				count += ft_put_unsigned_nbr((unsigned int)va_arg(ap, unsigned int));
			else if (format[i] == 'x')
				count += ft_puthex_small(va_arg(ap, int));
			else if (format[i] == 'X')
				count += ft_puthex_big(va_arg(ap, int));
			else if (format[i] == '%')
				count += ft_putchar_fd('%', 1);
		}
		else
			count += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}

int main() {
    char *test_str = "Hello, World!";
    int test_int = -123;
    unsigned int test_uint = 123;
    int *test_ptr = &test_int;

    printf("Original printf:\n");
    printf("String: %s\n", test_str);
    printf("Int: %d\n", test_int);
    printf("Unsigned Int: %u\n", test_uint);
    printf("Pointer: %p\n", test_ptr);

    printf("\nCustom ft_printf:\n");
    ft_printf("String: %s\n", test_str);
    ft_printf("Int: %d\n", test_int);
    ft_printf("Unsigned Int: %u\n", test_uint);
    ft_printf("Pointer: %p\n", test_ptr);
}
// int main()
// {
// 	printf("%c", '0');
// 	printf(" %c ", '0');
// 	printf(" %c", '0' - 256);
// 	printf("%c ", '0' + 256);
// 	printf(" %c %c %c ", '0', 0, '1');
// 	printf(" %c %c %c ", ' ', ' ', ' ');
// 	printf(" %c %c %c ", '1', '2', '3');
// 	printf(" %c %c %c ", '2', '1', 0);
// 	printf(" %c %c %c ", 0, '1', '2');
// 	printf("\n############\n");
// 	ft_printf("%c", '0');
// 	ft_printf(" %c ", '0');
// 	ft_printf(" %c", '0' - 256);
// 	ft_printf("%c ", '0' + 256);
// 	ft_printf(" %c %c %c ", '0', 0, '1');
// 	ft_printf(" %c %c %c ", ' ', ' ', ' ');
// 	ft_printf(" %c %c %c ", '1', '2', '3');
// 	ft_printf(" %c %c %c ", '2', '1', 0);
// 	ft_printf(" %c %c %c ", 0, '1', '2');
// 	printf("\n");

//     return 0;
// }
// int main()
// {
// 	printf(" NULL %s NULL ", (char *)NULL);
// 	printf("###\n");
// 	ft_printf(" NULL %s NULL ", (char *)NULL);
// }

// int main()
// {
// 	printf(" %x ", 0);
// 	printf(" %x ", -1);
// 	printf(" %x ", 1);
// 	printf(" %x ", 9);
// 	printf(" %x ", 10);
// 	printf(" %x ", 11);
// 	printf(" %x ", 15);
// 	printf(" %x ", 16);
// 	printf(" %x ", 17);
// 	printf(" %x ", 99);
// 	printf(" %x ", 100);
// 	printf(" %x ", 101);
// 	printf(" %x ", -9);
// 	printf(" %x ", -10);
// 	printf(" %x ", -11);
// 	printf(" %x ", -14);
// 	printf(" %x ", -15);
// 	printf(" %x ", -16);
// 	printf(" %x ", -99);
// 	printf(" %x ", -100);
// 	printf(" %x ", -101);
// 	printf(" %x ", INT_MAX);
// 	printf(" %x ", INT_MIN);
// 	printf(" %x ", LONG_MAX);
// 	printf(" %x ", LONG_MIN);
// 	printf(" %x ", UINT_MAX);
// 	printf(" %x ", ULONG_MAX);
// 	printf(" %x ", 9223372036854775807LL);
// 	printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	printf(" %x ", 42);
// 	printf(" %x ", -42);

// 		printf(" %x ", 0);
// 	printf(" %x ", -1);
// 	printf(" %x ", 1);
// 	printf(" %x ", 9);
// 	printf(" %x ", 10);
// 	printf(" %x ", 11);
// 	printf(" %x ", 15);
// 	printf(" %x ", 16);
// 	printf(" %x ", 17);
// 	printf(" %x ", 99);
// 	printf(" %x ", 100);
// 	printf(" %x ", 101);
// 	printf(" %x ", -9);
// 	printf(" %x ", -10);
// 	printf(" %x ", -11);
// 	printf(" %x ", -14);
// 	printf(" %x ", -15);
// 	printf(" %x ", -16);
// 	printf(" %x ", -99);
// 	printf(" %x ", -100);
// 	printf(" %x ", -101);

// 	return(0);
// }

// int main ()
// {
// 	printf(" %% \n");
// 	printf(" %%%% \n");
// 	printf(" %% %% %% \n");
// 	printf(" %%  %%  %% \n");
// 	printf(" %%   %%   %% \n");
// 	printf("%%\n");
// 	printf("%% %%\n");

// 		printf(" %% \n");
// 	ft_printf(" %%%% \n");
// 	ft_printf(" %% %% %% \n");
// 	ft_printf(" %%  %%  %% \n");
// 	ft_printf(" %%   %%   %% \n");
// 	ft_printf("%%\n");
// 	ft_printf("%% %%\n");
// }