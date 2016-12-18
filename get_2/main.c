#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

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

char check_lst(int fd, t_list *alist)
{
    if (alist) {
        while ((alist->content_size) != fd || alist->next != 0)
            alist = alist->next;
        if (alist->content_size == fd && alist->content != 0)
        {
            return (alist->content);
        }
    }
    return (0);
}

int get_next_line(int fd, char **line)
{
    static t_list *alist = 0;
    char *to_cut;
    char *tmp;

    if (!check_lst(fd, alist))
        ft_lstnew(get_next_part(fd), fd);

    while (!(ft_strchr(check_lst(fd, alist), '\n')))
         ft_strjoin(check_lst(fd, alist), get_next_part(fd));

    to_cut = ft_strchr(check_lst(fd, alist), '\n');
    *to_cut = '\0';
    tmp = check_lst(fd, alist);
    *line = tmp;
    tmp = to_cut + 1;
    return (1);


}

int main(void)
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