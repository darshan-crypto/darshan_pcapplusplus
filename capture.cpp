#include<iostream>
#include<pcapplusplus/PcapLiveDeviceList.h>
#include<vector>
#include<unistd.h>
using namespace std;
using namespace pcpp;
bool onPacketArrives(pcpp::RawPacket* packet, pcpp::PcapLiveDevice* dev, void* cookie)
{
    // extract the stats object form the cookie
    cout << "packet arrive  \n";
    for(int i =0;i<packet->getRawDataLen();i++){
     cout << packet->getRawData()[i];
    }
return true;
}

int main(int argc, char const *argv[])
{
 
   PcapLiveDevice*m;

m= PcapLiveDeviceList::getInstance().getPcapLiveDeviceByName("wlo1");
if (m->open())
{
    cout << "device opened";
}
if (m->startCaptureBlockingMode(onPacketArrives,NULL,30))
{
    cout << "capture starting";
}

  //this_thread::sleep_for(chrono::seconds(5));
//sleep(5);

m->stopCapture();
m->close();
    return 0;
}
