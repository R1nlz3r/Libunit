/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <vcombey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 13:03:44 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/11 21:47:36 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic_tests.h"

int		ft_unit_lst_len(t_unit_test *lst)
{
	return ((lst == NULL) ? 0 : 1 + ft_unit_lst_len(lst->next));
}


int		main()
{
	int count;

	count = 0;
	ft_putendl("************************************");
	ft_putendl("**        42  - Unit Tests        **");
	ft_putendl("************************************");
	count += strlen_launcher();
	count += atoi_launcher();
	return (0);
}
