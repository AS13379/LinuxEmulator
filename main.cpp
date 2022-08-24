#include <iostream>
#include <ctime>

using namespace std;
string keyin,keyinlist[5],sysimg[256],tmp,vm_sys[256],dir = "~",vm_keyin,vm_keyinlist[5],dir_list[256];
int cnt = 0,sys_id[256],vm_cnt = 0,start_cnt = 0,mkcnt = 0;

int vm_centos_start()
{
    string user,passwd;
    cout << "[NekoVM]VM CentOS Starting..." << endl;
    cout << "[NekoVM]Start Success." << endl;
    system("clear");
    cout << "CentOS Linux 7 (Core)" << endl << "Kernel 3.10.0-1160.62.1.el7.x86_64 on an x86_64" << endl << endl;
    while(1)
    {
        cout << "LinuxEmulator_Centos_7.0 login:";
        cin >> user;
        cout << "Psaaword:";
        cin >> passwd;
        if (user != "root" or passwd != "centospasswd")
        {
            cout << "Login Incorrect" << endl << endl;
        }
        else break;
    }
    system("clear");
    while (1)
    {
        cout << "[LinuxEmulator " << dir << "]# ";
        getline(cin, vm_keyin);

        int ccnt = 0;
        for (int i = 0; i < vm_keyin.size(); i++)
        {
            if(vm_keyin[i] != ' ') tmp += vm_keyin[i];
            else
            {
                vm_keyinlist[ccnt] = tmp;
                tmp.clear();
                ccnt += 1;
            }

        }
        vm_keyinlist[ccnt] = tmp;
        tmp.clear();
        //check
        if (vm_keyinlist[0] == "help")
        {
            cout << "Due to our technical limitations and C++ compatibility restrictions, we have modified the use of some commands. For details please use the [command] help" << endl;
            cout << "List of commands we currently support:" << endl;
            cout << "help : Type help to get a list of commands we currently support." << endl;
            cout << "tree : Displays the currently existing directories and files in a tree diagram, please note that only all files are currently supported." << endl;
            cout << "mkdir : make a new foder with your own name." << endl;
            cout << "logout : logout vm." << endl;
            cout << "rm : delete some docment."<< endl;
        }
        if (vm_keyinlist[0] == "tree")
        {
            if (dir_list[0].empty())
            {
                cout << "No files could be found in this folder." << endl;
            }
            else
            {
                cout << "Note: Subdirectories and subfolders are not supported" << endl;
                cout << "--------------------" << endl;
                cout << "|-->" << dir_list[0] << endl;
                int cccnt = 1;
                while(dir_list[cccnt].size() != 0)
                {
                    cout << "|" << endl;
                    cout << "|-->" << dir_list[cccnt] << endl;
                    cccnt += 1;
                }
                cout << "--------------------" << endl;
            }
        }
        if (vm_keyinlist[0] == "mkdir")
        {
            if (vm_keyinlist[1].empty())
            {
                cout << "Try <mkdir help> to get help" << endl;
            }
            else if (vm_keyinlist[1] == "help")
            {
                cout << "The command <mkdir> will help you to create a new folder in the current folder." << endl;
                cout << "You can use it like this" << endl;
                cout << "mkdir [New Folder's Name]" << endl;
            }
            else
            {
                dir_list[mkcnt] = vm_keyinlist[1];
                mkcnt += 1;
            }
        }
        if (vm_keyinlist[0] == "logout") {
            cout << "Please note that exiting this VM will retain some content and will not automatically clear it." << endl;
            cout << "If you want to empty them, please use the relevant functions of nekovm or devtools, and you can also use rm." << endl;
            return 0;
        }
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
    if(keyinlist[1] == "create" or keyinlist[1] == "CREATE")
    {
        if(keyinlist[2] == "centos" or keyinlist[2] == "CENTOS")
        {
            GetLocalTime();
            cout << "System CentOS Created" << endl << "id = " << cnt << endl << "user = root" << endl << "passwd = centospasswd" << endl;
            sysimg[cnt] = "centos";
            cnt += 1;
            return 0;
        }
        if(keyinlist[2] == "ubuntu" or keyinlist[2] == "UBUNTU")
        {
            GetLocalTime();
            cout << "System ubuntu Created" << endl << "id = " << cnt << endl << "user = ubuntu" << endl << "passwd = password123" << endl;
            sysimg[cnt] = "ubuntu";
            cnt += 1;
            return 0;
        }
        if(keyinlist[2] == "debian" or keyinlist[2] == "DEBIAN")
        {
            GetLocalTime();
            cout << "System debian Created" << endl << "id = " << cnt << endl << "user = deuser" << endl << "passwd = password123d" << endl;
            sysimg[cnt] = "debian";
            cnt += 1;
            return 0;
        }
    }
    if(keyinlist[1] == "list" or keyinlist[1] == "LIST")
    {
        for(int i = 0; i < 256; i++)
        {
            if(sysimg[i] != "")
            {
                cout << sysimg[i] << ",";
            }
        }
        cout << endl;
        return 0;
    }
}
int nekovm()
{
    if(keyinlist[1] == "input" or keyinlist[1] == "INPUT")
    {
        if(keyinlist[2] == "id" or keyinlist[2] == "ID")
        {
            sys_id[vm_cnt] = atoi(keyinlist[3].c_str());
            vm_sys[vm_cnt] = sysimg[sys_id[cnt]];
            GetLocalTime();
            cout << endl << "[NekoVM]" << "Input Success" << endl << "VM info:" << endl << "system_id = " << keyinlist[3] << endl << "system = " << sysimg[sys_id[vm_cnt]] << endl;
            cnt++;
            return 0;
        }

        if(keyinlist[2] == "name" or keyinlist[2] == "NAME")
        {
            if(keyinlist[3] == "centos" or keyinlist[3] == "CENTOS")
            {
                for (int i = 0; i < 256; i++)
                {
                    if(sysimg[i] == "centos")
                    {

                        GetLocalTime();
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
                    }
                }
            }
            if(keyinlist[3] == "ubuntu" or keyinlist[3] == "UBUNTU")
            {
                for (int i = 0; i < 256; i++)
                {
                    if(sysimg[i] == "ubuntu")
                    {
                        sys_id[vm_cnt] = i;
                        vm_sys[vm_cnt] = "ubuntu";
//                        //dev_start
//                        for (int j = 0; j < 256; j++){
//                            cout << vm_sys[j] << ' ';
//                        }
//                        cout << endl << endl;
//                        //dev_end	cout << endl << "[NekoVM]" << "Input Success" << endl << "VM info:" << endl << "system_id = " << sys_id[vm_cnt] << endl << "system = " << vm_sys[vm_cnt] << endl;
                        vm_cnt++;
                    }
                }
            }
            if(keyinlist[3] == "debian" or keyinlist[3] == "DEBIAN")
            {
                for (int i = 0; i < 256; i++)
                {
                    if(sysimg[i] == "debian")
                    {
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
                    }
                }
            }
            return 0;
        }
    }
    if(keyinlist[1] == "start" or keyinlist[1] == "START")
    {
        for(int i = 0; i < 256; i++)
        {
            if(atoi(keyinlist[2].c_str()) ==  sys_id[i])
            {
                start_cnt = i;
                cout << "[NekoVM]system find complete" << endl;
            }
            if(sysimg[start_cnt] == "centos")
            {
                vm_centos_start();
            }
        }
    }
    return 0;
}

int devtools()
{
    if (keyinlist[1] == "centos")
    {
        vm_centos_start();
    }
}
int check()
{
    if (keyinlist[0] == "img" or keyinlist[0] == "IMG")
    {
        img();
    }
    if (keyinlist[0] == "nekovm" or keyinlist[0] == "NEKOVM")
    {
        nekovm();
    }
    if (keyinlist[0] == "devtools" or keyinlist[0] == "DEVTOOLS")
    {
        devtools();
    }
    return 0;
}
int main()
{
    //system("title LinuxEmulator bash.vision ver.3-alpha.1"); //鏃犳硶閫傞厤鍏朵粬绯荤粺
    system("clear");
    cout << "welcome to LinuxEmulator bash.vision ver.3-alpha.2" << endl;
    while (1)
    {

        cout << "[user@bash]#";
        getline(cin, keyin);

        int ccnt = 0;
        for (int i = 0; i < keyin.size(); i++)
        {
            if(keyin[i] != ' ') tmp += keyin[i];
            else
            {
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
}
