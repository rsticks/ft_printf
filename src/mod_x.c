/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:16:46 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/24 17:16:50 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char					*mod_l(t_printf *prnt)
{
	char					*c;
	unsigned long long int	ln;

	ln = 0;
	ln = va_arg(prnt->arg, unsigned long int);
	c = ft_dec_to(ln, 16, prnt);
	return (c);
}

static char					*mod_ll(t_printf *prnt)
{
	char					*c;
	unsigned long long int	ln;

	ln = 0;
	ln = va_arg(prnt->arg, unsigned long long int);
	c = ft_dec_to(ln, 16, prnt);
	return (c);
}

static char					*mod_h(t_printf *prnt)
{
	char					*c;
	unsigned long long int	ln;

	ln = 0;
	ln = (unsigned short int)va_arg(prnt->arg, unsigned int);
	c = ft_dec_to(ln, 16, prnt);
	return (c);
}

char						*x_modificator(t_printf *prnt)
{
	char					*c;
	unsigned long long int	ln;

	ln = 0;
	if (MOD_L == (prnt->flags & MOD_L))
		c = mod_l(prnt);
	else if (MOD_LL == (prnt->flags & MOD_LL))
		c = mod_ll(prnt);
	else if (MOD_H == (prnt->flags & MOD_H))
		c = mod_h(prnt);
	else if (MOD_HH == (prnt->flags & MOD_HH))
	{
		ln = (unsigned char)va_arg(prnt->arg, unsigned int);
		c = ft_dec_to(ln, 16, prnt);
	}
	else
	{
		ln = va_arg(prnt->arg, unsigned int);
		c = ft_dec_to(ln, 16, prnt);
	}
	return (c);
}
