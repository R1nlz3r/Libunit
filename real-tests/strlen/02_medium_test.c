/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_medium_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:03:51 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/11 12:12:02 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		medium_test(void)
{
	char	test[50000];

	test = ft_strfill(test, 'a', 50000);
	if (strlen(test) == ft_strlen(test))
		return (0);
	else
		return (-1);
}
