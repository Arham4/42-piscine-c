#include "ft_perso.h"
#include <stdio.h>

int main() {
	t_perso jack;
	jack.name = strdup("jack");
	jack.life = 100.0;
	jack.age = 42;
	jack.profession = SAVE_THE_WORLD;
	return (0);
}
