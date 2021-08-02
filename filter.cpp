#include<iostream>
#include<pcapplusplus/PcapLiveDeviceList.h>

using namespace std;
using namespace pcpp;
bool x(RawPacket* pPacket, PcapLiveDevice* pDevice, void* userData){
    cout << "\np";
    return 0;
}
int main(int argc, char const *argv[])
{
    PcapLiveDevice *l  = PcapLiveDeviceList::getInstance().getPcapLiveDeviceByName("lo");
    if(l == NULL)return -1;
    l->open();
    AndFilter *a;
    a = new AndFilter();
//    PortFilter *p =new PortFilter(8080,Direction::SRC_OR_DST);
  //  a->addFilter(p);
    //ProtoFilter *p2 = new ProtoFilter(Ethernet);
    IPFilter *i = new IPFilter("127.0.0.1",SRC);
    string v;
    a->addFilter(i);
    a->parseToString(v);
    l->setFilter(v);
    l->startCaptureBlockingMode(x,0,30);
    return 0;
}
