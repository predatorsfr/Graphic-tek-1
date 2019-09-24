/*
** EPITECH PROJECT, 2017
** my atoi
** File description:
** raphael.dubois@epitech.eu
*/

int	my_atoi(char *nbr)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (nbr[i] >= '0' && nbr[i] <= '9') {
		res = res * 10 + nbr[i] - 48;
		i = i + 1;
	}
	return (res);
}
