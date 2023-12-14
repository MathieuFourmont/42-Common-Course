/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:17:56 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/06/14 15:32:48 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
        ERROR MANAGEMENT:
        1: MALLOC ERROR
        2: OPEN ERROR
        3: PIPES ERROR
*/

#ifndef MINISHELL_H
#define MINISHELL_H
#include "../libft/libft.h"
#include <curses.h>
#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <term.h>
#include <termcap.h>
#include <termios.h>
#include <unistd.h>
#define METACHARSET ""

// STRUCTS

typedef enum s_token_type {
  CHAR_GENERAL = -1,
  CHAR_PIPE = '|',
  CHAR_AMPERSAND = '&',
  CHAR_SQUOTE = '\'',
  CHAR_DQUOTE = '\"',
  CHAR_WHITESPACE = ' ',
  CHAR_TAB = '\t',
  CHAR_NEWLINE = '\n',
  CHAR_GREATER = '>',
  CHAR_LESSER = '<',
  CHAR_NULL = 0,
  TOKEN = -1,
} t_token_type;

typedef enum s_status {
  INIT,
  RESET,
  CHILD_PROCESS,
} t_status;

typedef struct s_fd {
  char *fname;
  int fd;
} t_fd;

typedef struct s_simp_cmd {
  int raw_argc;
  char **raw;
  int argc;
  char **argv;
  t_fd fd_in;
  t_fd fd_out;
  t_fd fd_err;
  int heredoc;
  char *delim;
  int append;
  int pid;
} t_scmd;

typedef struct s_cmd {
  int argc;
  char **tokens;
  int *pipes;
  t_list **env;
  char **envp;
  char **paths;
  uint8_t exit_status;
  t_scmd *scmds;
} t_cmd;

// GLOBALS
t_cmd g_cmd;

//////////////////////
// FUNCTION PROTOTYPES //
/////////////////////////
// TOKENISATION
void ft_setup(t_cmd *cmd, char **envp);
char **tokenize(const char *s);
void print_tokens(char **tokens);
void expand_tokens(char **tokens, t_list **env);
int ctt(int token);
int cst(char c);
int verify_redir(char *curr, char *next);
int check_even_quotes(char *token);
int verify_tokens(char **t);
int check_heredocs(t_cmd cmd);
int line_empty(const char *s);

// VARIABLE EXPANSION
char *get_var_name(char *token);
char *fill_expanded_name(char *line, int index);
char *get_expanded_name(char *var_name, t_list **env);
char *get_prestring(char *token);
char *get_poststring(char *token);
int check_quotes(const char *s);
int postcheck(const char *token);
int metachar_wordlen(const char *s, int offset);
int dollar_remaining(char *token);
int is_not_between_squotes(char *token, int i);
int is_expand_exception(char c);
int is_exit_code(char *token);
int dollar_remaining(char *token);
int find_first_expansion(char *token);
int count_poststring(char *token);

// QUOTE HANDLING
char *remove_outer_quotes(char *token);
char *remove_first_quote(char *token);
char *remove_last_quote(char *token);
void handle_quotes(char **tokens);

// COMMAND BUILDING
int build_cmds(char **tokens, t_cmd *cmd);
void free_tokens(char **tokens);
void free_cmds(t_cmd cmd);
int count_cmds(char **tokens);
int skip_token(char *token);
int scmd_arg_count(char **tokens, int index);
int raw_arg_count(t_cmd *cmd, char **tokens, int i, int j);
void write_raw_cmds(t_cmd *cmd, char **tokens);
int set_cmd_count(char **tokens, t_cmd *cmd);
void write_fds(t_cmd *cmd, char *fname, const char *mode, int pos);
void init_scmd_fds(t_cmd *cmd, int i);
void update_fds(t_cmd *cmd);
int count_argv(t_scmd scmd);
void print_commands(t_cmd *cmd);
void print_raw_commands(t_cmd *cmd);
void move_delims(t_scmd *scmd, int i);
void print_fds(t_cmd *cmd);
void print_split(char **split);
int update_empty_heredoc_cmds(t_cmd *cmd);

// COMMAND EXECUTION
int build_and_exec_cmds(t_cmd *cmd);
int exec_cmds(t_cmd *cmd);
char *find_path(t_list **env);
int build_paths(t_cmd *cmd);
int heredoc_input(t_cmd cmd, char *delim, int i);
int count_list_len(t_list **env);
char **create_envp(t_list **env);
int create_pipes(t_cmd *cmd);
int close_pipes(t_cmd *cmd);
int open_files(t_cmd *cmd);
int close_files(t_cmd cmd);
int set_redirections(t_cmd *cmd, int i);
char *get_bin(char **paths, char *bin);
void move_delims(t_scmd *scmd, int i);

// BUILTINS
int exec_echo(char **tokens);
int exec_cd(char **tokens, t_list **env);
int exec_pwd(void);
int exec_export(char **tokens, t_list **env);
int exec_env(t_list **env);
int exec_unset(char **tokens, t_list **env);
int builtin_identifier(char *tokens);
int builtin_executor(char **tokens, t_cmd *cmd);
void env_init(t_cmd *cmd, char **envp);
char *get_env_value(char *name, t_list **env);
void export_no_var(t_list **env);
int already_in_env(char *tokens, t_list **env);
void ft_clear_env(t_list **env);
char *get_next_line(int fd);
void rm_env_var(t_list *node, t_list **env);
void ft_free(char **ptr);
void set_pwd_vars_env(char *name, char *value, t_list **env);
char *get_term_var(t_list **env);
int ft_unlink(t_cmd cmd);
int init_term(void);
void ft_exit(t_cmd *cmd, char **envp);

// SIGNALS
void exec_signals(t_status status);
void error_message(char *s, int code, t_cmd *cmd);

// PROTOTYPES FOR READLINE
int rl_on_new_line(void);
void rl_replace_line(const char *text, int clear_undo);
void rl_redisplay(void);
#endif
