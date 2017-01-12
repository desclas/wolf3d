/*
** wolf.h for  in /home/mathias/Bureau/wolf
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Sun Dec 25 12:55:24 2016 Mathias
** Last update Wed Jan  4 13:34:31 2017 Mathias
*/

#ifndef WOLF_H_
# define WOLF_H_

# include <SFML/Graphics.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_my_framebuffer
{
  sfUint8 *pixels;
  int width;
  int height;
  sfVideoMode mode;
  sfRenderWindow *window;
  sfTexture *texture;
  sfSprite *sprite;
  sfEvent event;
  int **map;
  double *tcos;
  double *tsin;
  sfVector2f player;
  sfVector2f wind;
  sfVector2f to;
}		t_my_framebuffer;

#endif /* !WOLF_H */
