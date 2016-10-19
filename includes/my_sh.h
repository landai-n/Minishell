/*
** my_sh.h for my_sh in /home/landai_n/rendu/PSU_2013_minishell
** 
** Made by Nathanael Landais
** Login   <landai_n@epitech.net>
** 
** Started on  Thu Dec 12 15:25:41 2013 Nathanael Landais
** Last update Sun Mar  9 22:56:31 2014 Nathanael Landais
*/

#ifndef		__MY_SH__
# define	__MY_SH__

#include	<sys/types.h>
#include	<sys/dir.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	"my_elem.h"
# include	"hash_table.h"

/*	COMMANDS	*/
# define	CMD_EXIT	"exit"
# define	CMD_CD		"cd"
# define	CMD_SETENV	"setenv"
# define	CMD_UNSETENV	"unsetenv"
# define	CMD_ENV		"env"
# define	CMD_HASH	"hash"

/*	ERROR	       */
# define	ERROR_FORK	"Fork error."
# define	ERROR_MALLOC	"Malloc error."
# define	ERROR_NOTFOUND	"%s : command not found.\n"
# define	ERROR_NOFILDIR	"%s : no such file or directory.\n"
# define	ERROR_UNDFND	"Unable to launch this command."
# define	ERROR_SIG	"Unable to intercept the signal."
# define	ERROR_NBR_ARG	"Incorrect number of argument."
# define	ERROR_DIR_NFND	"Directory not found."
# define	ERROR_PATH	"Warning : Incorrect path in the env."
# define	ERROR_NO_PDIR	"No previous directory found."
# define	ERROR_NO_ENV	"Shell launched whithout any environment."
# define	ERROR_INVALID	"Please use only printable characters."
# define	ERROR_HASHEMPTY	"Hash table empty"
# define	ERROR_PIPE	"Broken pipe"
# define	ERROR_SEGFAULT	"Segmentation fault"
# define	ERROR_REDIRECT	"Redirection failed"
# define	ERROR_READ	"Read failed."
# define	ERROR_SYNTAX	"Bad syntax."

/*	OUTPUT MODE	*/
# define	NO_PIPE		-1
# define	OUTPUT_PIPE	1
# define	INPUT_PIPE	0
# define	MULTI_PIPE	2
# define	R_REDIRECT	3
# define	DR_REDIRECT	4
# define	L_REDIRECT	5
# define	DL_REDIRECT	6

/*	VAR ENV		*/
# define	PWD_VAR		"PWD"
# define	PREV_PWD_VAR	"OLDPWD"
# define	HOME_VAR	"HOME"
# define	PATH_VAR	"PATH"
# define	USER_VAR	"USER"

/*	USAGE		*/
# define	HASH_USAGE	"Usage : hash [-r]"
# define	ENV_USAGE	"Usage : env [-i]"

/*	OTHER	        */
# define	PROMPT_MSG	"$>"
# define	HASH_HEADER	"hits\tcommand\n"

/*	SEPARATORS	*/
# define	SEPARATOR_LIST	"|;><&"
# define	PIPE_CHAR	'|'
# define	AND_CHAR	'&'
# define	RREDIR_CHAR	'>'
# define	DRREDIR_CHAR	'['
# define	LREDIR_CHAR	'<'
# define	DLREDIR_CHAR	']'

typedef struct	s_command
{
  char		*bin;
  char		**arg;
  char		*next;
}		t_command;

/*	MAIN		*/
int		my_sh(char **env);
int		my_system(char **env, char **command, int fildes[], int *work);
int		my_builtin(char **env, char *buffer, int *run, int *value);

/*	EXEC_COMMAND	*/
int		interpret_command(char **env, char *buffer, int *run);
int             exec_command(char **env, char **commands, char *sep, int *run);
int             call_command(int fildes[], t_command *command, char **env);
int             get_commandinfo(char **command, char **env, t_command *actual);

/*	OPERATOR	*/
char            *get_sep(char *str, char *sep);
int             get_operator(char *sep, int i, int fildes[]);

/*	PIPE		*/
int             get_pipe(char *sep, int i, int fildes[]);
int             input_pipe(int fildes[]);
int             output_pipe(int fildes[]);
void		close_pipe(int fildes[]);
int             redirect_pipe(int fildes[]);

/*	RREDIRECT	*/
int             simple_rredirect(int fildes[], char *path);
int             double_rredirect(int fildes[], char *path);
int             simple_lredirect(int fildes[], char *path);
int             double_lredirect(int fildes[], char *word);
void            close_redirect(int fildes[], char ***command);

/*	ENV		*/
int		edit_env(char **env, char *var, char *value);
char		*get_env(char **env, char *var);
int		get_nbrelem(char **env);
char		*get_var(char **env, char *var);
int		copy_var(char **env, char *src, char *dest);

/*	PROMPT		*/
char		*get_promptmsg(char **env);
char		*prompt(char *msg);

/*	BIN		*/
char		*get_bin(char **path, char *name);
char		*get_localbin(char *path);
char		*complete_path(char **env, char *path);
char		*find_elem_table(t_hashtable *table, char *name);
char		*find_bin(char **path, char *name);
t_hashtable     *add_elem_table(t_hashtable *table, char *name, char *bin);

/*	BUILT-IN	*/
int		my_setenv(char **env, char **arg);
int		my_unsetenv(char **env, char **arg);
int		my_exit(char **arg, int *run, int *return_value);

/*	CMD_CD		*/
int		my_cd(char **env, char **arg);
char		*my_cdclassic(char **arg);
char		*my_cdhome(char **env);
char		*my_cdprev(char **env);
void		save_current_dir(char **env, char *path);

/*	CMD_ENV		*/
void		no_env(char **env, char **arg);
int		my_env(char **env, char **arg);
void		display_env(char **env);

/*	CMD_HASH	*/
int		my_hash(char **arg);
void            aff_hashtable(t_hashtable *table);
void            reset_hashtable(t_hashtable *table);

/*	UTILS		*/
int		is_error(char *error);
int		is_empty(char *str);
void		my_sig();
void		intercept_sig();
char		*get_str(char **arg);
int		get_nbr_arg(char *command, char *seps);
char		**get_arg(char *command, char *seps);
int		is_sep(char *seps, char c);

#endif
