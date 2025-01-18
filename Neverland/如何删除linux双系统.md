昨天晚上安装archlinxu，搞了一晚上，太麻烦啦。
而且感觉很不好用，现在准备删掉。

是不是只需要删除所在的卷，然后把grub引导删掉就行来着。
试一下。
给EFI分区分配盘符，然后删掉/EFI/arch，可以给vscode管理员权限，然后用vscode删除。
``` bash
diskpart
list volume
select volume 3
remove letter=D
exit
```
删除盘符，然后把那个卷删除。
应该就好了。