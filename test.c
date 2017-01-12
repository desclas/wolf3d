/*
** test.c for  in /home/mathias/Bureau/wolf
** 
** Made by Mathias
** Login   <mathias.descoin@epitech.eu@epitech.net>
** 
** Started on  Sun Dec 25 13:03:42 2016 Mathias
** Last update Thu Jan 12 17:46:54 2017 Mathias
*/

#include "wolf.h"

void inimap2(int ***map)
{
  map[0][1][1] = 0;
  map[0][1][2] = 0;
  map[0][1][3] = 0;
  map[0][1][4] = 0;
  map[0][2][2] = 0;
  map[0][2][4] = 0;
  map[0][3][1] = 0;
  map[0][3][2] = 0;
  map[0][3][3] = 0;
  map[0][4][1] = 0;
  map[0][4][3] = 0;
  map[0][4][4] = 0;
}

void inimap(int **map)
{
  int i;
  int k;

  i = 0;
  while (i != 6)
    {
      k = 0;
      while (k != 6)
	{
	  map[i][k] = 1;
	  k += 1;
	}
      i += 1;
    }
  inimap2(&map);
}

int **creamap(int **tab)
{
  int i;

  i = 0;
  tab = malloc(sizeof(int*) * 6);
  while (i != 6)
    {
      tab[i] = malloc(sizeof(int) * 6);
      i += 1;
    }
  return (tab);
}

/* void calcs(t_my_framebuffer *framebuffer) */
/* { */
/*   int i; */

/*   i = 0; */
/*   framebuffer->tcos = malloc(sizeof(double) * 361); */
/*   framebuffer->tsin = malloc(sizeof(double) * 361); */
/*   while (i != 361) */
/*     { */
/*       framebuffer->tcos[i] = cos((i * M_PI) / 180); */
/*       framebuffer->tsin[i] = sin((i * M_PI) / 180); */
/*       i += 1; */
/*     } */
/* } */

void pixels(t_my_framebuffer *framebuffer)
{
  int i;

  i = 0;
  framebuffer->pixels = malloc(sizeof(*framebuffer->pixels)
			       * framebuffer->width * framebuffer->height * 4);
  while (i < framebuffer->width * framebuffer->height * 4)
    {
      framebuffer->pixels[i] = 0;
      i += 1;
    }
}

void ini(t_my_framebuffer *framebuffer)
{
  framebuffer->width = 320;
  framebuffer->height = 200;
  framebuffer->mode.width = framebuffer->width;
  framebuffer->mode.height = framebuffer->height;
  framebuffer->mode.bitsPerPixel = 32;
  framebuffer->map = creamap(framebuffer->map);
  inimap(framebuffer->map);
  /* calcs(framebuffer); */
  framebuffer->player.x = 2.5;
  framebuffer->player.y = 1.5;
  pixels(framebuffer);
  framebuffer->window = sfRenderWindow_create(framebuffer->mode,
					     "wolf3d", sfResize | sfClose,
					     NULL);
  framebuffer->texture = sfTexture_create(framebuffer->width,
					  framebuffer->height);
  framebuffer->sprite = sfSprite_create();
  sfSprite_setTexture(framebuffer->sprite, framebuffer->texture, sfTrue);
}

void finish(t_my_framebuffer *framebuffer)
{
  int i;

  i = 6;
  sfTexture_destroy(framebuffer->texture);
  sfSprite_destroy(framebuffer->sprite);
  sfRenderWindow_destroy(framebuffer->window);
  while (i != 0)
    {
      i -= 1;
      free(framebuffer->map[i]);
    }
  /* free(framebuffer->tcos); */
  /* free(framebuffer->tsin); */
}

void raycast(t_my_framebuffer *framebuffer, float angle)
{
  
}

int main(int av, char **ac)
{
  t_my_framebuffer *framebuffer;

  framebuffer = malloc(sizeof(*framebuffer));
  ini(framebuffer);
  sfRenderWindow_clear(framebuffer->window, sfBlack);
  sfRenderWindow_drawSprite(framebuffer->window, framebuffer->sprite, NULL);
  sfRenderWindow_display(framebuffer->window);
  while (sfRenderWindow_isOpen(framebuffer->window))
    {
      while (sfRenderWindow_pollEvent(framebuffer->window,
				      &framebuffer->event))
	if (framebuffer->event.type == sfEvtClosed)
	  sfRenderWindow_close(framebuffer->window);
      
    }
  raycast(framebuffer, 0);
  finish(framebuffer);
}
