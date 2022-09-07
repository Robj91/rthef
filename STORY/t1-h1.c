//Freddys Four Fingers house

void main(void)
{
 preload_seq(93);
 preload_seq(95);
 preload_seq(64);

 editor_type(1, 0);
 editor_type(2, 0);
 editor_type(3, 0);
 editor_type(4, 0);
 editor_type(5, 0);
 editor_type(6, 0);

 //create the extra sprites
 //left side bottom wall fence
 &save_x = editor_frame(1, -1);
 if (&save_x == 0)
 {
  &save_x = create_sprite(183, 381, 0, 93, 1);
  sp_script(&save_x, "t1-wl");
 }
 
 //right side bottom wall fence
 &save_x = editor_frame(2, -1);
 if (&save_x == 0)
 {
  &save_x = create_sprite(459, 381, 0, 93, 1);
  sp_script(&save_x, "t1-wl");
 }
 
 //let side odd hardness
 &save_x = editor_frame(3, -1);
 if (&save_x == 0)
 {
  &save_x = create_sprite(111, 293, 0, 95, 7);
  sp_script(&save_x, "t1-hrd");
 }
 
 //top extensive hardness sprite
 &save_x = editor_frame(4, -1);
 if (&save_x == 0)
 { 
  &save_x = create_sprite(295, 85, 0, 64, 7);
  sp_script(&save_x, "t1-hrd2"); 
 }

 //left extensive hardness sprite
 &save_x = editor_frame(5, -1);
 if (&save_x == 0)
 { 
  &save_x = create_sprite(130, -104, 0, 64, 8);
  sp_script(&save_x, "t1-hrd2");
 }
 
 //right extensive hardness sprite
 &save_x = editor_frame(6, -1);
 if (&save_x == 0)
 {  
  &save_x = create_sprite(484, -20, 0, 64, 8);
  sp_script(&save_x, "t1-hrd2");
 }
}