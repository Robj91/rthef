//the puzzle status bar script

void main(void)
{
 //create the help/info button
 &save_x = sp_x(&current_sprite, -1);
 &save_y = sp_y(&current_sprite, -1);
 &save_x += 256;
 &save_y += 229;
 &save_x = create_sprite(&save_x, &save_y, 0, 98, 6);
 sp_noclip(&crap, 1);
 sp_que(&save_x, 1001);
 
 //create the system access button
 &save_x = sp_x(&current_sprite, -1);
 &save_y = sp_y(&current_sprite, -1);
 &save_x += 16;
 &save_y += 229
 &save_x = create_sprite(&save_x, &save_y, 0, 98, 6);
 sp_noclip(&crap, 1);
 sp_que(&save_x, 1001);
}