#include "Node.h"

Node::Node(){
  data = 0;
  left = nullptr;
  right = nullptr;
  height = 1;
}

Node::Node(int data){
  this->data = data;
  left = nullptr;
  right = nullptr;
}
