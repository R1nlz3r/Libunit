/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 12:04:05 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/18 03:00:57 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int		ft_unit_lst_len(t_unit_test *lst)
{
	return ((lst == NULL) ? 0 : 1 + ft_unit_lst_len(lst->next));
}

int		main(void)
{
	int count;

	count = 1;
	ft_putstr("---\n\n");
	ft_putendl("************************************");
	ft_putendl("**    42  - Unit Tests (tests)    **");
	ft_putendl("************************************");
	count = (count && tests_launcher());
	return (count == 1? 0 : -1);
}
