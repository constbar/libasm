#include "libasm.h"
int main()
{
	errno = 0;
	char *str = "welcome to my libasm";
	char *sstr = "london is the capital of great britain";
	char *lstr = "Мой отец граф де Бриссак сражался в Голландии в полку г-на Лаваля и был ранен копьем при осаде Монферрата, на стенах которого он первым водрузил королевское знамя.\0";
	char cstr[1000];

	printf("\n------------ft_strlen-------------------\n\n");
	printf("Some string\n");
	printf("strlen: %lu\n", strlen(str));
	printf("ft_strlen: %lu\n", ft_strlen(str));
	printf("Empty string\n");
	printf("strlen: %lu\n", strlen(""));
	printf("ft_strlen: %lu\n", ft_strlen(""));
	printf("Long string\n");
	printf("strlen: %lu\n", strlen(lstr));
	printf("ft_strlen: %lu\n", ft_strlen(lstr));

	printf("\n------------ft_strcpy-------------------\n");
	printf("Some string\n");
	printf("strcpy: %s\n", strcpy(cstr, str));
	printf("ft_strcpy: %s\n", ft_strcpy(cstr, str));
	printf("Empty string\n");
	printf("strcpy: %s\n", strcpy(cstr, ""));
	printf("ft_strcpy: %s\n", ft_strcpy(cstr, ""));
	printf("Long string\n");
	printf("strcpy: %s\n", strcpy(cstr, lstr));
	printf("ft_strcpy: %s\n", ft_strcpy(cstr, lstr));

	printf("\n------------ft_strcmp-------------------\n");
	printf("Some strings\n");
	printf("strcmp: %d\n", strcmp(sstr, str));
	printf("ft_strcmp: %d\n", ft_strcmp(sstr, str));
	printf("strcmp: %d\n", strcmp(str, sstr));
	printf("ft_strcmp: %d\n", ft_strcmp(str, sstr));
	printf("Empty strings\n");
	printf("strcmp: %d\n", strcmp("", ""));
	printf("ft_strcmp: %d\n", ft_strcmp("", ""));
	printf("One empty\n");
	printf("strcmp: %d\n", strcmp("", str));
	printf("ft_strcmp: %d\n", ft_strcmp("", str));
	printf("strcmp: %d\n", strcmp(str, ""));
	printf("ft_strcmp: %d\n", ft_strcmp(str, ""));

	int i = 0;
	int	fd;
	
	printf("\n------------ft_write-------------------\n");
	i = write(1, "Here\n", 5);
	printf("write: %d\n", i);
	i = ft_write(1, "Here\n", 5);
	printf("ft_write: %d\n", i);
	printf("To file\n");
	fd = open("write_test.txt", O_WRONLY|O_CREAT|O_TRUNC);
	i = write(fd, "Here1\n", 6);
	printf("write: %d\n", i);
	i = ft_write(fd, "Here2\n", 6);
	printf("ft_write: %d\n", i);
	close(fd);
	printf("Wrong file\n");
	fd = open("write_test.txt", O_RDONLY);
	i = write(fd, "Here3\n", 6);
	printf("write: %d %d\n", i, errno);
	errno = 0;
	i = ft_write(fd, "Here3\n", 6);
	printf("ft_write: %d %d\n", i, errno);
	close(fd);
	printf("Wrong file2\n");
	errno = 0;
	i = write(-3, "Here3\n", 6);
	printf("write: %d %d\n", i, errno);
	errno = 0;
	i = ft_write(-3, "Here4\n", 6);
	i = write(-3, "Here3\n", 6);
	printf("ft_write: %d %d\n", i, errno);

	printf("\n-------------ft_read--------------------\n");
	printf("From file\n");
	fd = open("read_test.txt", O_RDONLY);
	memset(cstr, 0, 1000);
	i = read(fd, cstr, 118);
	printf("read: %d\n %s\n", i, cstr);
	close(fd);
	fd = open("read_test.txt", O_RDONLY);
	memset(cstr, 0, 1000);
	i = ft_read(fd, cstr, 118);
	printf("ft_read: %d\n %s\n", i, cstr);
	close(fd);
	printf("Wrong file\n");
	errno = 0;
	fd = open("read_test.txt", O_WRONLY);
	i = read(fd, cstr, 7);
	printf("read: %d %d\n", i, errno);
	errno = 0;
	i = ft_read(fd, cstr, 1);
	printf("ft_read: %d %d\n", i, errno);
	close(fd);
	printf("Wrong file2\n");
	errno = 0;
	i = read(-3, cstr, 6);
	printf("read: %d %d\n", i, errno);
	errno = 0;
	i = ft_read(-3, cstr, 6);
	i = read(-3, "Here3\n", 6);
	printf("ft_read: %d %d\n", i, errno);

	char *s;
	printf("\n------------ft_strdup-------------------\n");
	printf("Some string\n");
	s = strdup(str);
	printf("strdup: %s\n", s);
	free(s);
	s = ft_strdup(str);
	printf("ft_strdup: %s\n", s);
	free(s);
	printf("Empty string\n");
	printf("strdup: %s\n", strdup(""));
	printf("ft_strdup: %s\n", ft_strdup(""));
	printf("Long string\n");
	s = strdup(lstr);
	printf("strdup: %s\n", s);
	free(s);
	s = ft_strdup(lstr);
	printf("ft_strdup: %s\n", s);
	free(s);
	
	return (0);
}

