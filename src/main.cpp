//
// main.cpp for  in /home/frasse_l/Projets/202unsold
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Wed Mar  2 12:25:40 2016 loic frasse-mathon
// Last update Thu Mar  3 02:56:10 2016 loic frasse-mathon
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include "unsold.hh"

static bool	is_number(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (i == 0 && (str[i] == '-' || str[i] == '+'))
	i++;
      else if (str[i] < '0' || str[i] > '9')
	return (false);
      else
	i++;
    }
  return (true);
}

static void	usage(char **av)
{
  std::cout << "USAGE" << std::endl;
  std::cout << "\t\t" << av[0] << " a b" << std::endl;
  std::cout << "DESCRIPTION" << std::endl;
  std::cout << "a\tconstant computed from the past results" << std::endl;
  std::cout << "b\tconstant computed from the past results" << std::endl;
  exit(0);
}

static void	error_args()
{
  std::cerr << "Error: Bad arguments, please run with -h for help" << std::endl;
  exit(84);
}

static void	unsold(int a, int b)
{
  uns::Unsold	unsold(a, b);

  if (a <= 50 || b <= 50)
    error_args();
  unsold.Calc_tab();
  unsold.Calc_zlaw();
  unsold.Calc_variance();
}

int	main(int ac, char **av)
{
  int	i;
  int	args[2];
  
  i = 1;
  while (i < ac)
    {
      if (std::string("-h") == av[1])
	usage(av);
      if (i > 2 || !is_number(av[i]))
	error_args();
      errno = 0;
      args[i - 1] = atoi(av[i]);
      if (errno == ERANGE)
        error_args();
      i++;
    }
  if (i != 3)
    error_args();
  unsold(args[0], args[1]);
  return (0);
}
