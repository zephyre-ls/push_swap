/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:56:23 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/07 10:25:50 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//exemple pile_a : [2] [4] [1] NULL
//
//		2		4
//		4		1
//		1		2
//		a		a=ra 

void	ft_rotate_ra(pile **a)
{
	pile	*tmp_a;

	tmp_a = *a; //recup 1er noeud tmp_a = [2]
	*a = (*a)->next; //supp 1er noeud et passe au suivant a = [4]
	tmp_a->next=NULL;
	ft_lstadd_back(a, tmp_a); //remplace le dernier noeud par le premier 
}

void	ft_rotate_rb(pile **b)
{
	pile	*tmp_b;
	t
	tmp_b = *b;
	*b = (*b)->next; //() permet de garder l'ordre des operations correcte, si abs = *a =*a->next cc *a=*(a->next)
	tmp_b->next=NULL;
	ft_lstadd_back(b, tmp_b);
}

void	ft_rotate_rr(pile **a, pile **b)
{
	pile	*tmp_a;
	pile	*tmp_b;

	tmp_a = *a;
	*a = (*a)->next;
	tmp_a->next=NULL;
	ft_lstadd_back(a, tmp_a);

	tmp_b = *b;
	*b = (*b)->next;
	tmp_b->next=NULL;
	ft_lstadd_back(b, tmp_b);
}

int main(void)
{
	pile *a = NULL;

	// Création de la pile
	pile *n1 = malloc(sizeof(pile));
	pile *n2 = malloc(sizeof(pile));
	pile *n3 = malloc(sizeof(pile));

	if (!n1 || !n2 || !n3)
		return (1);

	n1->value = 2;
	n2->value = 4;
	n3->value = 1;
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
	a = n1;

	// Affichage avant rotation
	printf("Avant rotation:\n");
	print_pile(a);

	// Effectuer la rotation
	ft_rotate_ra(&a);

	// Affichage après rotation
	printf("Après rotation:\n");
	print_pile(a);

	// Libération de la mémoire
	free(n1);
	free(n2);
	free(n3);

	return (0);
}
