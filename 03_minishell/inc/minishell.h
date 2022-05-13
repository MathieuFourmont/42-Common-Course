/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:17:56 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/05/13 11:59:46 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
#include <string.h>
#include <unistd.h>
# include "../libft/libft.h"
# define METACHARSET ""

// STRUCTS
typedef struct	s_ast {
	struct s_ast *left;
	struct s_ast *right;
	void *content;
}	t_ast;

typedef enum RedirType
{
	LEFT_SINGLE,
	LEFT_DOUBLE,
	RIGHT_SINGLE,
	RIGHT_DOUBLE
}	t_redir_type;

typedef enum s_token_type{
	CHAR_GENERAL = -1,
	CHAR_PIPE = '|',
	CHAR_AMPERSAND = '&',
	CHAR_SQUOTE = '\'',
	CHAR_DQUOTE = '\"',
	CHAR_WHITESPACE = ' ',
	CHAR_NEWLINE = '\n',
	CHAR_GREATER = '>',
	CHAR_LESSER = '<',
	CHAR_NULL = 0,
	TOKEN	= -1,
}	t_token_type;

typedef struct s_redir {
	t_redir_type redir_type;

}	t_redir;

typedef struct s_fd {
	char	*fname;
	int		fd;
}	t_fd;

typedef struct s_token {
	char 			*token;
	t_token_type	tokentype;
}	t_token;

typedef struct s_simp_cmd
{
	int		argc;
	char	**argv;
	t_fd	fd_in;
	t_fd	fd_out;
	t_fd	fd_err;
	int		heredoc;
	int		append;
}	t_scmd;

typedef struct s_cmd {
	int			argc;
	t_scmd		*scmds;	// ls -al
}	t_cmd;

// typedef struct s_env {
// 	char			*vars;
// 	struct s_env	*next;
// }	t_env;


// FUNCTION PROTOTYPES
char	**tokenize(const char *s);
void	print_tokens(char **tokens);
void	expand_tokens(char **tokens);
void	print_tokens(char **tokens);
int		check_token_type(int token);
int		check_quotes(const char *s);
int		metachar_wordlen(const char *s, int offset);
void	build_cmds(char **tokens, t_cmd *cmd);
void	exec_echo(char **tokens);
void	exec_cd(char **tokens);
void	exec_pwd(char **tokens);
void	exec_export(char **tokens, t_list **env);
void	exec_env(char **tokens, t_list **env);
int		builtin_identifier(char **tokens);
int		builtin_executor(char **tokens);
void	env_init(t_list **env, char **envp);
void	export_no_var(t_list **env);

#endif
