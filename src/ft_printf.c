/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:57:15 by rsticks           #+#    #+#             */
/*   Updated: 2019/12/03 18:28:52 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					putchar_and_count(t_printf *prnt, char c)
{
	prnt->buff[prnt->count] = c;
	prnt->count++;
}

void		parser(t_printf *prnt)
{
	prnt->count = 0;
	prnt->width = 0;
	prnt->accuracy = 0;

	while (*prnt->format != '\0')
	{
		if (*prnt->format == '%')
		{
			if (PRO_TRUE == (prnt->flags & PRO_TRUE)  && (FORM_TRUE != (prnt->flags & FORM_TRUE)))
			{
				prnt->format++;
				prnt->flags = 0;
				putchar_and_count(prnt, '%');
				continue;
			}
			if (DOUBLE_PRO != (prnt->flags & DOUBLE_PRO))
			{
				if_procent(prnt);
				if (FORM_TRUE == (prnt->flags & FORM_TRUE))
					prnt->flags = 0;				
				continue;
			}
			else
			{
				prnt->format++;
			}
		}
		else
		{
			putchar_and_count(prnt, *prnt->format);
		}
		if (*prnt->format != '\0' && *prnt->format != '%')
			prnt->format++;
	}
	va_end(prnt->arg);
}


int	ft_printf(const char *format, ...)
{
	t_printf	*prnt;

	prnt = (t_printf*)malloc(sizeof(t_printf));
	prnt->flags = 0;
	prnt->format = format; 
	prnt->buff = (char*)malloc(sizeof(char) * 255);
	va_start(prnt->arg, format);
	parser(prnt);
	write(1, prnt->buff, prnt->count);
	return(prnt->count);
}