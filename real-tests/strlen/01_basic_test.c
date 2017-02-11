/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 11:45:18 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/11 12:09:50 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		basic_test(void)
{
	char	test[20];

	test = "Les roses sont roses";
	if (strlen(test) == ft_strlen(test))
		return (0);
	else
		return (-1);
}
