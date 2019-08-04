#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}

int	main(void)
{
	char	buffer[1 + 1];
	int		bytes_read;

	bytes_read = read(STDIN_FILENO, buffer, 1);
	while (bytes_read)
	{
		buffer[bytes_read] = '\0';
		ft_putstr(buffer);
		if (buffer[0] == '\n')
			ft_putstr("bitch\n");
		bytes_read = read(STDIN_FILENO, buffer, 1);
	}
}
