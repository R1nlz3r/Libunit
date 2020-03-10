/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 11:46:52 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/10 14:34:03 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "libunit.h"

int		ft_unit_lst_len(t_unit_test *lst);

int		tests_launcher(void);
int		ok_test(void);
int		ko_test(void);
int		segfault_test(void);
int		bus_error_test(void);
int		abort_test(void) __attribute__((noreturn));
int		floating_point_exception_test(void);
int		timeout_test(void) __attribute__((noreturn));

#endif
