/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ucivelek <ucivelek@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:52:13 by ucivelek          #+#    #+#             */
/*   Updated: 2022/05/18 12:55:10 by ucivelek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int	a;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		n = -n;
		write (fd, "-", 1);
		ft_putnbr_fd (n, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd (n / 10, fd);
		a = n % 10 + 48;
		write (fd, &a, 1);
	}
}

void	take_it(int sig)
{
	static unsigned char	a;
	static int				i;

	if (sig == SIGUSR1)
		a = a | 1;
	i++;
	if (i == 8)
	{
		write(1, &a, 1);
		a = 0;
		i = 0;
	}
	a = a << 1;
}

int	main(void)
{
	write(1, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 2);
	signal(SIGUSR1, take_it);
	signal(SIGUSR2, take_it);
	while (1)
		pause ();
	return (0);
}
