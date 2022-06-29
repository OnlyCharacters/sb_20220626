## 使用说明

#### 需要具有 GUI 的 Linux 系统

1. 在虚拟机中安装 Chrome
2. 虚拟机中安装 python3，pip3
3. pip3 install selenium
4. git clone <https://github.com/OnlyCharacters/sb_20220626>
5. 根据 Chrome 版本，到 [Chrome Driver](https://chromedriver.chromium.org/downloads) 下载对应版本的 driver，解压并放到 sb_20220626/ 下
6. 下载 [webbenchmark](https://github.com/maintell/webBenchmark)，同样放到 sb_20220626/ 下
7. make
8. 在 Linux GUI 界面下 cd 到 sb_20220626/ ，打开终端，使用非 root 用户执行 make 得到的二进制文件

#### 注意事项

* 如果后续，网址变了，可以查看 [click2.py](http://click2.py) 修改
* chrome 获取下载连接后会立即被结束，也可能还没获取到连接就被结束，这个时间可以在 [click2.py](http://click2.py) 中修改
* chrome 可能会下载文件一小部分到 \~/Download 下，需要自己删除