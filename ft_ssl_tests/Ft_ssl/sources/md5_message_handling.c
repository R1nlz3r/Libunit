/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_message_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 02:54:23 by mapandel          #+#    #+#             */
/*   Updated: 2020/02/21 04:49:09 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
**	md5_message_buffer_preparation:
**
*/

static unsigned char		*md5_message_buffer_preparation(t_input *input,
	unsigned char *static_buffer)
{
	size_t					pad_len;
	size_t					bit_len;

	pad_len = 64 - ((input->msg_len + 9) % 64);
	if (pad_len == 64)
		pad_len = 0;

	if (!(static_buffer = (unsigned char*)ft_strnew(input->msg_len
		+ (size_t)9 + pad_len)))
		return (NULL);
	ft_memcpy(static_buffer, input->msg, input->msg_len);

	((char*)static_buffer)[input->msg_len] = -128;

	bit_len = input->msg_total_len * 8;
	ft_memcpy(static_buffer + input->msg_len + 1 + pad_len, &bit_len, 8);

	return (static_buffer);
}


/*
**	md5_message_buffer_handling:
**
*/

static int		md5_message_buffer_handling(t_input *input, int bool_dump)
{
	static unsigned char	*static_buffer = NULL;

	if (bool_dump)
	{
		ft_strdel((char**)&static_buffer);
		static_buffer = NULL;
	}
	else if (!static_buffer)
	{
		static_buffer = md5_message_buffer_preparation(input, static_buffer);
		if (!(input->flags & FLAG_S))
			ft_strdel((char**)&input->msg);
		input->msg = ft_memdup(static_buffer, 64);
	}
	else
	{
		if (input->msg_len < 55)
			input->msg_len = 0;
		else
			input->msg_len -= 55;
		ft_strdel((char**)&input->msg);
		input->msg = ft_memdup(static_buffer + 64, 64);
	}

	return (0);
}


/*
**	md5_message_obtaining:
**
*/

int 			md5_message_obtaining(t_input *input)
{
	if ((input->flags & FLAG_S))
	{
		if (!(input->msg))
		{
			input->msg_len = input->msg_total_len;
			input->msg = (unsigned char*)input->input;
		}
		else
		{
			if (input->msg_len > 64 && (input->msg_len -= 64))
				input->msg += 64;
			else
				input->msg_len = 0;
		}
	}
	else
	{
		input->msg_len = 0;
		input->msg = get_file_segment(input->fd, 64, (ssize_t*)&input->msg_len);
		input->msg_total_len += input->msg_len;
		if ((ssize_t)input->msg_len == -1)
			return (1);
		else if (!input->msg_len)
			ft_strdel((char**)&input->msg);
	}

	if (input->flags & FLAG_P)
		write(1, input->msg, input->msg_len);

	if (input->msg_len < 64)
		return (md5_message_buffer_handling(input, 0));

	return (0);
}


/*
**	md5_message_dumping:
**
*/

int				md5_message_dumping(t_input *input)
{
	if (!(input->flags & FLAG_S))
		ft_strdel((char**)&input->msg);

	// Dumps the static string
	if (input->msg_len < 55)
	{
		md5_message_buffer_handling(input, 1);
		return (1);
	}

	return (0);
}
