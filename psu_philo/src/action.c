/*
** action.c for action.c in /home/faisant/Bureau/projet/philo
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Thu Mar 20 09:23:29 2014 florian faisant
** Last update Sun Mar 23 12:08:48 2014 florian faisant
*/

#include	<stdio.h>
#include	<unistd.h>
#include	"philo.h"

static void	*eat_rice(void *pt)
{
  t_philo	*philo;

  philo = (t_philo *)pt;
  printf("Le philosophe %d constate qu'il reste %d part de riz\n",
	 philo->id, philo->rize_quant);
  philo->rize_quant -= 1;
  printf("Le philosophe %d mange.\n", philo->id);
  sleep(1);
  pthread_mutex_unlock(philo->left->mutex);
  pthread_mutex_unlock(philo->right->mutex);
  philo->is_right = false;
  philo->is_left = false;
  philo->rize_eat += 1;
  printf("Le philosophe %d a fini de manger et part se reposer.\n", philo->id);
  sleep(1);
  if (philo->id % 2)
    check_right(philo);
  else
    check_left(philo);
  return (NULL);
}

void		*check_left(void *pt)
{
  t_philo	*philo;

  philo = (t_philo *)pt;
  if (philo->rize_quant <= 0)
    {
      printf("Le philosophe %d arrete de manger (%d part mangé).\n",
	     philo->id, philo->rize_eat);
      return (NULL);
    }
  pthread_mutex_lock(philo->left->mutex);
  philo->is_left = true;
  printf("Le philosophe %d prend la baguette a sa gauche.\n", philo->id);
  if (philo->is_right)
    eat_rice(philo);
  else 
    check_right(philo);
  return (NULL);
}

void		*check_right(void *pt)
{
  t_philo	*philo;

  philo = (t_philo *)pt;
  if (philo->id == 6)
    printf("le philosohe 6 ce repose\n");
  if (philo->rize_quant <= 0)
    {
      printf("Le philosophe %d arrete de manger (%d part mangé).\n",
	     philo->id, philo->rize_eat);
      return (NULL);
    }
  pthread_mutex_lock(philo->right->mutex);
  philo->is_left = true;
  printf("Le philosophe %d prend la baguette a sa droite.\n", philo->id);
  if (philo->is_left)
    eat_rice(philo);
  else
    check_right(philo);
  return (NULL);
}
