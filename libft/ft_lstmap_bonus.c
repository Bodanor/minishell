/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:28:25 by mfinette          #+#    #+#             */
/*   Updated: 2022/11/11 09:58:43 by mfinette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new_lst;
	t_list	*new_lst_1;

	if (!lst)
		return (0);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (0);
	new_lst_1 = new_lst;
	while (lst->next)
	{
		lst = lst->next;
		new_lst_1->next = ft_lstnew((f)(lst->content));
		if (!new_lst_1->next)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		new_lst_1 = new_lst_1->next;
	}
	return (new_lst);
}
