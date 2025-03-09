/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:45:21 by htekdemi          #+#    #+#             */
/*   Updated: 2025/03/09 22:45:21 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <signal.h>
# include <unistd.h>

static void ft_writepid(pid_t a)
{
	char c;
 
	if(a > 9)
	{
		ft_writepid((a / 10));
		ft_writepid((a % 10));
	}
	else
	{
		c = 48 + a;
		write(1,&c,1);
	}
}

static void	signal_adder(int signal)
{
	static char	chr;
	static int i;

	if(signal == SIGUSR1)
		chr = chr | 1;
	i++;
	if (i == 8)
	{
		write(1, &chr, 1);
		i = 0;
		chr = 0;
	}
	chr = chr << 1;
}

int main(void)
{
    pid_t server_id;

    server_id = getpid();
	write(1, "\x1b[32m Pid: \x1b[0m" ,15);
    ft_writepid(server_id);
	write(1, "\n", 1);
	signal(SIGUSR1, signal_adder);
	signal(SIGUSR2, signal_adder);
	while (1)
	{
		pause();
	}
	return (0);
}
