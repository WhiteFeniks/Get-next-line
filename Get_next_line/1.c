/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 07:11:51 by jaleman           #+#    #+#             */
/*   Updated: 2019/05/21 15:38:12 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** выделяет достаточно памяти для копии строки s1, делает копию,
** и возвращает указатель на него.
*/

static char			*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;

	i = 0;
	while (s1[i])
		i += 1;
	if (!(s2 = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}

/*
** Распределяет с помощью malloc () и возвращает «свежую» строку, заканчивающуюся на «0»,
** результат объединения s1 и s2. Если распределение не удается
** функция возвращает NULL.
*/

static char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*s3;
	char		*tmp_s3;
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	while (s1[i])
		i += 1;
	while (s2[j])
		j += 1;
	if (!s1 || !s2 || !(s3 = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	tmp_s3 = s3;
	while (*s1 != '\0')
		*tmp_s3++ = *s1++;
	while (*s2 != '\0')
		*tmp_s3++ = *s2++;
	*tmp_s3 = '\0';
	return (s3);
}

/*
** Проверьте, есть ли в стеке новая строка. Если это не так, возвращает
** ноль (0), чтобы указать, что это недействительно. Если есть новая строка, мы делаем
** копия стека в строку, и мы скопировали все, что было в стеке
** раньше, обратно в стек (с созданным нами временным стеком).
*/

static int			gnl_verify_line(char **stack, char **line)
{
	char			*tmp_stack;
	char			*strchr_stack;
	int				i;

	i = 0;
	strchr_stack = *stack;
	while (strchr_stack[i] != '\n')
		if (!strchr_stack[i++])
			return (0);
	tmp_stack = &strchr_stack[i];
	*tmp_stack = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(tmp_stack + 1);
	return (1);
}

/*
** Читает в кучу, из файловых дескрипторов, определенное количество байтов
** определяется макросом BUFF_SIZE в файле get_nex_line.h. Это собирается
** продолжить чтение, когда возвращаемое значение функции чтения больше
** чем ноль (без ошибок, или если больше нечего читать).
** Если в стеке что-то есть, мы объединим все, что находится в
** там, с тем, что читается в куче. Если нет, мы просто добавим
** что бы ни было в куче в стек. Затем мы проверим стек
** посмотреть, если есть новая строка. Если есть, мы вырвемся из цикла while
** и форсировать положительное значение ret в единицу (1), используя макрос RET_VALUE ().
** Эта форма ответа SO помогла мне лучше визуализировать стек и кучу:
** http://stackoverflow.com/a/1213360
*/

static	int			gnl_read_file(int fd, char *heap, char **stack, char **line)
{
	int				ret;
	char			*tmp_stack;

	while ((ret = read(fd, heap, BUFF_SIZE)) > 0)
	{
		heap[ret] = '\0';
		if (*stack)
		{
			tmp_stack = *stack;
			*stack = ft_strjoin(tmp_stack, heap);
			free(tmp_stack);
			tmp_stack = NULL;
		}
		else
			*stack = ft_strdup(heap);
		if (gnl_verify_line(stack, line))
			break ;
	}
	return (RET_VALUE(ret));
}

/*
** Сначала проверяется на наличие ошибок (является ли строка пустой, если номер файла
** дескриптор недействителен, или если ему не удастся выделить кучу), поэтому он может вернуть
** минус один (-1) при необходимости.
**
** Если в стеке есть что-то (потому что мы используем статическую переменную),
** мы проверяем, что есть новая строка. Если нет, мы выделяем память для кучи,
** и мы читаем файл.
**
** Когда чтение файла закончится, мы освободим кучу (мы не собираемся
** использовать его больше), и мы проверяем значение ret (если это 1 или -1, вернуть
** что, если стек пуст, вернуть 0). Если ни одно из этих условий
** верно, мы приводим строку к значению стека, освобождаем стек и возвращаем 1
**
** Хорошее чтение о файловых дескрипторах:
** http://www.bottomupcs.com/file_descriptors.xhtml
*/

int					get_next_line(int const fd, char **line)
{
	static char		*stack[MAX_FD];
	char			*heap;
	int				ret;
	int				i;

	if (!line || (fd < 0 || fd >= MAX_FD) || (read(fd, stack[fd], 0) < 0) \
		|| !(heap = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (stack[fd])
		if (gnl_verify_line(&stack[fd], line))
			return (1);
	i = 0;
	while (i < BUFF_SIZE)
		heap[i++] = '\0';
	ret = gnl_read_file(fd, heap, &stack[fd], line);
	free(heap);
	if (ret != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}