# serverFrame

## 日志系统
log4j

## 配置系统
Config -> Yaml

配置的事件机制  
当一个配置项发生变化的时候，可以反向通知对应的代码， 回调

## 日志系统整合配置系统
```yaml
logs:
	- name: root
		level: (debug,info,warn,fatal)
		formatter: '%d%T%p%T%t%m%n'
		appender:
			- type: (StdoutLogAppender, FileLogAppender)
				level:
				file:
```

## 线程


## 协程库

## socket函数库

## http协议开发

## 分布协议

## 推荐系统

## 环境安装
#### boost
https://blog.csdn.net/u011641865/article/details/73498533
### yaml
https://blog.csdn.net/Fourier_Legend/article/details/82798297
