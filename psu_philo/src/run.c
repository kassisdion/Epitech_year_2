/*
** run.c for run in /home/faisant/Bureau/projet/philo
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Thu Mar 20 08:42:03 2014 florian faisant
** Last update Fri Mar 21 17:28:52 2014 florian faisant
*/

#include	<stdio.h>
#include	"philo.h"

static bool	create_thread(t_philo *philo)
{
  int		i;

  i = 0;
  while (i < NB_PHILO)
    {
      if (i % 2)
        pthread_create(philo[i].thread, NULL, &check_left, (void *)&(philo[i]));
      else
        pthread_create(philo[i].thread, NULL, &check_right, (void *)&(philo[i]));
      i++;
    }
  return (true);
}

static bool	join_thread(t_philo *philo)
{
  int		i;
  void		*ret;

  i = 0;
  while (i < NB_PHILO)
    {
      pthread_join(*philo[i].thread, &ret);
      i++;
    }
  return (true);
}

bool		run(t_philo *philo)
{
  create_thread(philo);
  join_thread(philo);
  return (true);
}
