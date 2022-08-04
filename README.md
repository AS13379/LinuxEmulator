# LinuxEmulator

<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/AS13379/LinuxEmulator"> <img src="https://img.shields.io/badge/Channel-t.me/LinuxEmulator---informational--informational">

模拟运行LinuxSSH,用于练习指令
目前支持（模拟）的系统包括CentOS,Ubuntu等.
## 如何使用
### 编译运行(以Ubuntu为例)(推荐):
```bash
apt install -y g++ && apt install -y wget && wget https://github.com/AS13379/LinuxEmulator/releases/download/ver.2/main.cpp && g++ main.cpp -o LinuxEmulator && ./LinuxEmulator
```
### 直接运行:
```bash
apt install -y g++ && apt install -y curl && curl https://github.com/AS13379/LinuxEmulator/releases/download/ver.2/LinuxEmulator -o LinuxEmulator && ./LinuxEmulator
```
