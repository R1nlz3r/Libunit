/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   24_no_argument_empty_file.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:40:57 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/06 16:51:20 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		sha256_no_argument_empty_file(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/sha256/24");
	system("touch trace/sha256/24/stdout00 trace/sha256/24/stdout01 \
trace/sha256/24/stderr00 trace/sha256/24/stderr01");

	ret_val = system("cat resources/empty_file | "FT_SSL_PATH "sha256 \
1> trace/sha256/24/stdout00 2> trace/sha256/24/stderr00");

	ret_val2 = system("cat resources/empty_file | openssl sha256 \
1> trace/sha256/24/stdout01 2> trace/sha256/24/stderr01");

	leaks_ret_val = system("cat resources/empty_file | \
"FT_SSL_LEAK_REPORT_PATH "sha256");
	system("mv leak_report trace/sha256/24/leak_report");

	if (system("diff trace/sha256/24/stdout00 trace/sha256/24/stdout01")
		|| system("diff trace/sha256/24/stderr00 trace/sha256/24/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
