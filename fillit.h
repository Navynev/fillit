/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:47:23 by ndelhomm          #+#    #+#             */
/*   Updated: 2019/01/03 14:31:24 by jbrisset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

struct item {
	int		height;
	int		width;
	char	**tetri;
	int		x;
	int		y;
};

struct item items[26];

#endif



















