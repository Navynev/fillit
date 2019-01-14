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

// test les board toussa

// int main(int argc, char **argv)
// {
//     (void)argc;
//     int block_nb;
//     int i;
//     char **board;
//     int l;
//     int c;
//     int size;

//     i = 0;
//     block_nb = check_and_read(argv[1]);
//     // if ((block_nb = check_and_read(argv[1])))
//     // {
//     //     while (i < block_nb)
//     //     {
//     //         printf("_________\n");
//     //         print_tetri(t_items[i].tetri);
//     //         printf("height = %d\n", t_items[i].height);
//     //         printf("width = %d\n", t_items[i].width);
//     //         printf("x = %d\n", t_items[i].x);
//     //         printf("y = %d\n", t_items[i].y);
//     //         printf("_________\n");
//     //         i++;
//     //     }
//     // }

//     board = NULL;
//     l = 0;
//     c = 1;
//     size = get_min_size(block_nb);
//     allocate_square(&board, size);
//     print_board(board);
//     printf("__________________\n");
//     place_item(&board, 0, 0, 0);
//     print_board(board);
//     printf("__________________\n");
//     printf("block fit = %d\n", block_fit(board, 1, l, c, size));
//     place_item(&board, 1, 0, 1);
//     print_board(board);
//     printf("__________________\n");
//     remove_item(&board, size, 0);
//     print_board(board);
//     printf("__________________\n");
//     return (0);
// }