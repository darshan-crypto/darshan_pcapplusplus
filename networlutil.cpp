#include<iostream>
#include<pcapplusplus/PcapLiveDeviceList.h>
#include<pcapplusplus/NetworkUtils.h>

using namespace pcpp;
using namespace std;


int main(int argc, char const *argv[])
{
    uint32_t a;
    double a2;

    PcapLiveDevice *d  = PcapLiveDeviceList::getInstance().getPcapLiveDeviceByName("wlo1");
 //   d->open();
   IPv4Address  i = NetworkUtils::getInstance().getIPv4Address("www.instagram.com",d,a2,a,-1);
   cout << i.toString();
//    MacAddress m = NetworkUtils::getInstance().getMacAddress(IPv4Address("192.168.24.54"),d,a2);
//    cout << m.toString();
//d->close();
    return 0;
}
