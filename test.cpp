#include<iostream>
#include<pcapplusplus/MacAddress.h>
#include<pcapplusplus/PcapLiveDeviceList.h>
#include<pcapplusplus/DpdkDeviceList.h>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
    std::string i="100.116.86.228";
   // pcpp::PcapLiveDevice* dev = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDeviceByIp(i.c_str());
  // pcpp::PcapLiveDeviceList *a;
   //a= new pcpp::PcapLiveDeviceList();
   
   std::vector<pcpp::PcapLiveDevice*> a2 ;
       std::vector<pcpp::DpdkDevice*> a3 ;
   a2 = pcpp::PcapLiveDeviceList::getInstance().getPcapLiveDevicesList();
     a3 = pcpp::DpdkDeviceList::getInstance().getDpdkDeviceList();
//   for(int i=0;i<a3.size();i++){
//       cout << endl << a3.at(i)->getDeviceName();//<<"  "<< a3.at(i)->getDesc()<<"  "<< a2.at(i)->getMacAddress().toString();
//   }
   
  //  cout << dev->getMacAddress().toString();
//     pcpp::MacAddress *n;
//     n = new pcpp::MacAddress();
//     cout << n->toString();
    return 0;
}
