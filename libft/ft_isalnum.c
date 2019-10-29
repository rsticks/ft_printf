/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:31:42 by rsticks           #+#    #+#             */
/*   Updated: 2019/04/18 18:22:47 by rsticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalnum(int ch)
{
	return ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)
			|| (ch >= '0' && ch <= '9'));
}
