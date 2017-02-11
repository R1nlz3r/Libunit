/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:39:05 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/11 17:06:45 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libunit.h"
#include "../libft/libft.h"
#include <unistd.h>

t_unit_test		*unit_test_new(char	*name, int (*f) (void))
{
	t_unit_test	*new;

	if (!(new = (t_unit_test*)malloc(sizeof(t_unit_test))))
		return (NULL);
	new->name = name;
	new->f = f;
	return (new);
}

void			load_test(t_unit_test	**testlist, char *name, int (*f) (void))
{
	t_unit_test	*new;

	new = unit_test_new(name, f);
	new->next = *testlist;
	*testlist = new;
}

int				exec_test(int (*f) (void))
{
	pid_t	father;
	int		*res;

	res = (int *)malloc(sizeof(int));
	*res = -42;
	father = fork();
	if (father == 0)
	{
		*res = f();
		exit (*res);
	}
	if (father > 0)
	{
		wait (res);
		ft_putnbr(*res);
	}
	return (*res);
}

int				launch_tests(t_unit_test **testlist)
{
	int				count;
	t_unit_test		*tmp;
	int				res;

	(void)res;
	count = 0;
	tmp = *testlist;
	while (tmp)
	{
		ft_putstr("    > ");
		ft_putstr(tmp->name);
		ft_putstr(" : ");
		res = exec_test(tmp->f);
		if (res == 0)
		{
			ft_putendl("\033[32m[OK]\033[0m");
			count++;
		}
		else if (res == -1)
			ft_putendl("\033[31m[KO]\033[0m");
		tmp = tmp->next;
	}
	return (count);
}
