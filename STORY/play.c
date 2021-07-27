//Scriptfor screen 3
//This has the part where the extra '5' gets removed
//and the power surge
//and then back to the document 
//where the '55' glitches out
//this is mostly done with full-screen sprites
//and changing them simultaneously

void main(void)
{
//make the current sprite invisible
 sp_nodraw(&current_sprite, 1);
 sp_nohit(&current_sprite, 1);
 if (&player_map == 3)
 {
 //create the notepad document image
  int &npad = create_sprite(429, 302, 0, 99, 6);
  sp_pseq(&npad, 99);
  sp_pframe(&npad, 6);
  sp_que(&npad, -600);
  wait(500);
  
 //speech bubble
  int &spch = create_sprite(562, 274, 0, 150, 8);
  sp_que(&spch, 500);
  sp_pseq(&spch, 150);
  sp_pframe(&spch, 8);
  sp_que(&spch, -500);
  Playsound(61,22050,0,0,0); 
  wait_for_button();
  sp_nodraw(&spch, 1);
  
 //create cursor
  int &mouse = create_sprite(395, 450, 0, 151, 1);
  sp_pseq(&mouse, 151);
  sp_pframe(&mouse, 1);
  sp_nohit(&mouse, 1);
  sp_que(&mouse, 500);
  sp_speed(&mouse, 4);
 
 //move the cursor on screen 
  move(&mouse, 7, 195, 1);
  Playsound(64,50250,0,0,0); 
  move_stop(&mouse, 7, 195, 1); 

 //create clicking noises and change notepad frame 
  wait(100);
  Playsound(62,44100,0,0,0);
  wait(300);
  sp_pframe(&npad, 7);
  wait(750);
  Playsound(62,44100,0,0,0);
  sp_pframe(&npad, 8);
  wait(700);

 //create text
  sp_x(&spch, 430);
  sp_y(&spch, 42);
  sp_pseq(&spch, 160);
  sp_pframe(&spch, 3);
  sp_nodraw(&spch, 0);
  Playsound(63,44100,0,0,0); 
  wait(700);
  wait_for_button(); 

 //move text off screen
  sp_speed(&spch, 7);
  Playsound(64,36050,0,0,0); 
  move_stop(&spch, 2, 470, 1);
  wait(650);

 //temporarily make the sprites invisible while changing them
 //probably not necessary but just being safe
  sp_nodraw(&spch, 1);
  sp_nodraw(&npad, 1);
  sp_nodraw(&mouse, 1);

 //change x and y of notepad 
 //and change sequence to power meter image
  sp_x(&npad, 433);
  sp_y(&npad, 322);
  sp_pseq(&npad, 152);
  sp_pframe(&npad, 1);
  sp_nodraw(&npad, 0);

 //change x and y of text
 //and change it to power surge text
  sp_x(&spch, 320);
  sp_y(&spch, 372);
  sp_pseq(&spch, 160);
  sp_pframe(&spch, 4);
  sp_size(&spch, 200);
  sp_nodraw(&spch, 0);
  sp_gold(&spch, 0);

 //give text the script which makes it flash
  sp_script(&spch, "psurge");  
 
 //stop playing the current midi
  stopmidi();

 //create grey rectangle gauge on top meter
  int &gau = create_sprite(320, 70, 0, 854, 1);
  sp_pseq(&gau, 854);
  sp_pframe(&gau, 1);
  sp_speed(&gau, 5);

 //create grey rectangle gauge on second meter
  int &gau2 = create_sprite(495, 145, 0, 854, 1);
  sp_pseq(&gau2, 854);
  sp_pframe(&gau2, 1);
  sp_speed(&gau2, 5);

 //create grey rectangle gauge on third meter
  int &gau3 = create_sprite(417, 230, 0, 854, 1);
  sp_pseq(&gau3, 854);
  sp_pframe(&gau3, 1);
  sp_speed(&gau3, 5);

 //create grey rectangle gauge on fourth meter
  int &gau4 = create_sprite(444, 315, 0, 854, 1);
  sp_pseq(&gau4, 854);
  sp_pframe(&gau4, 1);
  sp_speed(&gau4, 5);

 //give grey gauges their own scripts
 //these scripts will make them move
 //right and left randomly
  sp_script(&gau, "gau");
  sp_script(&gau2, "gau");
  sp_script(&gau3, "gau");
  sp_script(&gau4, "gau");

 //play power surge sound
  Playsound(60,44100,0,0,1); 
  &save_x = 0;
  wait(10000);
  &save_x = 1;
  
 //scene over
 //let's make everything invisible again 
  sp_nodraw(&gau, 1);
  sp_nodraw(&gau2, 1);
  sp_nodraw(&gau3, 1);
  sp_nodraw(&gau4, 1);
  sp_nodraw(&npad, 1);
  sp_nodraw(&mouse, 1);
  sp_nodraw(&spch, 1);
  sp_size(&spch, 100);
  
 //and change back to the notepad
  sp_x(&npad, 429);
  sp_y(&npad, 302);
  sp_pseq(&npad, 99);
  sp_pframe(&npad, 8);
  sp_nodraw(&npad, 0);
  wait(1000);
  kill_all_sounds(); 

 //create text
  sp_x(&spch, 430);
  sp_y(&spch, 42);
  sp_pframe(&spch, 6);
  sp_nodraw(&spch, 0);
  Playsound(63,44100,0,0,0);
  wait(700); 
  wait_for_button();

 //move text off screen
  Playsound(61,35000,0,0,0); 
  move_stop(&spch, 6, 820, 1);
  sp_nodraw(&spch, 1);

//let's use the size command with a loop
//to create an effect of zooming in
grow:
  &gau = sp_x(&npad, -1);
  &gau4 = sp_size(&npad, -1);
  &gau4 += 3;
  &gau += 6;

  if (&gau < 1030)
	sp_x(&npad, &gau);

  if (&gau4 == 106) 
	Playsound(67,36000,0,0,0);

  sp_size(&npad, &gau4);
  wait(0);
  if (&gau4 < 200)
	goto grow;

  &gau = 0;
  &gau2 = 1000;
  &gau3 = 900;

//create glitchy 55 effect
loop:
  sp_pframe(&npad, 6);

  if (&gau < 9) 
	Playsound(65,44100,0,0,0); 

  wait(&gau2); 
  sp_pframe(&npad, 8);

  if (&gau < 9) 
	Playsound(65,44100,0,0,0);

  if (&gau == 9) 
	Playsound(66,44100,0,0,1);

  wait(&gau3);
  &gau += 1;
  if (&gau > 4) 
  {  
   if (&gau < 7)
   {
    &gau2 -= 150;
    &gau3 -= 150;
   }
  }
  if (&gau == 8)
  {
   &gau2 = 100;
   &gau3 = 120;
  }
  if (&gau == 9)
  {
   &gau2 = 20;
   &gau3 = 20;
  } 
  if (&gau != 50)
	goto loop;
 
 //change frame to notepad with single 5
 //and create explosion
  sp_pframe(&npad, 6);
  kill_all_sounds();
  playsound(24, 22052, 0, 0, 0);
  int &explo = create_sprite(220, 238, 7, 167, 1);
  sp_seq(&explo, 167);
  sp_pframe(&npad, 8);
  wait(250); 

 //change screens
  script_attach(1000);
  fade_down();
  wait(400);
  &player_map = 34;
  load_screen(34);
  draw_screen();
  fade_up();
  kill_this_task();  
 }
}