// ***** Pour tester allocate square ****

// int		main(int argc, char **argv)
// {
// 	int fd;
// 	int i;
// 	int size;
// 	int tetri_nb;
// 	char **square;

// 	fd = open((argv[1]), O_RDONLY);
// 	i = 0;
// 	tetri_nb = 0;
// 	tetri_nb = check_general_conformity(fd);
// 	size = get_min_size(tetri_nb);
// 	square = NULL;
// 	(void)argc;
// 	printf("size = '%d\n", size);
// 	allocate_square(&square, size);
// 	while (i < size)
// 	{
// 		printf("%s\n", square[i]);
// 		i++;
// 	}
// 	return (0);
// }

// *** Pour tester upleft_tetri(); *****

// int main(void)
// {
// 	char **tab;

// 	tab = (char **)malloc(sizeof(char *) * 4);
// 	tab[0] = ft_strdup("....");
// 	tab[1] = ft_strdup("....");
// 	tab[2] = ft_strdup("...#");
// 	tab[3] = ft_strdup("...#");
// 	printf("%s\n", tab[0]);
// 	printf("%s\n", tab[1]);
// 	printf("%s\n", tab[2]);
// 	printf("%s\n", tab[3]);
// 	upleft_tetri(&tab);
// 	printf("__________\n");
// 	printf("%s\n", tab[0]);
// 	printf("%s\n", tab[1]);
// 	printf("%s\n", tab[2]);
// 	printf("%s\n", tab[3]);
// 	return (0);
// }