/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 08:56:49 by candriam          #+#    #+#             */
/*   Updated: 2024/07/28 14:03:15 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

	/* Compare deux strings */

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

	/* Affiche un message d'erreur et renvoie -1 */

int	puterror(char *msg)
{
	ft_putendl_fd(msg, 2);
	return (-1);
}

	/* Verifie si le nom de fichier q l'extension ".fdf" */

int	is_fdf_extension(const char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	return (ft_strcmp(&filename[len - 4], ".fdf") == 0);
}

	/* Verifie si un caractere est un chiffre hexadecimal */

int	ft_isxdigit(int c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

	/* Convertit une chaine de caracteres hexa en entier */

int	ft_htoi(const char *str)
{
	int		value;
	char	digit;

	value = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	while (*str && ft_isxdigit(*str))
	{
		digit = *str++;
		if (digit >= '0' && digit <= '9')
			value = value * 16 + (digit - '0');
		else if (digit >= 'a' && digit <= 'f')
			value = value * 16 + (digit - 'a' + 10);
		else if (digit >= 'A' && digit <= 'F')
			value = value * 16 + (digit - 'A' + 10);
		else
			break ;
	}
	return (value);
}
