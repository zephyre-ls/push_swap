/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:11:58 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/25 14:28:05 by lduflot          ###   ########.fr       */
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
    int size_a;
    
    while ((size_a = ft_lstsize(*a)) > 1)
    {
        comparaison_pivot_1(a, b);
      //  print_pile(*a);
			//	print_pile(*b);
    }
    // Une fois qu'il ne reste qu'un élément dans A, on push B vers A
    while (*b)
        ft_push_pa(a, b);
		ft_reverse_rotate_rra(a);
		
}
