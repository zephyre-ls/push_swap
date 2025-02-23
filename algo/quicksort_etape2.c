/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_etape2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:11:58 by lduflot           #+#    #+#             */
/*   Updated: 2025/02/23 18:14:18 by lduflot          ###   ########.fr       */
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
