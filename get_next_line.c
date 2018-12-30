/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:01:28 by ndelhomm          #+#    #+#             */
/*   Updated: 2018/12/20 18:14:09 by ndelhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** >> On rentre dans cette fonction uniquement si :
** - on lit un "\n";
** - ou si RET = 0 #finDeLecture et que STR[0] != NULL.
**
** >> Dans notre ex, on rentre ici 2 fois
** >> UNE PREMIERE FOIS avec STR = 'SA\nP'
** >> WHILE (STR[i++]) > on va avancer jusque STR[2] = '\nP'
** >> On a rencontre un \n donc on sort du while et on rentre dans le IF (\n)
** >> LINE = STRSUB("SA\nP", 0, I = 2) = 'SA'
** >> TMP = STRDUP(STR[I+1]) = STRDUP(STR[3]) = 'P'
** >> FREE(STR)
** >> STR[FD] = TMP = 'P'
**
** >> On entre dans le IF('\0') > STRDEL ssi le '\n' est le dernier char de STR
** >> Ce n'est pas le cas dans notre exemple, car apres le \n il y a 'P'
**
** >> On RETURN(1) : la ligne 'SA' a ete lue
**
** >> UNE DEUXIEME FOIS avec STR = 'PINS'
** >> WHILE (STR[i++]) > on va avancer jusque STR[4] = \0
** >> On a rencontre un \0 donc on sort du while et on rentre dans le IF (\0)
** >> LINE = STRDUP(STR[FD]) = STRDUP['PINS'] = 'PINS'
** >> On FREE str[fd] (strdel prend un double pointeur
** (C'est pour ca que j'envoie l'adresse)
**
** >> On RETURN(1) : la ligne 'PINS' a ete lue
*/

int		get_line(int fd, char **line, char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	else if (str[fd][i] == '\n')
	{
		*line = ft_strsub(str[fd], 0, i);
		tmp = ft_strdup(&str[fd][i + 1]);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	return (1);
}

/*
** >> B_S = 2   TXT = 'SA\nPINS'   RET = 2   BUF = 'SA'  STR = NULL
** >> RET : tant qu'on read au moins 1 octet
** >> STR(FD) : est a NULL au debut, quand elle passe dans le IF, on l'init a ''
** >> TMP : strjoin() de BUF = 'SA' et STR(FD) = '' donc TMP = 'SA'
** >> free(STR(FD)) : STR(FD) = ''
** >> STR(FD) = TMP : STR(FD) = 'SA'
** >> BUF = 'SA' : il n'y a pas de BSN, on ne rentre pas dans le if(strchr())
**
** >> ON REFAIT UN TOUR DANS WHILE
** >> RET = 2    BUF = '\nP'  STR = 'SA'
** >> STR = TMP = SRTJOIN('SA' '\nP') = 'SA\nP'
** >> ON RENTRE DANS LE IF strchr '\n' car il y a un '\n'
** >> BREAK, ON SORT DU WHILE
** >> RET = 2, donc on va rentrer dans notre RETURN(funct())
**
** >> BUF = 'IN'   RET = 2  STR = 'P'
** >> TMP = 'P' + 'IN' = 'PIN'
** >> STR = TMP = 'PIN'
** >> On recommence la boucle while car pas de \n
**
** >> RET = 1   BUF = 'S?'  STR = 'PIN'
** >> BUF[RET] = BUF[1] = ? ==> '\0'
** >> BUF[RET] = '\0' sert des que le B_S est sup au nbre d'octets lus
** >> TMP = 'PIN' + 'S' = 'PINS'
** >> STR = 'PINS'
** >> On recommence la boucle while car pas de \n
**
** >> OR, RET = 0 car il n'y a plus R a lire,
** >> On sort du while
** >> On ne rentre pas dans le else if car STR != NULL et STR[0] = 'P'
** >> Du coup, on va rentrer dans RETURN(funct())
**
** >> On revient dans G_N_L
** >> A ce stade, RET = 0 et STR = NULL, on return 0, la lecture est terminee.
*/

int		get_next_line(const int fd, char **line)
{
	static char		*str[1];
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*tmp;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (get_line(fd, line, str));
}
