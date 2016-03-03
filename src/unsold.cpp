//
// unsold.cpp for  in /home/frasse_l/Projets/202unsold
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Wed Mar  2 12:54:17 2016 loic frasse-mathon
// Last update Thu Mar  3 03:08:12 2016 loic frasse-mathon
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include "unsold.hh"

uns::Unsold::Unsold(int a, int b)
{
  this->a = a;
  this->b = b;
}

uns::Unsold::~Unsold()
{
}

void	uns::Unsold::Calc_tab()
{
  int	x;
  int	y;
  float	sum[6];

  Separator();
  std::cout << "\tX=10\tX=20\tX=30\tX=40\tX=50\tY law" << std::endl;
  y = 10;
  bzero(sum, sizeof(float) * 6);
  while (y <= 60)
    {
      x = 10;
      sum[5] = 0;
      std::cout << "Y=" << y << std::fixed << std::setprecision(3);
      while (x <= 50)
	{
	  tab[x / 10 - 1][y / 10 - 1] =
	    (y == 60 ? sum[x / 10 - 1] :
	     (float)((a - x) * (b - y)) / (float)((5 * a - 150) * (5 * b - 150)));
	  sum[x / 10 - 1] += tab[x / 10 - 1][y / 10 - 1];
	  std::cout << "\t" << tab[x / 10 - 1][y / 10 - 1];
	  sum[5] += tab[x / 10 - 1][y / 10 - 1];
	  x += 10;
	}
      std::cout << "\t" << sum[5] << std::endl;
      tab[x / 10 - 1][y / 10 - 1] = sum[5];
      y += 10;
    }
}

void	uns::Unsold::Calc_zlaw()
{
  int	x;
  int	y;

  Separator();
  x = 0;
  bzero(ztab, sizeof(float) * 10);
  std::cout << "z\t20\t30\t40\t50\t60\t70\t80\t90\t100\ttotal" << std::endl;
  std::cout << "p(Z=z)";
  while (x < 5)
    {
      y = 0;
      while (y < 5)
	{
	  ztab[x + y] += tab[x][y];
	  ztab[9] += tab[x][y];
	  y++;
	}
      x++;
    }
  x = 0;
  while (x < 10)
    {
      std::cout << "\t" << ztab[x];
      x++;
    }
  std::cout << std::endl;
}

void	uns::Unsold::Calc_variance()
{
  float	var[6];
  int	i;

  i = 0;
  bzero(var, sizeof(float) * 6);
  while (i < 5)
    {
      var[0] += (i + 1) * 10 * tab[i][5];
      var[2] += (i + 1) * 10 * tab[5][i];
      var[4] += (i + 2) * 10 * ztab[i];
      i++;
    }
  i = 0;
  while (i < 5)
    {
      var[1] += ((i + 1) * 10 - var[0]) * ((i + 1) * 10 - var[0]) * tab[i][5];
      var[3] += ((i + 1) * 10 - var[2]) * ((i + 1) * 10 - var[2]) * tab[5][i];
      if (i < 4)
	var[4] += (i + 7) * 10 * ztab[i + 5];
      i++;
    }
  i = 0;
  while (i < 9)
    {
      var[5] += ((i + 2) * 10 - var[4]) * ((i + 2) * 10 - var[4]) * ztab[i];
      i++;
    }
  Separator();
  std::cout << std::setprecision(1);
  std::cout << "expected value of X:\t" << var[0] << std::endl;
  std::cout << "variance of X:\t\t" << var[1] << std::endl;
  std::cout << "expected value of Y:\t" << var[2] << std::endl;
  std::cout << "variance of Y:\t\t" << var[3] << std::endl;
  std::cout << "expected value of Z:\t" << var[4] << std::endl;
  std::cout << "variance of Z:\t\t" << var[5] << std::endl;
  Separator();
}

void	uns::Unsold::Separator()
{
  std::cout << "————————————————————————————————————————"
	    << std::endl;;
}
