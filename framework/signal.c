/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 07:31:51 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/12 07:42:56 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void			ft_segfault(int sig)
{
	(void)sig;
	ft_putendl("\033[31m[SEGV]\033[0m");
	exit(1);
}

void 			ft_buseror(int sig)
{
	(void)sig;
	ft_putendl("\033[31m[BUSE]\033[0m");
	exit(1);
}
