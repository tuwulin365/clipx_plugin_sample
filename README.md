历史悠久的windows平台的粘贴板管理工具，已经停止更新好多年了。这个仓库存放的是官网上下载的插件SDK和示例工程。原工程使用VC++6开发。

我改用VS2015，并解决了编译问题（编译选项错误、缺少一些宏定义、函数返回值错误等）。支持生成x86和x64插件。只是x64的debug版本运行不起来，不知道为啥。其他版本都运行正常。

VC++6的工程文件：
\clipx_plugin_sample\plugins\Sample\Sample.dsw

vs2015的工程文件：
\clipx_plugin_sample\plugins\Sample\Sample.sln

clipx官网：
http://bluemars.org/clipx/
