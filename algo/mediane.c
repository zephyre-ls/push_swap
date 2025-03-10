/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:13:20 by lduflot           #+#    #+#             */
/*   Updated: 2025/03/10 21:19:13 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Trouver le plus grand et le plus petit nombre de ma liste chaine.
// Trouver la mediane, celle_ci devient le 1er pivot.

#include "../push_swap.h"

// Recherche du plus grand/petit nombre de ma pile.a
// Mediane = 1er pivot.
int	mediane(t_pile *a)
{
	t_pile	*tmp;
	t_pile	*tmp_little;
	t_pile	*tmp_big;
	int		tmp_pivot;

	tmp = a;
	tmp_little = a;
	tmp_big = a;
	while (tmp)
	{
		if (tmp->val > tmp_big->val)
			tmp_big = tmp;
		else if (tmp->val < tmp_little->val)
			tmp_little = tmp;
		tmp = tmp->next;
	}
	tmp_pivot = (tmp_big->val - tmp_little->val);
	tmp_pivot = tmp_pivot / 2;
	tmp_pivot = (tmp_pivot + tmp_little->val);
//	printf("le pivot est: %d\n", tmp_pivot);
	return (tmp_pivot);
}

//quand 11 element dans .a le pivot devient le 3eme plus grand nombre de la liste
// permet d eviter le cas ou la mediane est plus grande que le 3eme plus grand element
int	pivot_10(t_pile *a)
{
	t_pile *tmp_a;
	int	first;
	int	second;
	int	third_pivot;

	tmp_a = a;
	first = 0;
	second = 0;
  while (tmp_a)
  {
		if (tmp_a->val > first)
    {
      third_pivot = second;
      second = first;
      first = tmp_a->val;
    }
    else if (tmp_a->val > second)
    {
      third_pivot = second;
      second = tmp_a->val;
    }
    else if (tmp_a->val > third_pivot)
			third_pivot = tmp_a->val;
    tmp_a = tmp_a->next;
    }
		return third_pivot ;
}


/*
* PROBLEME AVEC LA MEDIANE EN FIN DE TRIE : 19 -> 20 -> 21 -> 29 -> 33 -> 34 -> 35 -> 39 -> 40 -> 49 -> 52 -> 54 -> 69 -> 70 -> 71 -> 78 -> 80 -> 95 -> 98 -> 100 -> 106 -> 120 -> 124 -> 126 -> 134 -> 137 -> 142 -> 143 -> 147 -> 162 -> 167 -> 169 -> 173 -> 177 -> 184 -> 185 -> 186 -> 187 -> 195 -> 198 -> 212 -> 226 -> 228 -> 231 -> 250 -> 273 -> 275 -> 276 -> 301 -> 306 -> 327 -> 337 -> 339 -> 358 -> 360 -> 376 -> 379 -> 381 -> 393 -> 412 -> 419 -> 426 -> 444 -> 448 -> 455 -> 468 -> 484 -> 488 -> 496 -> 501 -> 518 -> 521 -> 562 -> 566 -> 625 -> 634 -> 635 -> 640 -> 648 -> 650 -> 651 -> 657 -> 663 -> 666 -> 673 -> 676 -> 679 -> 682 -> 687 -> 689 -> 690 -> 699 -> 707 -> 725 -> 730 -> 748 -> 752 -> 756 -> 772 -> 787 -> 798 -> 805 -> 808 -> 809 -> 828 -> 830 -> 852 -> 858 -> 869 -> 874 -> 892 -> 897 -> 901 -> 907 -> 913 -> 924 -> 927 -> 943 -> 889 -> 986 -> 999 -> 
*
* taille pivot 944
907 -> 913 -> 924 -> 892 -> 986 -> 901 -> 889 -> 999 -> 
taille a aprés opération: 8
907 -> 913 -> 924 -> 892 -> 986 -> 901 -> 889 -> 999 -> 
pb
taille pivot 944
913 -> 924 -> 892 -> 986 -> 901 -> 889 -> 999 -> 
taille a aprés opération: 7
913 -> 924 -> 892 -> 986 -> 901 -> 889 -> 999 -> 
pb
taille pivot 944
924 -> 892 -> 986 -> 901 -> 889 -> 999 -> 
taille a aprés opération: 6
924 -> 892 -> 986 -> 901 -> 889 -> 999 -> 
pb
taille pivot 944
892 -> 986 -> 901 -> 889 -> 999 -> 
taille a aprés opération: 5
892 -> 986 -> 901 -> 889 -> 999 -> 
*/
