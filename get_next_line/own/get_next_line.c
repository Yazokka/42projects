#include "get_next_line.h"

int main()
{
	int fd;
	char buff[BUFFSIZE];
	
	fd = open("test.txt", O_RDONLY, BUFFSIZE);

	read(fd, buff, BUFFSIZE);

	printf("%s\n", buff);

	close(fd);


}