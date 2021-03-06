/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcombey <vcombey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 13:20:55 by vcombey           #+#    #+#             */
/*   Updated: 2017/02/12 21:12:12 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REAL_TESTS_H
# define REAL_TESTS_H

# include "../framework/libunit.h"

int		ft_unit_lst_len(t_unit_test *lst);

int		strlen_launcher(void);
int		basic_test(void);
int		medium_test(void);
int		hard_test(void);

int		atoi_launcher(void);
int		void_test(void);
int		basic_test_1(void);
int		basic_test_2(void);
int		basic_test_3(void);
int		basic_test_4(void);
int		space_test_1(void);
int		space_test_2(void);
int		error_test_1(void);
int		error_test_2(void);
int		tab_test(void);
int		intmin_test(void);
int		intmax_test(void);

int		putchar_launcher(void);
int		basic_test_putchar(void);
int		backslash_test_putchar(void);

#endif
