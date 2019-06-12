/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 20:59:52 by umoff             #+#    #+#             */
/*   Updated: 2019/05/21 14:34:23 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_ptr;

	if (!(new_ptr = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new_ptr->content = NULL;
		new_ptr->next = 0;
	}
	else
	{
		if ((new_ptr->content = malloc(content_size)) == NULL)
		{
			free(new_ptr);
			return (NULL);
		}
		ft_memcpy(new_ptr->content, content, content_size);
		new_ptr->content_size = content_size;
	}
	new_ptr->next = NULL;
	return (new_ptr);
}
