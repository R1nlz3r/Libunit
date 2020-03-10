/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_no_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 12:50:19 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/09 16:14:15 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		no_argument(void)
{
	int		ret_val;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/general_tests/01");
	system("touch trace/general_tests/01/stdout00 trace/general_tests/01/stdout01 \
trace/general_tests/01/stderr00 trace/general_tests/01/stderr01");

	ret_val = system(FT_SSL_PATH "\
1> trace/general_tests/01/stdout00 2> trace/general_tests/01/stderr00");

	system("echo \"usage: ft_ssl command [command opts] [command args]\" \
1> trace/general_tests/01/stderr01");

	leaks_ret_val = system(FT_SSL_LEAK_REPORT_PATH);
	system("cp leak_report trace/general_tests/01/leak_report");

	if (system("diff trace/general_tests/01/stdout00 \
trace/general_tests/01/stdout01")
		|| system("diff trace/general_tests/01/stderr00 \
trace/general_tests/01/stderr01")
		|| WEXITSTATUS(ret_val) != 1 || leaks_ret_val)
		return (-1);
	return (0);
}
