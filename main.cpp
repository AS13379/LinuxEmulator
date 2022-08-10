#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;
string keyin,keyinlist[5],sysimg[256],tmp,vm_sys[256],LocalSystem,dir = "~";
int cnt = 0,sys_id[256],vm_cnt = 0,start_cnt = 0;

int vm_centos_start() {
    string user,passwd;
    cout << "[NekoVM]VM CentOS Starting..." << endl;
    cout << "[NekoVM]Start Success." << endl;
    system("clear");
    cout << "CentOS Linux 7 (Core)" << endl << "Kernel 3.10.0-1160.62.1.el7.x86_64 on an x86_64" << endl << endl;
    while(1) {
    cout << "LinuxEmulator_Centos_7.0 login:";
    cin >> user;
    cout << "Psaaword:";
    cin >> passwd;
    if (user != "root" or passwd != "centospasswd") {
        cout << "Login Incorrect" << endl << endl;
    }
    else continue;
    }
    cout << endl;
    while (1) {
        cout << "[LinuxEmulator " << dir << "]# ";
    }
}

void GetLocalTime()
{
        time_t rawtime;
        struct tm *ptminfo;
        time(&rawtime);
        ptminfo=localtime(&rawtime);
        cout << ptminfo->tm_year+1900 << '-' << ptminfo->tm_mon+1 << '-' << ptminfo->tm_mday << ' ';
        cout << ptminfo->tm_hour << ':' << ptminfo->tm_min << ':' << ptminfo->tm_sec << ' ';
}
int img()
{
    if(keyinlist[1] == "create" or keyinlist[1] == "CREATE"){
        if(keyinlist[2] == "centos" or keyinlist[2] == "CENTOS"){
            GetLocalTime();
            cout << "System CentOS Created" << endl << "id = " << cnt << endl << "user = root" << endl << "passwd = centospasswd" << endl;
            sysimg[cnt] = "centos";
            cnt += 1;
            return 0;
        }
        if(keyinlist[2] == "ubuntu" or keyinlist[2] == "UBUNTU"){
            GetLocalTime();
            cout << "System ubuntu Created" << endl << "id = " << cnt << endl << "user = ubuntu" << endl << "passwd = password123" << endl;
            sysimg[cnt] = "ubuntu";
            cnt += 1;
            return 0;
        }
        if(keyinlist[2] == "debian" or keyinlist[2] == "DEBIAN"){
            GetLocalTime();
            cout << "System debian Created" << endl << "id = " << cnt << endl << "user = deuser" << endl << "passwd = password123d" << endl;
            sysimg[cnt] = "debian";
            cnt += 1;
            return 0;
        }
    }
    if(keyinlist[1] == "list" or keyinlist[1] == "LIST"){
        for(int i = 0; i < 256; i++){
            if(sysimg[i] != ""){cout << sysimg[i] << ",";}
        }
        cout << endl;
        return 0;
    }
}
int nekovm()
{
    if(keyinlist[1] == "input" or keyinlist[1] == "INPUT") {
        if(keyinlist[2] == "id" or keyinlist[2] == "ID") {
            sys_id[vm_cnt] = atoi(keyinlist[3].c_str());
            vm_sys[vm_cnt] = sysimg[sys_id[cnt]];
            GetLocalTime();
            cout << endl << "[NekoVM]" << "Input Success" << endl << "VM info:" << endl << "system_id = " << keyinlist[3] << endl << "system = " << sysimg[sys_id[vm_cnt]] << endl;
            cnt++;
            return 0;
        }

        if(keyinlist[2] == "name" or keyinlist[2] == "NAME"){
            if(keyinlist[3] == "centos" or keyinlist[3] == "CENTOS"){
                for (int i = 0; i < 256; i++){
                    if(sysimg[i] == "centos") {
                        sys_id[vm_cnt] = i;
                        vm_sys[vm_cnt] = "centos";
//                        //dev_start
//                        for (int j = 0; j < 256; j++){
//                            cout << vm_sys[j] << ' ';
//                        }
//                        cout << endl << endl;
//                        //dev_end
                        GetLocalTime();
                        cout << endl << "[NekoVM]" << "Input Success" << endl << "VM info:" << endl << "system_id = " << sys_id[vm_cnt] << endl << "system = " << vm_sys[vm_cnt] << endl;
                        vm_cnt++;
                    }}
            }
            if(keyinlist[3] == "ubuntu" or keyinlist[3] == "UBUNTU"){
                for (int i = 0; i < 256; i++){
                    if(sysimg[i] == "ubuntu") {
                        sys_id[vm_cnt] = i;
                        vm_sys[vm_cnt] = "ubuntu";
//                        //dev_start
//                        for (int j = 0; j < 256; j++){
//                            cout << vm_sys[j] << ' ';
//                        }
//                        cout << endl << endl;
//                        //dev_end
                        GetLocalTime();
                        cout << endl << "[NekoVM]" << "Input Success" << endl << "VM info:" << endl << "system_id = " << sys_id[vm_cnt] << endl << "system = " << vm_sys[vm_cnt] << endl;
                        vm_cnt++;
                    }}
            }
            if(keyinlist[3] == "debian" or keyinlist[3] == "DEBIAN"){
                for (int i = 0; i < 256; i++){
                    if(sysimg[i] == "debian") {
                        sys_id[vm_cnt] = i;
                        vm_sys[vm_cnt] = "debian";
//                        //dev_start
//                        for (int j = 0; j < 256; j++){
//                            cout << vm_sys[j] << ' ';
//                        }
//                        cout << endl << endl;
//                        //dev_end
                        GetLocalTime();
                        cout << endl << "[NekoVM]" << "Input Success" << endl << "VM info:" << endl << "system_id = " << sys_id[vm_cnt] << endl << "system = " << vm_sys[vm_cnt] << endl;
                        vm_cnt++;
                    }}
            }
        return 0;
        }
    }
    if(keyinlist[1] == "start" or keyinlist[1] == "START") {
        for(int i = 0; i < 256; i++) {
            if(atoi(keyinlist[2].c_str()) ==  sys_id[i])
            {
                start_cnt = i;
                cout << "[NekoVM]system find complete" << endl;
            }
            if(sysimg[start_cnt] == "centos") {
                vm_centos_start();
            }
        }
    }
    return 0;
}

int check()
{
    if (keyinlist[0] == "img" or keyinlist[0] == "IMG"){img();}
    if (keyinlist[0] == "nekovm" or keyinlist[0] == "NEKOVM"){nekovm();}
    return 0;
}
int main()
{
    //system("title LinuxEmulator bash.vision ver.3-alpha.1"); //鏃犳硶閫傞厤鍏朵粬绯荤粺
      system("clear");
    cout << "welcome to LinuxEmulator bash.vision ver.3-alpha.2" << endl;
    while (true)
    {

        cout << "[user@bash]#";
        getline(cin, keyin);

        int ccnt = 0;
        for (int i = 0; i < keyin.size(); i++){
            if(keyin[i] != ' ') tmp += keyin[i];
            else{
                keyinlist[ccnt] = tmp;
                tmp.clear();
                ccnt += 1;
            }

        }
        keyinlist[ccnt] = tmp;
        tmp.clear();
        //dev_start
//        for (int i = 0; i < 5; i++){
//            cout << keyinlist[i] << " ";
//
//        }
//        cout << endl;
        //dev_end
        check();
    }
    return 0;
}
