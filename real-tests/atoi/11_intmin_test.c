/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_intmin_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 13:23:15 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/11 13:25:40 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		intmin_test(void)
{
	if (atoi("-2147483648") == ft_atoi("-2147483648"))
		return (0);
	else
		return (-1);
}
