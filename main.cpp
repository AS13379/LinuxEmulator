#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;
string keyin,keyinlist[5],sysimg[256];
int cnt = 0;
string tmp;

void GetLocalTime()
{
        time_t rawtime;
        struct tm *ptminfo;
        time(&rawtime);
        ptminfo=localtime(&rawtime);
        cout<<ptminfo->tm_year+1900<<'-'
            <<ptminfo->tm_mon+1<<'-'
            <<ptminfo->tm_mday;
        cout<<ptminfo->tm_hour<<':'
            <<ptminfo->tm_min<<':'
            <<ptminfo->tm_sec<< ' ';
}
int img()
{
    if(keyinlist[1] == "create" or keyinlist[1] == "CREATE"){
        if(keyinlist[2] == "centos" or keyinlist[2] == "CENTOS"){
            GetLocalTime();
            cout << "System CentOS Created" << endl << "id = " << cnt << endl << "user = centosuser" << endl << "passwd = centospasswd" << endl;
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

int check()
{
    if (keyinlist[0] == "img" or keyinlist[0] == "IMG"){img();}
    return 0;
}
int main()
{
    system("title LinuxEmulator bash.vision alpha.1.0.0");

    cout << "welcome to LinuxEmulator bash.vision alpha.1.0.0" << endl;
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
}
