/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibotnaru <ibotnaru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 13:38:39 by ibotnaru          #+#    #+#             */
/*   Updated: 2019/12/08 17:56:32 by ibotnaru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int* tab, unsigned int len)
{
	unsigned int i = 0;
	int res = 0;
	while(i < len)
	{
		if(i == 0)
		{
			res = tab[i];
			i++;
		}
		if(tab[i] >= res)
			res = tab[i];
		i++;
	}
	return(res);
}
