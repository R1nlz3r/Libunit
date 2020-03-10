/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_dev_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:31:41 by mapandel          #+#    #+#             */
/*   Updated: 2020/03/06 16:54:43 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		sha256_dev_null(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/sha256/07");
	system("touch trace/sha256/07/stdout00 trace/sha256/07/stdout01 \
trace/sha256/07/stderr00 trace/sha256/07/stderr01");

	ret_val = system(FT_SSL_PATH "sha256 /dev/null \
1> trace/sha256/07/stdout00 2> trace/sha256/07/stderr00");

	ret_val2 = system("openssl sha256 /dev/null | \
sed 's/(/ (/g' | sed 's/)/) /g' \
1> trace/sha256/07/stdout01 2> trace/sha256/07/stderr01");

	leaks_ret_val = system(FT_SSL_LEAK_REPORT_PATH "sha256 resources/dev_null");
	system("mv leak_report trace/sha256/07/leak_report");

	if (system("diff trace/sha256/07/stdout00 trace/sha256/07/stdout01")
		|| system("diff trace/sha256/07/stderr00 trace/sha256/07/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
