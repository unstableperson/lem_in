/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:31:30 by kfalia-f          #+#    #+#             */
/*   Updated: 2020/02/15 21:18:52 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Reading map from stdin and validation

#include <lem_in.h>

void	ft_validation(t_tb *table)
{
	unsigned int	lst_len;

	lst_len = ft_lst_lenght(table->map);
	ft_putnbr(table->map_len);
	ft_putchar('\n');
	ft_putnbr(table->room_num);
	//ft_putnbr(lst_len);
	
}

int		ft_str_valid(t_tb *table, char *str)
{
	if (table->flag != -1 && (str[0] == '\n' || str[0] == ' ' || str[0] == '\t'))
		return (0);
	if (table->flag  == -1)
	{
		if (ft_check_first(table, str) == 0)
			ft_error_input(table);
	}
	else if (table->flag == 0 || table->flag == 4)
		if (ft_check_room(table, str) == 0)
			ft_error_input(table);
	return (1);
}

void	ft_read_stdin(t_tb *table)
{
	char	*str;
	t_map	*tmp;

	str = NULL;
	table->map = ft_new_list(table);
	tmp = table->map;
	get_next_line(0, &str);
	while (str && *str != '\0')
	{
		if (!ft_str_valid(table, str))
			break ;
		tmp->cont = str;
		str = NULL;
		if (get_next_line(0, &str) > 0)
		{
			tmp->next = ft_new_list(table);
			tmp = tmp->next;
		}
	}
	ft_strdel(&str);
	table->head = table->map;
	ft_validation(table);
}
