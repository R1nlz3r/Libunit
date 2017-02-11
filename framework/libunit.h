/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:34:53 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/11 13:27:04 by vcombey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

typedef struct			s_unit_test
{
	char				*name;
	int					(*f) (void);
	struct s_unit_test	*next;
}						t_unit_test;

void					load_test(t_unit_test	**testlist, char *name, int (*f) (void));
int						launch_tests(t_unit_test **testlist);

#endif
