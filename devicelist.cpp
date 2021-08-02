#include<iostream>
#include<pcapplusplus/PcapLiveDeviceList.h>
#include<vector>
using namespace std;
using namespace pcpp;
int main(int argc, char const *argv[])
{
   vector<PcapLiveDevice*> a;
   vector<IPv4Address> a2;
   PcapLiveDevice*m;
  a = PcapLiveDeviceList::getInstance().getPcapLiveDevicesList();
 //a2 = PcapLiveDeviceList::getInstance().getDnsServers();
m= PcapLiveDeviceList::getInstance().getPcapLiveDeviceByName("wlo1");
//   a2 = m->getDnsServers();
 vector<pcap_addr_t> x = m->getAddresses();
  for (size_t i = 0; i < x.size(); i++)
  {
      //LinkLayerType::
      cout << endl <<m->getDefaultGateway().toString();//.toString();
     // cout << endl <<a2.at(i).toString();
  }
 
 // cout << m->getName();
    return 0;
}
