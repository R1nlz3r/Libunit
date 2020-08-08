/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20_no_argument_small_binary_file.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:40:37 by mapandel          #+#    #+#             */
/*   Updated: 2020/08/08 19:48:54 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		sha512_no_argument_small_binary_file(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/sha512/20");
	system("touch trace/sha512/20/stdout00 trace/sha512/20/stdout01 \
trace/sha512/20/stderr00 trace/sha512/20/stderr01");

	ret_val = system("cat resources/small_binary_file | "FT_SSL_PATH "sha512 \
1> trace/sha512/20/stdout00 2> trace/sha512/20/stderr00");

	ret_val2 = system("cat resources/small_binary_file | openssl sha512 \
1> trace/sha512/20/stdout01 2> trace/sha512/20/stderr01");

	leaks_ret_val = system("cat resources/small_binary_file | \
"FT_SSL_LEAK_REPORT_PATH "sha512");
	system("mv leak_report trace/sha512/20/leak_report");

	if (system("diff trace/sha512/20/stdout00 trace/sha512/20/stdout01")
		|| system("diff trace/sha512/20/stderr00 trace/sha512/20/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
