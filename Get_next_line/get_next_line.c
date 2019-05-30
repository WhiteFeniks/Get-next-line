0/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:43:23 by umoff             #+#    #+#             */
/*   Updated: 2019/05/29 17:31:18 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char **empty_line(char **stack)
{
	if (*stack == NULL) 					// если пустая строка
		*stack = ft_strnew(0); 				// выделили и возратили очищенную строку
	return (stack);
}

static void new_string(char **stack, char *buf)
{
	char *temp;

	temp = ft_strjoin(*stack, buf); 		//склеили stack и buf в temp
	free(*stack); 							//очистили stack
	*stack = ft_strdup(temp); 				//cкопировали temp в stack склеенное
	free(temp); 							//очистили temp
}

static int new_line(char **stack, char **line)
{
	char *temp;

	if ((*stack)[0] == 0)					//если дальше ничего нет то вернуть 0, файл закончился
		return (0);
	if (ft_strchr(*stack, '\n'))			//если нашли в stack \n
	{
		*(ft_strchr(*stack, '\n')) = '\0';	//то меняем \n на \0
		*line = ft_strdup(*stack);			//копируем stack в line
		temp = ft_strdup(ft_strchr(*stack, '\0') + 1);	// пример \0идем_дальше, до этого указатель был бы на
														// \0 а теперь указатель на букве "и"
		free(*stack);						//очищаем stack
		if (temp != 0)						//если temp не пустой
		{
			*stack = ft_strdup(temp);		//то копируем temp в stack
			free(temp);						//очищаем temp
		}
	}
	else
	{
		*line = ft_strdup(*stack);			//в line копируем все из stack
		ft_memdel((void **)stack);			//очищаем область памяти stack и устанавливаем указатель на NULL
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*stack[FD_MAX];				//FD_MAX нашли по команде ulimit -n 10240
	char		buf[BUFF_SIZE + 1];			//+1 еще для нуль-терминатора
	int			count;

	if (fd == -1 || line == NULL || read (fd, buf, 0) == -1 || fd > FD_MAX)
        return (-1);						//проверка на ошибки, если -1 то ошибка
	empty_line(&(stack[fd]));				//проверка на пустую строку
	while(!(ft_strchr(stack[fd], '\n')))	//пока не найдет совпадение с символом \n
	{
		count = read(fd, buf, BUFF_SIZE);	//считывает с файла с fd в buf размера BUFF_SIZE и выдает количество байт
		buf[count] = '\0';					//записывает в конец нуль-терминатор
		if (count == 0)						// если ничего не считалось, то прерываемся
			break ;
		new_string(&(stack[fd]), buf); 		// получение новой строки
	}
	return (new_line(&(stack[fd]), line));
}

int main()
{
	char	*line;
	int		fd;
	int		j;
	fd = open ("war_and_peace", fd);		//открываем файл с названием war_and_peace
/*	while  (get_next_line(fd, &line) > 0)	//пока get_next_line работает != 0
	{
		printf("%s\n", line);				//выводим по линии
		ft_strdel(&line);					//очищаем строку line
	}
*/
	j = 3;
	while (j > 0)							//вывод первых 18 строк
	{
		get_next_line(fd, &line);
		printf("%s\n", line);				//выводим по линии
		ft_strdel(&line);					//очищаем строку line
		j--;
	}
	return (0);
}
