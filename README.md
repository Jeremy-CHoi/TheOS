# TheOS
This is our repository for CSC3002 project, please be sure to take care of your folder.<br>
Members can clone all the files to your local, and push the whole project file to this<br>
repository.<br>
TO WU:<br>
The Snake project has already been packed into WU folder, you can delete the file outside<br>
of the folder.<br>



UI部分：
1.登陆界面，widget那个文件，能不能加个tab，让用户直接按enter就可以选择登陆。\n
2.目前暂时用登陆界面的取消按钮来注册，待改名或者额外加slot。\n
  注册功能目前有个用户名和密码都是admin。已注册过的用户名不支持重新注册。
3.开机动画本来想用静态的，然后加上文字。结果开机的splash上面加不上文字，Windows和mac都不行，目前就改成了个gif实现开机动画。
  预期：想实现开机时有个welcome，xxx，但是目前splashscreen上加不上文字。
  注意：因为gif实现要求用到Sleep函数，故加了<Windows.h>，所以只能在Windows系统运行。
 4.用window运行时，发现下面的状态栏会被背景掩盖掉，要用虚拟机跑下重新调整背景。
 5.让元森在mainwindow里面加个槽，sk再加上关机和注销的功能。
