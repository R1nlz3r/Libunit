/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_invalid_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 03:36:16 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/09 16:14:41 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		invalid_command(void)
{
	int		ret_val;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/general_tests/02");
	system("touch trace/general_tests/02/stdout00 \
trace/general_tests/02/stdout01 trace/general_tests/02/stderr00 \
trace/general_tests/02/stderr01");

	ret_val = system(FT_SSL_PATH "foobar \
1> trace/general_tests/02/stdout00 2> trace/general_tests/02/stderr00");

	system("echo \"ft_ssl: Error: 'foobar' is an invalid command.\n\n\
Standard commands:\n\n\
Message Digest commands:\n\
md5\n\
sha256\n\n\
Cipher commands:\" \
1> trace/general_tests/02/stderr01");

	leaks_ret_val = system(FT_SSL_LEAK_REPORT_PATH "foobar");
	system("mv leak_report trace/general_tests/02/leak_report");

	if (system("diff trace/general_tests/02/stdout00 trace/general_tests/02/stdout01")
		|| system("diff trace/general_tests/02/stderr00 trace/general_tests/02/stderr01")
		|| WEXITSTATUS(ret_val) != 1 || leaks_ret_val)
		return (-1);
	return (0);
}
