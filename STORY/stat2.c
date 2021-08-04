//the puzzle status bar script

//puzzle title buttons is suence 36
//the pframe of the puzzle title is passed in sp_custom key "puzzle_pframe"

void main(void)
{
 int &val1;
 int &val2;

 //create the help/info button
 &save_x = sp_x(&current_sprite, -1);
 &save_y = sp_y(&current_sprite, -1);
 &save_x += 238;
 &save_y += 34;
 &val2 = create_sprite(&save_x, &save_y, 0, 98, 6);
 sp_noclip(&val2, 1);
 sp_que(&val2, 1001);
 sp_script(&val2, "but-hi");
 
 //create the system access button
 &save_x = sp_x(&current_sprite, -1);
 &save_x += 15;
 &val2 = create_sprite(&save_x, &save_y, 0, 98, 5);
 sp_noclip(&val2, 1);
 sp_que(&val2, 1001);
 sp_script(&val2, "but-sa");

 //create the puzzle title button
 &save_x = sp_x(&current_sprite, -1);
 &save_x -= 205;
 &val1 = sp_custom("puzzle_pframe", &current_sprite, -1);
 &val2 = create_sprite(&save_x, &save_y, 0, 36, &val1);
 sp_noclip(&val2, 1);
 sp_que(&val2, 1001);
 sp_script(&val2, "but-pz");
}