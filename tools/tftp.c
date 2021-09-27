1、 下载安装包
		客户端：tftp-hpa
		服务端：tftpd-hpa
		xinetd

2、 配置/etc/xinetd.conf,如下：
	# Simple configuration file for xinetd
	#
	# Some defaults, and include /etc/xinetd.d/
	defaults
	{
	# Please note that you need a log_type line to be able to use log_on_success
	# and log_on_failure. The default is the following :
	# log_type = SYSLOG daemon info
	}
	includedir /etc/xinetd.d

3、 配置/etc/default/tftpd-hpa
	# /etc/default/tftpd-hpa
	TFTP_USERNAME="tftp"
	TFTP_DIRECTORY="/tftpboot"		// 工作目录
	TFTP_ADDRESS="0.0.0.0:69"
	TFTP_OPTIONS="-l -c -s"

4、 配置/etc/xinetd.d/tftp
service tftp
{
	socket_type = dgram
	wait = yes
	disable = no
	user = root
	protocol = udp
	server = /usr/sbin/in.tftpd
	server_args = -s /tftpboot			// 配置服务器的文件存放的位置，就是进行 tftp 传输的时候，都是从该文件夹中搜索文件的
	#log_on_success += PID HOST DURATION
	#log_on_failure += HOST
	per_source = 11
	cps =100 2
	flags =IPv4
}

5、 重启服务
	sudo service tftpd-hpa restart
	sudo /etc/init.d/xinetd reload
	sudo /etc/init.d/xinetd restart

	重启服务
	sudo service tftpd-hpa restart
	打开服务
	sudo service tftpd-hpa start 
	关闭服务
	sudo service tftpd-hpa stop