/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_piped_small_binary_file.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:04:24 by mapandel          #+#    #+#             */
/*   Updated: 2020/02/25 00:15:16 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		sha256_piped_small_binary_file(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/sha256/12");
	system("touch trace/sha256/12/stdout00 trace/sha256/12/stdout01 \
trace/sha256/12/stderr00 trace/sha256/12/stderr01");

	ret_val = system("cat resources/small_binary_file > resources/pipe | \
"FT_SSL_PATH "sha256 resources/pipe \
1> trace/sha256/12/stdout00 2> trace/sha256/12/stderr00");

	ret_val2 = system("cat resources/small_binary_file > resources/pipe | \
openssl sha256 resources/pipe | sed 's/(/ (/g' | sed 's/)/) /g' \
1> trace/sha256/12/stdout01 2> trace/sha256/12/stderr01");

	leaks_ret_val = system("cat resources/small_binary_file > resources/pipe | \
"FT_SSL_LEAK_REPORT_PATH "sha256 resources/pipe");
	system("mv leak_report trace/sha256/12/leak_report");

	if (system("diff trace/sha256/12/stdout00 trace/sha256/12/stdout01")
		|| system("diff trace/sha256/12/stderr00 trace/sha256/12/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
