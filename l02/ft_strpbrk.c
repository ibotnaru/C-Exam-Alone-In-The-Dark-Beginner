/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:06:34 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/12/12 20:24:10 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
---------DO NOT PUSH subject---------------------------------------
**
**	Assignment name	: ft_strpbrk
**	Expected files	: ft_strpbrk.c
**	Allowed functions: None
**	---------------------------------------------------------------
**
**	Reproduce exactly the behavior of the function strpbrk
**	(man strpbrk).
**
**	The function should be prototyped as follows:
**
**	char	*ft_strpbrk(const char *s1, const char *s2);
*/

#include <stdlib.h>
char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	int j = 0;
	while(s1[i])
	{
		j = 0;
		while(s2[j])
		{
			if(s1[i] == s2[j])
				return((char *)s1 + i);
			j++;
		}
		i++;
	}
	return(NULL);
}

/*
-------DO NOT PUSH main()--------------------

#include <string.h>
#include <stdio.h>
int main(void)
{
	char *s1 = "0123456789";
	char *s2 = "abc";

	printf("ft_brk	= %s\n", ft_strpbrk(s1, s2));
	printf("brk		= %s\n", strpbrk(s1, s2));

	return(0);
}
*/
