/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrisset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 13:46:21 by jbrisset          #+#    #+#             */
/*   Updated: 2019/01/03 14:30:42 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_min_size(int tetri_nb)
{
	int	size;

	size = 2;
	while (tetri_nb * 4 > size * size)
		size++;
	return (size);
}

int	allocate_square(char ***square, int size)
{
	int	i;
	int	j;

	i = 0;
	if (!(square = (char **)malloc(sizeof(char *) * size)))
		return (0);
	while (i < size && i++)
	{
		j = 0;
		if (!(square[i] = ft_strnew(size)))
		{
			free(square);
			return (0);
		}
		while (j < size && j++)
			square[i][j] = '.';
	}
	return (1);
}

















