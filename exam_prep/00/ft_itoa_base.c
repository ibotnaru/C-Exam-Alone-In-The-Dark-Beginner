/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 16:45:00 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/12/08 17:56:15 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Assignment name  : ft_itoa_base
**	Expected files   : ft_itoa_base.c
**	Allowed functions: malloc
**	--------------------------------------------------------------------------------
**
**	Write a function that converts an integer value to a null-terminated string
**	using the specified base and stores the result in a char array that you must
**	allocate.
**
**	The base is expressed as an integer, from 2 to 16. The characters comprising
**	the base are the digits from 0 to 9, followed by uppercase letter from A to F.
**
**	For example, base 4 would be "0123" and base 16 "0123456789ABCDEF".
**
**	If base is 10 and value is negative, the resulting string is preceded with a
**	minus sign (-). With any other base, value is always considered unsigned.
**
**	Your function must be declared as follows:
**
**	char	*ft_itoa_base(int value, int base);
**	---------------------------------------------------------------------------
**	TRACE:
**	= ft_itoa_base =================================================================
**	$> gcc -Wextra -Wall -Werror ft_itoa_base.c main.c -o user_exe
**	= Test 1 ===================================================
**	$> ./pp8anrwin6g8isz2pjz5zus6
**	$> diff -U 3 user_output_test1 test1.output | cat -e
**	Diff OK :D
**	= Test 2 ===================================================
**	$> ./7np2fc2huew1d64kv36vtwnd "21" "2313" "12"
**	$> diff -U 3 user_output_test2 test2.output | cat -e
**	Diff OK :D
**	= Test 3 ===================================================
**	$> ./75kdcccqm8vdtnwx0w7g62r0 "2147483647" "10"
**	$> diff -U 3 user_output_test3 test3.output | cat -e
**	Diff OK :D
**	= Test 4 ===================================================
**	$> ./hysfvih8y5jp3dnz437sal00 "-2147483648" "10"
**	$> diff -U 3 user_output_test4 test4.output | cat -e
**	Diff OK :D
**	= Test 5 ===================================================
**	$> ./eg9ib0jelpetfvrzdvkql8do "0" "2"
**	$> diff -U 3 user_output_test5 test5.output | cat -e
**	Diff OK :D
**	= Test 6 ===================================================
**	$> ./551i461h1ke3oomjf8xw2tad "--223" "10"
**	$> diff -U 3 user_output_test6 test6.output | cat -e
**	Diff OK :D
**	= Test 7 ===================================================
**	$> ./75jeng26qxiacjiksmzjkf6u "177442482" "2"
**	$> diff -U 3 user_output_test7 test7.output | cat -e
**	Diff OK :D
**	= Test 8 ===================================================
**	$> ./53xk34lxgxxpjmmzthl5fglk "1652417946" "14"
**	$> diff -U 3 user_output_test8 test8.output | cat -e
**	Diff OK :D
**	= Test 9 ===================================================
**	$> ./hv0csjr7y72axhe87fykhfay "216283290" "16"
**	$> diff -U 3 user_output_test9 test9.output | cat -e
**	Diff OK :D
**	= Test 10 ==================================================
**	$> ./f5cutuavczbi0b6jpfb7fa17 "962303865" "2"
**	$> diff -U 3 user_output_test10 test10.output | cat -e
**	Diff OK :D
**	= Test 11 ==================================================
**	$> ./8qu5r9p0bgxu1yhnn6vd7wcv "628799470" "7"
**	$> diff -U 3 user_output_test11 test11.output | cat -e
**	Diff OK :D
**	= Test 12 ==================================================
**	$> ./q6whn91ezjwdg3bwjrr1him2 "272656931" "2"
**	$> diff -U 3 user_output_test12 test12.output | cat -e
**	Diff OK :D
**	= Test 13 ==================================================
**	$> ./42o4ifnbvp8wbdjrgz1zgfyq "260982880" "4"
**	$> diff -U 3 user_output_test13 test13.output | cat -e
**	Diff OK :D
**	= Test 14 ==================================================
**	$> ./4koi6hylouy2lfy7kyvmpu7t "372058695" "13"
**	$> diff -U 3 user_output_test14 test14.output | cat -e
**	Diff OK :D
**	= Test 15 ==================================================
**	$> ./8wyax37p94k1gofo37gxwk0y "-101146281" "10"
**	$> diff -U 3 user_output_test15 test15.output | cat -e
**	Diff OK :D
**	= Test 16 ==================================================
**	$> ./uwq3ckbb9dldl8xuowgft3jq "56617698" "3"
**	$> diff -U 3 user_output_test16 test16.output | cat -e
**	Diff OK :D
**	= Test 17 ==================================================
**	$> ./6qxehb1b3p6nbi4vd7zjbda0 "1698903052" "6"
**	$> diff -U 3 user_output_test17 test17.output | cat -e
**	Diff OK :D
**	= Test 18 ==================================================
**	$> ./lpqgcnylthbtflayreow7bf3 "1808012379" "14"
**	$> diff -U 3 user_output_test18 test18.output | cat -e
**	Diff OK :D
**	= Test 19 ==================================================
**	$> ./g3jshnksh0jro0czktt9tup4 "-74877406" "14"
**	$> diff -U 3 user_output_test19 test19.output | cat -e
**	Diff OK :D
**	= Test 20 ==================================================
**	$> ./n7c0aom99kug8n8ppj9zyvwi "449043599" "13"
**	$> diff -U 3 user_output_test20 test20.output | cat -e
**	Diff OK :Grade: 1
**	= Final grade: 1 ===============================================================
*/

#include <stdlib.h>
int		str_len(int value, int base)
{
	unsigned int		len = 0;

	if(value == 0)
		return(1);
	if (base == 10)
	{
		if (value < 0)
			len++;
	}
	if (value < 0)
		value = value * (-1);
	while (value > 0)
	{
		value = value / base;
		len++;
	}
	return(len);
}

char	put_c(unsigned int i)
{
	char str[16] = "0123456789ABCDEF";
		return(str[i]);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	unsigned int	len = 0;
	unsigned int	i = 0;

	len = str_len(value, base);
	str = NULL;
	if (value == -2147483648)
		return("-2147483648");
	if(base >= 2 && base <= 16)
	{
		str = (char *)malloc(sizeof(char) * len + 1);
		if (value < 0)
		{
			if (base == 10)
			{
				str[i] = '-';
				i++;
			}
			value = value * (-1);
		}
		str[len] = '\0';
		len--;
		if (value == 0)
			str[len] = '0';
		else
		{
			while(value > 0)
			{
				str[len] = put_c(value % base);
				value = value / base;
				len--;
			}
		}
	}
	return(str);
}

/*
#include <stdio.h>
int main(void)
{
	int value = 0;
	int base = 2;


	// int len = str_len(value, base);
	// printf("%d\n", len);
	char *str = ft_itoa_base(value, base);
	printf("%s\n", str);
	return(0);
}
*/
