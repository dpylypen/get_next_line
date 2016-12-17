#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"


/*
char  *put_get_list(char *content, size_t content_size)
{
	t_list *alist = 0;    зі мною разом сила, і з силою разом я

	ft_lstadd(&alist, ft_lstnew(content, content_size));



	printf("%s\n", alist->content);
	return (alist);
}
*/

char *check_lst(t_list *alist)
{
	if (!alist)
		return (0);
	else
		return (alist->content);
}

char *get_next_part(int fd)
{
	char *tmp;
	int res;


	tmp = ft_memalloc(BUFF_SIZE);
	res = read(fd, tmp, BUFF_SIZE);
	if (res)
		return (tmp);
	return (0);

}

int get_next_line(const int fd, char **line)
{
	char *tmp;
	char *to_del;
	static t_list *alist = 0;
	//t_list *alist = 0;

	//*tmp = '\0';
	if (!check_lst(alist))
		tmp = get_next_part(fd);
	else
		tmp = check_lst(alist);
	if (!strlen(tmp))
		return (0);
	//tmp = get_next_part(fd);
	if (tmp)
	{
		while (!(ft_strchr(tmp, '\n'))) {
			tmp = ft_strjoin(tmp, get_next_part(fd));
		}
		to_del = ft_strchr(tmp, '\n');
		tmp[to_del - tmp] = '\0';

		//put_get_list((tmp + (to_del - tmp) + 1), ft_strlen((tmp + (to_del - tmp) + 1)));
		ft_lstadd(&alist, ft_lstnew((tmp + (to_del - tmp) + 1), ft_strlen((tmp + (to_del - tmp) + 1))));
		*line = tmp;
		return (1);
	}
	else
	return (0);
}

int main()
{
	int fd;
	char *line = (char *)ft_memalloc(1000);

	fd = 0;
	fd = open("/nfs/2016/d/dpylypen/get_next_line/A", O_RDONLY);

	//while (fd++ < 6)
		//save_to_list("5555", 4);

	if (fd != -1)
	{
		printf("fd = %d\nRES_GET_NEXT_LINE_1 = %d\nNEXT_LINE_1 = %s", fd, get_next_line(fd, &line), line);
		printf("\nfd = %d\nRES_GET_NEXT_LINE_2 = %d\nNEXT_LINE_2 = %s", fd, get_next_line(fd, &line), line);
		printf("\nfd = %d\nRES_GET_NEXT_LINE_3 = %d\nNEXT_LINE_3 = %s", fd, get_next_line(fd, &line), line);
		printf("\nfd = %d\nRES_GET_NEXT_LINE_4 = %d\nNEXT_LINE_4 = %s", fd, get_next_line(fd, &line), line);
		printf("\nfd = %d\nRES_GET_NEXT_LINE_5 = %d\nNEXT_LINE_5 = %s", fd, get_next_line(fd, &line), line);
		//printf("\nfd = %d\nRES_GET_NEXT_LINE_6 = %d\nNEXT_LINE_6 = %s", fd, get_next_line(fd, &line), line);
	}
	else
		printf ("CAN*T OPEN FILE");
	return (0);
}