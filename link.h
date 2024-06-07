#ifndef LINK_H
#define LINK_H

#include "packet.h"
#include <cstdlib>

class Node;

class Link {
  friend class LinkInstaller;

private:
  Link(Node *nodeA, Node *nodeB) : nodeA_(nodeA), nodeB_(nodeB) {}

  Node *nodeA_;
  Node *nodeB_;
  double delay_;

public:
  double delay() { return delay_; }

  Node *nodeA() { return nodeA_; }

  Node *nodeB() { return nodeB_; }

  // 매개변수로 주어진 노드가 아닌 반대편 노드를 구한다.
  Node *other(const Node *node) const {
    return node == nodeA_ ? nodeB_ : nodeA_;
  }

  // 패킷을 전달
  void transmit(Packet *packet, int fromId);
};

#endif