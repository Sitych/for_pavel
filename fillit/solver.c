/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 01:06:08 by rretta            #+#    #+#             */
/*   Updated: 2019/12/30 20:38:14 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h" 

int     ft_solver(t_tetr *ptr, byte *map, int len)
{
	if (ptr == NULL)
		return (1);

	int		row;
	int		col;
	byte	tmp;
	int		i;

	row = 0;
	col = 0;
	while (row < len)
	{
		col = 0;
		while (col < len)
		{
			if (ft_mapcheck(map, ptr, len) == 1)
			{
				map = ft_xormap(map, ptr, len);
				if (ft_solver(ptr->next, map, len))
					return (1);
				map = ft_xormap(map, ptr, len);
			}
			ptr = ft_shift_tetr(ptr, 1, 1, len);
			col++;
		}
		ptr = ft_shift_tetr(ptr, -1, len, len);
		i = len;
		while (i >= 1)
		{
			ptr->tetromin[i] = ptr->tetromin[i - 1];
			i--;
		}
		ptr->tetromin[i] = 0;
		row++;
	}
	ptr->tetromin = ft_null_tetramin(ptr->tetromin);
	i = 0;
	while (i < 4)
	{
		ptr->tetromin[i] = ptr->line[i];
		i++;
	}
	return (0);
}
