/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:45:16 by htekdemi          #+#    #+#             */
/*   Updated: 2025/03/09 22:45:16 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <signal.h>
# include <unistd.h>


static int  ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (sign * result);
}
static void	send_signal(pid_t id, char *message)
{
	int		i;
	int		j;
	char	result;

	i = 0;
	while (message[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			result = (message[i] >> j & 1);
			if (result == 1)
				kill(id, SIGUSR1);
			else if (result == 0)
				kill(id, SIGUSR2);
			usleep(142);
			j--;
		}
		i++;
	}
}
int	main(int argc, char *argv[])
{
	pid_t	server_id;
	int i;

	if (argc == 3)
	{
		i = 0;
		server_id = ft_atoi(argv[1]);
		while(argv[1][i] != '\0')
		{
			if(!(argv[1][i] >= '0' && argv[1][i] <= '9') || server_id <= 0)
			{
				write(1, "CHECK THE PİD NUMBER", 20);
				return(0);
			}
			i++;
		}
		send_signal(server_id, argv[2]);
	}
	else
		write(1, "SOMETHING IS MISSING CHECK THE SCREEN", 38);
	return (0);
}