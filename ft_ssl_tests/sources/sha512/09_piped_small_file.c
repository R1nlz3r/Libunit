/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_piped_small_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:54:59 by mapandel          #+#    #+#             */
/*   Updated: 2020/08/08 19:48:30 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		sha512_piped_small_file(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/sha512/09");
	system("touch trace/sha512/09/stdout00 trace/sha512/09/stdout01 \
trace/sha512/09/stderr00 trace/sha512/09/stderr01");

	ret_val = system("cat resources/small_file > resources/pipe | \
"FT_SSL_PATH "sha512 resources/pipe \
1> trace/sha512/09/stdout00 2> trace/sha512/09/stderr00");

	ret_val2 = system("cat resources/small_file > resources/pipe | \
openssl sha512 resources/pipe | sed 's/(/ (/g' | sed 's/)/) /g' \
1> trace/sha512/09/stdout01 2> trace/sha512/09/stderr01");

	leaks_ret_val = system("cat resources/small_file > resources/pipe | \
"FT_SSL_LEAK_REPORT_PATH "sha512 resources/pipe");
	system("mv leak_report trace/sha512/09/leak_report");

	if (system("diff trace/sha512/09/stdout00 trace/sha512/09/stdout01")
		|| system("diff trace/sha512/09/stderr00 trace/sha512/09/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
