/*
** philo.h for philo.h in /home/faisant/Bureau/projet/philo
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Thu Mar 20 07:37:34 2014 florian faisant
** Last update Sun Mar 23 12:15:51 2014 florian faisant
*/

#ifndef			PHILO_H
# define		PHILO_H

# include		<stdbool.h>
# include		<pthread.h>

# define		NB_STICK	(7)
# define		NB_PHILO	(7)
# define		RIZE_QUANT	(3)

# define		ERR(msg)	error(__FILE__, __LINE__, __func__, msg)

typedef struct		s_stick
{
  bool			is_used;
  pthread_mutex_t	*mutex;
}			t_stick;

typedef struct		s_philo
{
  t_stick		*right;
  t_stick		*left;
  bool			is_left;
  bool			is_right;
  int			rize_eat;
  int			rize_quant;
  int			id;
  pthread_t		*thread;
}			t_philo;

bool			init_stick(t_stick *stick,
				   pthread_mutex_t *mutex);
bool			init_philo(t_philo *philo,
				   t_stick *stick,
				   pthread_t *thread,
				   int rize_quant);
bool			run(t_philo *philo);
void			*check_right(void *philo);
void			*check_left(void *philo);
bool			error(char *file, int line, const char *func_name,
			      char *error);

#endif
