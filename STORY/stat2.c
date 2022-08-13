//the puzzle status bar script

//puzzle title buttons is suence 36
//the pframe of the puzzle title is passed in sp_custom key "puzzle_pframe"

void main(void)
{
 int &val1;
 int &val2;

 //side bars
 &val2 = create_sprite(86, 20, 0, 98, 5);
 sp_noclip(&val2, 1);
 sp_que(&val2, 1001); 
 &val2 = create_sprite(685, 21, 0, 98, 6);
 sp_noclip(&val2, 1);
 sp_que(&val2, 1001); 

 //create the keyboard button
 &save_x = sp_x(&current_sprite, -1);
 &save_y = sp_y(&current_sprite, -1);
 &save_x -= 297;
 &save_y += 60;
 &val2 = create_sprite(&save_x, &save_y, 0, 37, 1);
 sp_touch_damage(&val2, -1);
 sp_noclip(&val2, 1);
 sp_que(&val2, 1002);
 sp_script(&val2, "but-kb"); 

 //create the puzzle title button
 &save_x = sp_x(&current_sprite, -1);
 &save_y = sp_y(&current_sprite, -1);
 &save_x -= 201;
 &save_y += 34;
 &val1 = sp_custom("puzzle_pframe", &current_sprite, -1);
 &val2 = create_sprite(&save_x, &save_y, 0, 36, &val1);
 sp_noclip(&val2, 1);
 sp_que(&val2, 1001);
 sp_script(&val2, "but-pz");

 //create the system acess button
 &save_x = sp_x(&current_sprite, -1);
 &save_y = sp_y(&current_sprite, -1);
 &save_x += 243;
 &save_y += 42;
 &val2 = create_sprite(&save_x, &save_y, 0, 38, 1);
 sp_noclip(&val2, 1);
 sp_que(&val2, 1001);
 sp_script(&val2, "but-hi");
 
 //create the help/info button
 &save_x = sp_x(&current_sprite, -1);
 &save_x += 44;
 &val2 = create_sprite(&save_x, &save_y, 0, 38, 2);
 sp_noclip(&val2, 1);
 sp_que(&val2, 1001);
 sp_script(&val2, "but-sa");
}