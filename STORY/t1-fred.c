//Freddy Four Fingers

void main(void)
{
 int &val1;
 int &val2;
}

void talk(void)
{
 freeze(1);

talk_menu:
 &val1 = editor_frame(7, -1);
 choice_start();
 set_title_color 10
 set_y 130
 title_start();
 A man stands in front of you, his hand in a fist, fingers concealed, as blood runs down his hand
 title_end();
 "Who are you?"
 (&val1 == 1) "What's that item on your left?"
 (&val1 == 1) "What's that item in front of you?"
 "leave"
 choice_end();
 
 if (&result == 1)
 {
  say_stop("Who are you?", 1);
  wait(200);
  say_stop("`3Hi, I'm Freddy Four Fingers and welcome to my store.", &current_sprite);
  wait(200);
  say_stop("Why four fingers?", 1);
  wait(200);
  say_stop("`3Fucked if I know. Buy something.", &current_sprite);
  wait(200);
  say_stop("Asshole.", 1);
  wait(200);
  say_stop("`3Prick.", &current_sprite);
  editor_frame(7, 1);
  goto talk_menu;
 }
 if (&result == 2)
 {
  //set the font colour
  set_font_color(12, 0, 255, 51);
  set_font_color(2, 85, 154, 99);
  
  say_stop("What's that item on your left", 1);
  wait(200);
  say_stop("`2Oh that item there, buddy? A cigar", &current_sprite);
  wait(200);
  say_stop("Ok, how much?", 1);
  wait(200);
  say_stop("`2For that, 1000 gold.", &current_sprite);
  wait(200);
  say_stop("1000 gold, what the hell?", 1);
  wait(200);
  if (&vcheck == 111)
  {
   &val1 = say_xy("`@cent cigar", 20, 58);
  }
  else
  {
   &val1 = say_xy("`@cent cigar", 23, 58);
  }
  sp_kill(&val1, 0);
  say_stop("`2You can't put a price on quality my friend, that's a        de               ", &current_sprite);
  sp_active(&val1, 0);
  wait(200);
  say_stop("you ok?", 1);
  wait(200);
  say_stop("`2ergh... my voice cracked, that's all. Now buy it or fuck off.", &current_sprite);
  
  //revert the font colour
  set_font_color(12, 255, 255, 2); 
  set_font_color(2, 8, 211, 252);
  goto talk_menu;
 }
 if (&result == 3)
 {
  //set the font colour
  set_font_color(12, 43, 178, 205);
  set_font_color(9, 104, 101, 210);
 
  say_stop("Ergh what the hell is this?", 1);
  wait(200);
  say_stop("`9What does it look like?", &current_sprite);
  wait(200);
  say_stop("A severed finger.. is it the extra one your missing?", 1);
  wait(200);
  say_stop("`9Listen, my stocks dry and I'm desperate, I'll sell anything at this point", &current_sprite);
  wait(200);
  say_stop("Why would anyone wanna buy your fifth, severed, bloody, finger?", 1);
  wait(200);
  if (&vcheck == 111)
  {
   &val1 = say_xy("`@finger", 38, 1);
   &val2 = say_xy("`@discount", -22, 39);
   sp_kill(&val1, 0);
   sp_kill(&val2, 0);
  }
  else
  {
   &val1 = say_xy("`@finger", 41, 1);
   &val2 = say_xy("`@discount", -20, 39);
   sp_kill(&val1, 0);
   sp_kill(&val2, 0);
  }
  say_stop("`9Well, this           is marked with a nice               so you never know", &current_sprite);
  sp_active(&val1, 0);
  sp_active(&val2, 0);
  wait(200);
  say_stop("right..", 1);

  //set the font colour
  set_font_color(12, 255, 255, 2); 
  set_font_color(9, 148, 198, 255);
  goto talk_menu;
 }
 
 unfreeze(1);
}