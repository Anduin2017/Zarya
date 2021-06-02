# Zarya

使用方法: 启动Zarya后，将会以wwwroot目录作为Web应用的根目录，以9000作为端口号，承载Web应用程序。

## 这个项目为什么后来不再被维护了

我在维护Zarya后，突然认识到原来做一个Web Server要处理的细节实在是太多了……

中间件、缓存、依赖注入、断点续传、ETag、Cookie、上下文发现和响应渲染、性能、过滤器、保护器……

所以我后来又拿C#重新写了一遍这个项目，在这儿 [https://github.com/Anduin2017/Genji.git](https://github.com/Anduin2017/Genji.git)

对Zarya感兴趣的朋友，它没有完工，只有基础的静态文件承载能力。如果你愿意扩展它，请带走这份代码。如果你对自建HTTP服务器感兴趣，请参考Genji。


## 如何运行
运行需要的环境：  
* Linux (Windows 下不支持)  

运行前需要安装：

* bower
* npm
* git
* g++

运行前需要准备：  

    bower install
    npm install

启动项目所需的命令：

    ./start.sh

之后启动浏览器，访问下面地址：

    http://localhost:9000/

如果能够正常体验应用，那么恭喜，你已经完成了该项目的编译、链接和运行！

## 如何部署到生产环境中

尚未完成

## 如何扩展开发

### 目录说明

### 中间件说明

### 关键文件

## 如何贡献
