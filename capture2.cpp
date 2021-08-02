#include<iostream>
#include<pcapplusplus/PcapLiveDeviceList.h>
#include<pcapplusplus/Packet.h>
#include<pcapplusplus/Layer.h>
#include<pcapplusplus/PayloadLayer.h>
#include<pcapplusplus/PcapFileDevice.h>
#include<pcapplusplus/EthLayer.h>
using namespace std;
using namespace pcpp;

 
bool setup(RawPacket *packet,PcapLiveDevice *device,void *m){
   
     PcapFileWriterDevice *r = (PcapFileWriterDevice*)m;
     
    r->writePacket(*packet);
    
cout << "\n packet";

Packet *p;
p = new Packet(packet);
  //EthLayer *layer = (EthLayer*)p->getFirstLayer();
int i = 0;
//if(layer == NULL)cout<<"layer error";
//cout<<layer->getSourceMac().toString();
//if(layer->getProtocol() == Ethernet)cout << "\n ether";
for (pcpp::Layer* curLayer = p->getFirstLayer(); curLayer != NULL; curLayer = curLayer->getNextLayer()){
   switch (curLayer->getProtocol())
   {
   case Ethernet:
       /* code */
       cout << "\n ethernet";
       break;
    case IPv4:
    cout << "\n ipv4";
       /* code */
       break;
    case TCP:
       /* code */
       cout << "\n tcp";
       break;
       
    //    case IPv4:
    //    /* code */
    //    break;
   default:
   cout << "un"<<curLayer->getProtocol();
       break;
   }
}
cout << i;
// if( p->getLayerOfType<PayloadLayer>() !=0){
//     uint8_t *data= p->getLayerOfType<PayloadLayer>()->getData();
//     cout << "\n payload \n";
//     for (size_t i = 0; i < p->getLayerOfType<PayloadLayer>()->getDataLen(); i++)
//     {
//         cout << *(data+i);
//     }
    
// }

return true;
}
int main(int argc, char const *argv[])
{
    PcapLiveDevice  *device  = PcapLiveDeviceList::getInstance().getPcapLiveDeviceByName("lo");
    if (device ==0)
    {
        cout << endl << "device error";

    }
    else{
         PcapFileWriterDevice *r = new PcapFileWriterDevice("mvc3.pcap");
device->open();
r->open();
r->close();
r->open(1);

device->startCaptureBlockingMode(setup,r,20);
device->stopCapture();
device->close();

r->close();
    }


    return 0;
}
