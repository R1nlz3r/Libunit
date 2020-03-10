/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <vcombey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:39:05 by vcombey           #+#    #+#             */
/*   Updated: 2020/02/21 18:35:00 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void			redirect_file_descriptors(void)
{
	int		p[2];

	pipe(p);
	dup2(p[1], 1);
	dup2(p[1], 2);
}

static t_unit_test		*unit_test_new(char *name, int (*f)(void))
{
	t_unit_test	*new;

	if (!(new = (t_unit_test*)malloc(sizeof(t_unit_test))))
		return (NULL);
	new->name = name;
	new->f = f;
	return (new);
}

void			load_test(t_unit_test **testlist, char *name, int (*f)(void))
{
	t_unit_test	*new;

	new = unit_test_new(name, f);
	new->next = *testlist;
	*testlist = new;
}

static int		print_result(pid_t father)
{
	if (WIFEXITED(father))
	{
		if (father == 0)
		{
			ft_putendl("\033[32m[OK]\033[0m");
			return (1);
		}
		else if (father == 256)
			ft_putendl("\033[31m[KO]\033[0m");
	}
	if (WIFSIGNALED(father))
	{
		if (WTERMSIG(father) == SIGALRM)
			ft_putendl("\033[31m[TIME]\033[0m");
		if (WTERMSIG(father) == SIGSEGV)
			ft_putendl("\033[31m[SIGV]\033[0m");
		if (WTERMSIG(father) == SIGBUS)
			ft_putendl("\033[31m[BUSE]\033[0m");
		if (WTERMSIG(father) == SIGABRT)
			ft_putendl("\033[31m[SIGA]\033[0m");
		if (WTERMSIG(father) == SIGFPE)
			ft_putendl("\033[31m[FPTE]\033[0m");
	}
	return (0);
}

static int		exec_test(int (*f) (void))
{
	pid_t	father;

	father = fork();
	if (father == 0)
	{
		alarm(20);
		if (f() == 0)
			exit(0);
		exit(1);
	}
	if (father > 0)
		wait(&father);
	return (print_result(father));
}

int				launch_tests(t_unit_test **testlist)
{
	int				count;
	t_unit_test		*tmp;

	count = 0;
	tmp = *testlist;
	while (tmp)
	{
		ft_putstr("    > ");
		ft_putstr(tmp->name);
		ft_putstr(" : ");
		count += exec_test(tmp->f);
		tmp = tmp->next;
	}
	return (count);
}
