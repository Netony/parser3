#include "test.h"
#include "parser.h"
#include <readline/history.h>
#include <readline/readline.h>

void	leaks(void)
{
	system("leaks parser");
}

int	main(int argc, char **argv, char **envp)
{
	char	*buf;
	t_list	*cmd_list;
	int		cmd_size;
	t_cmd	*cmd_array;
	int		i;
	t_env	*envlst;

	i = 0;
	(void)argc;
	(void)argv;
	atexit(leaks);
	envlst = envlist(envp);
	while (i++ < 2)
	{
		buf = readline("minishell$ ");
		if (buf)
		{
			cmd_list = parser(buf);
			if (cmd_list == NULL)
				continue ;
			cmd_size = ft_cmdsize(cmd_list);
			cmd_array = ft_convert(cmd_list);
			if (cmd_array == NULL)
				continue ;
			ft_cmddel(cmd_list);
			// ft_print_cmds(cmd_array, cmd_size);
			piping(cmd_array, cmd_size, &envlst);
		}
		else
			break ;
		/*
		add_history(buf);
		free(buf);
		ft_cmdsdel(cmd_array, cmd_size);
		*/
	}
	return (0);
}
// 1. main 문 인자 envp 를 envset() 함수에 넣어 환경변수 연결리스트 생성
// 2. while 문 ( 파싱 -> piping() or exbuiltin() -> free() )
// 2-1. piping()이 아닌 exbuiltin()으로 들어가는 경우는
// -> pipeline이 없으면서, builtin 함수일 때. (builtincheck()활용)
// 3. 종료시그널 발생 시(exit, ctl + D), 1의 리스트 free()
