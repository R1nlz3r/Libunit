/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   25_multiple_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 06:30:37 by mapandel          #+#    #+#             */
/*   Updated: 2020/08/08 19:49:00 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		sha512_multiple_files(void)
{
	int		ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/sha512/25");
	system("touch trace/sha512/25/stdout00 trace/sha512/25/stdout01 \
trace/sha512/25/stderr00 trace/sha512/25/stderr01");

	ret_val = system(FT_SSL_PATH "sha512 resources/small_file \
resources/medium_file resources/large_file resources/empty_file \
1> trace/sha512/25/stdout00 2> trace/sha512/25/stderr00");

	ret_val2 = system("openssl sha512 resources/small_file \
resources/medium_file resources/large_file resources/empty_file | \
sed 's/(/ (/g' | sed 's/)/) /g' \
1> trace/sha512/25/stdout01 2> trace/sha512/25/stderr01");

	leaks_ret_val = system(FT_SSL_LEAK_REPORT_PATH "sha512 resources/small_file \
resources/medium_file resources/large_file resources/empty_file");
	system("mv leak_report trace/sha512/25/leak_report");

	if (system("diff trace/sha512/25/stdout00 trace/sha512/25/stdout01")
		|| system("diff trace/sha512/25/stderr00 trace/sha512/25/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
