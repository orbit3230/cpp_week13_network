#ifndef LINK_H
#define LINK_H

#include "packet.h"
#include <cstdlib>

class Node;

class Link : public Object {
  friend class LinkInstaller;

private:
  Link(Node *nodeA, Node *nodeB, double delay = 0.0) : nodeA_(nodeA), nodeB_(nodeB), delay_(delay) {}

  Node *nodeA_;
  Node *nodeB_;
  double delay_;

  virtual std::string name() override { return "Link"; }

public:
  double delay() { return delay_; }

  Node *a() const { return nodeA_; }

  Node *b() const { return nodeB_; }

  // 매개변수로 주어진 노드가 아닌 반대편 노드를 구한다.
  Node *other(const Node *node) const {
    return node == nodeA_ ? nodeB_ : nodeA_;
  }

  // 패킷을 전달
  void transmit(Packet *packet, int fromId);
  void send(Packet *packet, Node *to);
  void receive(Packet *packet, Node *from);
};

#endif