/*
** main.c for main in /home/faisant/Bureau/projet/philo
** 
** Made by florian faisant
** Login   <faisant@epitech.net>
** 
** Started on  Thu Mar 20 07:36:42 2014 florian faisant
** Last update Fri Mar 21 17:20:39 2014 florian faisant
*/

#include		<stdlib.h>
#include		"philo.h"

int			main(void)
{
  t_philo		philo[NB_PHILO];
  t_stick		stick[NB_STICK];
  pthread_mutex_t	mutex[NB_STICK];
  pthread_t		thread[NB_PHILO];
  int			rize_qant;

  rize_qant = RIZE_QUANT;
  if (init_stick(stick, mutex) == false)
    return (EXIT_FAILURE);
  if (init_philo(philo, stick, thread, rize_qant) == false)
    return (EXIT_FAILURE);
  run(philo);
  return (EXIT_SUCCESS);
}
