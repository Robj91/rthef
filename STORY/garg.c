void main( void )
 {
 //script for gargoyle prototype

 //wait for house prototype to generate values for
 //house_x and house_y
 wait(10);
 int &my_x = sp_x(&current_sprite, -1);
 int &my_y = sp_y(&current_sprite, -1);
 int &text_said;
 //get relative position of house and gargoyle
 //if you write this down you can use it in hboxer.c
 &my_x -= &house_x;
 &my_y -= &house_y;
 &text_said = say("&my_x , &my_y", &current_sprite);
 sp_kill(&text_said, 2147483647);
 }