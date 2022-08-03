# LinuxEmulator
模拟运行LinuxSSH,用于练习指令
目前支持（模拟）的系统包括CentOS,Ubuntu等.
## 如何使用
### 编译运行(以Ubuntu为例)(推荐):
```bash
apt install -y g++ //安装g++
apt install -y curl //安装curl
curl https://github.com/AS13379/LinuxEmulator/releases/download/ver.2.alpha-1/main.cpp -o le.cpp //下载源文件
g++ le.cpp -o LinuxEmulator //编译
./LinuxEmulator //运行
```
将其组合起来:
```bash
apt install -y g++ && apt install -y curl && curl https://github.com/AS13379/LinuxEmulator/releases/download/ver.2.alpha-1/main.cpp -o le.cpp && g++ le.cpp -o LinuxEmulator && ./LinuxEmulator
```
### 直接运行:
```bash
apt install -y g++ && apt install -y curl && curl https://github.com/AS13379/LinuxEmulator/releases/download/ver.2.alpha-1/LinuxEmulator -o LinuxEmulator && ./LinuxEmulator
```
