/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:57:15 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/21 19:11:14 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
static void					init_prnt(t_printf *prnt)
{
	prnt->herna = 0;
	prnt->width = 0;
	prnt->accuracy = -2;
	prnt->flags = 0;
}

void					putchar_and_count(t_printf *prnt, char c)
{
	if (prnt->count % 255 == 0 && prnt->count != 0)
		write(1, prnt->buff, 255);
	prnt->buff[prnt->count % 255] = c;
	prnt->count++;
}

void		parser(t_printf *prnt)
{
	prnt->count = 0;
	prnt->width = 0;
	prnt->accuracy = -2;

	while (*prnt->format != '\0')
	{
		if (*prnt->format == '%')
		{
			if (PRO_TRUE == (prnt->flags & PRO_TRUE)  && (FORM_TRUE != (prnt->flags & FORM_TRUE)))
			{
				prnt->format++;
				putchar_and_count(prnt, '%');
				if ((prnt->width != 0) && (FLAG_MINUS == (prnt->flags & FLAG_MINUS)))
				{
					prnt->herna = 1;
					prnt->width--;
					unsigned_process_width(prnt, "\0");
				}
				init_prnt(prnt);
				continue;
			}
			if (DOUBLE_PRO != (prnt->flags & DOUBLE_PRO))
			{
				if_procent(prnt);
				if (FORM_TRUE == (prnt->flags & FORM_TRUE))
					init_prnt(prnt);				
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
	int			count;
	t_printf	*prnt;

	prnt = (t_printf*)malloc(sizeof(t_printf));
	prnt->flags = 0;
	prnt->format = format; 
	prnt->buff = (char*)malloc(sizeof(char) * 255);
	va_start(prnt->arg, format);
	parser(prnt);
	if (prnt->count % 255 == 0 && prnt->count != 0)
		write(1, prnt->buff, 255);
	else
		write(1, prnt->buff, (prnt->count % 255));
	ft_strdel(&prnt->buff);
	count = prnt->count;
	free(prnt);
	prnt = NULL;
	return(count);
}