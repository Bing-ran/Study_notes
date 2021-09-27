1、 安装nfs
	sudo apt-get install nfs-kernel-server nfs-common portmap -y

2、 配置nfs，修改/etc/exports配置文件
	例如：	/home/master/sambashare/linux_study/drivers/rootfs/rootfs *(rw,sync,no_root_squash,no_subtree_check)

3、 重启配置文件和服务
	sudo /etc/init.d/portmap restart
	sudo /etc/init.d/nfs-kernel-server restart