# Wolf3D
Le nouveau GTA

structure =>	{environnement, hauteur envi, plafond, hauteur plafond, item}

ENVIRONNEMENT
{1, 999}		Les Sols
{1002, 1999}	Les Murs
{1000, 1001}	Les Portes
Porte verticale = 1001 / horizontale = 1000

HAUTEUR ENVI
int de 1 (pour le sol) a 5 (hauteur max d'un mur)

PLAFOND
{1, 999}		Les Plafonds
1 = pas de plafond
2 = unicolor gris

HAUTEUR PLAFOND
int de 1 a 5

ITEM
{2, 5}		Le Joueur
{6, 99}		Les Items
1 = pas d'item
2 = spawn joueur / camera direction nord
3 = spawn joueur / camera direction est
4 = spawn joueur / camera direction sud
5 = spawn joueur / camera direction ouest
