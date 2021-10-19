#include "libasm.h"

int main()
{
	char *str = "welcome to my libasm";
	char cstr[1000];

	printf("ft_strlen\n");
	printf("empty str: %lu\n", ft_strlen(""));
	printf("simple str: %lu\n", ft_strlen(str));
	printf("\n");

	printf("ft_strcpy\n");
	printf("simple copy: %s\n", ft_strcpy(cstr, str));
	printf("\n");

	printf("ft_strcmp\n");
	printf("equal? %d\n", ft_strcmp(str, "new string"));
	printf("\n");

	int i = 0;
	int fd;
	
	printf("ft_write\n");
	printf("writing to file\n");
	fd = open("write_test.txt", O_WRONLY | O_CREAT | O_TRUNC);
	i = write(fd, "trying to write to a file", 25);
	printf("\n");

	printf("ft_read\n");
	fd = open("read_test.txt", O_RDONLY);
	memset(cstr, 0, 1000);
	i = ft_read(fd, cstr, 140);
	printf("was read: %d\n%s\n", i, cstr);
	printf("\n");
	close(fd);

	printf("ft_strdup\n");
	char *s;
	s = ft_strdup(str);
	printf("new string: %s\n", s);
	free(s);

	return (0);
}

