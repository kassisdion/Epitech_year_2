/*
** init.c for init in /home/faisant/Bureau/projet/philo/src
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Thu Mar 20 06:43:59 2014 florian faisant
** Last update Sun Mar 23 12:12:43 2014 florian faisant
*/

#include	<stdbool.h>
#include	<stdlib.h>
#include	"philo.h"

bool		init_stick(t_stick *stick,
			   pthread_mutex_t *mutex)
{
  int		i;
  
  i = 0;
  while (i < NB_STICK)
    {
      stick[i].mutex = &mutex[i];
      pthread_mutex_init(stick[i].mutex, NULL);
      stick[i].is_used = false;
      i++;
    }
  return (true);
}

bool		init_philo(t_philo *philo,
			   t_stick *stick,
			   pthread_t *thread,
			   int rize_quant)
{
  int		i;

  i  = 0;
  while (i < NB_PHILO)
    {
      philo[i].thread = &thread[i];
      philo[i].id = i;
      if (i == 0)
	philo[i].right = &(stick[6]);
      else
	philo[i].right = &(stick[i - 1]);
      philo[i].left = &stick[i];
      philo[i].rize_eat = 0;
      philo[i].rize_quant = rize_quant;
      philo[i].is_left = false;
      philo[i].is_right = false;
      i++;
    }
  return (true);
}
