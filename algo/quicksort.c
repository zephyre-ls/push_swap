/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:11:58 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/26 00:50:19 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Etape 2: pile_b est trié de maniere croissante (pour le moment reussir à la mettre décroissante)
//Maintenant il faut retrier la pile_a.
//Pour cela on va refaire une mediane entre max et min pile.a 
// > du deuxieme pivot ca ira sur la pile.b (vu qu'elle sera décroissante cela sera trier automatiquement)
// Et on refait ca jusqu'à ce que la pile a ne comporte plus qu'un nombre
// Aprés cela on repush tout b dans a 
// ET VOILA CST TRIE
// Aprés reste l'affichage des instructions et voir le nbr de coup si c'est ok ok. 
//
void    quick_sort(t_pile **a, t_pile **b)
{
	int	size_a;

	while ((size_a = ft_lstsize(*a)) > 3)
  {
		comparaison_pivot_1(a, b);
    //  print_pile(*a);
		//	print_pile(*b);
  }
	if (ft_lstsize(*a) == 3)
	{
//		print_pile(*a);
		tri_3_elements(a);
//		print_pile(*a);
	}
  // Une fois qu'il ne reste que 3 élément dans A, on push B vers A
  while (*b)
	{
		ft_push_pa(a, b);
	/*	printf("fin push a\n");
		print_pile(*a);
		print_pile(*b);	*/
	}
//	ft_reverse_rotate_rra(a);
}
 void	tri_3_elements(t_pile **a)
{
	int first = (*a)->val;
	int second = (*a)->next->val;
	int third = (*a)->next->next->val;

	printf("Avant tri3 : ");
	print_pile(*a);

	if (first > second && second < third && first < third)
		ft_swap_sa(a); // Cas 213 -> devient 123
	else if (first > second && second > third)
	{
		ft_swap_sa(a); // Cas 321 -> devient 231
		ft_reverse_rotate_rra(a); // 231 -> 123
	}
	else if (first > second && second < third && first > third)
		ft_rotate_ra(a); // Cas 312 -> devient 123
	else if (first < second && second > third && first < third)
	{
		ft_swap_sa(a); // Cas 132 -> devient 123
		ft_rotate_ra(a);
	}
	else if (first < second && second > third && first > third)
		ft_reverse_rotate_rra(a); // Cas 231 -> devient 123

//	printf("Après tri3 : ");
//	print_pile(*a);
}

/*void	tri_3_elements(t_pile **a)
{
  int first = (*a)->val;
  int second = (*a)->next->val;
	int third = (*a)->next->next->val;
// Si le premier est plus grand que le second
	printf("bien rentré trie3");
	if (first > second)
		ft_swap_sa(a);
	print_pile(*a);
// Si le premier est plus grand que le troisième après swap
  first = (*a)->val;
  second = (*a)->next->val;
	third = (*a)->next->next->val;
  if (first > third)
    ft_rotate_ra(a);
	print_pile(*a);
// Si le second est plus grand que le troisième 
	first = (*a)->val;
  second = (*a)->next->val;
  third = (*a)->next->next->val;
  if (second > third)
		ft_reverse_rotate_rra(a);
	print_pile(*a);
}*/
