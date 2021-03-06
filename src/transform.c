/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <rsticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:56:32 by rsticks           #+#    #+#             */
/*   Updated: 2020/01/24 17:08:14 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		transform(t_printf *prnt)
{
	if (FORM_D_I == (prnt->flags & FORM_D_I))
		ft_intger(prnt);
	else if (FORM_U == (prnt->flags & FORM_U))
		u_intger(prnt);
	else if (FORM_O == (prnt->flags & FORM_O))
		o_intger(prnt);
	else if (FORM_X == (prnt->flags & FORM_X) ||
	FORM_XX == (prnt->flags & FORM_XX))
		x_intger(prnt);
	else if (FORM_C == (prnt->flags & FORM_C))
		ft_char(prnt);
	else if (FORM_SS == (prnt->flags & FORM_SS))
		ft_str(prnt);
	else if (FORM_P == (prnt->flags & FORM_P))
		ft_ptr(prnt);
	else if (FORM_N == (prnt->flags & FORM_N))
		ft_ptr_n(prnt);
	else if (FORM_F == (prnt->flags & FORM_F))
		ft_flt_get(prnt);
}
