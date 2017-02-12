/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 11:46:52 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/12 12:20:32 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "../framework/libunit.h"

int		ft_unit_lst_len(t_unit_test *lst);

int		tests_launcher(void);
int		ok_test(void);
int		ko_test(void);
int		segfault_test(void);

#endif
