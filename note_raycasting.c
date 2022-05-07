// 1 position x et y du personnage 
//2 direction dirx, diry du personnage 
//planeX et planeY le plan caméra du joueur


int	while_window(t_data *data)
{
	int	x;

	x = 0;
	while (x < width_window)
	{
		//calculer la position et la direction du rayon double 
		cameraX = 2 * x / double(w) - 1; //coordonnée x dans l'espace caméra
		double rayDirX = dirX + planeX * cameraX;
		double rayonDirY = dirY + planeY * caméraX ;
		x++;
	}
}
int main(int /*argc*/, char */*argv*/ [])
{
	double pos_x, pos_y;  //x et y position de départ
	double dirX = -1, dirY = 0; //vecteur direction initial
	double planeX = 0, planeY = 0.66; //la version 2d raycaster du plan caméra

	double time = 0; //heure de la trame courante
	double oldTime = 0; //heure de l'image précédente
}