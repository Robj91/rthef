void main(void)
{
 int &nstat = create_sprite(308, 407, 0, 98, 3);
 sp_noclip(&nstat, 1);
 sp_que(&nstat, -1000);
 sp_nohit(&nstat, 1);

 int &nstat2 = create_sprite(610, 287, 0, 98, 1);
 sp_noclip(&nstat2, 1);
 sp_que(&nstat2, -1000);
 sp_nohit(&nstat2, 1);

 int &nstat3 = create_sprite(14, 287, 0, 98, 2);
 sp_noclip(&nstat3, 1);
 sp_que(&nstat3, -1000);
 sp_nohit(&nstat3, 1);
}