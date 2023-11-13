/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaliska <ecaliska@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:00:39 by mhuszar           #+#    #+#             */
/*   Updated: 2023/11/12 19:11:48 by ecaliska         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "wordle.h"

int isindict(char *dict, char letter)
{
	int i = 0;
	int count = 0;
	while(dict[i])
	{
		if(dict[i]==letter)
			count++;
		i++;
	}
	return count;
}

char	*ft_toupper(char *str)
{
	int counter = 0;
	while (str[counter])
	{
		if (str[counter] >= 'a' && str[counter] <= 'z')
			str[counter] = str[counter] - 32;
		counter++;
	}
	return (str);
}

int isincorrectpos(char *dict, char *input)
{
	int i = 0;
	char *tempDict = NULL;
	int	*flag_arr;

    flag_arr = calloc(4, 28);
	if(!flag_arr)
		return -1;
    tempDict = strdup(dict);
	if (!tempDict)
	{
		free(flag_arr);
		return -1;
	}
	while (i < 5)
	{
		if(input[i] == dict[i])
			tempDict[i] = '-';
		i++;
	}
	i = 0;
	while(i < 5)
	{
		flag_arr[input[i] - 'a']++;
		if(input[i] == dict[i])
		{
			printf("\033[0;92m");
			printf("%c ", input[i] - 32);
		}
		else if (isindict(dict, input[i]))
		{
			if (isindict(tempDict, input[i]) && flag_arr[input[i] - 'a'] <= isindict(dict, input[i]))
				printf("\033[0;93m");
			else
				printf("\033[0;90m");
			printf("%c ", input[i] - 32);
		}
		else
		{
			printf("\033[0;90m");
			printf("%c ", input[i] - 32);
		}
		i++;
	}
	if (strcmp(dict, input) == 0)
	{
		free(flag_arr);
		free(tempDict);
		return 1;
	}
	free(tempDict);
	free(flag_arr);
	return 0;
}

void printrules(void)
{
	//150 with;
	printf("MWNNWMWNNWMWNNWMWNNWMWNNWMWNWMMWNWMMWNWMWNNWMWNNWMWNNWMWNNWMWNNWMWNNWMWNNMMWWNWMMWNWMMNNWMWNNWMWNNWMWNNWMWNNWMWNNMMWNNMMWNWMMWNWMMNNWMWNNWMWNNWMWNNWMW\n");
	printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n");
	printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n");
	printf("WWWNWMWWNWWWNNWWWNWWWWNWWWWNWWWWNWWWWNWWWWNWWWWNWWWNNWWWWWWWWNWWWWWWWWWNWWWWWNWWWWNWWWWNWWWWNWWWWWWMWWWWWWNWWWWNWWWWNWWWWNWWWWNWWWWNWWWWNWWWWNWWWNNWWW\n");
	printf("NWWWWNWWWWNWWWWNWWWWNWWWNNWMWWNWWWNNWWWNWWWWNWWWWNWWWWNWWWWNWWWWNWWWWNWWWNNWWWWNNWWWNWWWWWWWWWNKkdookKWWNWWWWNWWWWNWMWWWWMWNNWMWWWWWWNWWWWNWWWWNWWWWNW\n");
	printf("WWWWWWWWWWWWNWWWWNWWWWNWWWWWWWWWNWWWWNWWWWNWWWWWWWWWWWWWWWWWWWWWWWNWWWWNWWWWWNWWWWWWWWXOxdodkXXc     .l0WWNWWWWWWKkxddxOOdkNWNOd0WWWWWWWNWWWWNWWWWWWWW\n");
	printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNo.    'O0'       cXWWWWWWWWX0k;cOKd';kN0c.lNWWWWWWWWWWWWWWWWWWWW\n");
	printf("WWWWWWWWWWWWWWWWWWWWWNKkoc:::lOWWWWWWWWWWWWWWXkl::cxNWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWNl     cXd.  ..   cXWWWWWWWWWWKcoNWx:coOdl:oNWWWWWWWWWWWWWWWWWWWW\n");
	printf("WWWWWWWWWWWWWWWWWWWWW0,      'OWWWWNXKKXNWWWWO'    :KWWWWWWWWWWWWWWWWWWWWWWWWNWWWWWWWNc    'OK:  .dc  .dWWNWWWWWWWWKcoNWx:xd:lkcoNWWWWWWWWWWWWWWWWWWWW\n");
	printf("NWWWWNWWWWNWWWWNWWWWNx.      lXWMWk;'...dNMWNo.   .xWWNWWWNNWWWWNWNKkONMWNNWWMWNWWWWWK;   .oNx.  lO;  .kNWWWNNWWWWNNO0NNKOXKx0NOONWWWNWWWWNWWWWNWWWWNW\n");
	printf("MWWNWWWWWWWWNNWWWNWWWd.     'OWWNK;    .kWNWK,    ;KWWXkl;;dXNWWWO:. cXWWWWWWNWWWX0XW0'   ;0K;  .xo.  lNWXxc;:dKNWWWNWWWWNWWWWNWWWWNWWWWNWWWWNWWWNNWWW\n");
	printf("WWWWWWWWWWWWWWWWWWWWNo      cXWWWx.    ;KWWNo.   .xNKo'    .xWWWXl   ,ooclOXNWWKo'.'ol.  .xNx.  ;l.  :KNx,     'dXWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n");
	printf("WWWWWWWWWWWWWWWWWWWWNl     .oNWWK;     lNWWk.    lXk'       ,kNWNo.       'oONx'         :XK:   ..  :KXo.   ''  .lXWKOXWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n");
	printf("WWWWWWWWWWWWWWWWWWWWWo     .kWWXl     .oWW0,    :0x.   .:c.  .xXO, .;,   .l00o.    ''   .kWk.     .oXNx.  .lKd.  .xO,.dWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n");
	printf("NWWWWNWWWWNWWWWNWWWWNd.    .OWNd.     .oNK:    ;0k.   .oXo    .'. .ok,  .lKNx.   .d0c   :KNo    .:ONWK;  .oNXc   'l, .xNWWWWWWWWNWWWWNWWWWNWWWWNWWWWNW\n");
	printf("MWWNWMWNNWWWNNWMWNWWWO.    .OWk.  ..   lO:    ,OXc    ;KNo.      'dk;   cKkc'   .xNk.  .xNk'   'kXWWWk.  .:c,.  ;o,  lNWWNWWWWNWWWWNWWWWNWWWNNWWWNWWWW\n");
	printf("WWWWWWWWWWWWWWWNWWWWWX:    .dx.  :k:   ..    :0WK,    oNWk. .:llxKK:   :Od.     lN0,   ,kd.    :XWNXk;   ':,..;do.  cXWNWWWWWWWWNWWWWWWWWWNWWWWWWWWWWW\n");
	printf("WWWWWWWWWWWWWWWWWWWWWWk.    ..  ,0Wk.      .lKWWX:   .o0d' .lXWWWNo.  .c;.     .ok,    .'      .,;,..    ;KNKOd;.  cKWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n");
	printf("WWWWWWWWWWWWWWWWWWWWWWNx.      .kWWNk,   .,kNWWWNx.   ..  .lKWWWWXo.      .;;.  ..  ..    .ld,       .,.  ,;,.   .dXWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n");
	printf("NWWWWNWWWWNWWWWNWWWWNWWW0l,...,xNWWWWXkdxOXWWWWWWXx,.   .,xXWWWWWWNk:'',:d0NNO:.  .:O0d::o0NWXkoc:clxKN0l,.. ..;o0NWWWWWWWWWNWWWWWWWWWWWWWNWWWWNWWWWNW\n");
	printf("MWWNWWWWNWWWNNWWWNWWWWNWWWXK0KNNNWWWWNWMWWNWMWWNWMWXOxxxOXWWWNWWWWNWWNXXNWWWWNNKOxONWWWNWWWWNWWWWNWMWNNWWN0OO0KXNWWWNWWWWNWWWWNWWWWNWWWWNWWWWNWWWNWWWW\n");
	printf("NWWWWNWWWWNWWWWNWWWWNWWWWNWWWNNWMWNWWWWNWWWWNWWWWNWWWWNWWWWNWWWWNWWWWNWWWWNWWWWNNWWWNWWWWNWWWWNWWWWNWWWWNWWWWNWWWWNWWWWNWMWNWWWWNWWWWNWWWWNWWWWNWWWWNW\n");
	printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n");
	printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n");
	printf("NNWMWNWMMWNWMMNNWMWNNWMWNNWMWNNWMWNNWMWNNWMWNNMMWNNMMWNWMMWNWMMNNWMWNNWMWNNNWMWNNWMWNNWMWNNWMWNWMMWNWMMWNWMWNNWMWNNWMWNNWMWNNWMWNNWMWNNWMWNNMMWNWMMWNW\n\n");
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("                        _ _\n");
	printf("__	  __           | | |\n");
	printf("\\ \\      / /__  _ __ __| | | ___\n");
	printf(" \\ \\ /\\ / / _ \\| '__/ _  | |/ _ \\\n");
	printf("  \\ V  V / (_) | | | (_| | |  __/\n");
	printf("   \\_/\\_/ \\___/|_|  \\__,_|_|\\___|\n\n");
	printf(" ONLY WORDS WITH 5 LETTERS ARE ACCEPTED\n");
	printf("\033[0;92m CORRECT LETTER\n");
	printf("\033[0;93m CORRECT LETTER IN THE WRONG PLACE\n");
	printf("\033[0;90m INCORRECT LETTER\n\n\033[0;39m");
}

#include <errno.h>
#include <string.h>

int cheatfunctions(char *str)
{
	if (strcmp(str, "!exit\n") == 0)
		return 2;
	else if (strcmp(str, "!word\n") == 0)
		return 1;
	return 0;	
}

int main(void)
{
	start_game:
	printrules();	
	char **input;
	int i = 0;
	int j = 0;
	int p = 0;
	int flag = 0;
	int	flag2 = 0;
	//int res = 0;
	//errno = 0;
	char yes_no[3];
	t_keyvalue	**hashtab;
	int			fd = 0;
	char		*target_word;

	fd = open("words.txt", 0);
	if (fd == -1)
	{
		printf("Error opening dictionary\n");
		return (-1);
	}
	hashtab = (t_keyvalue **)calloc(sizeof(t_keyvalue *), HASHTABLE_SIZE);
	if (!hashtab)
		return (-1);
	if (!read_data(hashtab, fd))
	{
		free_everything(hashtab);
		return (-1);
	}
	input = (char **)calloc(sizeof(char *), 7);
	if (!input)
	{
		free_everything(hashtab);
		return (-1);
	}
	printf("Calculating target word...\n");
	target_word = find_target(hashtab);

	while(i <= 6)
	{
		input[i] = calloc(1000, 1);
		if (!input[i])
		{
			free_input(input, i - 1);
			free_everything(hashtab);
			return -1;
		}
		start_loop:
		p = 0;
		j = i;
		while(p < i && !flag)
		{
			printf("\n");
			if(isincorrectpos(target_word, input[p]) == -1)
				return -1;
			printf("\n");
			p++;
		}
		if (i == 6) //ASK IF THE PLAYER WANTS TO PLAY AGAIN
		{
			ask_yes:
			target_word = ft_toupper(target_word);
			printf("\033[0;37m\n\n\tcorrect word was %s\n", target_word);
			printf("\t\033[0;39mSorry you couldn't find the word\n\tType 'yes' if you want to try again!\n\t");
			fgets(yes_no, 4, stdin);
			if(strcmp(yes_no, "yes") == 0)
			{
				getchar();
				free_input(input, i);
				free_everything(hashtab);
				goto start_game;
			}
			break ;
		}
		while(j < 6 && !flag && flag2) //PRINT THE LINES
		{
			printf("\033[0;37m");
			printf("\t\n_ _ _ _ _\n");
			j++;
		}
		flag2 = 1;
		printf("\033[0;37m\nPlease input a word: ");
		if (!fgets(input[i], 1000, stdin))
		{
			free_input(input, i);
			free_everything(hashtab);
			return (-1);
		}
		ft_tolower(input[i]);
		if(input[i][0] == '!')
		{
			if(cheatfunctions(input[i]) == 1) //!WORD to get the word
				goto ask_yes;
			else if(cheatfunctions(input[i]) == 2) //!EXIT to exit the game
			{
				printf("Succesfully exited!\n");
				break;
			}
			else if (cheatfunctions(input[i]) == 0) //Error if there is no !-Command
			{
				printf("\n\033[0;91mThere is no such command!\033[0;39m\n");
				flag = 1;
			}
			goto start_loop;
		}
		if (input[i][0] == '\n') //CHECK IF JUST A NEWLINE WAS INPUTED
		{
			printf("\n\033[0;91mPlease input word, not just newline\033[0;39m\n");
			flag = 1;
			goto start_loop;
		}
		if (strlen(input[i]) != 6) //ERROR FOR WORDLENGTH NOT 5
		{
			printf("\033[0;37m");
			input[i][strlen(input[i]) - 1] = '\0';
			printf("\n\033[0;91m%s is not 5 letters long\033[0;39m\n", input[i]);
			flag = 1;
			goto start_loop;
		}
		flag = 0;
		input[i][5] = '\n';
		input[i][6] = '\0';
		if (!(search_input(hashtab, input[i]))) // FIND WORD IN DATABASE
		{
			printf("\n\033[0;91mThis word is not in our database.\033[0;39m\n");
			flag = 1;
			goto start_loop;
		}
		if (strcmp(target_word, input[i]) == 0) //IF CORRECT WORD WAS FOUND
		{
			p = 0;
			while(p < i)
			{
				printf("\n");
				if(isincorrectpos(target_word, input[p]) == -1)
					return -1;
				printf("\n");
				p++;
			}
			int x = 0;
			target_word = ft_toupper(target_word);
			printf("\n");
			while(x < 5)
			{
				printf("\033[0;92m%c ", target_word[x]);
				x++;
			}
			printf("\n");
			j = i + 1;
			while(j < 6)
			{
				printf("\033[0;37m");
				printf("\t\n_ _ _ _ _\n");
				j++;
			}
			input[i][5] = '\0';
			printf("\n\033[0;92mCongratulations '%s' was the correct word\n", ft_toupper(input[i]));
			free_everything(hashtab);
			free_input(input, i);
			return (0);
		}
		i++;
	}
	target_word = ft_toupper(target_word);
	free_input(input, i);
	free_everything(hashtab);
	return (0);
}
