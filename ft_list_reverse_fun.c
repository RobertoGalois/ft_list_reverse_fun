#include	<stdlib.h>
#include	"ft_list.h"

void	ft_swap(t_list **begin_list, t_list **temp_prev, t_list **temp_next, t_list *new_next)
{
	*temp_next = (*begin_list)->next;
	(*begin_list)->next = new_next;
	*temp_prev = (*begin_list);
	(*begin_list) = *temp_next;
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*temp_next;
	t_list	*temp_prev;

	if ((begin_list != NULL) && ((*begin_list) != NULL) && ((*begin_list)->next) != NULL)
	{
		ft_swap(begin_list, &temp_prev, &temp_next, NULL);

		while ((*begin_list)->next != NULL)
			ft_swap(begin_list, &temp_prev, &temp_next, temp_prev);

		(*begin_list)->next = temp_prev;
	}	
}


void	ft_swap_fun(t_list **ptr1, t_list **ptr2)
{
	t_list	temp_list;

	temp_list.data = (*ptr1)->data;
	temp_list.next = (*ptr1)->next;
	(*ptr1)->data = (*ptr2)->data;
	(*ptr1)->next = (*ptr2)->next;
	(*ptr2)->data = temp_list.data;
	(*ptr2)->next = temp_list.next;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*old_first_el;
	t_list	*old_next_first;
	t_list	*old_last_el;

	/* if the list isn't empty or has more than one element */
	if ((begin_list != NULL) && (begin_list->next != NULL))
	{
		old_first_el = begin_list;
		old_next_first = old_first_el->next;
		ft_list_reverse(&begin_list);
		old_last_el = begin_list;

		/* we link the before last element to the new last element (that was the first before) */
		old_next_first->next = old_last_el;

		/*we switch the content of the first el and the last el of the list */
		ft_swap_fun(&old_last_el, &old_first_el);
	}
}
