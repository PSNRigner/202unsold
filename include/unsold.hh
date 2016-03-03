//
// unsold.hh for  in /home/frasse_l/Projets/202unsold
// 
// Made by loic frasse-mathon
// Login   <frasse_l@epitech.net>
// 
// Started on  Wed Mar  2 11:56:57 2016 loic frasse-mathon
// Last update Wed Mar  2 21:41:55 2016 loic frasse-mathon
//

#ifndef UNSOLD_HH_
# define UNSOLD_HH_

namespace	uns
{
  class		Unsold
  {
  public:
    Unsold(int, int);
    ~Unsold();
    void	Calc_tab();
    void	Calc_zlaw();
    void	Calc_variance();
  private:
    void	Separator();
    int		a;
    int		b;
    float	tab[6][6];
    float	ztab[10];
  };
}

#endif /* !UNSOLD_HH_ */
