/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_medium_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:17:27 by mapandel          #+#    #+#             */
/*   Updated: 2020/08/08 19:48:22 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "real_tests.h"

int		sha512_medium_file(void)
{
	int 	ret_val;
	int		ret_val2;
	int		leaks_ret_val;

	redirect_file_descriptors();

	system("mkdir -p trace/sha512/02");
	system("touch trace/sha512/02/stdout00 trace/sha512/02/stdout01 \
trace/sha512/02/stderr00 trace/sha512/02/stderr01");

	ret_val = system(FT_SSL_PATH "sha512 resources/medium_file \
1> trace/sha512/02/stdout00 2> trace/sha512/02/stderr00");

	ret_val2 = system("openssl sha512 resources/medium_file | \
sed 's/(/ (/g' | sed 's/)/) /g' \
1> trace/sha512/02/stdout01 2> trace/sha512/02/stderr01");

	leaks_ret_val = system(FT_SSL_LEAK_REPORT_PATH "sha512 resources/medium_file");
	system("mv leak_report trace/sha512/02/leak_report");

	if (system("diff trace/sha512/02/stdout00 trace/sha512/02/stdout01")
		|| system("diff trace/sha512/02/stderr00 trace/sha512/02/stderr01")
		|| ret_val != ret_val2 || leaks_ret_val)
		return (-1);
	return (0);
}
