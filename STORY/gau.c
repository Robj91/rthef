//Script for gauges on the power meters in intro
//To make them move randomly left and right

void main(void)
{
 sp_speed(&current_sprite, 7);
loop:
 int &x = sp_x(&current_sprite, -1);
 int &rand = random(268, 243);
 
 if (&rand == &x)
	goto loop;
 if (&rand > &x)
	move_stop(&current_sprite, 6, &rand, 1);
 if (&rand < &x)
	move_stop(&current_sprite, 4, &rand, 1);
goto loop;
}
 