/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:55:03 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/12/08 17:55:47 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		printstr(char *str, int i)
{
	while(str[i] && str[i] != ' ' && str[i] != '\t')
	{
		write(1, &str[i], 1);
		i++;
	}
	return(i);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		while(av[1][i])
		{
			while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
				i++;
			if(av[1][i])
				i = printstr(av[1], i);
			while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
				i++;
			if(av[1][i])
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return(0);
}
