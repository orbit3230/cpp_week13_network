#include "link.h"
#include "node.h"
#include "simulator.h"

void Link::transmit(Packet *packet, int fromId) {
  // nodeA_ -> nodeB_ 인 경우
  if (fromId == nodeA_->id()) {
    receive(packet, nodeA_);
  }
  // nodeB_ -> nodeA_ 인 경우
  else {
    receive(packet, nodeB_);
  }

}

void Link::send(Packet *packet, Node *to) {
  log("packet out: " + packet->toString() + " to " + to->toString());
  to->receive(packet);
}

void Link::receive(Packet *packet, Node *from) {
  log("packet in: " + packet->toString() + " from " + from->toString());
  Simulator::schedule(Simulator::now() + delay_, [this, packet, from]() { send(packet, other(from)); });
}