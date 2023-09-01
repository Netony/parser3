#include <unistd.h>
#include "test.h"
#include "parser.h"
#include "minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <termios.h>

void	leaks(void)
{
	system("leaks parser");
}

void	ms_excuter(t_cmd *cmd_array, int cmd_size, t_info *info)
{
	t_exnode	*onebuilt;

	if (cmd_size != 1 || \
			!(builtincheck((cmd_array->command)[0])))
		piping(cmd_array, cmd_size, info);
	else
	{
		onebuilt = (t_exnode *)malloc(sizeof(t_exnode));
		if (!onebuilt)
		{
			errormsg(MS_MALLOC, 0);
			return ;
		}
		exnodeset(onebuilt, *cmd_array, 0);
		if (!(ft_strcmp((cmd_array->command)[0], "exit")))
			ft_exit(onebuilt, info->envlst, 1);
		info->status = exbuiltin(onebuilt, &(info->envlst), 0, 1);
		exlstfree(onebuilt, 1);
	}
}
// exit 일 때 , cmd_array 할당 해제 추가하기.

void	handler(int signum)
{
	(void)signum;
	printf("minishell$ \n");
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

int	main(int argc, char **argv, char **envp)
{
	struct termios	term;
	t_info	info;
	char	*buf;
	t_list	*cmd_list;
	int		cmd_size;
	t_cmd	*cmd_array;
	int		ret;

	(void)argc;
	(void)argv;
	// atexit(leaks);
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	info.envlst = envlist(envp);
	ret = 0;
	info.status = 0;
	while (ret == 0)
	{
		buf = readline("minishell$ ");
		if (buf)
		{
			cmd_list = parser(&info, buf);
			if (cmd_list == NULL)
				continue ;
			cmd_size = ft_cmdsize(cmd_list);
			cmd_array = ft_convert(cmd_list);
			if (cmd_array == NULL)
				continue ;
			ft_cmddel(cmd_list);
			ft_print_cmds(cmd_array, cmd_size);
			printf("test\n");
		//	signal(SIGINT, SIG_DFL);
			//ms_excuter(cmd_array, cmd_size, &info);
		//	signal(SIGINT, handler);
			add_history(buf);
			free(buf);
		}
		else
		{
			printf("\033[10C");
			printf("\033[1A");
			printf(" exit\n");
			ret = 1;
		}
		//ft_cmdsdel(cmd_array, cmd_size);
	}
	return (0);
}
// 1. main 문 인자 envp 를 envset() 함수에 넣어 환경변수 연결리스트 생성
// 2. while 문 ( 파싱 -> piping() or exbuiltin() -> free(command는 free하지않는다))
// 2-1. piping()이 아닌 exbuiltin()으로 들어가는 경우는
// -> pipeline이 없으면서, builtin 함수일 때. (builtincheck()활용)
// 3. 종료시그널 발생 시(exit, ctl + D), 1의 리스트 free()
