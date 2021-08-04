//the puzzle status bar script

//the pframe of the puzzle title is passed in sp_custom key "puzzle_pframe"

void main(void)
{
 int &val1;

 //create the help/info button
 &save_x = sp_x(&current_sprite, -1);
 &save_y = sp_y(&current_sprite, -1);
 &save_x += 238;
 &save_y += 34;
 &save_x = create_sprite(&save_x, &save_y, 0, 98, 6);
 sp_noclip(&save_x, 1);
 sp_que(&save_x, 1001);
 
 //create the system access button
 &save_x = sp_x(&current_sprite, -1);
 &save_x += 15;
 &save_x = create_sprite(&save_x, &save_y, 0, 98, 5);
 sp_noclip(&save_x, 1);
 sp_que(&save_x, 1001);

 //create the puzzle title button
 &save_x = sp_x(&current_sprite, -1);
 &save_x -= 205;
 &val1 = sp_custom("puzzle_pframe", &current_sprite, -1);
 &save_x = create_sprite(&save_x, &save_y, 0, 98, &val1);
 sp_noclip(&save_x, 1);
 sp_que(&save_x, 1001);
}