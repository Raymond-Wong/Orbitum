# Orbitum
中山大学软件学院2015春季学期软件设计课程课程设计——Orbitum

## 环境
+ win7 64位
+ vs2012
+ cocos2d-x 3.0

## 运行方式
+ 这个文件夹下面还缺少一个cocos2d的文件夹。这个文件夹是放cocos引擎源码的，很大，所以我没有上传。
+ 你配置好环境后新建一个项目``cocos new proj_name-l cpp -d . -p package_name``
+ 将新建项目中的cocos2d文件夹复制到我们项目的根目录下
+ 用vs打开proj.win32/Orbitum.sln
+ ctri+F5运行程序

## 协作方式
1. 假设本地已经有dev0，现在要开发功能xxx，就先<br>
``git checkout -b xxx``<br>
它会自动切换到xxx分支，<br>
2. 各种写代码，但是千万不要复制粘贴覆盖文件！<br>
写一段，就``git status``看一下<br>
3. 然后``git add files...`` 增加到待提交区
4. 再用``git commit -m "descrption"``<br>
把待提交区的更新全部提交，这时候再<br>
5. 然后，最终编码完成后，要合并了<br>
就千万记得先切回到 dev0<br>
``git checkout dev0``<br>
6. 然后更新dev0分支<br>
``git pull origin dev0``<br>
7. 然后，再切换回xxx分支，把更新完的dev0合并到xxx分支<br>
``git checkout xxx``<br>
``git merge --no-ff dev0<br>``
8. 这个时候如果有冲突就解决冲突，没有就继续<br>
再切换到dev0<br>
``git checkout dev0``<br>
9. 然后把目前最新的xxx分支（已拥有dev0最新代码）合并到dev0<br>
``git merge --no-ff xxx``<br>
10. 至此，dev0与xxx都是最新了，就可以进一步推到远程仓库<br>
``git push``
