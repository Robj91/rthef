void main( void )
 {
 //text in... some other color
 wait(10);
 int &my_x = sp_x(&current_sprite, -1);
 int &my_y = sp_y(&current_sprite, -1);
 int &text_said;
 &my_x -= &house_x;
 &my_y -= &house_y;
 &text_said = say("`3&my_x , &my_y", &current_sprite);
 sp_kill(&text_said, 2147483647);
 }